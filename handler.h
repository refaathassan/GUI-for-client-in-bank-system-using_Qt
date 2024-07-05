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
    virtual void Handling(QByteArray json)=0;
    virtual void SetNextHandler(Handler* pru)=0;
signals:
    void logsignal(bool flag,bool admin);
    void getacountnumber(QString massage);
    void viewvccountbalance(int massage);
    void viewdatabase (QStringList massage);
    void deleteuser(QString massage);
    void adduser(QString massage);
    void maketransaction(QString massage);
    void transferamount(QString massage);
    void viewtransactionhistory(QStringList massage);

};

#endif // HANDLER_H
