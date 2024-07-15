#include "getacoutnnumberhandler.h"

// Constructor
GetAcoutnNumberHandler::GetAcoutnNumberHandler(QObject *parent)
    : Handler{parent} // Call base class constructor
{}

// Handling function override
void GetAcoutnNumberHandler::Handling(QByteArray jso)
{
    // Convert JSON byte array to JSON object
    QJsonDocument js = QJsonDocument::fromJson(jso);
    QJsonObject json = js.object();

    // Check if the request is "GetAccountNumber"
    if(json["Request"].toString() == "GetAccountNumber")
    {
        // Retrieve account number from JSON
        QString AccNum = json["Response"].toString();

        // Emit signal to provide account number
        emit getacountnumber(AccNum);
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
void GetAcoutnNumberHandler::SetNextHandler(Handler *pru)
{
    this->pru = pru;
}
