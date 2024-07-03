#include "getacoutnnumberhandler.h"

GetAcoutnNumberHandler::GetAcoutnNumberHandler(QObject *parent)
    : Handler{parent}
{}
void GetAcoutnNumberHandler::Handling(QByteArray jso)
{
    QJsonDocument js=QJsonDocument::fromJson(jso);
    QJsonObject json=js.object();
    if(json["Request"].toString()=="GetAccountNumber")
    {
        QString AccNum=json["Response"].toString();
        emit getacountnumber(AccNum);
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

void GetAcoutnNumberHandler::SetNextHandler(Handler *pru)
{
    this->pru=pru;
}
