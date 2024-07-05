#include "updateuserhandler.h"

UpdateUserHandler::UpdateUserHandler(QObject *parent)
    : Handler{parent}
{}
void UpdateUserHandler::Handling(QByteArray jso)
{
    QJsonDocument js=QJsonDocument::fromJson(jso);
    QJsonObject json=js.object();
    if(json["Request"].toString()=="UpdateUser")
    {
        QString AccNum=json["Response"].toString();
        emit updateuser(AccNum);
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

void UpdateUserHandler::SetNextHandler(Handler *pru)
{
    this->pru=pru;
}
