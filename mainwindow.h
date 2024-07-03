#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMetaEnum>
#include <QIntValidator>
#include "tcpsocket.h"
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

    void OnConnectDe(void);
    void OnDisconnectDe(void);
    void OnErrorDe(QAbstractSocket::SocketError socketError);
    void OnTriggerDe(QAbstractSocket::SocketState socketState);
    void OnlogRespose(bool flag,bool admin);
    void OnGetAcoutnNumberResponse(QString massage);
    void OnViewAccountBalnce(int massage);
    void OnViewDataBase(QStringList massage);
    void OnDeleteUser(QString massage);
    void OnAddUser(QString massage);
    void OnMakeTransaction(QString massage);
    void OnTransferAmount(QString massage);

    ~MainWindow();
private slots:
    void on_PBLog_clicked();

    void on_PBLogOutUser_clicked();

    void on_PBLogOutAdmin_clicked();

    void on_PBGetAccountNumberUser_clicked();

    void on_PBGetAccountNumberadmin_clicked();

    void on_PBViewAccountBalanceUser_clicked();

    void on_PBViewAccountBalanceAdmin_clicked();

    void on_PBLogOutAdmin_14_clicked();

    void on_PBDeleteUserAdmin_clicked();

    void on_PBCreateNewUser_clicked();

    void on_PBMakeTransactionUser_clicked();

    void on_PBTransferAmountUser_clicked();

private:
    Ui::MainWindow *ui;
    TCPSocket handler;
};
#endif // MAINWINDOW_H
