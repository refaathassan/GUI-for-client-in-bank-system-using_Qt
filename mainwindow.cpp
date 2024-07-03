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

    handler.MakeConnect("192.168.1.9",1234);
    QStringList items;
    items <<"admin"<<"user";
    ui->comboBox->addItems(items);
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
    handler.WriteToSocket(news);
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
    ui->PBViewAccountBalanceAdmin->setFocus();
    QJsonObject news;
    news["Request"]="ViewAccountBalance";
    news["accountnumber"]=ui->LEGetAccountNumberadmin->text();
    handler.WriteToSocket(news);
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
    QJsonObject news;
    news["Request"]="DeleteUser";
    news["accountnumber"]=ui->LEDeleteUserAdmin->text();
    handler.WriteToSocket(news);
}


void MainWindow::on_PBCreateNewUser_clicked()
{
    ui->PBCreateNewUser->setFocus();
    QJsonObject news;
    news["Request"]="AddUser";
    news["username"]=ui->LECreateNewUserLogName->text();
    news["fullname"]=ui->LEPBCreateNewUserName->text();
    news["password"]=ui->LECreateNewUserPassword->text();
    news["type"]=ui->comboBox->currentText();

    if(news["type"].toString()=="user")
    {
        QString inputText = ui->LECreateNewUserAccountNumber->text();

        // Validate input as integer using QIntValidator
        QIntValidator validator;
        int pos = 0; // This will store the position of the first non-numeric character
        QValidator::State state = validator.validate(inputText, pos);

        if ((state == QValidator::Acceptable)&&(ui->LEMakeTransactionUser->text()!=""))
        {
            news["accountnumber"]=ui->LECreateNewUserAccountNumber->text();
            handler.WriteToSocket(news);
        }
        else
        {
            // Handle case where input is not a valid integer
            ui->LWAdmin->addItem("Please enter a valid integer amount.");
            ui->LECreateNewUserAccountNumber->clear(); // Optionally clear the line edit
            ui->LECreateNewUserAccountNumber->setFocus(); // Optionally set focus back to the line edit
        }

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

    if ((state == QValidator::Acceptable)&&(ui->LEMakeTransactionUser->text()!=""))
    {
        // Conversion to integer
        int amount = inputText.toInt();

        // Proceed with your logic here, e.g., send 'amount' over the network
        QJsonObject news;
        news["Request"] = "MakeTransaction";
        news["amount"] = amount;
        handler.WriteToSocket(news);
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
    QValidator::State state2 = validator.validate(inputText2, pos);
    if ((state1 == QValidator::Acceptable)&&(state2 == QValidator::Acceptable)
        &&(ui->LETransferAmountUserAcountNumber->text()!="")&&(ui->LETransferAmountUserAmount->text()!=""))
    {
        // Conversion to integer
        int amount = inputText2.toInt();

        // Proceed with your logic here, e.g., send 'amount' over the network
        QJsonObject news;
        news["Request"] = "TransferAmount";
        news["amount"] = amount;
        news["accountnumber"] = inputText1;
        handler.WriteToSocket(news);
    }
    else
    {
        // Handle case where input is not a valid integer
        ui->LWUser->addItem("Please enter a valid integer amount.");
        ui->LETransferAmountUserAcountNumber->clear(); // Optionally clear the line edit
        ui->LETransferAmountUserAcountNumber->setFocus(); // Optionally set focus back to the line edit
        ui->LETransferAmountUserAmount->clear(); // Optionally clear the line edit
        ui->LETransferAmountUserAmount->setFocus();
    }
}

