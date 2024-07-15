#ifndef LOGHANDLER_H
#define LOGHANDLER_H

#include <QObject>
#include "handler.h"
class LogHandler : public Handler
{
    Q_OBJECT
public:
    explicit LogHandler(QObject *parent = nullptr);
private:
    Handler* pru; // Pointer to the next handler in the chain
public:
    void Handling(QByteArray jso) override; // Handling function override for JSON data
    void SetNextHandler(Handler* pru) override; // Set the next handler in the chain
signals:

};

#endif // LOGHANDLER_H
