#include "qannconsole.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QProcess>
#include <QSettings>
#include <QCompleter>
#include <QTime>
#include <QStandardPaths>
//#define LOGIN_SHELL_CMD_STR "killall dt_ui;/tmp/dt_ui --platform vnc&sleep 1;ps | grep dt_ui | grep -v grep && echo connect2vnc"
//#define LOGOUT_SHELL_CMD_STR "killall dt_ui;/tmp/dt_ui&sleep 1;ps | grep dt_ui | grep -v grep && echo remote dt_ui is running"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon("://logo.ico"));
    this->InitStyle();
}

MainWindow::~MainWindow()
{
    delete sshScoket;
    delete console;
    delete gridLayout;
    delete ui;
}

void MainWindow::InitStyle()
{
    sshScoket = nullptr;
    console = nullptr;
    gridLayout = nullptr;
    uploadStatus = false;
    cfg = new QSettings("./" + qAppName() + ".ini", QSettings::IniFormat, this);
    cfg->setValue("port", "22");
    cfg->setValue("username", "moxa");
    cfg->setValue("passwd", "moxa");
    cfg->setValue("uploadDir", "/home/moxa");
    errorList  << "创建套接字失败" << "无法找到远程设备" << "创建ssh协议失败" << "创建scp协议失败" << "拉取文件传输失败"
               << "推送文件传输失败" << "传输的目标文件不存在" << "读取远程文件失败" << "写入远程文件失败" << "远程登录验证失败";
    setWindowFlags(windowFlags() & ~Qt::WindowMinMaxButtonsHint | Qt::WindowMinimizeButtonHint);
    //IP校验
    QRegExp regxName("\\b(?:(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\.){3}(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\b");
    QValidator *validatorName = new QRegExpValidator(regxName);
    ui->lineEdit->setValidator(validatorName);    //ui为lineEdit的控件
    time = new QTimer();
    connect(time, &QTimer::timeout, this, &MainWindow::slotCreateConnection);
    ui->listWidget->setSelectionMode(QAbstractItemView::ContiguousSelection);
    int count = cfg->value("hostipcount").toInt();
    for (int i = 0; i <  count; i++) {
        QString listAddr = cfg->value(QString("hostip%1").arg(i + 1)).toString();
        ui->listWidget->addItem(listAddr);
    }
    gridLayout = new QGridLayout(ui->stackedWidget);
    gridLayout->setSpacing(6);
    gridLayout->setContentsMargins(11, 11, 11, 11);
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    gridLayout->setContentsMargins(9, -1, -1, -1);
    time->start(1000 * 3);
}

