#ifndef TCPSOCKET_H
#define TCPSOCKET_H

#include <QObject>
#include <QTcpSocket>
#include <QJsonObject>
#include <QJsonDocument>
#include <QCryptographicHash>
#include <QByteArray>
#include <QFile>
#include <QApplication>
#include <openssl/pem.h>
#include <openssl/rsa.h>
#include <openssl/sha.h>
#include "qaesencryption.h"

// Include all handler classes
#include "loghandler.h"
#include "getacoutnnumberhandler.h"
#include "viewaccountbalancehandler.h"
#include "viewdatabasehandler.h"
#include "deletehandler.h"
#include "adduserhandler.h"
#include "maketransactionhandler.h"
#include "transferamounthandler.h"
#include "viewtransectionhistoryhandler.h"
#include "updateuserhandler.h"

class TCPSocket : public QObject
{
    Q_OBJECT
public:
    explicit TCPSocket(QObject *parent = nullptr);

    // Socket connection methods
    void MakeConnect(QString ip, qint32 port);
    void MakeDisconnect(void);

    // Method to write JSON data to socket
    void WriteToSocket(QJsonObject json);

    // Getters for handler objects
    Handler * GetHandler1(void);
    Handler * GetHandler2(void);
    Handler * GetHandler3(void);
    Handler * GetHandler4(void);
    Handler * GetHandler5(void);
    Handler * GetHandler6(void);
    Handler * GetHandler7(void);
    Handler * GetHandler8(void);
    Handler * GetHandler9(void);
    Handler * GetHandler10(void);

    // Encryption and signing methods
    QByteArray encryptAndSign(const QByteArray &originalData, const QByteArray &key, const QByteArray &iv, const QByteArray &rsaPrivateKeyFile);
    QByteArray signData(const QByteArray &data, const QByteArray &rsaPrivateKeyFile);

private:
    QString ip;             // IP address of the server
    qint32 port;            // Port number for the connection
    QTcpSocket socket;      // TCP socket for communication
    bool flag;
    Handler *PRU1;          // Handler instance 1
    Handler *PRU2;          // Handler instance 2
    Handler *PRU3;          // Handler instance 3
    Handler *PRU4;          // Handler instance 4
    Handler *PRU5;          // Handler instance 5
    Handler *PRU6;          // Handler instance 6
    Handler *PRU7;          // Handler instance 7
    Handler *PRU8;          // Handler instance 8
    Handler *PRU9;          // Handler instance 9
    Handler *PRU10;         // Handler instance 10
    QByteArray key;         // Encryption key
    QByteArray iv;          // Initialization vector
    QString privatek;       // Path to private RSA key file

    // Private socket event handlers
    void OnConnect(void);           // Handle connection event
    void OnDisconnect(void);        // Handle disconnection event
    void OnError(QAbstractSocket::SocketError socketError);  // Handle socket errors
    void OnTrigger(QAbstractSocket::SocketState socketState);  // Handle socket state changes
    void OnReadyRead(void);         // Handle data reception

signals:
    // Signals for socket events
    void Connect(void);             // Signal emitted on successful connection
    void Disconnect(void);          // Signal emitted on disconnection
    void Error(QAbstractSocket::SocketError socketErro);  // Signal emitted on socket errors
    void Trigger(QAbstractSocket::SocketState socketState);  // Signal emitted on socket state changes
    void ReadyRead(QJsonObject json);  // Signal emitted when data is ready to read
};

#endif // TCPSOCKET_H
