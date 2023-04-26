#include "qannconsole.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QProcess>
#include <QSettings>
#include <QCompleter>
#include <QTime>
//#define LOGIN_SHELL_CMD_STR "killall dt_ui;/tmp/dt_ui --platform vnc&sleep 1;ps | grep dt_ui | grep -v grep && echo connect2vnc"
//#define LOGOUT_SHELL_CMD_STR "killall dt_ui;/tmp/dt_ui&sleep 1;ps | grep dt_ui | grep -v grep && echo remote dt_ui is running"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    cfg = new QSettings("./" + qAppName() + ".ini", QSettings::IniFormat, this);
    ui->setupUi(this);
    cfg->setValue("port", "22");
    cfg->setValue("username", "moxa");
    cfg->setValue("passwd", "moxa");
    cfg->setValue("uploadDir", "/home/moxa");
    ui->stackedWidget->setCurrentIndex(0);

    errorList  << "创建套接字失败" << "无法找到远程设备" << "创建ssh协议失败" << "创建scp协议失败" << "拉取文件传输失败"
               << "推送文件传输失败" << "传输的目标文件不存在" << "读取远程文件失败" << "写入远程文件失败" << "远程登录验证失败";

    setWindowFlags(windowFlags() & ~Qt::WindowMinMaxButtonsHint | Qt::WindowMinimizeButtonHint);

    //IP校验
    QRegExp regxName("\\b(?:(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\.){3}(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\b");
    QValidator *validatorName = new QRegExpValidator(regxName);
    ui->lineEdit->setValidator(validatorName);    //ui为lineEdit的控件
    int hostipcount = cfg->value("hostipcount").toInt();
    if (hostipcount > 0) {
        for (int i = 0; i < hostipcount ; i++) {
            QString hostip = cfg->value(tr("hostip%1").arg(i + 1)).toString();
            ui->listWidget->addItem(hostip);
        }
    }

    time = new QTimer();
    connect(time, &QTimer::timeout, this, &MainWindow::slotCreateConnection);

    ui->listWidget->setSelectionMode(QAbstractItemView::ContiguousSelection);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnUpload_clicked()
{

    QStringList files = QFileDialog::getOpenFileNames(this);
    if (files.isEmpty()) {
        return;
    }

    if (!sshMap->isLoggedIn()) {
        ui->textBrowser->append(tr("请先连接上再传输"));
        return;
    }
    bool txOver = false;
    int txDoneCnt = 0;
    QAnnConsole *console = ui->stackedWidget->widget(i)->findChild<QAnnConsole *>("console");
    QColor defaultColor = console->textColor();
    connect(sshMap.find(listAddr).value(), &QSshSocket::pushSuccessful, this, [&](QString srcFile, QString dstFile) {
        QFileInfo fileInfo = QFileInfo(srcFile);
        if (!dstFile.isEmpty()) {
            console->setTextColor(Qt::blue);
            console->append(tr("%1--->%2:\t上传100%,上传成功!").arg(srcFile).arg(dstFile));
            ui->textBrowser->append(tr("%1：%2,上传100%,上传成功!").arg(sshMap.find(listAddr).value()->host()).arg(fileInfo.fileName()));
            txDoneCnt++;
        } else {
            console->setTextColor(Qt::red);//.arg(sshMap.find(listAddr).value()->host()).arg(files)
            console->append(srcFile + "--->" + dstFile + ",上传错误，请检查!");
            ui->textBrowser->append(tr("%1：%2,上传错误，请检查!").arg(sshMap.find(listAddr).value()->host()).arg(fileInfo.fileName()));
        }
        txOver = true;
        console->setTextColor(defaultColor);
    });
    foreach (auto file, files) {
        txOver = false;
        QFileInfo fi(file);
        if (!file.isEmpty()) {
            console->append(tr("准备上传%1,请稍等...").arg(fi.fileName()));
            ui->textBrowser->append(tr("%1：准备上传%2,请稍等...").arg(sshMap.find(listAddr).value()->host()).arg(fi.fileName()));
        }
        qDebug() << "uploadDir:" << cfg->value("uploadDir").toString() + "/" + fi.fileName();
        sshMap.find(listAddr).value()->pushFile(file, cfg->value("uploadDir").toString() + "/" + fi.fileName());
        while (!txOver && sshMap.find(listAddr).value()->isLoggedIn()) {
            qApp->processEvents();
            usleep(1000);
        }
    }
    this->disconnect(sshMap.find(listAddr).value(), &QSshSocket::pushSuccessful, 0, 0);
    console->setTextColor(Qt::green);
    console->append(tr("======总共上传了%1个文件======\n").arg(txDoneCnt));
    ui->textBrowser->append(tr("%1：总共上传了%2个文件").arg(sshMap.find(listAddr).value()->host()).arg(txDoneCnt));
    console->setCurrentCharFormat(defaultCFTMap.find(listAddr).value());
    sshMap.find(listAddr).value()->enter2shell();


}

