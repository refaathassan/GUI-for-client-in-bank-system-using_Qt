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
    Handler* pru;
public:
    void Handling(QByteArray jso) override;
    void SetNextHandler(Handler* pru)override;
signals:
};

#endif // VIEWDATABASEHANDLER_H

