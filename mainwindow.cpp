#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(&handler,&TCPSocket::Connect,this,&MainWindow::OnConnectDe);
    connect(&handler,&TCPSocket::Disconnect,this,&MainWindow::OnDisconnectDe);
    connect(&handler,&TCPSocket::Error,this,&MainWindow::OnErrorDe);
    connect(&handler,&TCPSocket::Trigger,this,&MainWindow::OnTriggerDe);
    connect(handler.GetHandler1(),&Handler::logsignal,this,&MainWindow::OnlogRespose);
    connect(handler.GetHandler2(),&Handler::getacountnumber,this,&MainWindow::OnGetAcoutnNumberResponse);
    connect(handler.GetHandler3(),&Handler::viewvccountbalance,this,&MainWindow::OnViewAccountBalnce);
    connect(handler.GetHandler4(),&Handler::viewdatabase,this,&MainWindow::OnViewDataBase);
    connect(handler.GetHandler5(),&Handler::deleteuser,this,&MainWindow::OnDeleteUser);
    connect(handler.GetHandler6(),&Handler::adduser,this,&MainWindow::OnAddUser);
    connect(handler.GetHandler7(),&Handler::maketransaction,this,&MainWindow::OnMakeTransaction);
    connect(handler.GetHandler8(),&Handler::transferamount,this,&MainWindow::OnTransferAmount);
    connect(handler.GetHandler9(),&Handler::viewtransactionhistory,this,&MainWindow::OnViewTransactionHistory);
    connect(handler.GetHandler10(),&Handler::updateuser,this,&MainWindow::OnUpdateUser);

    handler.MakeConnect("192.168.1.9",1234);
    ui->tabWidget->setTabEnabled(0,true);
    ui->tabWidget->setTabEnabled(1,false);
    ui->tabWidget->setTabEnabled(2,false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_PBLog_clicked()
{
    ui->PBLog->setFocus();
    QJsonObject news;
    news["Request"]="Log";
    news["username"]=ui->LEUserName->text();
    news["password"]=ui->LEUserPassword->text();
    handler.WriteToSocket(news);
}


void MainWindow::on_PBLogOutUser_clicked()
{
    ui->tabWidget->setTabEnabled(0,true);
    ui->tabWidget->setTabEnabled(1,false);
    ui->tabWidget->setTabEnabled(2,false);
    ui->LEUserName->clear();
    ui->LEUserPassword->clear();
    ui->tabWidget->setCurrentIndex(0);
}


void MainWindow::on_PBLogOutAdmin_clicked()
{
    ui->tabWidget->setTabEnabled(0,true);
    ui->tabWidget->setTabEnabled(1,false);
    ui->tabWidget->setTabEnabled(2,false);
    ui->LEUserName->clear();
    ui->LEUserPassword->clear();
    ui->tabWidget->setCurrentIndex(0);

}
void MainWindow::OnConnectDe(void)
{
    ui->LWLogging->addItem("you are ready to log");
}
void MainWindow::OnDisconnectDe(void)
{
    if(ui->tabWidget->currentIndex()==1)
    {
        ui->LWUser->addItem("error in connection with server ");
        ui->LWUser->addItem("you are disconnected now ");
    }
    else if(ui->tabWidget->currentIndex()==2)
    {
        ui->LWAdmin->addItem("error in connection with server ");
        ui->LWAdmin->addItem("you are disconnected now ");
    }
    else
    {
        ui->LWLogging->addItem("error in connection with server ");
        ui->LWLogging->addItem("you are disconnected now ");
    }
}

void MainWindow::OnlogRespose(bool flag,bool admin)
{
    if(flag==true&&admin==false)
    {
        ui->tabWidget->setTabEnabled(0,false);
        ui->tabWidget->setTabEnabled(1,true);
        ui->tabWidget->setTabEnabled(2,false);
        ui->tabWidget->setCurrentIndex(1);
    }
    else if(flag==true&&admin==true)
    {
        ui->tabWidget->setTabEnabled(0,false);
        ui->tabWidget->setTabEnabled(1,false);
        ui->tabWidget->setTabEnabled(2,true);
        ui->tabWidget->setCurrentIndex(2);
    }
    else
    {
       ui->LWLogging->addItem("you are not user or admin");
    }

}

void MainWindow::OnGetAcoutnNumberResponse(QString massage)
{
    if(ui->tabWidget->currentIndex()==1)
    {
        ui->LWUser->addItem(massage);
    }
    else if(ui->tabWidget->currentIndex()==2)
    {
        ui->LWAdmin->addItem(massage);
    }
}

void MainWindow::OnViewAccountBalnce(int massage)
{
    qDebug()<<massage<<Qt::endl;
    if(ui->tabWidget->currentIndex()==1)
    {
        ui->LWUser->addItem(QString::number(massage));
    }
    else if(ui->tabWidget->currentIndex()==2)
    {
        ui->LWAdmin->addItem(QString::number(massage));
    }
}

void MainWindow::OnViewDataBase(QStringList massage)
{
    qDebug()<<massage<<Qt::endl;
    if(ui->tabWidget->currentIndex()==1)
    {
        ui->LWUser->addItems(massage);
    }
    else if(ui->tabWidget->currentIndex()==2)
    {
        ui->LWAdmin->addItems(massage);
    }
}
void MainWindow::OnDeleteUser(QString massage)
{
    qDebug()<<massage<<Qt::endl;
    if(ui->tabWidget->currentIndex()==1)
    {
        ui->LWUser->addItem(massage);
    }
    else if(ui->tabWidget->currentIndex()==2)
    {
        ui->LWAdmin->addItem(massage);
    }
}
void MainWindow::OnAddUser(QString massage)
{
    qDebug()<<massage<<Qt::endl;
    if(ui->tabWidget->currentIndex()==1)
    {
        ui->LWUser->addItem(massage);
    }
    else if(ui->tabWidget->currentIndex()==2)
    {
        ui->LWAdmin->addItem(massage);
    }
}

void MainWindow::OnMakeTransaction(QString massage)
{
    ui->LWUser->addItem(massage);
}

void MainWindow::OnTransferAmount(QString massage)
{
    ui->LWUser->addItem(massage);
}



void MainWindow::OnViewTransactionHistory(QStringList massage)
{
    qDebug()<<massage<<Qt::endl;
    if(ui->tabWidget->currentIndex()==1)
    {
        ui->LWUser->addItems(massage);
    }
    else if(ui->tabWidget->currentIndex()==2)
    {
        ui->LWAdmin->addItems(massage);
    }
}

void MainWindow::OnUpdateUser(QString massage)
{
    ui->LWAdmin->addItem(massage);
}

void MainWindow::OnTriggerDe(QAbstractSocket::SocketState socketState)
{

}
void MainWindow::OnErrorDe(QAbstractSocket::SocketError socketError)
{
    //ui->LWLogging->addItem("it is a error in connection with server");
    QMetaEnum me=QMetaEnum::fromType<QAbstractSocket::SocketError>();

    if(ui->tabWidget->currentIndex()==1)
    {
        ui->LWUser->addItem("error in connection with server ");
        ui->LWUser->addItem("you are disconnected now ");
        ui->LWUser->addItem(me.valueToKey(socketError));
    }
    else if(ui->tabWidget->currentIndex()==2)
    {
        ui->LWAdmin->addItem("error in connection with server ");
        ui->LWAdmin->addItem("you are disconnected now ");
        ui->LWAdmin->addItem(me.valueToKey(socketError));
    }
    else
    {
        ui->LWLogging->addItem("error in connection with server ");
        ui->LWLogging->addItem("you are disconnected now ");
        ui->LWLogging->addItem(me.valueToKey(socketError));
    }
}


void MainWindow::on_PBGetAccountNumberUser_clicked()
{
    ui->PBGetAccountNumberUser->setFocus();
    QJsonObject news;
    news["Request"]="GetAccountNumber";
    handler.WriteToSocket(news);
}


void MainWindow::on_PBGetAccountNumberadmin_clicked()
{
    ui->PBGetAccountNumberadmin->setFocus();
    QJsonObject news;
    news["Request"]="GetAccountNumber";
    news["username"]=ui->LEGetAccountNumberadmin->text();

    if(isAlphabetic(ui->LEGetAccountNumberadmin->text(),"^[a-zA-Z]+$")&&ui->LEGetAccountNumberadmin->text()!="")
    {
            handler.WriteToSocket(news);
            ui->LEGetAccountNumberadmin->clear();
    }
    else
    {
            // Handle case where input is not a valid integer
            ui->LWAdmin->addItem("Please enter a valid user name string without space.");
            ui->LEGetAccountNumberadmin->clear(); // Optionally clear the line edit
            ui->LEGetAccountNumberadmin->setFocus(); // Optionally set focus back to the line edit
    }
}


void MainWindow::on_PBViewAccountBalanceUser_clicked()
{
    ui->PBViewAccountBalanceUser->setFocus();
    QJsonObject news;
    news["Request"]="ViewAccountBalance";
    handler.WriteToSocket(news);
}


void MainWindow::on_PBViewAccountBalanceAdmin_clicked()
{

    ui->PBDeleteUserAdmin->setFocus();
    // QJsonObject news;
    // news["Request"]="MakeTransaction";
    // news["amount"]=ui->LEMakeTransactionUser->text().toInt();
    // handler.WriteToSocket(news);
    QString inputText = ui->LEViewAccountBalanceAdmin->text();

    // Validate input as integer using QIntValidator
    QIntValidator validator;
    int pos = 0; // This will store the position of the first non-numeric character
    QValidator::State state = validator.validate(inputText, pos);

    if ((state == QValidator::Acceptable)&&(ui->LEViewAccountBalanceAdmin->text()!=""))
    {
        QJsonObject news;
        news["Request"]="ViewAccountBalance";
        news["accountnumber"]=ui->LEViewAccountBalanceAdmin->text();
        handler.WriteToSocket(news);
        ui->LEViewAccountBalanceAdmin->clear();
    }
    else
    {
        // Handle case where input is not a valid integer
        ui->LWAdmin->addItem("Please enter a valid integer accountnumber.");
        ui->LEViewAccountBalanceAdmin->clear(); // Optionally clear the line edit
        ui->LEViewAccountBalanceAdmin->setFocus(); // Optionally set focus back to the line edit
    }
}


void MainWindow::on_PBLogOutAdmin_14_clicked()
{
    ui->PBLogOutAdmin_14->setFocus();
    QJsonObject news;
    news["Request"]="ViewDataBase";
    handler.WriteToSocket(news);
}


void MainWindow::on_PBDeleteUserAdmin_clicked()
{
    ui->PBDeleteUserAdmin->setFocus();
    // QJsonObject news;
    // news["Request"]="MakeTransaction";
    // news["amount"]=ui->LEMakeTransactionUser->text().toInt();
    // handler.WriteToSocket(news);
    QString inputText = ui->LEDeleteUserAdmin->text();

    // Validate input as integer using QIntValidator
    QIntValidator validator;
    int pos = 0; // This will store the position of the first non-numeric character
    QValidator::State state = validator.validate(inputText, pos);

    if ((state == QValidator::Acceptable)&&(inputText!=""))
    {
        // Conversion to integer
        //int amount = inputText.toInt();

        // Proceed with your logic here, e.g., send 'amount' over the network
        QJsonObject news;
        news["Request"] = "DeleteUser";
        news["accountnumber"] =inputText ;
        handler.WriteToSocket(news);
        ui->LEDeleteUserAdmin->clear();
    }
    else
    {
        // Handle case where input is not a valid integer
        ui->LWAdmin->addItem("Please enter a valid integer accountnumber.");
        ui->LEDeleteUserAdmin->clear(); // Optionally clear the line edit
        ui->LEDeleteUserAdmin->setFocus(); // Optionally set focus back to the line edit
    }
}


void MainWindow::on_PBCreateNewUser_clicked()
{
    ui->PBCreateNewUser->setFocus();
    QJsonObject news;
    news["Request"]="AddUser";
    news["username"]=ui->LECreateNewUserLogName->text();
    if(isAlphabetic(news["username"].toString(),"^[a-zA-Z]+$")&&news["username"].toString()!="")
    {
        news["fullname"]=ui->LEPBCreateNewUserName->text();
        if(isAlphabetic(news["fullname"].toString(),"^[a-zA-Z ]+$")&&news["fullname"].toString()!="")
        {
            news["password"]=ui->LECreateNewUserPassword->text();
            if(news["password"].toString()!="")
            {
                news["type"]="user";
                handler.WriteToSocket(news);
                ui->LECreateNewUserPassword->clear();
                ui->LEPBCreateNewUserName->clear();
                ui->LECreateNewUserLogName->clear();
            }
            else
            {
                // Handle case where input is not a valid integer
                ui->LWAdmin->addItem("Please enter a valid password .");
                ui->LECreateNewUserPassword->clear(); // Optionally clear the line edit
                ui->LECreateNewUserPassword->setFocus(); // Optionally set focus back to the line edit
            }
        }
        else
        {
            // Handle case where input is not a valid integer
            ui->LWAdmin->addItem("Please enter a valid string .");
            ui->LEPBCreateNewUserName->clear(); // Optionally clear the line edit
            ui->LEPBCreateNewUserName->setFocus(); // Optionally set focus back to the line edit
        }
    }
    else
    {
        // Handle case where input is not a valid integer
        ui->LWAdmin->addItem("Please enter a valid string .");
        ui->LECreateNewUserLogName->clear(); // Optionally clear the line edit
        ui->LECreateNewUserLogName->setFocus(); // Optionally set focus back to the line edit
    }

}


void MainWindow::on_PBMakeTransactionUser_clicked()
{
    ui->PBMakeTransactionUser->setFocus();
    // QJsonObject news;
    // news["Request"]="MakeTransaction";
    // news["amount"]=ui->LEMakeTransactionUser->text().toInt();
    // handler.WriteToSocket(news);
    QString inputText = ui->LEMakeTransactionUser->text();

    // Validate input as integer using QIntValidator
    QIntValidator validator;
    int pos = 0; // This will store the position of the first non-numeric character
    QValidator::State state = validator.validate(inputText, pos);

    if ((state == QValidator::Acceptable)&&(inputText!=""))
    {

        // Conversion to integer
        int amount = inputText.toInt();
        if(amount!=0)
        {
            // Proceed with your logic here, e.g., send 'amount' over the network
            QJsonObject news;
            news["Request"] = "MakeTransaction";
            news["amount"] = amount;
            handler.WriteToSocket(news);
            ui->LEMakeTransactionUser->clear();
        }
        else
        {
            // Handle case where input is not a valid integer
            ui->LWUser->addItem("Please enter a valid integer amount.");
            ui->LEMakeTransactionUser->clear(); // Optionally clear the line edit
            ui->LEMakeTransactionUser->setFocus(); // Optionally set focus back to the line edit
        }
    }
    else
    {
        // Handle case where input is not a valid integer
        ui->LWUser->addItem("Please enter a valid integer amount.");
        ui->LEMakeTransactionUser->clear(); // Optionally clear the line edit
        ui->LEMakeTransactionUser->setFocus(); // Optionally set focus back to the line edit
    }
}


void MainWindow::on_PBTransferAmountUser_clicked()
{
    ui->PBTransferAmountUser->setFocus();
    // QJsonObject news;
    // news["Request"]="MakeTransaction";
    // news["amount"]=ui->LEMakeTransactionUser->text().toInt();
    // handler.WriteToSocket(news);
    QString inputText1 = ui->LETransferAmountUserAcountNumber->text();
    QString inputText2 = ui->LETransferAmountUserAmount->text();
    // Validate input as integer using QIntValidator
    QIntValidator validator;
    int pos = 0; // This will store the position of the first non-numeric character
    QValidator::State state1 = validator.validate(inputText1, pos);
    if((state1 == QValidator::Acceptable)&&(ui->LETransferAmountUserAcountNumber->text()!=""))
    {
        QValidator::State state2 = validator.validate(inputText2, pos);
        if ((state2 == QValidator::Acceptable)&&(ui->LETransferAmountUserAmount->text()!=""))
        {
            // Conversion to integer
            int amount = inputText2.toInt();
            if(amount>0)
            {
                // Proceed with your logic here, e.g., send 'amount' over the network
                QJsonObject news;
                news["Request"] = "TransferAmount";
                news["amount"] = amount;
                news["accountnumber"] = inputText1;
                handler.WriteToSocket(news);
                ui->LETransferAmountUserAmount->clear();
                ui->LETransferAmountUserAcountNumber->clear();
            }
            else
            {
                // Handle case where input is not a valid integer
                ui->LWUser->addItem("Please enter a valid integer amount.");

                ui->LETransferAmountUserAmount->clear(); // Optionally clear the line edit
                ui->LETransferAmountUserAmount->setFocus();
            }
        }
        else
        {
            // Handle case where input is not a valid integer
            ui->LWUser->addItem("Please enter a valid integer amount.");

            ui->LETransferAmountUserAmount->clear(); // Optionally clear the line edit
            ui->LETransferAmountUserAmount->setFocus();
        }
    }
    else
    {
        ui->LWUser->addItem("Please enter a valid accountnumber.");
        ui->LETransferAmountUserAcountNumber->clear(); // Optionally clear the line edit
        ui->LETransferAmountUserAcountNumber->setFocus(); // Optionally set focus back to the line edit
    }
}


void MainWindow::on_PBViewTransactionHistoryUser_clicked()
{
    ui->PBDeleteUserAdmin->setFocus();
    QJsonObject news;
    news["Request"]="ViewTransactionHistory";
    news["count"]=5;
    handler.WriteToSocket(news);
}


void MainWindow::on_PBViewTransactionHistoryAdmin_clicked()
{
    ui->PBDeleteUserAdmin->setFocus();
    QJsonObject news;
    news["Request"]="ViewTransactionHistory";
    news["accountnumber"]=ui->LEViewTransactionHistoryAdmin->text();
    news["count"]=5;
    handler.WriteToSocket(news);
    ui->LEViewTransactionHistoryAdmin->clear();
}
bool  MainWindow::isAlphabetic(const QString &str, QString str1) {
    QRegularExpression regex(str1); // Regular expression to match alphabetic characters only
    return regex.match(str).hasMatch();
}

void MainWindow::on_PBUpdateNewUser_clicked()
{
    ui->PBUpdateNewUser->setFocus();
    QJsonObject news;
    QString inputText = ui->LEUpdateaccoutnnumber->text();
    QString inputText2 = ui->LEUpdateNewUserBalance->text();
    QIntValidator validator;
    int pos = 0;
    QValidator::State state = validator.validate(inputText, pos);
    QValidator::State state2 = validator.validate(inputText2, pos);
    if ((state == QValidator::Acceptable)&&(ui->LEUpdateaccoutnnumber->text()!=""))
    {
        news["Request"]="UpdateUser";
        news["accountnumber"]=ui->LEUpdateaccoutnnumber->text();
        if ((state2 == QValidator::Acceptable||ui->LEUpdateNewUserBalance->text()==""))
        {
            news["balance"]=ui->LEUpdateNewUserBalance->text();
            if(isAlphabetic(ui->LEPBUpdateNewUser->text(),"^[a-zA-Z]+$")||ui->LEPBUpdateNewUser->text()=="")
            {
                news["username"]=ui->LEPBUpdateNewUser->text();

                if(isAlphabetic(ui->LEPBUpdateNewUserName->text(),"^[a-zA-Z]+$")||ui->LEPBUpdateNewUserName->text()=="")
                {
                    news["fullname"]=ui->LEPBUpdateNewUserName->text();
                    news["password"]=ui->LEUpdateNewUserPassword->text();
                    news["type"]="user";
                    handler.WriteToSocket(news);
                    ui->LEPBUpdateNewUserName->clear();
                    ui->LEPBUpdateNewUser->clear();
                    ui->LEUpdateNewUserBalance->clear();
                    ui->LEUpdateaccoutnnumber->clear();
                }
                else
                {
                    // Handle case where input is not a valid integer
                    ui->LWAdmin->addItem("Please enter a valid full name .");
                    ui->LEPBUpdateNewUserName->clear(); // Optionally clear the line edit
                    ui->LEPBUpdateNewUserName->setFocus(); // Optionally set focus back to the line edit
                }
            }
            else
            {
                ui->LWAdmin->addItem("Please enter a valid account user name .");
                ui->LEPBUpdateNewUser->clear(); // Optionally clear the line edit
                ui->LEPBUpdateNewUser->setFocus(); // Optionally set focus back to the line edit
            }
        }
        else
        {
            // Handle case where input is not a valid integer
            ui->LWAdmin->addItem("Please enter a valid balance .");
            ui->LEUpdateNewUserBalance->clear(); // Optionally clear the line edit
            ui->LEUpdateNewUserBalance->setFocus(); // Optionally set focus back to the line edit
        }
    }
    else
    {
        ui->LWAdmin->addItem("Please enter a valid account number.");
        ui->LEUpdateaccoutnnumber->clear(); // Optionally clear the line edit
        ui->LEUpdateaccoutnnumber->setFocus(); // Optionally set focus back to the line edit
    }
}

