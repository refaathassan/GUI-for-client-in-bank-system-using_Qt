#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMetaEnum>
#include <QIntValidator>
#include "tcpsocket.h"
#include <QProcess>
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    void OnConnectDe(void); // Method for connecting
    void OnDisconnectDe(void); // Method for disconnecting
    void OnErrorDe(QAbstractSocket::SocketError socketError); // Method for handling errors
    void OnlogRespose(bool flag, bool admin); // Method for handling log response
    void OnGetAcoutnNumberResponse(QString massage); // Method for handling get account number response
    void OnViewAccountBalnce(int massage); // Method for handling view account balance response
    void OnViewDataBase(QStringList massage); // Method for handling view database response
    void OnDeleteUser(QString massage); // Method for handling delete user response
    void OnAddUser(QString massage); // Method for handling add user response
    void OnMakeTransaction(QString massage); // Method for handling make transaction response
    void OnTransferAmount(QString massage); // Method for handling transfer amount response
    void OnViewTransactionHistory(QStringList massage); // Method for handling view transaction history response
    void OnUpdateUser(QString massage); // Method for handling update user response

    bool isAlphabetic(const QString &str, QString str1); // Method for checking if string is alphabetic

    ~MainWindow();

private slots:
    void on_PBLog_clicked(); // Slot for log button click

    void on_PBLogOutUser_clicked(); // Slot for log out user button click

    void on_PBLogOutAdmin_clicked(); // Slot for log out admin button click

    void on_PBGetAccountNumberUser_clicked(); // Slot for get account number user button click

    void on_PBGetAccountNumberadmin_clicked(); // Slot for get account number admin button click

    void on_PBViewAccountBalanceUser_clicked(); // Slot for view account balance user button click

    void on_PBViewAccountBalanceAdmin_clicked(); // Slot for view account balance admin button click

    void on_PBLogOutAdmin_14_clicked(); // Slot for log out admin 14 button click

    void on_PBDeleteUserAdmin_clicked(); // Slot for delete user admin button click

    void on_PBCreateNewUser_clicked(); // Slot for create new user button click

    void on_PBMakeTransactionUser_clicked(); // Slot for make transaction user button click

    void on_PBTransferAmountUser_clicked(); // Slot for transfer amount user button click

    void on_PBViewTransactionHistoryUser_clicked(); // Slot for view transaction history user button click

    void on_PBViewTransactionHistoryAdmin_clicked(); // Slot for view transaction history admin button click

    void on_PBUpdateNewUser_clicked(); // Slot for update new user button click

private:
    Ui::MainWindow *ui; // UI object
    TCPSocket handler; // TCP socket handler object
    QProcess process;
};

#endif // MAINWINDOW_H
