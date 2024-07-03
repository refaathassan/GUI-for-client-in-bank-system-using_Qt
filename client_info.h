#ifndef CLIENT_INFO_H
#define CLIENT_INFO_H

#include <QObject>

class Client_Info
{
public:

    Client_Info(Client_Info& obj)=delete;
    Client_Info& operator=(const Client_Info& obj)=delete;
    static Client_Info* GetObject();
    QString getUserName() const;
    void setUserName(const QString &newUserName);
    QString getPassword() const;
    void setPassword(const QString &newPassword);
    QString getAcountNumber() const;
    void setAcountNumber(const QString &newAcountNumber);
    QString getName() const;
    void setName(const QString &newName);
    int32_t getBalance() const;
    void setBalance(int32_t newBalance);
protected:
    static Client_Info* client_info;
private:
    Client_Info();
    QString UserName;
    QString Password;
    QString AcountNumber;
    QString Name;
    int32_t Balance;
};

#endif // CLIENT_INFO_H