void MainWindow::on_btnupgrade_clicked()
{
    if (ui->btnConnect->text() == "断开(&C)") {
        int row = sshMap.count();

        QString localPath = QCoreApplication::applicationDirPath();

        if (row <= 0) {
            ui->textBrowser->append(tr("请添加IP地址后，再连接设备"));
            return ;
        }

        for (int i = 0; i < row; i++) {
            QString listAddr = sshMap.keys().at(i);
            QString filePath;
            QString fileName;
            QString remoteFilePath = tr("/home/moxa/%1FileState.txt").arg(listAddr);
            QString shellCmd = tr("find /home/moxa/ -name jcore_update.tar.gz* > %1").arg(remoteFilePath);

            localPath = tr("%1/%2FileState.txt").arg(localPath).arg(listAddr);
            QStringList shell_cmd_list  = { "sudo su", "moxa", "mv jcore_update.tar.gz.* jcore_update.tar.gz",
                                            "tar -zxf jcore_update.tar.gz", "bash update.sh"
                                          };
            if (!sshMap.find(listAddr).value()->isLoggedIn()) {
                ui->textBrowser->append(tr("未连接设备，无法更新固件"));
                return;
            }
//            sshMap.find(listAddr).value()->add2ShellCommand(shellCmd);
//            sshMap.find(listAddr).value()->pullFile(localPath, remoteFilePath);
            Sleep(500);

            QFile file(localPath);
            if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
                qDebug() << "Can't open the file!" << endl;
                return ;
            }

            while (!file.atEnd()) {
                QByteArray line = file.readLine();
                filePath += line;
            }
            filePath = filePath.remove("\n");
            QFileInfo fileInfo(filePath);
            fileName = fileInfo.fileName();
//            if (fileName.contains("jcore_update.tar.gz", Qt::CaseSensitive)) {
            ui->textBrowser->append(tr("%1：正在更新固件").arg(listAddr));
            foreach (QString shell_cmd, shell_cmd_list) {
                Sleep(100);
                sshMap.find(listAddr).value()->add2ShellCommand(shell_cmd);
            }

//            } else {
//                ui->textBrowser->append(tr("%1：未上传更新固件,更新失败").arg(listAddr));
//                return ;
//            }

        }
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
        int row = sshMap.count();

        QString localPath = QCoreApplication::applicationDirPath();

        if (row <= 0) {
            ui->textBrowser->append(tr("请添加IP地址后，再连接设备"));
            return ;
        }

        for (int i = 0; i < row; i++) {
            QString listAddr = sshMap.keys().at(i);
            int ping = QProcess::execute(tr("ping %1 -w 1 -n 1").arg(listAddr));
            qDebug() << "ping:" << ping;
            if (0 == ping) {
                ui->listWidget->item(i)->setBackground(Qt::green);
//                ui->textBrowser->append(tr("%1：该设备可以连接").arg(listAddr));
            } else {
                ui->listWidget->item(i)->setBackground(Qt::red);
                ui->textBrowser->append(tr("%1：该设备已断开").arg(listAddr));
                int ret = sshMap.find(listAddr).value()->isLoggedIn();
                qDebug() << "ret:" << ret;
                if (ret) {
                    int stacked_count = ui->stackedWidget->count();
                    QAnnConsole *console;
                    for (int i = 0; i < stacked_count ; i++) {
                        console = ui->stackedWidget->widget(i)->findChild<QAnnConsole *>(listAddr);
                    }
                    console->deleteLater();

                    int combo_count = ui->comboBox->findText(listAddr);
                    ui->comboBox->removeItem(combo_count);
                    ui->stackedWidget->removeWidget(ui->stackedWidget->widget(i));
                    sshMap.find(listAddr).value()->disconnectFromHost();
                    sshMap.find(listAddr).value()->deleteLater();
                    sshMap.find(listAddr).value() = nullptr;
                    sshMap.remove(listAddr);
                    defaultCFTMap.remove(listAddr);
                }
            }
        }
    } else {
        ui->textBrowser->append(tr("未连接设备，无法监测设备连接状态"));
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
        ui->listWidget->addItem(ui->lineEdit->text());
        ui->lineEdit->clear();
    } else {
        ui->textBrowser->append(tr("正在保持连接无法添加设备"));
    }
}

