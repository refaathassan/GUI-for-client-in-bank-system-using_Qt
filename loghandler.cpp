#include "loghandler.h"

// Constructor
LogHandler::LogHandler(QObject *parent)
    : Handler{parent} // Call base class constructor
{
    pru = nullptr; // Initialize next handler pointer to null
}

// Handling function override
void LogHandler::Handling(QByteArray jso)
{
    bool flag = false;
    bool admin = false;

    // Convert JSON byte array to JSON object
    QJsonDocument js = QJsonDocument::fromJson(jso);
    QJsonObject json = js.object();

    // Check if the request is "Log"
    if(json["Request"].toString() == "Log")
    {
        // Check if the response indicates successful log and user type
        if(json["Response"].toString() == "1" && json["type"].toString() == "admin")
        {
            flag = true;
            admin = true;
        }
        else if(json["Response"].toString() == "1" && json["type"].toString() == "user")
        {
            flag = true;
        }
        else
        {
            // Handle other cases if needed
        }

        // Emit signal with log status and admin flag
        emit logsignal(flag, admin);
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
void LogHandler::SetNextHandler(Handler *pru)
{
    this->pru = pru;
}
