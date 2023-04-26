/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_5;
    QSplitter *splitter;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_3;
    QTextBrowser *textBrowser;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout;
    QPushButton *btnDel;
    QPushButton *btnConnect;
    QPushButton *btnUpload;
    QPushButton *btnInstall;
    QPushButton *btnupgrade;
    QPushButton *btnIPStatus;
    QPushButton *btnClear;
    QLabel *label_4;
    QListWidget *listWidget;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QPushButton *btnAdd;
    QDockWidget *dockWidget;
    QWidget *stackedWidget_2;
    QGridLayout *gridLayout_3;
    QWidget *stackedWidget;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(936, 492);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        MainWindow->setFont(font);
        MainWindow->setStyleSheet(QString::fromUtf8("QPushButton:hover{\n"
"	background-color: rgb(78, 154, 6);\n"
"}\n"
"\n"
"  QToolButton { /* all types of tool button */\n"
"      border: 2px solid #8f8f91;\n"
"      border-radius: 6px;\n"
"      background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                        stop: 0 #f6f7fa, stop: 1 #dadbde);\n"
"  }\n"
"\n"
"  QToolButton[popupMode=\"1\"] { /* only for MenuButtonPopup */\n"
"      padding-right: 20px; /* make way for the popup button */\n"
"  }\n"
"QToolButton:hover{\n"
"	background-color: rgb(78, 154, 6);\n"
"}\n"
"  QToolButton:pressed {\n"
"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                        stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"  }\n"
"\n"
"  QToolButton::menu-button {\n"
"      border: 2px solid gray;\n"
"      border-top-right-radius: 6px;\n"
"      border-bottom-right-radius: 6px;\n"
"      /* 16px width + 4px for border = 20px allocated above */\n"
"      width: 16px;\n"
"  }\n"
"\n"
"\n"
"  QToolButton"
                        "::menu-arrow:open {\n"
"      top: 1px; left: 1px; /* shift it a bit */\n"
"  }"));
        MainWindow->setDocumentMode(false);
        MainWindow->setUnifiedTitleAndToolBarOnMac(false);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_5 = new QGridLayout(groupBox);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        splitter = new QSplitter(groupBox);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setAutoFillBackground(false);
        splitter->setLineWidth(1);
        splitter->setOrientation(Qt::Horizontal);
        splitter->setHandleWidth(4);
        layoutWidget = new QWidget(splitter);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_2->addWidget(label_3);

        textBrowser = new QTextBrowser(layoutWidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setMinimumSize(QSize(230, 0));

        verticalLayout_2->addWidget(textBrowser);

        splitter->addWidget(layoutWidget);
        layoutWidget1 = new QWidget(splitter);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        gridLayout_2 = new QGridLayout(layoutWidget1);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        btnDel = new QPushButton(layoutWidget1);
        btnDel->setObjectName(QString::fromUtf8("btnDel"));
        btnDel->setAutoDefault(true);
        btnDel->setFlat(false);

        verticalLayout->addWidget(btnDel);

        btnConnect = new QPushButton(layoutWidget1);
        btnConnect->setObjectName(QString::fromUtf8("btnConnect"));
        btnConnect->setAutoDefault(true);
        btnConnect->setFlat(false);

        verticalLayout->addWidget(btnConnect);

        btnUpload = new QPushButton(layoutWidget1);
        btnUpload->setObjectName(QString::fromUtf8("btnUpload"));
        btnUpload->setEnabled(false);

        verticalLayout->addWidget(btnUpload);

        btnInstall = new QPushButton(layoutWidget1);
        btnInstall->setObjectName(QString::fromUtf8("btnInstall"));
        btnInstall->setEnabled(false);

        verticalLayout->addWidget(btnInstall);

        btnupgrade = new QPushButton(layoutWidget1);
        btnupgrade->setObjectName(QString::fromUtf8("btnupgrade"));
        btnupgrade->setEnabled(false);

        verticalLayout->addWidget(btnupgrade);

        btnIPStatus = new QPushButton(layoutWidget1);
        btnIPStatus->setObjectName(QString::fromUtf8("btnIPStatus"));
        btnIPStatus->setEnabled(true);

        verticalLayout->addWidget(btnIPStatus);

        btnClear = new QPushButton(layoutWidget1);
        btnClear->setObjectName(QString::fromUtf8("btnClear"));
        btnClear->setEnabled(true);

        verticalLayout->addWidget(btnClear);


        horizontalLayout_3->addLayout(verticalLayout);


        gridLayout_2->addLayout(horizontalLayout_3, 2, 0, 1, 1);

        label_4 = new QLabel(layoutWidget1);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_2->addWidget(label_4, 0, 0, 1, 1);

        listWidget = new QListWidget(layoutWidget1);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setMinimumSize(QSize(39, 0));

        gridLayout_2->addWidget(listWidget, 1, 0, 1, 1);

        splitter->addWidget(layoutWidget1);

        gridLayout_5->addWidget(splitter, 0, 0, 1, 1);


        gridLayout->addWidget(groupBox, 0, 0, 1, 1);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayout_3 = new QVBoxLayout(groupBox_2);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        lineEdit = new QLineEdit(groupBox_2);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setStyleSheet(QString::fromUtf8(""));
        lineEdit->setDragEnabled(false);
        lineEdit->setReadOnly(false);
        lineEdit->setClearButtonEnabled(true);

        horizontalLayout_2->addWidget(lineEdit);

        btnAdd = new QPushButton(groupBox_2);
        btnAdd->setObjectName(QString::fromUtf8("btnAdd"));
        btnAdd->setMinimumSize(QSize(106, 0));
        btnAdd->setAutoDefault(true);
        btnAdd->setFlat(false);

        horizontalLayout_2->addWidget(btnAdd);


        verticalLayout_3->addLayout(horizontalLayout_2);


        gridLayout->addWidget(groupBox_2, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        dockWidget = new QDockWidget(MainWindow);
        dockWidget->setObjectName(QString::fromUtf8("dockWidget"));
        dockWidget->setMinimumSize(QSize(553, 424));
        dockWidget->setFeatures(QDockWidget::DockWidgetFloatable|QDockWidget::DockWidgetMovable);
        dockWidget->setAllowedAreas(Qt::AllDockWidgetAreas);
        stackedWidget_2 = new QWidget();
        stackedWidget_2->setObjectName(QString::fromUtf8("stackedWidget_2"));
        gridLayout_3 = new QGridLayout(stackedWidget_2);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        stackedWidget = new QWidget(stackedWidget_2);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setProperty("currentIndex", QVariant(-1));

        gridLayout_3->addWidget(stackedWidget, 0, 0, 1, 2);

        dockWidget->setWidget(stackedWidget_2);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(1), dockWidget);

        retranslateUi(MainWindow);

        btnDel->setDefault(false);
        btnConnect->setDefault(false);
        btnAdd->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MOXA\347\275\221\345\205\263\345\215\207\347\272\247\347\250\213\345\272\217", nullptr));
        groupBox->setTitle(QString());
        label_3->setText(QApplication::translate("MainWindow", "\346\223\215\344\275\234\350\256\260\345\275\225\357\274\232", nullptr));
        textBrowser->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\345\215\207\347\272\247\350\257\264\346\230\216\357\274\232</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">1\343\200\201\345\205\210\346\267\273\345\212\240IP\345\234\260\345\235\200</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">2\343\200\201\347\202\271\345\207\273\343\200\220\350\277\236\346\216\245\343\200\221\350\277\236\346\216\245\345\210\260\350\256\276\345\244\207</p>\n"
"<p style=\" margin-top"
                        ":0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">3\343\200\201\347\202\271\345\207\273\343\200\220\344\270\212\344\274\240\343\200\221\351\200\211\346\213\251\351\234\200\350\246\201\346\233\264\346\226\260\347\232\204\346\226\207\344\273\266</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">4\343\200\201\347\202\271\345\207\273\343\200\220\345\256\211\350\243\205\343\200\221\350\277\233\350\241\214\345\256\211\350\243\205\345\233\272\344\273\266</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">5\343\200\201\347\202\271\345\207\273\343\200\220\346\233\264\346\226\260\343\200\221\350\277\233\350\241\214\346\233\264\346\226\260\345\233\272\344\273\266</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br "
                        "/></p></body></html>", nullptr));
        btnDel->setText(QApplication::translate("MainWindow", "\345\210\240\351\231\244(&D)", nullptr));
        btnConnect->setText(QApplication::translate("MainWindow", "\350\277\236\346\216\245(&C)", nullptr));
        btnUpload->setText(QApplication::translate("MainWindow", "\344\270\212\344\274\240(&U)", nullptr));
        btnInstall->setText(QApplication::translate("MainWindow", "\345\256\211\350\243\205(&I)", nullptr));
        btnupgrade->setText(QApplication::translate("MainWindow", "\346\233\264\346\226\260(&G)", nullptr));
        btnIPStatus->setText(QApplication::translate("MainWindow", "\350\256\276\345\244\207\347\212\266\346\200\201(&P)", nullptr));
        btnClear->setText(QApplication::translate("MainWindow", "\346\270\205\351\231\244\350\256\260\345\275\225(&Q)", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "\350\256\276\345\244\207\345\210\227\350\241\250\357\274\232", nullptr));
        groupBox_2->setTitle(QString());
        label_2->setText(QApplication::translate("MainWindow", "IP\345\234\260\345\235\200\357\274\232", nullptr));
        btnAdd->setText(QApplication::translate("MainWindow", "\346\267\273\345\212\240(&A)", nullptr));
        dockWidget->setWindowTitle(QApplication::translate("MainWindow", "ssh", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
