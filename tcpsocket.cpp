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
    PRU1->SetNextHandler(PRU2);
    PRU2->SetNextHandler(PRU3);
    PRU3->SetNextHandler(PRU4);
    PRU4->SetNextHandler(PRU5);
    PRU5->SetNextHandler(PRU6);
    PRU6->SetNextHandler(PRU7);
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

void TCPSocket::WriteToSocket(QJsonObject json)
{
    if(socket.isOpen())
    {
        QByteArray byte=QJsonDocument(json).toJson(QJsonDocument::Compact);
        //QString str=QString("JsonSize:%1/").arg(byte.size());
        //byte.prepend(str.toUtf8());
        socket.write(byte);
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
