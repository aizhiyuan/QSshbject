#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QVector>
#include "qsshsocket.h"
#include "qannconsole.h"
#include <QMessageBox>
#include <QTimer>
#include <QThread>
class QSettings;


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void run();

public:
    //延时函数
    void Sleep(int msec);
    //定时刷新
    void slotCreateConnection();
private slots:
    void on_btnUpload_clicked();

    void on_btnupgrade_clicked();

    void on_btnAdd_clicked();

    void on_btnConnect_clicked();

    void on_btnWidgetSub_clicked();

    void on_btnWidgetAdd_clicked();

    void on_btnDel_clicked();

    void on_btnSave_clicked();

    void on_btnIPStatus_clicked();

    void on_btnClear_clicked();

    void on_btnSend_clicked();

    void on_lineShellCmd_returnPressed();

private:
    Ui::MainWindow *ui;

    QMap<QString, QSshSocket *> sshMap;
    QMap<QString, QAnnConsole *> consoleMap;
    QMap<QString, QTextCharFormat> defaultCFTMap;
    QList<QString> errorList;
    int index = 0;
    QSettings *cfg;

    QTimer *time;

};

#endif // MAINWINDOW_H
