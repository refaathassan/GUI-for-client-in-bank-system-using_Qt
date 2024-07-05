#ifndef VIEWTRANSECTIONHISTORYHANDLER_H
#define VIEWTRANSECTIONHISTORYHANDLER_H

#include <QObject>
#include "handler.h"
class ViewTransectionHistoryHandler : public Handler
{
    Q_OBJECT
public:
    explicit ViewTransectionHistoryHandler(QObject *parent = nullptr);
private:
    Handler* pru;
public:
    void Handling(QByteArray jso) override;
    void SetNextHandler(Handler* pru)override;
signals:
};

#endif // VIEWTRANSECTIONHISTORYHANDLER_H
