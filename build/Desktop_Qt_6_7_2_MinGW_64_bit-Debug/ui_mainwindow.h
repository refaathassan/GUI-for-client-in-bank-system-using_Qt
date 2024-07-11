/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *logging;
    QGroupBox *logging_2;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *LEUserName;
    QLineEdit *LEUserPassword;
    QPushButton *PBLog;
    QListWidget *LWLogging;
    QWidget *user;
    QListWidget *LWUser;
    QPushButton *PBLogOutUser;
    QPushButton *PBGetAccountNumberUser;
    QLabel *label_5;
    QPushButton *PBViewTransactionHistoryUser;
    QPushButton *PBMakeTransactionUser;
    QPushButton *PBViewAccountBalanceUser;
    QLineEdit *LEMakeTransactionUser;
    QLineEdit *LETransferAmountUserAcountNumber;
    QLabel *label_8;
    QLabel *label_9;
    QPushButton *PBTransferAmountUser;
    QLineEdit *LETransferAmountUserAmount;
    QLabel *label_16;
    QComboBox *CBCount_2;
    QWidget *admin;
    QPushButton *PBLogOutAdmin;
    QListWidget *LWAdmin;
    QPushButton *PBGetAccountNumberadmin;
    QLabel *label_10;
    QLineEdit *LEViewAccountBalanceAdmin;
    QPushButton *PBViewAccountBalanceAdmin;
    QLineEdit *LEGetAccountNumberadmin;
    QLabel *label_11;
    QPushButton *PBViewTransactionHistoryAdmin;
    QLabel *label_12;
    QLineEdit *LEViewTransactionHistoryAdmin;
    QPushButton *PBLogOutAdmin_14;
    QPushButton *PBDeleteUserAdmin;
    QLabel *label_13;
    QLineEdit *LEDeleteUserAdmin;
    QLineEdit *LECreateNewUserPassword;
    QLabel *label_14;
    QPushButton *PBCreateNewUser;
    QLabel *label_15;
    QLineEdit *LEPBCreateNewUserName;
    QLabel *label_17;
    QLineEdit *LECreateNewUserLogName;
    QLabel *label_18;
    QLabel *label_19;
    QLineEdit *LEPBUpdateNewUser;
    QLineEdit *LEUpdateNewUserPassword;
    QPushButton *PBUpdateNewUser;
    QLabel *label_20;
    QLineEdit *LEPBUpdateNewUserName;
    QLabel *label_21;
    QLabel *label_22;
    QLineEdit *LEUpdateNewUserBalance;
    QLabel *label_38;
    QLineEdit *LEUpdateaccoutnnumber;
    QComboBox *CBCount;
    QLineEdit *LECreateNewUseremail;
    QLabel *label_23;
    QLineEdit *LEUpdateemail;
    QLabel *label_24;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(990, 723);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(10, 0, 961, 681));
        logging = new QWidget();
        logging->setObjectName("logging");
        logging_2 = new QGroupBox(logging);
        logging_2->setObjectName("logging_2");
        logging_2->setGeometry(QRect(20, 10, 781, 531));
        label = new QLabel(logging_2);
        label->setObjectName("label");
        label->setGeometry(QRect(130, 350, 181, 41));
        label->setStyleSheet(QString::fromUtf8("font: 16pt \"Segoe UI\";\n"
"color: rgb(0, 0, 0);\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0.0681818, x2:0.744318, y2:0.665, stop:0 rgba(0, 0, 0, 255), stop:0.886364 rgba(62, 164, 255, 255));"));
        label_2 = new QLabel(logging_2);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(130, 410, 181, 41));
        label_2->setStyleSheet(QString::fromUtf8("font: 16pt \"Segoe UI\";\n"
"color: rgb(0, 0, 0);\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0.0681818, x2:0.744318, y2:0.665, stop:0 rgba(0, 0, 0, 255), stop:0.886364 rgba(62, 164, 255, 255));"));
        LEUserName = new QLineEdit(logging_2);
        LEUserName->setObjectName("LEUserName");
        LEUserName->setGeometry(QRect(350, 350, 341, 41));
        LEUserPassword = new QLineEdit(logging_2);
        LEUserPassword->setObjectName("LEUserPassword");
        LEUserPassword->setGeometry(QRect(350, 410, 341, 41));
        PBLog = new QPushButton(logging_2);
        PBLog->setObjectName("PBLog");
        PBLog->setGeometry(QRect(130, 470, 561, 41));
        PBLog->setStyleSheet(QString::fromUtf8("font: 18pt \"Segoe UI\";"));
        LWLogging = new QListWidget(logging_2);
        LWLogging->setObjectName("LWLogging");
        LWLogging->setGeometry(QRect(130, 190, 561, 151));
        LWLogging->setStyleSheet(QString::fromUtf8("font: 12pt \"Segoe UI\";"));
        tabWidget->addTab(logging, QString());
        user = new QWidget();
        user->setObjectName("user");
        LWUser = new QListWidget(user);
        LWUser->setObjectName("LWUser");
        LWUser->setGeometry(QRect(110, 10, 256, 421));
        PBLogOutUser = new QPushButton(user);
        PBLogOutUser->setObjectName("PBLogOutUser");
        PBLogOutUser->setGeometry(QRect(740, 10, 121, 31));
        PBLogOutUser->setStyleSheet(QString::fromUtf8("font: 14pt \"Segoe UI\";"));
        PBGetAccountNumberUser = new QPushButton(user);
        PBGetAccountNumberUser->setObjectName("PBGetAccountNumberUser");
        PBGetAccountNumberUser->setGeometry(QRect(110, 450, 251, 31));
        PBGetAccountNumberUser->setStyleSheet(QString::fromUtf8("font: 14pt \"Segoe UI\";"));
        label_5 = new QLabel(user);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(420, 470, 161, 21));
        label_5->setStyleSheet(QString::fromUtf8("font: 16pt \"Segoe UI\";\n"
"color: rgb(0, 0, 0);\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0.0681818, x2:0.744318, y2:0.665, stop:0 rgba(0, 0, 0, 255), stop:0.886364 rgba(62, 164, 255, 255));"));
        PBViewTransactionHistoryUser = new QPushButton(user);
        PBViewTransactionHistoryUser->setObjectName("PBViewTransactionHistoryUser");
        PBViewTransactionHistoryUser->setGeometry(QRect(430, 300, 361, 31));
        PBViewTransactionHistoryUser->setStyleSheet(QString::fromUtf8("font: 14pt \"Segoe UI\";"));
        PBMakeTransactionUser = new QPushButton(user);
        PBMakeTransactionUser->setObjectName("PBMakeTransactionUser");
        PBMakeTransactionUser->setGeometry(QRect(420, 500, 371, 31));
        PBMakeTransactionUser->setStyleSheet(QString::fromUtf8("font: 14pt \"Segoe UI\";"));
        PBViewAccountBalanceUser = new QPushButton(user);
        PBViewAccountBalanceUser->setObjectName("PBViewAccountBalanceUser");
        PBViewAccountBalanceUser->setGeometry(QRect(110, 500, 251, 31));
        PBViewAccountBalanceUser->setStyleSheet(QString::fromUtf8("font: 14pt \"Segoe UI\";"));
        LEMakeTransactionUser = new QLineEdit(user);
        LEMakeTransactionUser->setObjectName("LEMakeTransactionUser");
        LEMakeTransactionUser->setGeometry(QRect(590, 470, 201, 21));
        LETransferAmountUserAcountNumber = new QLineEdit(user);
        LETransferAmountUserAcountNumber->setObjectName("LETransferAmountUserAcountNumber");
        LETransferAmountUserAcountNumber->setGeometry(QRect(590, 360, 201, 21));
        label_8 = new QLabel(user);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(420, 390, 161, 21));
        label_8->setStyleSheet(QString::fromUtf8("font: 16pt \"Segoe UI\";\n"
"color: rgb(0, 0, 0);\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0.0681818, x2:0.744318, y2:0.665, stop:0 rgba(0, 0, 0, 255), stop:0.886364 rgba(62, 164, 255, 255));"));
        label_9 = new QLabel(user);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(420, 360, 161, 21));
        label_9->setStyleSheet(QString::fromUtf8("font: 16pt \"Segoe UI\";\n"
"color: rgb(0, 0, 0);\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0.0681818, x2:0.744318, y2:0.665, stop:0 rgba(0, 0, 0, 255), stop:0.886364 rgba(62, 164, 255, 255));"));
        PBTransferAmountUser = new QPushButton(user);
        PBTransferAmountUser->setObjectName("PBTransferAmountUser");
        PBTransferAmountUser->setGeometry(QRect(420, 420, 371, 31));
        PBTransferAmountUser->setStyleSheet(QString::fromUtf8("font: 14pt \"Segoe UI\";"));
        LETransferAmountUserAmount = new QLineEdit(user);
        LETransferAmountUserAmount->setObjectName("LETransferAmountUserAmount");
        LETransferAmountUserAmount->setGeometry(QRect(590, 390, 201, 21));
        label_16 = new QLabel(user);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(10, 20, 91, 21));
        label_16->setStyleSheet(QString::fromUtf8("font: 16pt \"Segoe UI\";\n"
"color: rgb(0, 0, 0);\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0.0681818, x2:0.744318, y2:0.665, stop:0 rgba(0, 0, 0, 255), stop:0.886364 rgba(62, 164, 255, 255));"));
        CBCount_2 = new QComboBox(user);
        CBCount_2->setObjectName("CBCount_2");
        CBCount_2->setGeometry(QRect(720, 270, 69, 22));
        tabWidget->addTab(user, QString());
        admin = new QWidget();
        admin->setObjectName("admin");
        PBLogOutAdmin = new QPushButton(admin);
        PBLogOutAdmin->setObjectName("PBLogOutAdmin");
        PBLogOutAdmin->setGeometry(QRect(810, 10, 101, 31));
        PBLogOutAdmin->setStyleSheet(QString::fromUtf8("font: 14pt \"Segoe UI\";"));
        LWAdmin = new QListWidget(admin);
        LWAdmin->setObjectName("LWAdmin");
        LWAdmin->setGeometry(QRect(60, 10, 271, 481));
        PBGetAccountNumberadmin = new QPushButton(admin);
        PBGetAccountNumberadmin->setObjectName("PBGetAccountNumberadmin");
        PBGetAccountNumberadmin->setGeometry(QRect(60, 580, 271, 31));
        PBGetAccountNumberadmin->setStyleSheet(QString::fromUtf8("font: 14pt \"Segoe UI\";"));
        label_10 = new QLabel(admin);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(360, 590, 161, 21));
        label_10->setStyleSheet(QString::fromUtf8("font: 16pt \"Segoe UI\";\n"
"color: rgb(0, 0, 0);\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0.0681818, x2:0.744318, y2:0.665, stop:0 rgba(0, 0, 0, 255), stop:0.886364 rgba(62, 164, 255, 255));"));
        LEViewAccountBalanceAdmin = new QLineEdit(admin);
        LEViewAccountBalanceAdmin->setObjectName("LEViewAccountBalanceAdmin");
        LEViewAccountBalanceAdmin->setGeometry(QRect(530, 590, 201, 20));
        PBViewAccountBalanceAdmin = new QPushButton(admin);
        PBViewAccountBalanceAdmin->setObjectName("PBViewAccountBalanceAdmin");
        PBViewAccountBalanceAdmin->setGeometry(QRect(360, 620, 371, 31));
        PBViewAccountBalanceAdmin->setStyleSheet(QString::fromUtf8("font: 14pt \"Segoe UI\";"));
        LEGetAccountNumberadmin = new QLineEdit(admin);
        LEGetAccountNumberadmin->setObjectName("LEGetAccountNumberadmin");
        LEGetAccountNumberadmin->setGeometry(QRect(170, 550, 151, 20));
        label_11 = new QLabel(admin);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(60, 550, 101, 21));
        label_11->setStyleSheet(QString::fromUtf8("font: 16pt \"Segoe UI\";\n"
"color: rgb(0, 0, 0);\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0.0681818, x2:0.744318, y2:0.665, stop:0 rgba(0, 0, 0, 255), stop:0.886364 rgba(62, 164, 255, 255));"));
        PBViewTransactionHistoryAdmin = new QPushButton(admin);
        PBViewTransactionHistoryAdmin->setObjectName("PBViewTransactionHistoryAdmin");
        PBViewTransactionHistoryAdmin->setGeometry(QRect(360, 550, 371, 31));
        PBViewTransactionHistoryAdmin->setStyleSheet(QString::fromUtf8("font: 14pt \"Segoe UI\";"));
        label_12 = new QLabel(admin);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(360, 489, 161, 21));
        label_12->setStyleSheet(QString::fromUtf8("font: 16pt \"Segoe UI\";\n"
"color: rgb(0, 0, 0);\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0.0681818, x2:0.744318, y2:0.665, stop:0 rgba(0, 0, 0, 255), stop:0.886364 rgba(62, 164, 255, 255));"));
        LEViewTransactionHistoryAdmin = new QLineEdit(admin);
        LEViewTransactionHistoryAdmin->setObjectName("LEViewTransactionHistoryAdmin");
        LEViewTransactionHistoryAdmin->setGeometry(QRect(530, 490, 201, 20));
        PBLogOutAdmin_14 = new QPushButton(admin);
        PBLogOutAdmin_14->setObjectName("PBLogOutAdmin_14");
        PBLogOutAdmin_14->setGeometry(QRect(60, 510, 271, 31));
        PBLogOutAdmin_14->setStyleSheet(QString::fromUtf8("font: 14pt \"Segoe UI\";"));
        PBDeleteUserAdmin = new QPushButton(admin);
        PBDeleteUserAdmin->setObjectName("PBDeleteUserAdmin");
        PBDeleteUserAdmin->setGeometry(QRect(360, 440, 371, 31));
        PBDeleteUserAdmin->setStyleSheet(QString::fromUtf8("font: 14pt \"Segoe UI\";"));
        label_13 = new QLabel(admin);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(360, 410, 161, 21));
        label_13->setStyleSheet(QString::fromUtf8("font: 16pt \"Segoe UI\";\n"
"color: rgb(0, 0, 0);\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0.0681818, x2:0.744318, y2:0.665, stop:0 rgba(0, 0, 0, 255), stop:0.886364 rgba(62, 164, 255, 255));"));
        LEDeleteUserAdmin = new QLineEdit(admin);
        LEDeleteUserAdmin->setObjectName("LEDeleteUserAdmin");
        LEDeleteUserAdmin->setGeometry(QRect(530, 411, 201, 20));
        LECreateNewUserPassword = new QLineEdit(admin);
        LECreateNewUserPassword->setObjectName("LECreateNewUserPassword");
        LECreateNewUserPassword->setGeometry(QRect(530, 301, 201, 20));
        label_14 = new QLabel(admin);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(360, 300, 161, 21));
        label_14->setStyleSheet(QString::fromUtf8("font: 16pt \"Segoe UI\";\n"
"color: rgb(0, 0, 0);\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0.0681818, x2:0.744318, y2:0.665, stop:0 rgba(0, 0, 0, 255), stop:0.886364 rgba(62, 164, 255, 255));"));
        PBCreateNewUser = new QPushButton(admin);
        PBCreateNewUser->setObjectName("PBCreateNewUser");
        PBCreateNewUser->setGeometry(QRect(360, 360, 371, 31));
        PBCreateNewUser->setStyleSheet(QString::fromUtf8("font: 14pt \"Segoe UI\";"));
        label_15 = new QLabel(admin);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(360, 240, 161, 21));
        label_15->setStyleSheet(QString::fromUtf8("font: 16pt \"Segoe UI\";\n"
"color: rgb(0, 0, 0);\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0.0681818, x2:0.744318, y2:0.665, stop:0 rgba(0, 0, 0, 255), stop:0.886364 rgba(62, 164, 255, 255));"));
        LEPBCreateNewUserName = new QLineEdit(admin);
        LEPBCreateNewUserName->setObjectName("LEPBCreateNewUserName");
        LEPBCreateNewUserName->setGeometry(QRect(530, 240, 201, 20));
        label_17 = new QLabel(admin);
        label_17->setObjectName("label_17");
        label_17->setGeometry(QRect(360, 270, 161, 21));
        label_17->setStyleSheet(QString::fromUtf8("font: 16pt \"Segoe UI\";\n"
"color: rgb(0, 0, 0);\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0.0681818, x2:0.744318, y2:0.665, stop:0 rgba(0, 0, 0, 255), stop:0.886364 rgba(62, 164, 255, 255));"));
        LECreateNewUserLogName = new QLineEdit(admin);
        LECreateNewUserLogName->setObjectName("LECreateNewUserLogName");
        LECreateNewUserLogName->setGeometry(QRect(530, 270, 201, 20));
        label_18 = new QLabel(admin);
        label_18->setObjectName("label_18");
        label_18->setGeometry(QRect(0, 20, 51, 21));
        label_18->setStyleSheet(QString::fromUtf8("font: 16pt \"Segoe UI\";\n"
"color: rgb(0, 0, 0);\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0.0681818, x2:0.744318, y2:0.665, stop:0 rgba(0, 0, 0, 255), stop:0.886364 rgba(62, 164, 255, 255));"));
        label_19 = new QLabel(admin);
        label_19->setObjectName("label_19");
        label_19->setGeometry(QRect(360, 70, 161, 21));
        label_19->setStyleSheet(QString::fromUtf8("font: 16pt \"Segoe UI\";\n"
"color: rgb(0, 0, 0);\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0.0681818, x2:0.744318, y2:0.665, stop:0 rgba(0, 0, 0, 255), stop:0.886364 rgba(62, 164, 255, 255));"));
        LEPBUpdateNewUser = new QLineEdit(admin);
        LEPBUpdateNewUser->setObjectName("LEPBUpdateNewUser");
        LEPBUpdateNewUser->setGeometry(QRect(530, 40, 201, 20));
        LEUpdateNewUserPassword = new QLineEdit(admin);
        LEUpdateNewUserPassword->setObjectName("LEUpdateNewUserPassword");
        LEUpdateNewUserPassword->setGeometry(QRect(530, 71, 201, 20));
        PBUpdateNewUser = new QPushButton(admin);
        PBUpdateNewUser->setObjectName("PBUpdateNewUser");
        PBUpdateNewUser->setGeometry(QRect(360, 190, 371, 31));
        PBUpdateNewUser->setStyleSheet(QString::fromUtf8("font: 14pt \"Segoe UI\";"));
        label_20 = new QLabel(admin);
        label_20->setObjectName("label_20");
        label_20->setGeometry(QRect(360, 40, 161, 21));
        label_20->setStyleSheet(QString::fromUtf8("font: 16pt \"Segoe UI\";\n"
"color: rgb(0, 0, 0);\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0.0681818, x2:0.744318, y2:0.665, stop:0 rgba(0, 0, 0, 255), stop:0.886364 rgba(62, 164, 255, 255));"));
        LEPBUpdateNewUserName = new QLineEdit(admin);
        LEPBUpdateNewUserName->setObjectName("LEPBUpdateNewUserName");
        LEPBUpdateNewUserName->setGeometry(QRect(530, 10, 201, 20));
        label_21 = new QLabel(admin);
        label_21->setObjectName("label_21");
        label_21->setGeometry(QRect(360, 10, 161, 21));
        label_21->setStyleSheet(QString::fromUtf8("font: 16pt \"Segoe UI\";\n"
"color: rgb(0, 0, 0);\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0.0681818, x2:0.744318, y2:0.665, stop:0 rgba(0, 0, 0, 255), stop:0.886364 rgba(62, 164, 255, 255));"));
        label_22 = new QLabel(admin);
        label_22->setObjectName("label_22");
        label_22->setGeometry(QRect(360, 99, 161, 21));
        label_22->setStyleSheet(QString::fromUtf8("font: 16pt \"Segoe UI\";\n"
"color: rgb(0, 0, 0);\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0.0681818, x2:0.744318, y2:0.665, stop:0 rgba(0, 0, 0, 255), stop:0.886364 rgba(62, 164, 255, 255));"));
        LEUpdateNewUserBalance = new QLineEdit(admin);
        LEUpdateNewUserBalance->setObjectName("LEUpdateNewUserBalance");
        LEUpdateNewUserBalance->setGeometry(QRect(530, 100, 201, 20));
        label_38 = new QLabel(admin);
        label_38->setObjectName("label_38");
        label_38->setGeometry(QRect(360, 160, 161, 21));
        label_38->setStyleSheet(QString::fromUtf8("font: 16pt \"Segoe UI\";\n"
"color: rgb(0, 0, 0);\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0.0681818, x2:0.744318, y2:0.665, stop:0 rgba(0, 0, 0, 255), stop:0.886364 rgba(62, 164, 255, 255));"));
        LEUpdateaccoutnnumber = new QLineEdit(admin);
        LEUpdateaccoutnnumber->setObjectName("LEUpdateaccoutnnumber");
        LEUpdateaccoutnnumber->setGeometry(QRect(530, 160, 201, 20));
        CBCount = new QComboBox(admin);
        CBCount->setObjectName("CBCount");
        CBCount->setGeometry(QRect(660, 520, 69, 22));
        LECreateNewUseremail = new QLineEdit(admin);
        LECreateNewUseremail->setObjectName("LECreateNewUseremail");
        LECreateNewUseremail->setGeometry(QRect(530, 330, 201, 20));
        label_23 = new QLabel(admin);
        label_23->setObjectName("label_23");
        label_23->setGeometry(QRect(360, 329, 161, 21));
        label_23->setStyleSheet(QString::fromUtf8("font: 16pt \"Segoe UI\";\n"
"color: rgb(0, 0, 0);\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0.0681818, x2:0.744318, y2:0.665, stop:0 rgba(0, 0, 0, 255), stop:0.886364 rgba(62, 164, 255, 255));"));
        LEUpdateemail = new QLineEdit(admin);
        LEUpdateemail->setObjectName("LEUpdateemail");
        LEUpdateemail->setGeometry(QRect(530, 130, 201, 20));
        label_24 = new QLabel(admin);
        label_24->setObjectName("label_24");
        label_24->setGeometry(QRect(360, 129, 161, 21));
        label_24->setStyleSheet(QString::fromUtf8("font: 16pt \"Segoe UI\";\n"
"color: rgb(0, 0, 0);\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0.0681818, x2:0.744318, y2:0.665, stop:0 rgba(0, 0, 0, 255), stop:0.886364 rgba(62, 164, 255, 255));"));
        tabWidget->addTab(admin, QString());
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 990, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);
        QObject::connect(PBLogOutUser, &QPushButton::clicked, LETransferAmountUserAcountNumber, qOverload<>(&QLineEdit::clear));
        QObject::connect(PBLogOutUser, &QPushButton::clicked, LETransferAmountUserAmount, qOverload<>(&QLineEdit::clear));
        QObject::connect(PBLogOutUser, &QPushButton::clicked, LEMakeTransactionUser, qOverload<>(&QLineEdit::clear));
        QObject::connect(PBLogOutUser, &QPushButton::clicked, LWUser, qOverload<>(&QListWidget::clear));
        QObject::connect(PBLogOutAdmin, &QPushButton::clicked, LEPBCreateNewUserName, qOverload<>(&QLineEdit::clear));
        QObject::connect(PBLogOutAdmin, &QPushButton::clicked, LECreateNewUserLogName, qOverload<>(&QLineEdit::clear));
        QObject::connect(PBLogOutAdmin, &QPushButton::clicked, LECreateNewUserPassword, qOverload<>(&QLineEdit::clear));
        QObject::connect(PBLogOutAdmin, &QPushButton::clicked, LEDeleteUserAdmin, qOverload<>(&QLineEdit::clear));
        QObject::connect(PBLogOutAdmin, &QPushButton::clicked, LEViewTransactionHistoryAdmin, qOverload<>(&QLineEdit::clear));
        QObject::connect(PBLogOutAdmin, &QPushButton::clicked, LEViewAccountBalanceAdmin, qOverload<>(&QLineEdit::clear));
        QObject::connect(PBLogOutAdmin, &QPushButton::clicked, LEGetAccountNumberadmin, qOverload<>(&QLineEdit::clear));
        QObject::connect(PBLogOutAdmin, &QPushButton::clicked, LWAdmin, qOverload<>(&QListWidget::clear));

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        logging_2->setTitle(QCoreApplication::translate("MainWindow", "logging", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">User Name:</p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">User password:</p></body></html>", nullptr));
        PBLog->setText(QCoreApplication::translate("MainWindow", "LOG", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(logging), QCoreApplication::translate("MainWindow", "logging", nullptr));
        PBLogOutUser->setText(QCoreApplication::translate("MainWindow", "Log out", nullptr));
        PBGetAccountNumberUser->setText(QCoreApplication::translate("MainWindow", "Get Account Number", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt;\">transaction amount</span></p></body></html>", nullptr));
        PBViewTransactionHistoryUser->setText(QCoreApplication::translate("MainWindow", "View Transaction History", nullptr));
        PBMakeTransactionUser->setText(QCoreApplication::translate("MainWindow", "Make Transaction", nullptr));
        PBViewAccountBalanceUser->setText(QCoreApplication::translate("MainWindow", "View Account Balance", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt;\">Transfer amount</span></p></body></html>", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt;\">to_AN</span></p></body></html>", nullptr));
        PBTransferAmountUser->setText(QCoreApplication::translate("MainWindow", "Transfer Amount ", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt;\">Resp:</span></p></body></html>", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(user), QCoreApplication::translate("MainWindow", "user", nullptr));
        PBLogOutAdmin->setText(QCoreApplication::translate("MainWindow", "Log out", nullptr));
        PBGetAccountNumberadmin->setText(QCoreApplication::translate("MainWindow", "Get Account Number", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt;\">account number</span></p></body></html>", nullptr));
        PBViewAccountBalanceAdmin->setText(QCoreApplication::translate("MainWindow", "View Account Balance", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt;\">username</span></p></body></html>", nullptr));
        PBViewTransactionHistoryAdmin->setText(QCoreApplication::translate("MainWindow", "View Transaction History", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt;\">account number</span></p></body></html>", nullptr));
        PBLogOutAdmin_14->setText(QCoreApplication::translate("MainWindow", "View Bank DataBase", nullptr));
        PBDeleteUserAdmin->setText(QCoreApplication::translate("MainWindow", "Delete User", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt;\">account number</span></p></body></html>", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt;\">Password</span></p></body></html>", nullptr));
        PBCreateNewUser->setText(QCoreApplication::translate("MainWindow", "Create New User", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt;\">Full Nmar</span></p></body></html>", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt;\">User Name</span></p></body></html>", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt;\">Resp:</span></p></body></html>", nullptr));
        label_19->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt;\">Password</span></p></body></html>", nullptr));
        PBUpdateNewUser->setText(QCoreApplication::translate("MainWindow", "Update User", nullptr));
        label_20->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt;\">User Name</span></p></body></html>", nullptr));
        label_21->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt;\">Full Nmar</span></p></body></html>", nullptr));
        label_22->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt;\">balance</span></p></body></html>", nullptr));
        label_38->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt;\">account number of user</span></p></body></html>", nullptr));
        label_23->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt;\">E-mail</span></p></body></html>", nullptr));
        label_24->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt;\">E-mail</span></p></body></html>", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(admin), QCoreApplication::translate("MainWindow", "admin", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
