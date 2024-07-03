#include "viewdatabasehandler.h"

ViewDataBaseHandler::ViewDataBaseHandler(QObject *parent)
    : Handler{parent}
{}
void ViewDataBaseHandler::Handling(QByteArray jso)
{
    qDebug()<<"i am here berfore view handler"<<Qt::endl;
    QStringList stringList;
    QJsonDocument js=QJsonDocument::fromJson(jso);
    QJsonObject json=js.object();
    if(json["Request"].toString()=="ViewDataBase")
    {
       QJsonArray jsonar=json["Response"].toArray();
        for(auto ele:jsonar)
        {
           QJsonObject jsons=ele.toObject();
           if(jsons["type"].toString()=="admin")
           {
               stringList<<QString("username : %1").arg(jsons["username"].toString());
               stringList<<QString("full name: %1").arg(jsons["fullname"].toString());
               stringList<<"type:  admin";
               stringList<<"--------------------------------------------------";

           }
           else if(jsons["type"].toString()=="user")
           {
               stringList<<QString("username : %1").arg(jsons["username"].toString());
               stringList<<QString("full name: %1").arg(jsons["fullname"].toString());
               stringList<<QString("accountnumber : %1").arg(jsons["accountnumber"].toString());
               stringList<<QString("balance: %1").arg(jsons["password"].toString());
               stringList<<"type:  user";
               stringList<<"--------------------------------------------------";
           }

        }
        emit viewdatabase(stringList);
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

void ViewDataBaseHandler::SetNextHandler(Handler *pru)
{
    this->pru=pru;
}
