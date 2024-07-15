#include "adduserhandler.h"

// Constructor
AddUserHandler::AddUserHandler(QObject *parent)
    : Handler{parent} // Call base class constructor
{}

// Handling function override
void AddUserHandler::Handling(QByteArray jso)
{
    // Convert JSON byte array to JSON object
    QJsonDocument js = QJsonDocument::fromJson(jso);
    QJsonObject json = js.object();

    // Check if the request is "AddUser"
    if(json["Request"].toString() == "AddUser")
    {
        // Retrieve account number from JSON
        QString AccNum = json["Response"].toString();

        // Emit signal to indicate successful addition of user
        emit adduser(AccNum);
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
void AddUserHandler::SetNextHandler(Handler *pru)
{
    this->pru = pru;
}
