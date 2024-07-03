#include "loghandler.h"

LogHandler::LogHandler(QObject *parent)
    : Handler{parent}
{
    pru=nullptr;
}

void LogHandler::Handling(QByteArray jso)
{
    bool flag=false;
    bool admin=false;
    QJsonDocument js=QJsonDocument::fromJson(jso);
    QJsonObject json=js.object();
    if(json["Request"].toString()=="Log")
    {
        if(json["Response"].toString()=="1"&&json["type"].toString()=="admin")
        {
            flag=true;
            admin=true;
        }
        else if(json["Response"].toString()=="1"&&json["type"].toString()=="user")
        {
            flag=true;
        }
        else
        {
        }
        emit logsignal(flag,admin);
    }
    else
    {
        if(pru!=nullptr)
        {
            pru->Handling(jso);
        }
        else
        {

        }
    }
}

void LogHandler::SetNextHandler(Handler *pru)
{
    this->pru=pru;
}
