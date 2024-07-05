QT       += core gui
QT       += network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    adduserhandler.cpp \
    deletehandler.cpp \
    getacoutnnumberhandler.cpp \
    handler.cpp \
    loghandler.cpp \
    main.cpp \
    mainwindow.cpp \
    maketransactionhandler.cpp \
    tcpsocket.cpp \
    transferamounthandler.cpp \
    updateuserhandler.cpp \
    viewaccountbalancehandler.cpp \
    viewdatabasehandler.cpp \
    viewtransectionhistoryhandler.cpp

HEADERS += \
    adduserhandler.h \
    deletehandler.h \
    getacoutnnumberhandler.h \
    handler.h \
    loghandler.h \
    mainwindow.h \
    maketransactionhandler.h \
    tcpsocket.h \
    transferamounthandler.h \
    updateuserhandler.h \
    viewaccountbalancehandler.h \
    viewdatabasehandler.h \
    viewtransectionhistoryhandler.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
