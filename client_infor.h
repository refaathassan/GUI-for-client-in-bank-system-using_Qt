#ifndef CLIENT_INFOR_H
#define CLIENT_INFOR_H

#include <QObject>

class Client_Infor : public QObject
{
    Q_OBJECT
public:

public:
protected:
    static Client_Infor* client_infor;
private:
    explicit Client_Infor(QObject *parent = nullptr);

};

#endif // CLIENT_INFOR_H
