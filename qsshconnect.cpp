#include "qsshconnect.h"

#include <qgridlayout.h>
#include <qprocess.h>
#include <qwidget.h>

QSshConnect::QSshConnect(QObject *parent) : QObject(parent) {
  m_errorList << "创建套接字失败"
              << "无法找到远程设备"
              << "创建ssh协议失败"
              << "创建scp协议失败"
              << "拉取文件传输失败"
              << "推送文件传输失败"
              << "传输的目标文件不存在"
              << "读取远程文件失败"
              << "写入远程文件失败"
              << "远程登录验证失败";
  sshScoket = new QSshSocket(this);
}

QSshConnect::~QSshConnect() {}

void QSshConnect::recvDevPara(struct DevPara _devPara) {
  m_devHost = _devPara.devHost;
  m_devPort = _devPara.devPort;
  m_devUser = _devPara.devUser;
  m_devPasswd = _devPara.devPasswd;
  m_devUploadDir = _devPara.devUploadDir;
}

void QSshConnect::recvDevHost(QString _devHost) { m_devHost = _devHost; }

void QSshConnect::recvDevPort(int _devPort) { m_devPort = _devPort; }

void QSshConnect::recvDevUser(QString _devUser) { m_devUser = _devUser; }

void QSshConnect::recvDevPasswd(QString _devPasswd) {
  m_devPasswd = _devPasswd;
}

void QSshConnect::recvDevUploadDir(QString _devUploadDir) {
  m_devUploadDir = _devUploadDir;
}

void QSshConnect::recvShellCmd(QString _shellCmd) { m_shellCmd = _shellCmd; }

void QSshConnect::connect() {
  QObject::connect(sshScoket, &QSshSocket::loginSuccessful, this, [=]() {
    QWidget *page = new QWidget();
    page->setObjectName(m_devHost);
    QGridLayout *gridLayout = new QGridLayout(page);
    gridLayout->setSpacing(6);
    gridLayout->setContentsMargins(11, 11, 11, 11);
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    gridLayout->setContentsMargins(9, -1, -1, -1);
    QAnnConsole *console = new QAnnConsole(page);
    console->setObjectName(m_devHost);
    QFont font1;
    font1.setFamily(QString::fromUtf8(
        "\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\345"
        "\276\256\347\261\263\351\273\221"));
    font1.setBold(false);
    font1.setWeight(50);
    console->setFont(font1);
    console->setStyleSheet(
        QString::fromUtf8("background-color: rgb(85, 87, 83);\n"
                          "color: rgb(255, 255, 255);\n"));
    console->setFrameShape(QFrame::NoFrame);
    console->setReadOnly(false);
    gridLayout->addWidget(console, 0, 0, 1, 1);
    m_defaultCFT = console->currentCharFormat();

    console->installEventFilter(sshScoket);
    QObject::connect(sshScoket, &QSshSocket::commandExecuted, this,
                     [=](QString s1, QString s2) {
                       if (!s1.isEmpty()) {
                         qDebug() << "s1" << s1;
                       }
                       if (!s2.isEmpty()) {
                         console << s2;
                       }
                     });
    sshScoket->enter2shell();
  });
}

void QSshConnect::disConnect() {}

void QSshConnect::upload() {}

void QSshConnect::update() {}

void QSshConnect::ping() {
  int ping = QProcess::execute(tr("ping %1 -c 1").arg(m_devHost));
  emit pingStatus(!ping);
}
