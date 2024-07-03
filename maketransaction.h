#ifndef MAKETRANSACTION_H
#define MAKETRANSACTION_H

#include <QObject>

class MakeTransaction : public QObject
{
    Q_OBJECT
public:
    explicit MakeTransaction(QObject *parent = nullptr);

signals:
};

#endif // MAKETRANSACTION_H
