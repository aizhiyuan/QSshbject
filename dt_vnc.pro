
QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += C++11

TARGET = QMoxaLog
TEMPLATE = app

SOURCES += main.cpp\
    frmlog.cpp \
        mainwindow.cpp \
    qannconsole.cpp \
    qsshconnect.cpp \
    qsshsocket.cpp \
    qvncclientwidget.cpp

HEADERS  += mainwindow.h \
    frmlog.h \
    qannconsole.h \
    qsshconnect.h \
    qsshsocket.h \
    qvncclientwidget.h

FORMS    += mainwindow.ui \
    frmlog.ui

#LIBS += -lssh
win32{
        # static lib request this
        DEFINES += LIBSSH_STATIC
        LIBS += -L$$PWD/lib -lssh -lgcrypt -lgpg-error
        LIBS += -lws2_32 -lz
}
else:LIBS += -lssh

#RC_ICONS = ://logo.ico
RC_ICONS = logo.ico

RESOURCES += \
    img.qrc



