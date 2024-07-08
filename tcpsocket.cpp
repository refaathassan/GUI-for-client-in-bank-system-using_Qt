#include "tcpsocket.h"

TCPSocket::TCPSocket(QObject *parent)
    : QObject{parent}
{
    connect(&socket,&QTcpSocket::connected,this,&TCPSocket::OnConnect);
    connect(&socket,&QTcpSocket::disconnected,this,&TCPSocket::OnDisconnect);
    connect(&socket,&QTcpSocket::errorOccurred,this,&TCPSocket::OnError);
    connect(&socket,&QTcpSocket::stateChanged,this,&TCPSocket::OnTrigger);
    connect(&socket,&QTcpSocket::readyRead,this,&TCPSocket::OnReadyRead);
    PRU1=new LogHandler();
    PRU2=new GetAcoutnNumberHandler();
    PRU3=new ViewAccountBalanceHandler();
    PRU4=new ViewDataBaseHandler();
    PRU5=new DeleteHandler();
    PRU6=new AddUserHandler();
    PRU7=new MakeTransactionHandler();
    PRU8=new TransferAmountHandler();
    PRU9=new ViewTransectionHistoryHandler();
    PRU10=new UpdateUserHandler();
    PRU1->SetNextHandler(PRU2);
    PRU2->SetNextHandler(PRU3);
    PRU3->SetNextHandler(PRU4);
    PRU4->SetNextHandler(PRU5);
    PRU5->SetNextHandler(PRU6);
    PRU6->SetNextHandler(PRU7);
    PRU7->SetNextHandler(PRU8);
    PRU8->SetNextHandler(PRU9);
    PRU9->SetNextHandler(PRU10);

     key = "abcdefghijklmnop"; // 16 bytes for AES 128
     iv = "1234567890123456";  // 16 bytes IV
     privatek =QApplication::applicationDirPath()+"//private.pem";
}


void TCPSocket::MakeConnect(QString ip, qint32 port)
{
    if(socket.isOpen())
    {
        if(this->ip==ip&&this->port==port)
        {
            return;
        }
        else
        {
            socket.close();
            this->ip=ip;
            this->port=port;
            socket.connectToHost(this->ip,this->port);

        }
    }
    else
    {
        this->ip=ip;
        this->port=port;
        socket.connectToHost(this->ip,this->port);
    }
}

void TCPSocket::MakeDisconnect()
{
    if(socket.isOpen())
    {
        socket.close();
    }
}


Handler *TCPSocket::GetHandler1()
{
    return PRU1;
}

Handler *TCPSocket::GetHandler2()
{
    return PRU2;
}
Handler *TCPSocket::GetHandler3()
{
    return PRU3;
}
Handler *TCPSocket::GetHandler4()
{
    return PRU4;
}
Handler *TCPSocket::GetHandler5()
{
    return PRU5;
}
Handler *TCPSocket::GetHandler6()
{
    return PRU6;
}
Handler *TCPSocket::GetHandler7()
{
    return PRU7;
}
Handler *TCPSocket::GetHandler8()
{
    return PRU8;
}
Handler *TCPSocket::GetHandler9()
{
    return PRU9;
}
Handler *TCPSocket::GetHandler10()
{
    return PRU10;
}
void TCPSocket::OnConnect()
{
    emit Connect();
}

void TCPSocket::OnDisconnect()
{
    emit disconnect();
}

void TCPSocket::OnError(QAbstractSocket::SocketError socketError)
{
    emit Error(socketError);
}

void TCPSocket::OnTrigger(QAbstractSocket::SocketState socketState)
{
    if(socketState == QAbstractSocket::UnconnectedState)
    {
        socket.close();
    }
    emit Trigger(socketState);
}


void TCPSocket::OnReadyRead()
{
    QByteArray arr= socket.readAll();
   // QByteArray dec_arr=decryptAES(arr);
    // Parse the JSON response
    //QJsonParseError jsonError;
    //QJsonDocument jsonResponse = QJsonDocument::fromJson(arr);
    // if (jsonError.error == QJsonParseError::NoError && jsonResponse.isObject())
    // {
    // QJsonObject jsonObject = jsonResponse.object();
    // // Extract id and name
    // QString id = jsonObject["id"].toString();
    // QString name = jsonObject["name"].toString();
    // emit ReadyRead(QString("id :  "+id+"   name  : "+name));
    //}
    // QString str=QString(arr);
    // qint32 length=str.split("/")[0].split(':')[1].toInt();
    // QString data=str.right(length);
    //QJsonDocument json=QJsonDocument::fromJson(arr);
    //QJsonObject jsonObj=json.object();
    PRU1->Handling(arr);
    // qint32 dataSize=jsonObj["size"].toInt();
    // QString realdata=jsonObj["FileData"].toString();
    // if(dataSize==realdata.size())
    // {
    //     emit ReadyRead(realdata);
    // }
    //QString data=QString(arr);


}

void TCPSocket::WriteToSocket(QJsonObject json)
{
    if(socket.isOpen())
    {
        QByteArray byte=QJsonDocument(json).toJson(QJsonDocument::Compact);
        QByteArray enc_byte=encryptAndSign(byte,key,iv,privatek.toUtf8());
        //QString str=QString("JsonSize:%1/").arg(byte.size());
        //byte.prepend(str.toUtf8());
        socket.write(enc_byte);
    }

}
QByteArray TCPSocket::encryptAndSign(const QByteArray &originalData, const QByteArray &key, const QByteArray &iv, const QByteArray &rsaPrivateKeyFile) {
    // Sign the original data
    QByteArray signature = signData(originalData, rsaPrivateKeyFile);
    if (signature.isEmpty()) {
        qDebug() << "Failed to sign data";
        return QByteArray();
    }

    // Append the signature to the original data
    QByteArray dataToEncrypt = originalData + signature;

    // Encrypt the combined data (original data + signature)
    QByteArray encrypted = QAESEncryption::Crypt(QAESEncryption::AES_128, QAESEncryption::CBC, dataToEncrypt, key, iv, QAESEncryption::PKCS7);

    // Convert encrypted data to base64 for easy storage and transport
    return encrypted.toBase64();
}
QByteArray TCPSocket::signData(const QByteArray &data, const QByteArray &rsaPrivateKeyFile) {
    QFile file(rsaPrivateKeyFile);
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "Failed to open private key file";
        return QByteArray();
    }

    QByteArray privateKeyData = file.readAll();
    file.close();

    const char *privateKey = privateKeyData.constData();

    // Read RSA private key
    BIO *bio = BIO_new_mem_buf((void*)privateKey, -1);
    if (!bio) {
        qDebug() << "Failed to create BIO for private key";
        return QByteArray();
    }

    RSA *rsa = PEM_read_bio_RSAPrivateKey(bio, NULL, NULL, NULL);
    if (!rsa) {
        qDebug() << "Failed to load RSA private key";
        BIO_free(bio);
        return QByteArray();
    }

    // Sign data
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256((const unsigned char *)data.constData(), data.length(), hash);

    unsigned char signature[RSA_size(rsa)];
    unsigned int signatureLength;
    if (!RSA_sign(NID_sha256, hash, SHA256_DIGEST_LENGTH, signature, &signatureLength, rsa)) {
        qDebug() << "Failed to sign data";
        RSA_free(rsa);
        BIO_free(bio);
        return QByteArray();
    }

    RSA_free(rsa);
    BIO_free(bio);

    return QByteArray((const char *)signature, signatureLength);
}
