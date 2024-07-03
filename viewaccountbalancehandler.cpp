#include "viewaccountbalancehandler.h"

ViewAccountBalanceHandler::ViewAccountBalanceHandler(QObject *parent)
    : Handler{parent}
{}
void ViewAccountBalanceHandler::Handling(QByteArray jso)
{
     qDebug()<<"i am here berfore view handler"<<Qt::endl;
    QJsonDocument js=QJsonDocument::fromJson(jso);
    QJsonObject json=js.object();
    if(json["Request"].toString()=="ViewAccountBalance")
    {
        int AccNum=json["Response"].toInt();
        qDebug()<<AccNum<<Qt::endl;
        emit viewvccountbalance(AccNum);
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

void ViewAccountBalanceHandler::SetNextHandler(Handler *pru)
{
    this->pru=pru;
}
