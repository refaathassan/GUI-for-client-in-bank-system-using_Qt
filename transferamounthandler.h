#ifndef TRANSFERAMOUNTHANDLER_H
#define TRANSFERAMOUNTHANDLER_H

#include <QObject>

class TransferAmountHandler : public QObject
{
    Q_OBJECT
public:
    explicit TransferAmountHandler(QObject *parent = nullptr);

signals:
};

#endif // TRANSFERAMOUNTHANDLER_H
