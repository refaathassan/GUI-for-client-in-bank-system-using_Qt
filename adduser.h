#ifndef ADDUSER_H
#define ADDUSER_H

#include <QObject>

class AddUser : public QObject
{
    Q_OBJECT
public:
    explicit AddUser(QObject *parent = nullptr);

signals:
};

#endif // ADDUSER_H
