#ifndef VIEWDATABASEHANDLER_H
#define VIEWDATABASEHANDLER_H

#include <QObject>
#include "handler.h"

class ViewDataBaseHandler : public Handler
{
    Q_OBJECT
public:
    explicit ViewDataBaseHandler(QObject *parent = nullptr);
private:
    Handler* pru; // Pointer to the next handler in the chain
public:
    void Handling(QByteArray jso) override; // Handling function override for JSON data
    void SetNextHandler(Handler* pru)override; // Set the next handler in the chain
signals:
};

#endif // VIEWDATABASEHANDLER_H
