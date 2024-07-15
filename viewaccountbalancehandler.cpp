#include "viewaccountbalancehandler.h"

// Constructor for ViewAccountBalanceHandler class
ViewAccountBalanceHandler::ViewAccountBalanceHandler(QObject *parent)
    : Handler{parent}
{}

// Method to handle incoming data (JSON) for ViewAccountBalanceHandler
void ViewAccountBalanceHandler::Handling(QByteArray jso)
{
    qDebug() << "i am here berfore view handler" << Qt::endl; // Debug output
    QJsonDocument js = QJsonDocument::fromJson(jso); // Parse JSON byte array to JSON document
    QJsonObject json = js.object(); // Extract JSON object from JSON document

    // Check if the request type is "ViewAccountBalance"
    if(json["Request"].toString() == "ViewAccountBalance")
    {
        int AccNum = json["Response"].toInt(); // Extract the account balance from JSON
        qDebug() << AccNum << Qt::endl; // Debug output
        emit viewvccountbalance(AccNum); // Emit signal with the extracted account balance
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
void ViewAccountBalanceHandler::SetNextHandler(Handler *pru)
{
    this->pru = pru; // Set the next handler
}
