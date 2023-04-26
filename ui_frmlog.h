/********************************************************************************
** Form generated from reading UI file 'frmlog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMLOG_H
#define UI_FRMLOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_frmLog
{
public:
    QGridLayout *gridLayout;
    QLineEdit *lineSaveDir;
    QSpacerItem *verticalSpacer_2;
    QPushButton *btnOpenDir;
    QLabel *labIP;
    QLineEdit *lineIP;
    QLabel *labSaveDir;
    QLabel *label_4;
    QPushButton *btnOptDir;
    QSpacerItem *verticalSpacer;
    QPushButton *btnLogin;
    QPushButton *btnExportLog;
    QLabel *labLog;

    void setupUi(QWidget *frmLog)
    {
        if (frmLog->objectName().isEmpty())
            frmLog->setObjectName(QString::fromUtf8("frmLog"));
        frmLog->resize(540, 211);
        gridLayout = new QGridLayout(frmLog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        lineSaveDir = new QLineEdit(frmLog);
        lineSaveDir->setObjectName(QString::fromUtf8("lineSaveDir"));
        lineSaveDir->setMinimumSize(QSize(0, 35));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(10);
        font.setBold(false);
        font.setWeight(50);
        lineSaveDir->setFont(font);

        gridLayout->addWidget(lineSaveDir, 4, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 1, 0, 1, 1);

        btnOpenDir = new QPushButton(frmLog);
        btnOpenDir->setObjectName(QString::fromUtf8("btnOpenDir"));
        btnOpenDir->setMinimumSize(QSize(0, 35));

        gridLayout->addWidget(btnOpenDir, 4, 3, 1, 1);

        labIP = new QLabel(frmLog);
        labIP->setObjectName(QString::fromUtf8("labIP"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(10);
        labIP->setFont(font1);
        labIP->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(labIP, 2, 0, 1, 1);

        lineIP = new QLineEdit(frmLog);
        lineIP->setObjectName(QString::fromUtf8("lineIP"));
        lineIP->setMinimumSize(QSize(0, 35));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(12);
        lineIP->setFont(font2);
        lineIP->setDragEnabled(true);
        lineIP->setClearButtonEnabled(true);

        gridLayout->addWidget(lineIP, 2, 1, 1, 1);

        labSaveDir = new QLabel(frmLog);
        labSaveDir->setObjectName(QString::fromUtf8("labSaveDir"));
        labSaveDir->setFont(font1);
        labSaveDir->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(labSaveDir, 4, 0, 1, 1);

        label_4 = new QLabel(frmLog);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setStyleSheet(QString::fromUtf8("font: 75 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        label_4->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_4, 0, 0, 1, 4);

        btnOptDir = new QPushButton(frmLog);
        btnOptDir->setObjectName(QString::fromUtf8("btnOptDir"));
        btnOptDir->setMinimumSize(QSize(0, 35));

        gridLayout->addWidget(btnOptDir, 4, 2, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 3, 1, 1, 1);

        btnLogin = new QPushButton(frmLog);
        btnLogin->setObjectName(QString::fromUtf8("btnLogin"));
        btnLogin->setMinimumSize(QSize(0, 35));
        QFont font3;
        font3.setPointSize(9);
        btnLogin->setFont(font3);
        btnLogin->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(btnLogin, 2, 2, 1, 1);

        btnExportLog = new QPushButton(frmLog);
        btnExportLog->setObjectName(QString::fromUtf8("btnExportLog"));
        btnExportLog->setEnabled(false);
        btnExportLog->setMinimumSize(QSize(0, 35));

        gridLayout->addWidget(btnExportLog, 2, 3, 1, 1);

        labLog = new QLabel(frmLog);
        labLog->setObjectName(QString::fromUtf8("labLog"));
        labLog->setMinimumSize(QSize(0, 35));
        labLog->setFont(font2);

        gridLayout->addWidget(labLog, 5, 0, 1, 4);


        retranslateUi(frmLog);

        QMetaObject::connectSlotsByName(frmLog);
    } // setupUi

    void retranslateUi(QWidget *frmLog)
    {
        frmLog->setWindowTitle(QApplication::translate("frmLog", "Form", nullptr));
        lineSaveDir->setPlaceholderText(QApplication::translate("frmLog", "C:\\Users\\Administrator\\Desktop", nullptr));
        btnOpenDir->setText(QApplication::translate("frmLog", "\346\211\223\345\274\200\347\233\256\345\275\225(&O)", nullptr));
        labIP->setText(QApplication::translate("frmLog", "IP\345\234\260\345\235\200\357\274\232", nullptr));
        lineIP->setPlaceholderText(QApplication::translate("frmLog", "192.168.3.127", nullptr));
        labSaveDir->setText(QApplication::translate("frmLog", "\344\277\235\345\255\230\347\233\256\345\275\225\357\274\232", nullptr));
        label_4->setText(QApplication::translate("frmLog", "MOXA\347\275\221\345\205\263\346\227\245\345\277\227\345\257\274\345\207\272\345\267\245\345\205\267", nullptr));
        btnOptDir->setText(QApplication::translate("frmLog", "\351\200\211\346\213\251\347\233\256\345\275\225(&S)", nullptr));
        btnLogin->setText(QApplication::translate("frmLog", "\347\231\273\345\275\225(&C)", nullptr));
        btnExportLog->setText(QApplication::translate("frmLog", "\346\227\245\345\277\227\345\257\274\345\207\272(&E)", nullptr));
        labLog->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class frmLog: public Ui_frmLog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMLOG_H
