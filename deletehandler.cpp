#include "deletehandler.h"


DeleteHandler::DeleteHandler(QObject *parent)
    : Handler{parent}
{}
void DeleteHandler::Handling(QByteArray jso)
{
    QJsonDocument js=QJsonDocument::fromJson(jso);
    QJsonObject json=js.object();
    if(json["Request"].toString()=="DeleteUser")
    {
        QString AccNum=json["Response"].toString();
        emit deleteuser(AccNum);
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

void DeleteHandler::SetNextHandler(Handler *pru)
{
    this->pru=pru;
}