void MainWindow::on_btnUpload_clicked()
{
    if (ui->btnConnect->text() == "断开(&C)") {
        if (!sshScoket->isLoggedIn()) {
            ui->textBrowser->append(tr("请先连接上再传输"));
            return;
        }
        QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
//        QStandardPaths::standardLocations(QStandardPaths::DesktopLocation);
        QString desktop_path = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
        QStringList files = QFileDialog::getOpenFileNames(this, nullptr, desktop_path);
        if (files.isEmpty()) {
            return;
        }
        if(uploadStatus) {
            Sleep(100);
            sshScoket->add2ShellCommand("sudo su");
            Sleep(100);
            sshScoket->add2ShellCommand("moxa");
            Sleep(100);
            sshScoket->add2ShellCommand("rm -rf /home/moxa/*");
            uploadStatus = false;
        }
        ui->btnConnect->setEnabled(false);
        ui->btnUpload->setEnabled(false);
        bool txOver = false;
        int txDoneCnt = 0;
        QColor defaultColor = console->textColor();
        QTextCharFormat defaultCFT = console->currentCharFormat();
        connect(sshScoket, &QSshSocket::pushSuccessful, this, [&](QString srcFile, QString dstFile) {
            QFileInfo fileInfo = QFileInfo(srcFile);
            if (!dstFile.isEmpty()) {
                console->setTextColor(Qt::blue);
                console->append(tr("%1--->%2:\t上传100%,上传成功!").arg(srcFile).arg(dstFile));
                ui->textBrowser->append(tr("%1：%2,上传100%,上传成功!").arg(sshScoket->host()).arg(fileInfo.fileName()));
                txDoneCnt++;
                ui->btnupgrade->setEnabled(true);
                ui->btnInstall->setEnabled(true);
                uploadStatus = true;
            } else {
                console->setTextColor(Qt::red);//.arg(ssh.find(listAddr).value()->host()).arg(files)
                console->append(srcFile + "--->" + dstFile + ",上传错误，请检查!");
                ui->textBrowser->append(tr("%1：%2,上传错误，请检查!").arg(sshScoket->host()).arg(fileInfo.fileName()));
                uploadStatus = false;
            }
            ui->btnConnect->setEnabled(true);
            ui->btnUpload->setEnabled(true);
            txOver = true;
            console->setTextColor(defaultColor);
        });
        foreach (auto file, files) {
            txOver = false;
            QFileInfo fi(file);
            if (!file.isEmpty()) {
                console->append(tr("准备上传%1,请稍等...").arg(fi.fileName()));
                ui->textBrowser->append(tr("%1：准备上传%2,请稍等...").arg(sshScoket->host()).arg(fi.fileName()));
            }
            qDebug() << "uploadDir:" << cfg->value("uploadDir").toString() + "/" + fi.fileName();
            sshScoket->pushFile(file, cfg->value("uploadDir").toString() + "/" + fi.fileName());
            while (!txOver && sshScoket->isLoggedIn()) {
                qApp->processEvents();
                usleep(1000);
            }
        }
        this->disconnect(sshScoket, &QSshSocket::pushSuccessful, 0, 0);
        console->setTextColor(Qt::green);

        console->append(tr("======总共上传了%1个文件======\n").arg(txDoneCnt));
        ui->textBrowser->append(tr("%1：总共上传了%2个文件").arg(sshScoket->host()).arg(txDoneCnt));
        console->setCurrentCharFormat(defaultCFT);
        sshScoket->enter2shell();
    } else {
        ui->textBrowser->append(tr("未连接设备，无法上传固件"));
    }
}

void MainWindow::on_btnupgrade_clicked()
{
    if (ui->btnConnect->text() == "断开(&C)") {
        QString listAddr = ui->listWidget->item(0)->text();
        QString filePath;
        QString fileName;
        QStringList shell_cmd_list  = { "sudo su", "moxa", "pkill -f ./j", "mv jcore_update.tar.gz* jcore_update.tar.gz",
                                        "tar -zxf jcore_update.tar.gz", "bash update.sh"
                                      };
        if (!sshScoket->isLoggedIn()) {
            ui->textBrowser->append(tr("未连接设备，无法更新固件"));
            return;
        }
        ui->btnupgrade->setEnabled(false);
        ui->btnConnect->setEnabled(false);
//        ui->btnUpload->setEnabled(false);
        Sleep(500);
        ui->textBrowser->append(tr("%1：正在更新固件").arg(listAddr));
        foreach (QString shell_cmd, shell_cmd_list) {
            Sleep(100);
            sshScoket->add2ShellCommand(shell_cmd);
        }
        rebootStatus = true;
    } else {
        ui->textBrowser->append(tr("未连接设备，无法更新固件"));
    }
}

void MainWindow::Sleep(int msec)
{
    QTime dieTime = QTime::currentTime().addMSecs(msec);
    while (QTime::currentTime() < dieTime) {
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    }
}

void MainWindow::slotCreateConnection()
{
    if (ui->btnConnect->text() == "断开(&C)") {
        QString localPath = QCoreApplication::applicationDirPath();
        int count = ui->listWidget->count();
        if(count <= 0) {
            return;
        }
        QString listAddr =  ui->listWidget->item(0)->text();
        int ping = QProcess::execute(tr("ping %1 -w 1 -n 1").arg(listAddr));
        qDebug() << "ping:" << ping;
        if (0 == ping) {
            ui->listWidget->item(0)->setBackground(Qt::green);
//            ui->textBrowser->append(tr("%1：该设备可以连接").arg(listAddr));
        } else {
            ui->listWidget->item(0)->setBackground(Qt::red);
//            ui->textBrowser->append(tr("%1：该设备已断开").arg(listAddr));
            if(rebootStatus) {
                QMessageBox::information(this, "提示", "更新成功，网关设备重启中...");
            }
            if(sshScoket != nullptr) {
                console->deleteLater();
                sshScoket->disconnectFromHost();
                sshScoket->deleteLater();
                ui->btnConnect->setText("连接(&C)");
                ui->btnUpload->setEnabled(false);
                ui->btnupgrade->setEnabled(false);
                ui->btnConnect->setEnabled(true);
                ui->btnDel->setEnabled(true);
                ui->btnAdd->setEnabled(true);
                sshScoket = nullptr;
            }
        }
    } else {
//        ui->textBrowser->append(tr("未连接设备，无法监测设备连接状态"));
    }
}