void MainWindow::on_btnConnect_clicked()
{
    index = 0;
    if (ui->btnConnect->text() == "连接(&C)") {
        ui->textBrowser->clear();
        int row = ui->listWidget->count();
        if (row <= 0) {
            ui->textBrowser->append(tr("请添加IP地址后，再连接设备"));
            return ;
        }
        qDebug() << "listWidget count:" << row;
        for (int i = 0; i < row; ++i) {
            QString listAddr = ui->listWidget->item(i)->text();
            int ping = QProcess::execute(tr("ping %1 -w 1 -n 1").arg(listAddr));
            qDebug() << "ping:" << ping;
            if (!ping) {
                ui->listWidget->item(i)->setBackground(Qt::green);
            } else {
                ui->listWidget->item(i)->setBackground(Qt::red);
                ui->textBrowser->append(tr("%1：远程设备未上线").arg(listAddr));
                continue;
            }
            QSshSocket *sshScoket = new QSshSocket(this);
            connect(sshScoket, &QSshSocket::loginSuccessful, this, [ = ]() {
                ui->textBrowser->append(tr("%1：已连接").arg(listAddr));
                QWidget *page = new QWidget();
                page->setObjectName(listAddr);
                QGridLayout *gridLayout = new QGridLayout(page);
                gridLayout->setSpacing(6);
                gridLayout->setContentsMargins(11, 11, 11, 11);
                gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
                gridLayout->setContentsMargins(9, -1, -1, -1);
                QAnnConsole *console = new QAnnConsole(page);
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
                QTextCharFormat defaultCFT = console->currentCharFormat();
                defaultCFTMap.insert(listAddr, defaultCFT);

                console->installEventFilter(sshScoket);
                connect(sshScoket, &QSshSocket::commandExecuted, this, [ = ](QString s1, QString s2) {
                    if (!s1.isEmpty()) {
                        qDebug() << "s1" << s1;
                    }
                    if (!s2.isEmpty()) {
                        console << s2;
                    }
                });

                sshMap.insert(listAddr, sshScoket);
                consoleMap.insert(listAddr, console);
                ui->comboBox->insertItem(index, listAddr);
                ui->stackedWidget->insertWidget(index, page);
                ui->btnUpload->setEnabled(true);
                ui->btnupgrade->setEnabled(true);
                ui->lineShellCmd->setEnabled(true);
                ui->btnSend->setEnabled(true);
                ui->btnAdd->setEnabled(false);
                ui->btnDel->setEnabled(false);
                ui->btnWidgetSub->setEnabled(true);
                ui->comboBox->setEnabled(true);
                ui->btnWidgetAdd->setEnabled(true);
                index++;
                time->start(1000 * 10);
                ui->btnConnect->setText(tr("断开(&C)"));
                sshScoket->enter2shell();
            });

            //error(QSshSocket::SshError error)
            connect(sshScoket, &QSshSocket::error, this, [ = ](QSshSocket::SshError error) {
                sshScoket->disconnectFromHost();
//                sshScoket->deleteLater();
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
            }

        }

        for (QMap<QString, QSshSocket *>::iterator it = sshMap.begin(); it != sshMap.end(); it++) {
            qDebug() << "key:" << it.key() << "," << "value:" << it.value();
        }
    } else if (ui->btnConnect->text() == "断开(&C)") {
        int count = sshMap.count();
        qDebug() << "count:" << count;
        if (count <= 0) {
            ui->textBrowser->append(tr("请添加IP地址后，再连接设备"));
            return ;
        }
        for (int i = count - 1; i >= 0; i--) {
            qDebug() << "i:" << i;
            QString listAddr = sshMap.keys().at(i);
            int ret = sshMap.find(listAddr).value()->isLoggedIn();
            qDebug() << "ret:" << ret;
            if (ret) {
                ui->textBrowser->append(tr("%1：已断开").arg(sshMap.find(listAddr).value()->host()));
                QAnnConsole *console = ui->stackedWidget->widget(i)->findChild<QAnnConsole *>("console");
                console->deleteLater();
                ui->comboBox->removeItem(i);
                ui->stackedWidget->removeWidget(ui->stackedWidget->widget(i));
                sshMap.find(listAddr).value()->disconnectFromHost();
                sshMap.find(listAddr).value()->deleteLater();
                sshMap.find(listAddr).value() = nullptr;
                sshMap.remove(listAddr);
                defaultCFTMap.remove(listAddr);
            }
        }
        time->stop();
        sshMap.clear();
        ui->btnConnect->setText(tr("连接(&C)"));
        ui->btnAdd->setEnabled(true);
        ui->btnDel->setEnabled(true);
        ui->btnUpload->setEnabled(false);
        ui->btnupgrade->setEnabled(false);
        ui->btnWidgetSub->setEnabled(false);
        ui->comboBox->setEnabled(false);
        ui->btnWidgetAdd->setEnabled(false);

    }
}


void MainWindow::on_btnWidgetSub_clicked()
{
    int index = ui->stackedWidget->currentIndex();
    index--;
    if (index < 0) {
        index = ui->stackedWidget->count();
    }
    ui->stackedWidget->setCurrentIndex(index);
}


void MainWindow::on_btnWidgetAdd_clicked()
{
    int index = ui->stackedWidget->currentIndex();
    index++;
    if (index > ui->stackedWidget->count()) {
        index = 0;
    }
    ui->stackedWidget->setCurrentIndex(index);
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


void MainWindow::on_btnSave_clicked()
{
    int count = ui->listWidget->count();
    for (int i = 0; i <  count; i++) {
        QString listAddr = ui->listWidget->item(i)->text();
        cfg->setValue(tr("hostip%1").arg(i + 1), listAddr);
    }
    cfg->setValue("hostipcount", count);
    ui->textBrowser->append(tr("IP地址保存成功"));
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
    int count = sshMap.count();
    for (int i = 0; i < count; i++) {
        QString listAddr = sshMap.keys().at(i);
        consoleMap.find(listAddr).value()->clear();
    }
    count = ui->listWidget->count();
    for (int i = 0; i < count; i++) {
        ui->listWidget->item(i)->setBackgroundColor(Qt::white);
    }

}

void MainWindow::on_btnSend_clicked()
{
    if (ui->btnConnect->text() == "断开(&C)") {
        int row = sshMap.count();
        QString shell_cmd = ui->lineShellCmd->text();
        if (shell_cmd.isEmpty()) {
            return;
        }

        if (row <= 0) {
            ui->textBrowser->append(tr("请添加IP地址后，再连接设备"));
            return ;
        }

        for (int i = 0; i < row; i++) {
            QString listAddr = sshMap.keys().at(i);
            if (!sshMap.find(listAddr).value()->isLoggedIn()) {
                ui->textBrowser->append(tr("%1:未连接设备，无法发送shell命令").arg(listAddr));
                continue;;
            }
            sshMap.find(listAddr).value()->add2ShellCommand(shell_cmd);
        }

    } else if (ui->btnConnect->text() == "连接(&C)") {
        ui->textBrowser->append(tr("设备未连接,无法发送shell命令"));
    }
}



void MainWindow::on_lineShellCmd_returnPressed()
{

}

