#include "viewtransectionhistoryhandler.h"

// Constructor for ViewTransectionHistoryHandler class
ViewTransectionHistoryHandler::ViewTransectionHistoryHandler(QObject *parent)
    : Handler{parent}
{}

// Method to handle incoming data (JSON) for ViewTransectionHistoryHandler
void ViewTransectionHistoryHandler::Handling(QByteArray jso)
{
    qDebug() << "i am here berfore view handler" << Qt::endl; // Debug output
    QStringList stringList; // Initialize a string list to hold transaction history data

    QJsonDocument js = QJsonDocument::fromJson(jso); // Parse JSON byte array to JSON document
    QJsonObject json = js.object(); // Extract JSON object from JSON document

    // Check if the request type is "ViewTransactionHistory"
    if(json["Request"].toString() == "ViewTransactionHistory")
    {
        QJsonValue responseValue = json.value("Response"); // Extract the "Response" value from JSON

        // Check if the "Response" is an array
        if (responseValue.isArray())
        {
            QJsonArray jsonar = json["Response"].toArray(); // Extract array from JSON response

            // Iterate over each element in the JSON array
            for(auto ele : jsonar)
            {
                QJsonObject jsons = ele.toObject(); // Convert each element to JSON object

                // Format and add transaction details to string list
                stringList << QString("amount : %1").arg(jsons["amount"].toInt());
                stringList << QString("date: %1").arg(jsons["date"].toString());
                stringList << QString("descraption: %1").arg(jsons["descraption"].toString());
                stringList << "--------------------------------------------------";
            }
        }
        // If the "Response" is a string, add it directly to the string list
        else if (responseValue.isString())
        {
            stringList << responseValue.toString();
        }

        emit viewtransactionhistory(stringList); // Emit signal with populated string list
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
void ViewTransectionHistoryHandler::SetNextHandler(Handler *pru)
{
    this->pru = pru; // Set the next handler
}