void MainWindow::on_btnAdd_clicked()
{
    if (ui->btnConnect->text() == "连接(&C)") {
        QString ipAddr = ui->lineEdit->text();
        if (ipAddr.isEmpty()) {
            return;
        }
        int row = ui->listWidget->count();
        for (int i = 0; i < row; i++) {
            QString  listAddr = ui->listWidget->item(i)->text();
            if (listAddr == ipAddr) {
                ui->textBrowser->append(tr("不能重复添加该IP:%1").arg(ipAddr));
                return ;
            }
        }
        if(row == 1) {
            delete ui->listWidget->takeItem(0);
        }
        ui->listWidget->addItem(ui->lineEdit->text());
        ui->lineEdit->clear();
    } else {
        ui->textBrowser->append(tr("正在保持连接无法添加设备"));
    }
}

void MainWindow::on_btnConnect_clicked()
{
    if (ui->btnConnect->text() == "连接(&C)") {
        ui->textBrowser->clear();
        int count = ui->listWidget->count();
        for (int i = 0; i <  count; i++) {
            QString listAddr = ui->listWidget->item(i)->text();
            cfg->setValue(tr("hostip%1").arg(i + 1), listAddr);
        }
        cfg->setValue("hostipcount", count);
        int row = ui->listWidget->count();
        if (row <= 0) {
            ui->textBrowser->append(tr("请添加IP地址后，再连接设备"));
            return ;
        }
        qDebug() << "listWidget count:" << row;
        QString listAddr = ui->listWidget->item(0)->text();
        int ping = QProcess::execute(tr("ping %1 -w 1 -n 1").arg(listAddr));
        qDebug() << "ping:" << ping;
        if (!ping) {
            ui->listWidget->item(0)->setBackground(Qt::green);
        } else {
            ui->listWidget->item(0)->setBackground(Qt::red);
            ui->textBrowser->append(tr("%1：远程设备未上线").arg(listAddr));
            return ;
        }
        sshScoket = new QSshSocket(this);
        connect(sshScoket, &QSshSocket::loginSuccessful, this, [ = ]() {
            ui->textBrowser->append(tr("%1：已连接").arg(listAddr));
            console = new QAnnConsole(ui->stackedWidget);
            console->setObjectName(listAddr);
            QFont font1;
            font1.setFamily(QString::fromUtf8("\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\345\276\256\347\261\263\351\273\221"));
            font1.setBold(false);
            font1.setWeight(50);
            console->setFont(font1);
            console->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 87, 83);\n"
                                   "color: rgb(255, 255, 255);\n"));
            console->setFrameShape(QFrame::NoFrame);
            console->setReadOnly(false);
            gridLayout->addWidget(console, 0, 0, 1, 1);
            console->installEventFilter(sshScoket);
            connect(sshScoket, &QSshSocket::commandExecuted, this, [ = ](QString s1, QString s2) {
                if (!s1.isEmpty()) {
//                    qDebug() << "s1" << s1;
                }
                if (!s2.isEmpty()) {
                    console << s2;
                }
            });
            rebootStatus = false;
            ui->btnDel->setEnabled(false);
            ui->btnUpload->setEnabled(true);
            ui->btnAdd->setEnabled(false);
            ui->btnConnect->setText(tr("断开(&C)"));
            sshScoket->enter2shell();
        });
        connect(sshScoket, &QSshSocket::error, this, [ = ](QSshSocket::SshError error) {
            sshScoket->disconnectFromHost();
            ui->textBrowser->append(tr("%1：%2").arg(listAddr).arg(errorList.at(error)));
        });
        if (!sshScoket->isLoggedIn()) {
            QString username, passwd;
            username = cfg->value("username").toString();
            passwd = cfg->value("passwd").toString();
            if (listAddr.isEmpty()) {
                ui->textBrowser->append(tr("温馨提示：IP地址为空"));
                return;
            }
            sshScoket->setConnectHost(listAddr);
            sshScoket->login(username, passwd);
            Sleep(100);
            sshScoket->add2ShellCommand("sudo su");
            Sleep(100);
            sshScoket->add2ShellCommand("moxa");
            Sleep(100);
            sshScoket->add2ShellCommand("rm -rf /home/moxa/*");
        }
    } else if (ui->btnConnect->text() == "断开(&C)") {
        QString listAddr = ui->listWidget->item(0)->text();
        if (sshScoket->isLoggedIn()) {
            ui->textBrowser->append(tr("%1：已断开").arg(sshScoket->host()));
            console->deleteLater();
//            gridLayout->deleteLater();
            sshScoket->disconnectFromHost();
            sshScoket->deleteLater();
            sshScoket = nullptr;
        }
//        time->stop();
        ui->btnConnect->setText(tr("连接(&C)"));
        ui->btnDel->setEnabled(true);
        ui->btnAdd->setEnabled(true);
        ui->btnUpload->setEnabled(false);
        ui->btnupgrade->setEnabled(false);
    }
}

