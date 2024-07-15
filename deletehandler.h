#ifndef DELETEHANDLER_H
#define DELETEHANDLER_H

#include <QObject>
#include "handler.h"
class DeleteHandler : public Handler
{
    Q_OBJECT
public:
    explicit DeleteHandler(QObject *parent = nullptr);

private:
    Handler* pru; // Pointer to the next handler in the chain
public:
    void Handling(QByteArray jso) override; // Handling function override for JSON data
    void SetNextHandler(Handler* pru) override; // Set the next handler in the chain
signals:
};

#endif // DELETEHANDLER_H

