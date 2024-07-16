#include "tcpsocket.h"

// Constructor for TCPSocket class, initializes connections and handlers
TCPSocket::TCPSocket(QObject *parent)
    : QObject{parent},
    // Connect signals from socket to corresponding slots in TCPSocket
    // This sets up signal-slot connections for socket events
    PRU1(new LogHandler()),                    // Instantiate LogHandler for chain of responsibility
    PRU2(new GetAcoutnNumberHandler()),        // Instantiate GetAcoutnNumberHandler for chain
    PRU3(new ViewAccountBalanceHandler()),     // Instantiate ViewAccountBalanceHandler for chain
    PRU4(new ViewDataBaseHandler()),           // Instantiate ViewDataBaseHandler for chain
    PRU5(new DeleteHandler()),                 // Instantiate DeleteHandler for chain
    PRU6(new AddUserHandler()),                // Instantiate AddUserHandler for chain
    PRU7(new MakeTransactionHandler()),        // Instantiate MakeTransactionHandler for chain
    PRU8(new TransferAmountHandler()),         // Instantiate TransferAmountHandler for chain
    PRU9(new ViewTransectionHistoryHandler()), // Instantiate ViewTransectionHistoryHandler for chain
    PRU10(new UpdateUserHandler()),            // Instantiate UpdateUserHandler for chain
    key("abcdefghijklmnop"),                  // Initialize AES encryption key (16 bytes)
    iv("1234567890123456"),    // Initialize AES IV (16 bytes)
    privatek(QApplication::applicationDirPath() + "//private.pem") // Set path for private key

{
    flag=false;
    // Connect signals from socket to corresponding slots in TCPSocket
    connect(&socket, &QTcpSocket::connected, this, &TCPSocket::OnConnect);
    connect(&socket, &QTcpSocket::disconnected, this, &TCPSocket::OnDisconnect);
    connect(&socket, &QTcpSocket::errorOccurred, this, &TCPSocket::OnError);
    connect(&socket, &QTcpSocket::stateChanged, this, &TCPSocket::OnTrigger);
    connect(&socket, &QTcpSocket::readyRead, this, &TCPSocket::OnReadyRead);

    // Set up chain of responsibility
    PRU1->SetNextHandler(PRU2);
    PRU2->SetNextHandler(PRU3);
    PRU3->SetNextHandler(PRU4);
    PRU4->SetNextHandler(PRU5);
    PRU5->SetNextHandler(PRU6);
    PRU6->SetNextHandler(PRU7);
    PRU7->SetNextHandler(PRU8);
    PRU8->SetNextHandler(PRU9);
    PRU9->SetNextHandler(PRU10);
}

// Method to establish a connection to a specified IP address and port
void TCPSocket::MakeConnect(QString ip, qint32 port)
{
    if (socket.isOpen())
    {
        if (this->ip == ip && this->port == port)
        {
            return; // Already connected to the same IP and port
        }
        else
        {
            socket.close(); // Close existing connection
            this->ip = ip;  // Set new IP address
            this->port = port; // Set new port
            socket.connectToHost(this->ip, this->port); // Connect to the new host
        }
    }
    else
    {
        this->ip = ip;  // Set IP address
        this->port = port; // Set port
        socket.connectToHost(this->ip, this->port); // Connect to host
    }
}

// Method to disconnect from the current host
void TCPSocket::MakeDisconnect()
{
    if (socket.isOpen())
    {
        socket.close(); // Close the socket if it's open
    }
}

// Methods to retrieve each handler in the chain of responsibility
Handler *TCPSocket::GetHandler1() { return PRU1; }
Handler *TCPSocket::GetHandler2() { return PRU2; }
Handler *TCPSocket::GetHandler3() { return PRU3; }
Handler *TCPSocket::GetHandler4() { return PRU4; }
Handler *TCPSocket::GetHandler5() { return PRU5; }
Handler *TCPSocket::GetHandler6() { return PRU6; }
Handler *TCPSocket::GetHandler7() { return PRU7; }
Handler *TCPSocket::GetHandler8() { return PRU8; }
Handler *TCPSocket::GetHandler9() { return PRU9; }
Handler *TCPSocket::GetHandler10(){ return PRU10; }

// Slot to handle socket connected signal
void TCPSocket::OnConnect() { emit Connect(); }

// Slot to handle socket disconnected signal
void TCPSocket::OnDisconnect() { emit disconnect(); }

// Slot to handle socket error signal
void TCPSocket::OnError(QAbstractSocket::SocketError socketError) { emit Error(socketError); }

// Slot to handle socket state changed signal
void TCPSocket::OnTrigger(QAbstractSocket::SocketState socketState)
{
    if (socketState == QAbstractSocket::UnconnectedState)
    {
        socket.close(); // Close the socket if state is unconnected
    }
    emit Trigger(socketState); // Emit signal with socket state
}

// Slot to handle readyRead signal from socket
void TCPSocket::OnReadyRead()
{
    QByteArray arr = socket.readAll(); // Read all available data from socket
    PRU1->Handling(arr); // Pass the data to the first handler in the chain
}

// Method to write a JSON object to the socket after encrypting it
void TCPSocket::WriteToSocket(QJsonObject json)
{
    if (socket.isOpen())
    {
        QByteArray byte = QJsonDocument(json).toJson(QJsonDocument::Compact); // Convert JSON object to compact JSON byte array
        if(flag==false)
        {
          socket.write(byte);
            flag=true;
        }
        else
        {
            QByteArray enc_byte = encryptAndSign(byte, key, iv, privatek.toUtf8()); // Encrypt and sign the byte array
            socket.write(enc_byte); // Write the encrypted byte array to the socket
        }
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
