#ifndef VIEWACCOUNTBALANCEHANDLER_H
#define VIEWACCOUNTBALANCEHANDLER_H

#include <QObject>
#include "handler.h"
class ViewAccountBalanceHandler : public Handler
{
    Q_OBJECT
public:
    explicit ViewAccountBalanceHandler(QObject *parent = nullptr);
private:
    Handler* pru;
public:
    void Handling(QByteArray jso) override;
    void SetNextHandler(Handler* pru)override;
signals:
};
#endif // TCPSOCKET_H
