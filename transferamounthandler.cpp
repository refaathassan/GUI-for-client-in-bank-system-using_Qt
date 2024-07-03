#include "transferamounthandler.h"

TransferAmountHandler::TransferAmountHandler(QObject *parent)
    : Handler{parent}
{}
void TransferAmountHandler::Handling(QByteArray jso)
{
    QJsonDocument js=QJsonDocument::fromJson(jso);
    QJsonObject json=js.object();
    if(json["Request"].toString()=="TransferAmount")
    {
        QString AccNum=json["Response"].toString();
        emit transferamount(AccNum);
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

void TransferAmountHandler::SetNextHandler(Handler *pru)
{
    this->pru=pru;
}
