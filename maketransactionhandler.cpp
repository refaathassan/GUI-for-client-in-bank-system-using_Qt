#include "maketransactionhandler.h"

// Constructor for MakeTransactionHandler class
MakeTransactionHandler::MakeTransactionHandler(QObject *parent)
    : Handler{parent}  // Initialize base class with parent QObject
{}

// Handling method to process incoming JSON data
void MakeTransactionHandler::Handling(QByteArray jso)
{
    QJsonDocument js = QJsonDocument::fromJson(jso);  // Parse JSON data from QByteArray
    QJsonObject json = js.object();  // Extract JSON object from the document

    if (json["Request"].toString() == "MakeTransaction")
    {
        QString AccNum = json["Response"].toString();  // Extract 'Response' field as QString
        emit maketransaction(AccNum);  // Emit signal with extracted account number
    }
    else
    {
        if (pru != nullptr)
        {
            pru->Handling(jso);  // Pass JSON data to the next handler if it exists
        }
        else
        {
            // Handle case where there is no next handler
            // Typically, you might log an error or perform some default action
        }
    }
}

// Method to set the next handler in the chain of responsibility
void MakeTransactionHandler::SetNextHandler(Handler *pru)
{
    this->pru = pru;  // Set the next handler to process subsequent requests
}
