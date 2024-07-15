#ifndef HANDLER_H
#define HANDLER_H

#include <QObject>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QDebug>

class Handler : public QObject
{
    Q_OBJECT
public:
    explicit Handler(QObject *parent = nullptr);
    virtual void Handling(QByteArray json) = 0; // Virtual function for handling JSON data
    virtual void SetNextHandler(Handler* pru) = 0; // Virtual function to set the next handler
signals:
    void logsignal(bool flag, bool admin); // Signal for logging
    void getacountnumber(QString massage); // Signal for getting account number
    void viewvccountbalance(int massage); // Signal for viewing account balance
    void viewdatabase(QStringList massage); // Signal for viewing database
    void deleteuser(QString massage); // Signal for deleting user
    void adduser(QString massage); // Signal for adding user
    void maketransaction(QString massage); // Signal for making transaction
    void transferamount(QString massage); // Signal for transferring amount
    void viewtransactionhistory(QStringList massage); // Signal for viewing transaction history
    void updateuser(QString massage); // Signal for updating user
};

#endif // HANDLER_H
