QT       += core gui
QT       += network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
INCLUDEPATH += "C:/Program Files/OpenSSL-Win64/include"

# Path to OpenSSL libraries directory
LIBS += -L"C:/Program Files/OpenSSL-Win64/lib/VC/x64/MD" -lssl -lcrypto

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
    viewtransectionhistoryhandler.cpp \
    qaesencryption.cpp

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
    viewtransectionhistoryhandler.h \
    aesni/aesni-key-init.h \
    qaesencryption.h \
    aesni/aesni-key-exp.h \
    aesni/aesni-enc-ecb.h \
    aesni/aesni-enc-cbc.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
