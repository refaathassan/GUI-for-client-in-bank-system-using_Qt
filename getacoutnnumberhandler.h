#ifndef GETACOUTNNUMBERHANDLER_H
#define GETACOUTNNUMBERHANDLER_H

#include <QObject>
#include "handler.h"
class GetAcoutnNumberHandler : public Handler
{
    Q_OBJECT
public:
    explicit GetAcoutnNumberHandler(QObject *parent = nullptr);

private:
    Handler* pru;
public:
    void Handling(QByteArray jso) override;
    void SetNextHandler(Handler* pru)override;
signals:
};

#endif // GETACOUTNNUMBERHANDLER_H
