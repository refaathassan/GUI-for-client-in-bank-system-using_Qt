#include "viewtransectionhistoryhandler.h"


ViewTransectionHistoryHandler::ViewTransectionHistoryHandler(QObject *parent)
    : Handler{parent}
{}
void ViewTransectionHistoryHandler::Handling(QByteArray jso)
{
    qDebug()<<"i am here berfore view handler"<<Qt::endl;
    QStringList stringList;
    QJsonDocument js=QJsonDocument::fromJson(jso);
    QJsonObject json=js.object();
    if(json["Request"].toString()=="ViewTransactionHistory")
    {
            QJsonValue responseValue = json.value("Response");
            if (responseValue.isArray())
            {
                QJsonArray jsonar=json["Response"].toArray();
                for(auto ele:jsonar)
                {
                    QJsonObject jsons=ele.toObject();
                    stringList<<QString("amount : %1").arg(jsons["amount"].toInt());
                    stringList<<QString("date: %1").arg(jsons["date"].toString());
                    stringList<<QString("descraption: %1").arg(jsons["descraption"].toString());
                    stringList<<"--------------------------------------------------";

                }

            }
            else if (responseValue.isString())
            {
                stringList<<responseValue.toString();
            }
            emit viewtransactionhistory(stringList);
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

void ViewTransectionHistoryHandler::SetNextHandler(Handler *pru)
{
    this->pru=pru;
}