void MainWindow::on_btnDel_clicked()
{
    if (ui->btnConnect->text() == "连接(&C)") {
        QList<QListWidgetItem *>itemList = ui->listWidget->selectedItems();
        if (itemList.count() <= 0) {
            ui->textBrowser->append(tr("请选择需要删除的IP地址"));
            return;
        }
        foreach (QListWidgetItem *item, itemList) {
            delete item;
        }
    } else {
        ui->textBrowser->append(tr("正在保持连接无法删除设备"));
    }
}



void MainWindow::on_btnIPStatus_clicked()
{
    int count = ui->listWidget->count();
    for (int i = 0; i < count; i++) {
        QString listAddr = ui->listWidget->item(i)->text();
        int ping = QProcess::execute(tr("ping %1 -w 1 -n 1").arg(listAddr));
        qDebug() << "ping:" << ping;
        if (0 == ping) {
            ui->listWidget->item(i)->setBackground(Qt::green);
            ui->textBrowser->append(tr("%1：该设备已在线").arg(listAddr));
        } else {
            ui->listWidget->item(i)->setBackground(Qt::red);
            ui->textBrowser->append(tr("%1：该设备已离线").arg(listAddr));
        }
    }
    ui->textBrowser->append(tr(" 设备状态已更新"));
}

void MainWindow::on_btnClear_clicked()
{
    ui->textBrowser->clear();
    if(sshScoket != nullptr) {
        console->clear();
    }
    int count = ui->listWidget->count();
    if(count > 0) {
        ui->listWidget->item(0)->setBackgroundColor(Qt::white);
    }
}



void MainWindow::on_btnInstall_clicked()
{
    if (ui->btnConnect->text() == "断开(&C)") {
        QString listAddr = ui->listWidget->item(0)->text();
        QString filePath;
        QString fileName;
        QStringList shell_cmd_list  = { "sudo su", "moxa", "pkill -f ./j", "rm -rf  /home/jcore","cd /home/moxa",
                                        "tar -zxf jcore_*.tar.gz -C /home/", "cd /home/jcore/web/install_junmix_environment","bash install.sh","reboot"
                                      };
        if (!sshScoket->isLoggedIn()) {
            ui->textBrowser->append(tr("未连接设备，无法安装固件"));
            return;
        }
        ui->btnupgrade->setEnabled(false);
        ui->btnConnect->setEnabled(false);
//        ui->btnUpload->setEnabled(false);
        Sleep(500);
        ui->textBrowser->append(tr("%1：正在安装固件").arg(listAddr));
        foreach (QString shell_cmd, shell_cmd_list) {
            Sleep(100);
            sshScoket->add2ShellCommand(shell_cmd);
        }
        rebootStatus = true;
    } else {
        ui->textBrowser->append(tr("未连接设备，无法安装固件"));
    }
}

