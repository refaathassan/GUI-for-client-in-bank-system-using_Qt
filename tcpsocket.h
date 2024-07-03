#ifndef TCPSOCKET_H
#define TCPSOCKET_H

#include <QObject>
#include <QTcpSocket>
#include <QJsonObject>
#include <QJsonDocument>
#include "loghandler.h"
#include "getacoutnnumberhandler.h"
#include "viewaccountbalancehandler.h"
#include "viewdatabasehandler.h"
#include "deletehandler.h"
#include "adduserhandler.h"
#include "maketransactionhandler.h"
#include "transferamounthandler.h"
class TCPSocket : public QObject
{
    Q_OBJECT
public:
    explicit TCPSocket(QObject *parent = nullptr);
    void MakeConnect(QString ip,qint32 port);
    void MakeDisconnect(void);
    void WriteToSocket(QJsonObject json);
    Handler * GetHandler1(void);
    Handler * GetHandler2(void);
    Handler * GetHandler3(void);
    Handler * GetHandler4(void);
    Handler * GetHandler5(void);
    Handler * GetHandler6(void);
    Handler * GetHandler7(void);
    Handler * GetHandler8(void);

private:
    QString ip;
    qint32 port;
    QTcpSocket socket;
    Handler *PRU1;
    Handler *PRU2;
    Handler *PRU3;
    Handler *PRU4;
    Handler *PRU5;
    Handler *PRU6;
    Handler *PRU7;
    Handler *PRU8;
    void OnConnect(void);
    void OnDisconnect(void);
    void OnError(QAbstractSocket::SocketError socketError);
    void OnTrigger(QAbstractSocket::SocketState socketState);
    void OnReadyRead(void);

signals:
    void Connect(void);
    void Disconnect(void);
    void Error(QAbstractSocket::SocketError socketErro);
    void Trigger(QAbstractSocket::SocketState socketState);
    void ReadyRead(QJsonObject json);
};

#endif // TCPSOCKET_H
