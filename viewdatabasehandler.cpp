#include "viewdatabasehandler.h"

// Constructor for ViewDataBaseHandler class
ViewDataBaseHandler::ViewDataBaseHandler(QObject *parent)
    : Handler{parent}
{}

// Method to handle incoming data (JSON) for ViewDataBaseHandler
void ViewDataBaseHandler::Handling(QByteArray jso)
{
    qDebug() << "i am here berfore view handler" << Qt::endl; // Debug output
    QStringList stringList; // Initialize a string list

    QJsonDocument js = QJsonDocument::fromJson(jso); // Parse JSON byte array to JSON document
    QJsonObject json = js.object(); // Extract JSON object from JSON document

    // Check if the request type is "ViewDataBase"
    if(json["Request"].toString() == "ViewDataBase")
    {
        QJsonArray jsonar = json["Response"].toArray(); // Extract array from JSON response

        // Iterate over each element in the JSON array
        for(auto ele : jsonar)
        {
            QJsonObject jsons = ele.toObject(); // Convert each element to JSON object

            // Depending on the type of user (admin or user), populate the string list accordingly
            if(jsons["type"].toString() == "admin")
            {
                stringList << QString("username : %1").arg(jsons["username"].toString());
                stringList << QString("full name: %1").arg(jsons["fullname"].toString());
                stringList << "type:  admin";
                stringList << "--------------------------------------------------";
            }
            else if(jsons["type"].toString() == "user")
            {
                stringList << QString("username : %1").arg(jsons["username"].toString());
                stringList << QString("full name: %1").arg(jsons["fullname"].toString());
                stringList << QString("accountnumber : %1").arg(jsons["accountnumber"].toString());
                stringList << QString("balance: %1").arg(jsons["password"].toString());
                stringList << "type:  user";
                stringList << "--------------------------------------------------";
            }
        }
        emit viewdatabase(stringList); // Emit signal with populated string list
    }
    else
    {
        // If next handler exists, pass the JSON data to it
        if(pru != nullptr)
        {
            pru->Handling(jso);
        }
        else
        {
            // Handle case where no next handler is available
        }
    }
}

// Method to set the next handler in the chain of responsibility
void ViewDataBaseHandler::SetNextHandler(Handler *pru)
{
    this->pru = pru; // Set the next handler
}
