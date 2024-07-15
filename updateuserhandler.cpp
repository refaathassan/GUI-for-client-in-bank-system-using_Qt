#include "updateuserhandler.h"

// Constructor for UpdateUserHandler class
UpdateUserHandler::UpdateUserHandler(QObject *parent)
    : Handler{parent}
{}

// Method to handle incoming data (JSON) for UpdateUserHandler
void UpdateUserHandler::Handling(QByteArray jso)
{
    QJsonDocument js = QJsonDocument::fromJson(jso); // Parse JSON byte array to JSON document
    QJsonObject json = js.object(); // Extract JSON object from JSON document

    // Check if the request type is "UpdateUser"
    if(json["Request"].toString() == "UpdateUser")
    {
        QString AccNum = json["Response"].toString(); // Extract the account number from JSON
        emit updateuser(AccNum); // Emit signal with the extracted account number
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
void UpdateUserHandler::SetNextHandler(Handler *pru)
{
    this->pru = pru; // Set the next handler
}
