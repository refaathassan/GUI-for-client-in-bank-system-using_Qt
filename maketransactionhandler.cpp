#include "maketransactionhandler.h"


MakeTransactionHandler::MakeTransactionHandler(QObject *parent)
    : Handler{parent}
{}
void MakeTransactionHandler::Handling(QByteArray jso)
{
    QJsonDocument js=QJsonDocument::fromJson(jso);
    QJsonObject json=js.object();
    if(json["Request"].toString()=="MakeTransaction")
    {
        QString AccNum=json["Response"].toString();
        emit maketransaction(AccNum);
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

void MakeTransactionHandler::SetNextHandler(Handler *pru)
{
    this->pru=pru;
}
