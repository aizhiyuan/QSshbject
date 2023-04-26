#include "frmlog.h"
#include "ui_frmlog.h"
#include <QDesktopServices>
#include <QFileDialog>
#include <QMessageBox>
#include <QRegExpValidator>
#include <QStandardPaths>
#include <qdatetime.h>

frmLog::frmLog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::frmLog)
{
    ui->setupUi(this);
    this->initStyle();
}

frmLog::~frmLog()
{
    delete ui;
    delete sshScoket;
}

void frmLog::initStyle()
{
    pullStatus = false;
    sshScoket = nullptr;
//    sshScoket = new QSshSocket(this);
    desktop_path = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
    errorList  << "创建套接字失败" << "无法找到远程设备" << "创建ssh协议失败" << "创建scp协议失败" << "拉取文件传输失败"
               << "推送文件传输失败" << "传输的目标文件不存在" << "读取远程文件失败" << "写入远程文件失败" << "远程登录验证失败";
    QRegExp regxName("\\b(?:(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\.){3}(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\b");
    QValidator *validatorName = new QRegExpValidator(regxName);
    ui->lineIP->setValidator(validatorName);    //ui为lineEdit的控件
    ui->lineSaveDir->setText(desktop_path);
    this->setWindowIcon(QIcon("://logo.ico"));
    this->setWindowTitle("MOXA网关日志导出工具");
    this->setWindowFlags(windowFlags() & ~Qt::WindowMinMaxButtonsHint | Qt::WindowMinimizeButtonHint);
}

void frmLog::initFunction()
{
//    连接成功后执行
    connect(sshScoket, &QSshSocket::loginSuccessful, this, &frmLog::loginSuccessful);
//    错误时执行
    connect(sshScoket, &QSshSocket::error, this, &frmLog::error) ;
    //    下载成功后执行
    connect(sshScoket, &QSshSocket::pullSuccessful, this, &frmLog::pullSuccessful) ;
}

void frmLog::on_btnLogin_clicked()
{
    if(ui->btnLogin->text() == "登录(&C)") {
        QString moxa_ip = ui->lineIP->text();
        if(moxa_ip.isEmpty()) {
            QMessageBox::information(this, "提示", "网关IP地址未填写，请填写IP地址后再登录！");
            ui->lineIP->clear();
            return ;
        }
        ui->btnLogin->setEnabled(false);
        if(sshScoket == nullptr) {
            sshScoket = new QSshSocket(this);
            sshScoket->setConnectHost(ui->lineIP->text(), 22);
            sshScoket->login("moxa", "moxa");
            ui->btnLogin->setText("断开(&C)");
            this->initFunction();
        }
    } else  if(ui->btnLogin->text() == "断开(&C)") {
        if(nullptr != sshScoket) {
            sshScoket->disconnectFromHost();
            sshScoket->deleteLater();
            sshScoket = nullptr;
            ui->btnLogin->setText("登录(&C)");
            ui->labLog->setText(tr("%1：已断开").arg(ui->lineIP->text()));
            ui->btnLogin->setStyleSheet("");
            ui->btnExportLog->setEnabled(false);
        }
    }
}

void frmLog::loginSuccessful()
{
    ui->labLog->setText(tr("%1：已连接").arg(ui->lineIP->text()));
    ui->btnExportLog->setEnabled(true);
    ui->btnLogin->setStyleSheet("background-color: rgb(85, 170, 0);");
    ui->btnLogin->setEnabled(true);
}

void frmLog::error(QSshSocket::SshError error)
{
    sshScoket->disconnectFromHost();
    ui->labLog->setText(tr("%1：%2").arg(ui->lineIP->text()).arg(errorList.at(error)));
    QMessageBox::information(this, "提示", tr("%1：%2").arg(ui->lineIP->text()).arg(errorList.at(error)));
    ui->btnLogin->setText("登录(&C)");
    if(nullptr != sshScoket) {
        sshScoket->disconnectFromHost();
        sshScoket->deleteLater();
        sshScoket = nullptr;
    }
    ui->btnExportLog->setEnabled(false);
    ui->btnLogin->setEnabled(true);
}

void frmLog::pullSuccessful(QString localFile, QString remoteFile)
{
    ui->labLog->setText(tr("%1：日志已下载").arg(ui->lineIP->text()));
    QMessageBox::information(this, "提示", "Moxa网关日志导出成功！");
    ui->btnLogin->setEnabled(true);
    ui->btnExportLog->setEnabled(true);
}

void frmLog::Sleep(int msec)
{
    QTime dieTime = QTime::currentTime().addMSecs(msec);
    while (QTime::currentTime() < dieTime) {
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    }
}


void frmLog::on_btnExportLog_clicked()
{
    if(ui->lineSaveDir->text().isEmpty()) {
        QMessageBox::information(this, "提示", "请选择保存目录后，再导出日志！");
        return;
    }
    ui->btnExportLog->setEnabled(false);
    ui->btnLogin->setEnabled(false);
    QString fileName = tr("moxa_%1.tar.gz").arg(ui->lineIP->text().replace(".", "_"));
    qDebug() << "fileName:" << fileName;
    QString saveFime = tr("%1/%2").arg(ui->lineSaveDir->text()).arg(fileName);
    qDebug() << "saveFime:" << saveFime;
    QString remoteFile = tr("/home/moxa/%1").arg(fileName);
    qDebug() << "remoteFile:" << remoteFile;
    QFile file(saveFime);
    sshScoket->add2ShellCommand(tr("rm -rf %1").arg(remoteFile));
    Sleep(2000);
    sshScoket->add2ShellCommand("cd /tmp/");
    Sleep(1000);
    sshScoket->add2ShellCommand(tr("tar -zcf %1 *").arg(remoteFile));
    Sleep(500);
    ui->labLog->setText(tr("%1：日志已打包").arg(ui->lineIP->text()));
    Sleep(500);
    sshScoket->pullFile(saveFime, remoteFile);
    Sleep(2000);

}


void frmLog::on_btnOptDir_clicked()
{
    QString files = QFileDialog::getExistingDirectory();
    if (files.isEmpty()) {
        return;
    }
    ui->lineSaveDir->setText(files);
}

void frmLog::on_btnOpenDir_clicked()
{
    QUrl _url = QUrl::fromLocalFile(ui->lineSaveDir->text());
    QDesktopServices::openUrl(_url);
}

