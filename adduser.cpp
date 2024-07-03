#include "adduser.h"

AddUser::AddUser(QObject *parent)
    : Handler{parent}
{}
void AddUser::Handling(QByteArray jso)
{
    QJsonDocument js=QJsonDocument::fromJson(jso);
    QJsonObject json=js.object();
    if(json["Request"].toString()=="AddUser")
    {
        QString AccNum=json["Response"].toString();
        emit adduser(AccNum);
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

void AddUser::SetNextHandler(Handler *pru)
{
    this->pru=pru;
}
