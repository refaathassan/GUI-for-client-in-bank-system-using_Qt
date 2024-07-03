#include "client_info.h"

Client_Info::Client_Info() {}

Client_Info *Client_Info::GetObject()
{
    if(client_info==nullptr)
    {
        client_info = new client_info();
    }
    return client_info;
}

QString Client_Info::getUserName() const
{
    return UserName;
}

void Client_Info::setUserName(const QString &newUserName)
{
    UserName = newUserName;
}

QString Client_Info::getPassword() const
{
    return Password;
}

void Client_Info::setPassword(const QString &newPassword)
{
    Password = newPassword;
}

QString Client_Info::getAcountNumber() const
{
    return AcountNumber;
}

void Client_Info::setAcountNumber(const QString &newAcountNumber)
{
    AcountNumber = newAcountNumber;
}

QString Client_Info::getName() const
{
    return Name;
}

void Client_Info::setName(const QString &newName)
{
    Name = newName;
}

int32_t Client_Info::getBalance() const
{
    return Balance;
}

void Client_Info::setBalance(int32_t newBalance)
{
    Balance = newBalance;
}
Client_Info* Client_Info::client_info=nullptr;
