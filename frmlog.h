#ifndef FRMLOG_H
#define FRMLOG_H

#include "qsshsocket.h"
#include <QList>
#include <QWidget>

namespace Ui
{
    class frmLog;
}

class frmLog : public QWidget
{
    Q_OBJECT

public:
    explicit frmLog(QWidget *parent = nullptr);
    ~frmLog();

public:
    void initStyle(void);
    void initFunction(void);
    void Sleep(int msec);

private slots:
    void on_btnLogin_clicked(void);
    void loginSuccessful(void);
    void error(QSshSocket::SshError error);
    void pullSuccessful(QString localFile, QString remoteFile);

    void on_btnExportLog_clicked();

    void on_btnOptDir_clicked();

    void on_btnOpenDir_clicked();

private:
    Ui::frmLog *ui;
    QSshSocket *sshScoket;
    QList<QString> errorList;
    QString desktop_path;
    int count;
    bool pullStatus;
};

#endif // FRMLOG_H
