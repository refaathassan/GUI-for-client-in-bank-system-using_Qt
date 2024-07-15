#include "deletehandler.h"

// Constructor
DeleteHandler::DeleteHandler(QObject *parent)
    : Handler{parent} // Call base class constructor
{}

// Handling function override
void DeleteHandler::Handling(QByteArray jso)
{
    // Convert JSON byte array to JSON object
    QJsonDocument js = QJsonDocument::fromJson(jso);
    QJsonObject json = js.object();

    // Check if the request is "DeleteUser"
    if(json["Request"].toString() == "DeleteUser")
    {
        // Retrieve account number from JSON
        QString AccNum = json["Response"].toString();

        // Emit signal to indicate user deletion
        emit deleteuser(AccNum);
    }
    else
    {
        // If not responsible for the request, forward to next handler
        if(pru != nullptr)
        {
            pru->Handling(jso);
        }
        else
        {
            // Handle case where there's no next handler
        }
    }
}

// Set the next handler in the chain
void DeleteHandler::SetNextHandler(Handler *pru)
{
    this->pru = pru;
}
