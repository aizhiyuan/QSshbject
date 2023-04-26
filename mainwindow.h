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
#include <QGridLayout>
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
    void InitStyle(void);
    //延时函数
    void Sleep(int msec);
    //定时刷新
    void slotCreateConnection();
private slots:
    void on_btnUpload_clicked();

    void on_btnupgrade_clicked();

    void on_btnAdd_clicked();

    void on_btnConnect_clicked();

    void on_btnDel_clicked();

    void on_btnIPStatus_clicked();

    void on_btnClear_clicked();

    void on_btnInstall_clicked();

private:
    Ui::MainWindow *ui;
    QSshSocket *sshScoket;
    QAnnConsole * console;
    QGridLayout *gridLayout;
    QList<QString> errorList;
    QSettings *cfg;
    QTimer *time;
    bool uploadStatus;
    bool rebootStatus;

};

#endif // MAINWINDOW_H
