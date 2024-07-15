#include "transferamounthandler.h"

// Constructor for TransferAmountHandler class
TransferAmountHandler::TransferAmountHandler(QObject *parent)
    : Handler{parent}
{}

// Method to handle incoming data (JSON) for TransferAmountHandler
void TransferAmountHandler::Handling(QByteArray jso)
{
    QJsonDocument js = QJsonDocument::fromJson(jso); // Parse JSON byte array to JSON document
    QJsonObject json = js.object(); // Extract JSON object from JSON document

    // Check if the request type is "TransferAmount"
    if(json["Request"].toString() == "TransferAmount")
    {
        QString AccNum = json["Response"].toString(); // Extract the account number from JSON
        emit transferamount(AccNum); // Emit signal with the extracted account number
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
void TransferAmountHandler::SetNextHandler(Handler *pru)
{
    this->pru = pru; // Set the next handler
}
