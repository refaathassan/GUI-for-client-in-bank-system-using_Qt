/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
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
    QComboBox *comboBox;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(906, 644);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(10, 10, 871, 591));
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
        LWUser->setGeometry(QRect(110, 10, 256, 391));
        PBLogOutUser = new QPushButton(user);
        PBLogOutUser->setObjectName("PBLogOutUser");
        PBLogOutUser->setGeometry(QRect(740, 10, 121, 31));
        PBLogOutUser->setStyleSheet(QString::fromUtf8("font: 14pt \"Segoe UI\";"));
        PBGetAccountNumberUser = new QPushButton(user);
        PBGetAccountNumberUser->setObjectName("PBGetAccountNumberUser");
        PBGetAccountNumberUser->setGeometry(QRect(110, 410, 251, 31));
        PBGetAccountNumberUser->setStyleSheet(QString::fromUtf8("font: 14pt \"Segoe UI\";"));
        label_5 = new QLabel(user);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(420, 470, 161, 21));
        label_5->setStyleSheet(QString::fromUtf8("font: 16pt \"Segoe UI\";\n"
"color: rgb(0, 0, 0);\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0.0681818, x2:0.744318, y2:0.665, stop:0 rgba(0, 0, 0, 255), stop:0.886364 rgba(62, 164, 255, 255));"));
        PBViewTransactionHistoryUser = new QPushButton(user);
        PBViewTransactionHistoryUser->setObjectName("PBViewTransactionHistoryUser");
        PBViewTransactionHistoryUser->setGeometry(QRect(110, 490, 251, 31));
        PBViewTransactionHistoryUser->setStyleSheet(QString::fromUtf8("font: 14pt \"Segoe UI\";"));
        PBMakeTransactionUser = new QPushButton(user);
        PBMakeTransactionUser->setObjectName("PBMakeTransactionUser");
        PBMakeTransactionUser->setGeometry(QRect(420, 500, 371, 31));
        PBMakeTransactionUser->setStyleSheet(QString::fromUtf8("font: 14pt \"Segoe UI\";"));
        PBViewAccountBalanceUser = new QPushButton(user);
        PBViewAccountBalanceUser->setObjectName("PBViewAccountBalanceUser");
        PBViewAccountBalanceUser->setGeometry(QRect(110, 450, 251, 31));
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
        tabWidget->addTab(user, QString());
        admin = new QWidget();
        admin->setObjectName("admin");
        PBLogOutAdmin = new QPushButton(admin);
        PBLogOutAdmin->setObjectName("PBLogOutAdmin");
        PBLogOutAdmin->setGeometry(QRect(740, 10, 101, 31));
        PBLogOutAdmin->setStyleSheet(QString::fromUtf8("font: 14pt \"Segoe UI\";"));
        LWAdmin = new QListWidget(admin);
        LWAdmin->setObjectName("LWAdmin");
        LWAdmin->setGeometry(QRect(60, 10, 271, 481));
        PBGetAccountNumberadmin = new QPushButton(admin);
        PBGetAccountNumberadmin->setObjectName("PBGetAccountNumberadmin");
        PBGetAccountNumberadmin->setGeometry(QRect(360, 510, 371, 31));
        PBGetAccountNumberadmin->setStyleSheet(QString::fromUtf8("font: 14pt \"Segoe UI\";"));
        label_10 = new QLabel(admin);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(360, 400, 161, 21));
        label_10->setStyleSheet(QString::fromUtf8("font: 16pt \"Segoe UI\";\n"
"color: rgb(0, 0, 0);\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0.0681818, x2:0.744318, y2:0.665, stop:0 rgba(0, 0, 0, 255), stop:0.886364 rgba(62, 164, 255, 255));"));
        LEViewAccountBalanceAdmin = new QLineEdit(admin);
        LEViewAccountBalanceAdmin->setObjectName("LEViewAccountBalanceAdmin");
        LEViewAccountBalanceAdmin->setGeometry(QRect(530, 401, 201, 20));
        PBViewAccountBalanceAdmin = new QPushButton(admin);
        PBViewAccountBalanceAdmin->setObjectName("PBViewAccountBalanceAdmin");
        PBViewAccountBalanceAdmin->setGeometry(QRect(360, 430, 371, 31));
        PBViewAccountBalanceAdmin->setStyleSheet(QString::fromUtf8("font: 14pt \"Segoe UI\";"));
        LEGetAccountNumberadmin = new QLineEdit(admin);
        LEGetAccountNumberadmin->setObjectName("LEGetAccountNumberadmin");
        LEGetAccountNumberadmin->setGeometry(QRect(530, 480, 201, 20));
        label_11 = new QLabel(admin);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(360, 479, 161, 21));
        label_11->setStyleSheet(QString::fromUtf8("font: 16pt \"Segoe UI\";\n"
"color: rgb(0, 0, 0);\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0.0681818, x2:0.744318, y2:0.665, stop:0 rgba(0, 0, 0, 255), stop:0.886364 rgba(62, 164, 255, 255));"));
        PBViewTransactionHistoryAdmin = new QPushButton(admin);
        PBViewTransactionHistoryAdmin->setObjectName("PBViewTransactionHistoryAdmin");
        PBViewTransactionHistoryAdmin->setGeometry(QRect(360, 350, 371, 31));
        PBViewTransactionHistoryAdmin->setStyleSheet(QString::fromUtf8("font: 14pt \"Segoe UI\";"));
        label_12 = new QLabel(admin);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(360, 319, 161, 21));
        label_12->setStyleSheet(QString::fromUtf8("font: 16pt \"Segoe UI\";\n"
"color: rgb(0, 0, 0);\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0.0681818, x2:0.744318, y2:0.665, stop:0 rgba(0, 0, 0, 255), stop:0.886364 rgba(62, 164, 255, 255));"));
        LEViewTransactionHistoryAdmin = new QLineEdit(admin);
        LEViewTransactionHistoryAdmin->setObjectName("LEViewTransactionHistoryAdmin");
        LEViewTransactionHistoryAdmin->setGeometry(QRect(530, 320, 201, 20));
        PBLogOutAdmin_14 = new QPushButton(admin);
        PBLogOutAdmin_14->setObjectName("PBLogOutAdmin_14");
        PBLogOutAdmin_14->setGeometry(QRect(60, 510, 271, 31));
        PBLogOutAdmin_14->setStyleSheet(QString::fromUtf8("font: 14pt \"Segoe UI\";"));
        PBDeleteUserAdmin = new QPushButton(admin);
        PBDeleteUserAdmin->setObjectName("PBDeleteUserAdmin");
        PBDeleteUserAdmin->setGeometry(QRect(360, 270, 371, 31));
        PBDeleteUserAdmin->setStyleSheet(QString::fromUtf8("font: 14pt \"Segoe UI\";"));
        label_13 = new QLabel(admin);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(360, 240, 161, 21));
        label_13->setStyleSheet(QString::fromUtf8("font: 16pt \"Segoe UI\";\n"
"color: rgb(0, 0, 0);\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0.0681818, x2:0.744318, y2:0.665, stop:0 rgba(0, 0, 0, 255), stop:0.886364 rgba(62, 164, 255, 255));"));
        LEDeleteUserAdmin = new QLineEdit(admin);
        LEDeleteUserAdmin->setObjectName("LEDeleteUserAdmin");
        LEDeleteUserAdmin->setGeometry(QRect(530, 241, 201, 20));
        LECreateNewUserPassword = new QLineEdit(admin);
        LECreateNewUserPassword->setObjectName("LECreateNewUserPassword");
        LECreateNewUserPassword->setGeometry(QRect(530, 91, 201, 20));
        label_14 = new QLabel(admin);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(360, 90, 161, 21));
        label_14->setStyleSheet(QString::fromUtf8("font: 16pt \"Segoe UI\";\n"
"color: rgb(0, 0, 0);\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0.0681818, x2:0.744318, y2:0.665, stop:0 rgba(0, 0, 0, 255), stop:0.886364 rgba(62, 164, 255, 255));"));
        PBCreateNewUser = new QPushButton(admin);
        PBCreateNewUser->setObjectName("PBCreateNewUser");
        PBCreateNewUser->setGeometry(QRect(360, 190, 371, 31));
        PBCreateNewUser->setStyleSheet(QString::fromUtf8("font: 14pt \"Segoe UI\";"));
        label_15 = new QLabel(admin);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(360, 30, 161, 21));
        label_15->setStyleSheet(QString::fromUtf8("font: 16pt \"Segoe UI\";\n"
"color: rgb(0, 0, 0);\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0.0681818, x2:0.744318, y2:0.665, stop:0 rgba(0, 0, 0, 255), stop:0.886364 rgba(62, 164, 255, 255));"));
        LEPBCreateNewUserName = new QLineEdit(admin);
        LEPBCreateNewUserName->setObjectName("LEPBCreateNewUserName");
        LEPBCreateNewUserName->setGeometry(QRect(530, 30, 201, 20));
        label_17 = new QLabel(admin);
        label_17->setObjectName("label_17");
        label_17->setGeometry(QRect(360, 60, 161, 21));
        label_17->setStyleSheet(QString::fromUtf8("font: 16pt \"Segoe UI\";\n"
"color: rgb(0, 0, 0);\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0.0681818, x2:0.744318, y2:0.665, stop:0 rgba(0, 0, 0, 255), stop:0.886364 rgba(62, 164, 255, 255));"));
        LECreateNewUserLogName = new QLineEdit(admin);
        LECreateNewUserLogName->setObjectName("LECreateNewUserLogName");
        LECreateNewUserLogName->setGeometry(QRect(530, 60, 201, 20));
        comboBox = new QComboBox(admin);
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(600, 150, 131, 31));
        tabWidget->addTab(admin, QString());
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 906, 22));
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
        tabWidget->setTabText(tabWidget->indexOf(admin), QCoreApplication::translate("MainWindow", "admin", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
