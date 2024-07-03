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
    Handler* pru;
public:
    void Handling(QByteArray jso) override;
    void SetNextHandler(Handler* pru)override;
signals:

};

#endif // LOGHANDLER_H
