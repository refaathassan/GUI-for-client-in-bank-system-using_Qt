#ifndef MAKETRANSACTIONHANDLER_H
#define MAKETRANSACTIONHANDLER_H

#include <QObject>
#include "handler.h"
class MakeTransactionHandler : public Handler
{
    Q_OBJECT
public:
    explicit MakeTransactionHandler(QObject *parent = nullptr);   
private:
    Handler* pru;
public:
    void Handling(QByteArray jso) override;
    void SetNextHandler(Handler* pru)override;
signals:
};

#endif // MAKETRANSACTIONHANDLER_H


