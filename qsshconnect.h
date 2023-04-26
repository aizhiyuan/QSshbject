#ifndef QSSHCONNECT_H
#define QSSHCONNECT_H

#include <QObject>
#include <QString>
#include <QStringList>

#include "qannconsole.h"
#include "qsshsocket.h"

struct DevPara {
  QString devHost;
  int devPort;
  QString devUser;
  QString devPasswd;
  QString devUploadDir;
};

class QSshConnect : public QObject {
  Q_OBJECT

 public:
  explicit QSshConnect(QObject *parent = nullptr);
  ~QSshConnect();
 public slots:

  void recvDevPara(struct DevPara _devPara);
  void recvDevHost(QString _devHost);
  void recvDevPort(int _devPort);
  void recvDevUser(QString _devUser);
  void recvDevPasswd(QString _devPasswd);
  void recvDevUploadDir(QString _devUploadDir);
  void recvShellCmd(QString _shellCmd);
  void connect();
  void disConnect();
  void upload();
  void update();
  void ping();

 signals:
  void errorStr(QString _errorStr);
  void pingStatus(bool _status);
  void connStatus(QString _statusStr);

 private:
  // 设备IP地址
  QString m_devHost;
  int m_devPort;
  QString m_devUser;
  QString m_devPasswd;
  QString m_devUploadDir;
  QString m_shellCmd;
  QStringList m_errorList;
  QTextCharFormat m_defaultCFT;
  QSshSocket *sshScoket;
};

#endif  // QSSHCONNECT_H
