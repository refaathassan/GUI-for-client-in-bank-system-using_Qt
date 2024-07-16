#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    // Initialize the UI
    ui->setupUi(this);

    // Connect signals from TCPSocket instance to slots in MainWindow
    connect(&handler, &TCPSocket::Connect, this, &MainWindow::OnConnectDe);
    connect(&handler, &TCPSocket::Disconnect, this, &MainWindow::OnDisconnectDe);
    connect(&handler, &TCPSocket::Error, this, &MainWindow::OnErrorDe);

    // Connect signals from various Handler instances to respective slots in MainWindow
    connect(handler.GetHandler1(), &Handler::logsignal, this, &MainWindow::OnlogRespose);
    connect(handler.GetHandler2(), &Handler::getacountnumber, this, &MainWindow::OnGetAcoutnNumberResponse);
    connect(handler.GetHandler3(), &Handler::viewvccountbalance, this, &MainWindow::OnViewAccountBalnce);
    connect(handler.GetHandler4(), &Handler::viewdatabase, this, &MainWindow::OnViewDataBase);
    connect(handler.GetHandler5(), &Handler::deleteuser, this, &MainWindow::OnDeleteUser);
    connect(handler.GetHandler6(), &Handler::adduser, this, &MainWindow::OnAddUser);
    connect(handler.GetHandler7(), &Handler::maketransaction, this, &MainWindow::OnMakeTransaction);
    connect(handler.GetHandler8(), &Handler::transferamount, this, &MainWindow::OnTransferAmount);
    connect(handler.GetHandler9(), &Handler::viewtransactionhistory, this, &MainWindow::OnViewTransactionHistory);
    connect(handler.GetHandler10(), &Handler::updateuser, this, &MainWindow::OnUpdateUser);

    // Initialize TCPSocket and connect to server
    handler.MakeConnect("192.168.1.9", 30000);

    // Enable and initialize tabs and comboboxes
    ui->tabWidget->setTabEnabled(0, true);   // Enable tab 0 (Logging)
    ui->tabWidget->setTabEnabled(1, false);  // Disable tab 1 (User)
    ui->tabWidget->setTabEnabled(2, false);  // Disable tab 2 (Admin)

    // Populate comboboxes with items
    QStringList items;
    items << "0" << "1" << "2" << "3" << "4" << "5";
    ui->CBCount->addItems(items);
    ui->CBCount_2->addItems(items);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_PBLog_clicked()
{
    // Set focus on the login button
    ui->PBLog->setFocus();

    // Get username and password inputs
    QString inputText1 = ui->LEUserName->text();
    QString inputText2 = ui->LEUserPassword->text();

    // Validate username
    if (isAlphabetic(inputText1, "^[a-zA-Z]+$") && inputText1.length() > 5)
    {
        // Validate password
        if (inputText2.length() > 5)
        {
            // Construct JSON object for login request
            QJsonObject news;
            news["Request"] = "Log";
            news["username"] = inputText1;
            news["password"] = inputText2;
            handler.WriteToSocket(news);
        }
        else
        {
            // Handle invalid password
            ui->LWLogging->addItem("Please enter a valid password");
            ui->LEUserPassword->clear();  // Clear password input
            ui->LEUserPassword->setFocus();  // Set focus back to password input
        }
    }
    else
    {
        // Handle invalid username
        ui->LWLogging->addItem("Please enter a valid user name");
        ui->LEUserName->clear();  // Clear username input
        ui->LEUserName->setFocus();  // Set focus back to username input
    }
}

void MainWindow::on_PBLogOutUser_clicked()
{
    // Logout user and switch tabs
    ui->tabWidget->setTabEnabled(0, true);   // Enable Logging tab
    ui->tabWidget->setTabEnabled(1, false);  // Disable User tab
    ui->tabWidget->setTabEnabled(2, false);  // Disable Admin tab
    ui->LEUserName->clear();  // Clear username input
    ui->LEUserPassword->clear();  // Clear password input
    ui->tabWidget->setCurrentIndex(0);  // Switch to Logging tab
}

void MainWindow::on_PBLogOutAdmin_clicked()
{
    // Logout admin and switch tabs
    ui->tabWidget->setTabEnabled(0, true);   // Enable Logging tab
    ui->tabWidget->setTabEnabled(1, false);  // Disable User tab
    ui->tabWidget->setTabEnabled(2, false);  // Disable Admin tab
    ui->LEUserName->clear();  // Clear username input
    ui->LEUserPassword->clear();  // Clear password input
    ui->tabWidget->setCurrentIndex(0);  // Switch to Logging tab
}

void MainWindow::OnConnectDe(void)
{
    // Handle connection established event
    ui->LWLogging->addItem("you are ready to log");
    // Path to your batch script
    QString batchFilePath = QApplication::applicationDirPath() + "//keys.bat";
    // Start the batch script with arguments
    process.start(batchFilePath);
    if (!process.waitForFinished())
    {
        qDebug() << "Failed to run batch script:" << process.errorString();
        return;
    }
    QFile file(QApplication::applicationDirPath() + "//public.pem");  // Open the RSA public key file
    file.open(QIODevice::ReadOnly);
    QByteArray publicKeyData = file.readAll();
    QJsonObject news;
    news["key"]=QString::fromUtf8(publicKeyData);
    handler.WriteToSocket(news);
}

void MainWindow::OnDisconnectDe(void)
{
    // Handle disconnection event
    if (ui->tabWidget->currentIndex() == 1)
    {
        ui->LWUser->addItem("error in connection with server ");
        ui->LWUser->addItem("you are disconnected now ");
    }
    else if (ui->tabWidget->currentIndex() == 2)
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

void MainWindow::OnlogRespose(bool flag, bool admin)
{
    // Handle login response
    if (flag == true && admin == false)
    {
        // Successful user login
        ui->tabWidget->setTabEnabled(0, false);  // Disable Logging tab
        ui->tabWidget->setTabEnabled(1, true);   // Enable User tab
        ui->tabWidget->setTabEnabled(2, false);  // Disable Admin tab
        ui->tabWidget->setCurrentIndex(1);  // Switch to User tab
    }
    else if (flag == true && admin == true)
    {
        // Successful admin login
        ui->tabWidget->setTabEnabled(0, false);  // Disable Logging tab
        ui->tabWidget->setTabEnabled(1, false);  // Disable User tab
        ui->tabWidget->setTabEnabled(2, true);   // Enable Admin tab
        ui->tabWidget->setCurrentIndex(2);  // Switch to Admin tab
    }
    else
    {
        // Failed login attempt
        ui->LWLogging->addItem("you are not user or admin");
    }
}

void MainWindow::OnGetAcoutnNumberResponse(QString massage)
{
    // Handle response to getting account number
    if (ui->tabWidget->currentIndex() == 1)
    {
        ui->LWUser->addItem(massage);  // Add message to User log list
    }
    else if (ui->tabWidget->currentIndex() == 2)
    {
        ui->LWAdmin->addItem(massage);  // Add message to Admin log list
    }
}


void MainWindow::OnViewAccountBalnce(int massage)
{
    qDebug() << massage << Qt::endl;  // Output massage to debug log
    if (ui->tabWidget->currentIndex() == 1)
    {
        ui->LWUser->addItem(QString::number(massage));  // Add massage to User log list
    }
    else if (ui->tabWidget->currentIndex() == 2)
    {
        ui->LWAdmin->addItem(QString::number(massage));  // Add massage to Admin log list
    }
}

void MainWindow::OnViewDataBase(QStringList massage)
{
    qDebug() << massage << Qt::endl;  // Output massage to debug log
    if (ui->tabWidget->currentIndex() == 1)
    {
        ui->LWUser->addItems(massage);  // Add items from massage to User log list
    }
    else if (ui->tabWidget->currentIndex() == 2)
    {
        ui->LWAdmin->addItems(massage);  // Add items from massage to Admin log list
    }
}

void MainWindow::OnDeleteUser(QString massage)
{
    qDebug() << massage << Qt::endl;  // Output massage to debug log
    if (ui->tabWidget->currentIndex() == 1)
    {
        ui->LWUser->addItem(massage);  // Add massage to User log list
    }
    else if (ui->tabWidget->currentIndex() == 2)
    {
        ui->LWAdmin->addItem(massage);  // Add massage to Admin log list
    }
}

void MainWindow::OnAddUser(QString massage)
{
    qDebug() << massage << Qt::endl;  // Output massage to debug log
    if (ui->tabWidget->currentIndex() == 1)
    {
        ui->LWUser->addItem(massage);  // Add massage to User log list
    }
    else if (ui->tabWidget->currentIndex() == 2)
    {
        ui->LWAdmin->addItem(massage);  // Add massage to Admin log list
    }
}

void MainWindow::OnMakeTransaction(QString massage)
{
    ui->LWUser->addItem(massage);  // Add massage to User log list
}

void MainWindow::OnTransferAmount(QString massage)
{
    ui->LWUser->addItem(massage);  // Add massage to User log list
}

void MainWindow::OnViewTransactionHistory(QStringList massage)
{
    qDebug() << massage << Qt::endl;  // Output massage to debug log
    if (ui->tabWidget->currentIndex() == 1)
    {
        ui->LWUser->addItems(massage);  // Add items from massage to User log list
    }
    else if (ui->tabWidget->currentIndex() == 2)
    {
        ui->LWAdmin->addItems(massage);  // Add items from massage to Admin log list
    }
}

void MainWindow::OnUpdateUser(QString massage)
{
    ui->LWAdmin->addItem(massage);  // Add massage to Admin log list
}


void MainWindow::OnErrorDe(QAbstractSocket::SocketError socketError)
{
    // Handle socket errors
    // Uncomment the line below to add error message to Logging tab
    // ui->LWLogging->addItem("it is a error in connection with server");

    // Convert socket error enum to string representation
    QMetaEnum me = QMetaEnum::fromType<QAbstractSocket::SocketError>();

    if (ui->tabWidget->currentIndex() == 1)
    {
        // Add error messages to User log list
        ui->LWUser->addItem("error in connection with server ");
        ui->LWUser->addItem("you are disconnected now ");
        ui->LWUser->addItem(me.valueToKey(socketError));  // Add specific error description
    }
    else if (ui->tabWidget->currentIndex() == 2)
    {
        // Add error messages to Admin log list
        ui->LWAdmin->addItem("error in connection with server ");
        ui->LWAdmin->addItem("you are disconnected now ");
        ui->LWAdmin->addItem(me.valueToKey(socketError));  // Add specific error description
    }
    else
    {
        // Add error messages to Logging tab
        ui->LWLogging->addItem("error in connection with server ");
        ui->LWLogging->addItem("you are disconnected now ");
        ui->LWLogging->addItem(me.valueToKey(socketError));  // Add specific error description
    }
}

void MainWindow::on_PBGetAccountNumberUser_clicked()
{
    ui->PBGetAccountNumberUser->setFocus();  // Set focus on the Get Account Number button
    QJsonObject news;
    news["Request"] = "GetAccountNumber";
    handler.WriteToSocket(news);  // Send request to server to get account number
}

void MainWindow::on_PBGetAccountNumberadmin_clicked()
{
    ui->PBGetAccountNumberadmin->setFocus();  // Set focus on the Get Account Number button
    QJsonObject news;
    news["Request"] = "GetAccountNumber";
    news["username"] = ui->LEGetAccountNumberadmin->text();  // Get username input

    if (isAlphabetic(ui->LEGetAccountNumberadmin->text(), "^[a-zA-Z]+$") && ui->LEGetAccountNumberadmin->text().length() > 5)
    {
        // Send request to server to get account number if username is valid
        handler.WriteToSocket(news);
        ui->LEGetAccountNumberadmin->clear();  // Clear username input field
    }
    else
    {
        // Handle case where input is not a valid username string
        ui->LWAdmin->addItem("Please enter a valid user name string without space.");
        ui->LEGetAccountNumberadmin->clear();  // Optionally clear the line edit
        ui->LEGetAccountNumberadmin->setFocus();  // Optionally set focus back to the line edit
    }
}


void MainWindow::on_PBViewAccountBalanceUser_clicked()
{
    ui->PBViewAccountBalanceUser->setFocus();  // Set focus on the View Account Balance button
    QJsonObject news;
    news["Request"] = "ViewAccountBalance";
    handler.WriteToSocket(news);  // Send request to server to view account balance
}

void MainWindow::on_PBViewAccountBalanceAdmin_clicked()
{
    ui->PBDeleteUserAdmin->setFocus();  // Set focus on the Delete User Admin button
    QString inputText = ui->LEViewAccountBalanceAdmin->text();

    // Validate input as integer using QIntValidator
    QIntValidator validator;
    int pos = 0;  // This will store the position of the first non-numeric character
    QValidator::State state = validator.validate(inputText, pos);

    if ((state == QValidator::Acceptable) && (!inputText.isEmpty()))
    {
        QJsonObject news;
        news["Request"] = "ViewAccountBalance";
        news["accountnumber"] = inputText;
        handler.WriteToSocket(news);  // Send request to server to view account balance for specific account number
        ui->LEViewAccountBalanceAdmin->clear();  // Clear account number input field
    }
    else
    {
        // Handle case where input is not a valid integer
        ui->LWAdmin->addItem("Please enter a valid integer account number.");
        ui->LEViewAccountBalanceAdmin->clear();  // Optionally clear the line edit
        ui->LEViewAccountBalanceAdmin->setFocus();  // Optionally set focus back to the line edit
    }
}

void MainWindow::on_PBLogOutAdmin_14_clicked()
{
    ui->PBLogOutAdmin_14->setFocus();  // Set focus on the Log Out Admin button
    QJsonObject news;
    news["Request"] = "ViewDataBase";
    handler.WriteToSocket(news);  // Send request to server to view database
}

void MainWindow::on_PBDeleteUserAdmin_clicked()
{
    ui->PBDeleteUserAdmin->setFocus();  // Set focus on the Delete User Admin button
    QString inputText = ui->LEDeleteUserAdmin->text();

    // Validate input as integer using QIntValidator
    QIntValidator validator;
    int pos = 0;  // This will store the position of the first non-numeric character
    QValidator::State state = validator.validate(inputText, pos);

    if ((state == QValidator::Acceptable) && (!inputText.isEmpty()))
    {
        QJsonObject news;
        news["Request"] = "DeleteUser";
        news["accountnumber"] = inputText;
        handler.WriteToSocket(news);  // Send request to server to delete user with specified account number
        ui->LEDeleteUserAdmin->clear();  // Clear account number input field
    }
    else
    {
        // Handle case where input is not a valid integer
        ui->LWAdmin->addItem("Please enter a valid integer account number.");
        ui->LEDeleteUserAdmin->clear();  // Optionally clear the line edit
        ui->LEDeleteUserAdmin->setFocus();  // Optionally set focus back to the line edit
    }
}

void MainWindow::on_PBCreateNewUser_clicked()
{
    ui->PBCreateNewUser->setFocus();  // Set focus on the Create New User button
    QJsonObject news;
    news["Request"] = "AddUser";
    news["username"] = ui->LECreateNewUserLogName->text();

    if (isAlphabetic(news["username"].toString(), "^[a-zA-Z]+$") && news["username"].toString().length() > 5)
    {
        news["fullname"] = ui->LEPBCreateNewUserName->text();

        if (isAlphabetic(news["fullname"].toString(), "^[a-zA-Z]+$") && news["fullname"].toString().length() > 5)
        {
            news["password"] = ui->LECreateNewUserPassword->text();

            if (news["password"].toString().length() > 5)
            {
                if (isAlphabetic(ui->LECreateNewUseremail->text(), "[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,}") &&
                    !ui->LECreateNewUseremail->text().isEmpty())
                {
                    news["type"] = "user";
                    news["email"] = ui->LECreateNewUseremail->text();
                    handler.WriteToSocket(news);  // Send request to server to add new user
                    ui->LECreateNewUserPassword->clear();  // Clear password input field
                    ui->LEPBCreateNewUserName->clear();  // Clear full name input field
                    ui->LECreateNewUserLogName->clear();  // Clear username input field
                    ui->LECreateNewUseremail->clear();  // Clear email input field
                }
                else
                {
                    // Handle case where input is not a valid email
                    ui->LWAdmin->addItem("Please enter a valid email.");
                    ui->LECreateNewUseremail->clear();  // Optionally clear the line edit
                    ui->LECreateNewUseremail->setFocus();  // Optionally set focus back to the line edit
                }
            }
            else
            {
                // Handle case where input is not a valid password
                ui->LWAdmin->addItem("Please enter a valid password.");
                ui->LECreateNewUserPassword->clear();  // Optionally clear the line edit
                ui->LECreateNewUserPassword->setFocus();  // Optionally set focus back to the line edit
            }
        }
        else
        {
            // Handle case where input is not a valid full name
            ui->LWAdmin->addItem("Please enter a valid string for full name.");
            ui->LEPBCreateNewUserName->clear();  // Optionally clear the line edit
            ui->LEPBCreateNewUserName->setFocus();  // Optionally set focus back to the line edit
        }
    }
    else
    {
        // Handle case where input is not a valid username
        ui->LWAdmin->addItem("Please enter a valid string for username.");
        ui->LECreateNewUserLogName->clear();  // Optionally clear the line edit
        ui->LECreateNewUserLogName->setFocus();  // Optionally set focus back to the line edit
    }
}


void MainWindow::on_PBMakeTransactionUser_clicked()
{
    ui->PBMakeTransactionUser->setFocus();  // Set focus on the Make Transaction User button
    QString inputText = ui->LEMakeTransactionUser->text();

    // Validate input as integer using QIntValidator
    QIntValidator validator;
    int pos = 0; // This will store the position of the first non-numeric character
    QValidator::State state = validator.validate(inputText, pos);

    if ((state == QValidator::Acceptable) && (!inputText.isEmpty()))
    {
        // Conversion to integer
        int amount = inputText.toInt();
        if (amount != 0)
        {
            // Proceed with sending 'amount' over the network
            QJsonObject news;
            news["Request"] = "MakeTransaction";
            news["amount"] = amount;
            handler.WriteToSocket(news);  // Send request to server to make transaction
            ui->LEMakeTransactionUser->clear();  // Clear transaction amount input field
        }
        else
        {
            // Handle case where input is not a valid integer
            ui->LWUser->addItem("Please enter a valid integer amount.");
            ui->LEMakeTransactionUser->clear();  // Optionally clear the line edit
            ui->LEMakeTransactionUser->setFocus();  // Optionally set focus back to the line edit
        }
    }
    else
    {
        // Handle case where input is not a valid integer
        ui->LWUser->addItem("Please enter a valid integer amount.");
        ui->LEMakeTransactionUser->clear();  // Optionally clear the line edit
        ui->LEMakeTransactionUser->setFocus();  // Optionally set focus back to the line edit
    }
}


void MainWindow::on_PBTransferAmountUser_clicked()
{
    ui->PBTransferAmountUser->setFocus();  // Set focus on the Transfer Amount User button
    QString inputText1 = ui->LETransferAmountUserAcountNumber->text();
    QString inputText2 = ui->LETransferAmountUserAmount->text();

    // Validate account number input as integer using QIntValidator
    QIntValidator validator;
    int pos = 0; // This will store the position of the first non-numeric character
    QValidator::State state1 = validator.validate(inputText1, pos);
    if ((state1 == QValidator::Acceptable) && (!inputText1.isEmpty()))
    {
        // Validate amount input as integer using QIntValidator
        QValidator::State state2 = validator.validate(inputText2, pos);
        if ((state2 == QValidator::Acceptable) && (!inputText2.isEmpty()))
        {
            // Conversion to integer
            int amount = inputText2.toInt();
            if (amount > 0)
            {
                // Proceed with sending 'amount' and 'account number' over the network
                QJsonObject news;
                news["Request"] = "TransferAmount";
                news["amount"] = amount;
                news["accountnumber"] = inputText1;
                handler.WriteToSocket(news);  // Send request to server to transfer amount
                ui->LETransferAmountUserAmount->clear();  // Clear transfer amount input field
                ui->LETransferAmountUserAcountNumber->clear();  // Clear account number input field
            }
            else
            {
                // Handle case where input amount is not valid
                ui->LWUser->addItem("Please enter a valid integer amount.");
                ui->LETransferAmountUserAmount->clear(); // Optionally clear the line edit
                ui->LETransferAmountUserAmount->setFocus(); // Optionally set focus back to the line edit
            }
        }
        else
        {
            // Handle case where input amount is not a valid integer
            ui->LWUser->addItem("Please enter a valid integer amount.");
            ui->LETransferAmountUserAmount->clear(); // Optionally clear the line edit
            ui->LETransferAmountUserAmount->setFocus(); // Optionally set focus back to the line edit
        }
    }
    else
    {
        // Handle case where input account number is not a valid integer
        ui->LWUser->addItem("Please enter a valid account number.");
        ui->LETransferAmountUserAcountNumber->clear(); // Optionally clear the line edit
        ui->LETransferAmountUserAcountNumber->setFocus(); // Optionally set focus back to the line edit
    }
}


void MainWindow::on_PBViewTransactionHistoryUser_clicked()
{
    ui->PBViewTransactionHistoryUser->setFocus();  // Set focus on the View Transaction History User button
    QJsonObject news;
    news["Request"] = "ViewTransactionHistory";
    news["count"] = ui->CBCount_2->currentText().toInt();  // Retrieve selected count from combo box
    handler.WriteToSocket(news);  // Send request to server to view transaction history
}


void MainWindow::on_PBViewTransactionHistoryAdmin_clicked()
{
    ui->PBViewTransactionHistoryAdmin->setFocus();  // Set focus on the View Transaction History Admin button
    QString inputText = ui->LEViewTransactionHistoryAdmin->text();

    // Validate input as integer using QIntValidator
    QIntValidator validator;
    int pos = 0; // This will store the position of the first non-numeric character
    QValidator::State state = validator.validate(inputText, pos);

    if ((state == QValidator::Acceptable) && (!inputText.isEmpty()))
    {
        // Proceed with sending 'account number' and 'count' over the network
        QJsonObject news;
        news["Request"] = "ViewTransactionHistory";
        news["accountnumber"] = inputText;
        news["count"] = ui->CBCount->currentText().toInt();  // Retrieve selected count from combo box
        handler.WriteToSocket(news);  // Send request to server to view transaction history for specific account number
        ui->LEViewTransactionHistoryAdmin->clear();  // Clear account number input field
    }
    else
    {
        // Handle case where input account number is not a valid integer
        ui->LWAdmin->addItem("Please enter a valid integer account number.");
        ui->LEViewTransactionHistoryAdmin->clear(); // Optionally clear the line edit
        ui->LEViewTransactionHistoryAdmin->setFocus(); // Optionally set focus back to the line edit
    }
}

void MainWindow::on_PBUpdateNewUser_clicked()
{
    ui->PBUpdateNewUser->setFocus();  // Set focus on the Update New User button
    QJsonObject news;
    QString inputText = ui->LEUpdateaccoutnnumber->text();  // Retrieve account number input
    QString inputText2 = ui->LEUpdateNewUserBalance->text();  // Retrieve balance input

    QIntValidator validator;
    int pos = 0;
    QValidator::State state = validator.validate(inputText, pos);  // Validate account number as integer
    QValidator::State state2 = validator.validate(inputText2, pos);  // Validate balance as integer

    if ((state == QValidator::Acceptable) && (!inputText.isEmpty()))
    {
        news["Request"] = "UpdateUser";
        news["accountnumber"] = ui->LEUpdateaccoutnnumber->text();  // Set account number in request

        if ((state2 == QValidator::Acceptable) || (ui->LEUpdateNewUserBalance->text() == ""))
        {
            news["balance"] = ui->LEUpdateNewUserBalance->text();  // Set balance in request

            if ((isAlphabetic(ui->LEPBUpdateNewUser->text(), "^[a-zA-Z]+$") && ui->LEPBUpdateNewUser->text().length() > 5)
                || ui->LEPBUpdateNewUser->text() == "")
            {
                news["username"] = ui->LEPBUpdateNewUser->text();  // Set username in request

                if ((isAlphabetic(ui->LEPBUpdateNewUserName->text(), "^[a-zA-Z]+$") && ui->LEPBUpdateNewUserName->text().length() > 5)
                    || ui->LEPBUpdateNewUserName->text() == "")
                {
                    news["fullname"] = ui->LEPBUpdateNewUserName->text();  // Set full name in request

                    if (isAlphabetic(ui->LEUpdateemail->text(), "[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,}")
                        || ui->LEUpdateemail->text() == "")
                    {
                        news["email"] = ui->LEUpdateemail->text();  // Set email in request

                        if (ui->LEUpdateNewUserPassword->text().length() > 5 || ui->LEUpdateNewUserPassword->text() == "")
                        {
                            news["password"] = ui->LEUpdateNewUserPassword->text();  // Set password in request
                            news["type"] = "user";  // Set user type in request

                            handler.WriteToSocket(news);  // Send update request to server
                            // Clear all input fields after successful update
                            ui->LEPBUpdateNewUserName->clear();
                            ui->LEPBUpdateNewUser->clear();
                            ui->LEUpdateNewUserBalance->clear();
                            ui->LEUpdateaccoutnnumber->clear();
                            ui->LEUpdateNewUserPassword->clear();
                        }
                        else
                        {
                            // Handle case where password input is not valid
                            ui->LWAdmin->addItem("Please enter a valid password.");
                            ui->LEUpdateNewUserPassword->clear();  // Optionally clear the line edit
                            ui->LEUpdateNewUserPassword->setFocus();  // Optionally set focus back to the line edit
                        }
                    }
                    else
                    {
                        // Handle case where email input is not valid
                        ui->LWAdmin->addItem("Please enter a valid email.");
                        ui->LEUpdateemail->clear();  // Optionally clear the line edit
                        ui->LEUpdateemail->setFocus();  // Optionally set focus back to the line edit
                    }
                }
                else
                {
                    // Handle case where full name input is not valid
                    ui->LWAdmin->addItem("Please enter a valid full name.");
                    ui->LEPBUpdateNewUserName->clear();  // Optionally clear the line edit
                    ui->LEPBUpdateNewUserName->setFocus();  // Optionally set focus back to the line edit
                }
            }
            else
            {
                // Handle case where username input is not valid
                ui->LWAdmin->addItem("Please enter a valid username.");
                ui->LEPBUpdateNewUser->clear();  // Optionally clear the line edit
                ui->LEPBUpdateNewUser->setFocus();  // Optionally set focus back to the line edit
            }
        }
        else
        {
            // Handle case where balance input is not valid
            ui->LWAdmin->addItem("Please enter a valid balance.");
            ui->LEUpdateNewUserBalance->clear();  // Optionally clear the line edit
            ui->LEUpdateNewUserBalance->setFocus();  // Optionally set focus back to the line edit
        }
    }
    else
    {
        // Handle case where account number input is not valid
        ui->LWAdmin->addItem("Please enter a valid account number.");
        ui->LEUpdateaccoutnnumber->clear();  // Optionally clear the line edit
        ui->LEUpdateaccoutnnumber->setFocus();  // Optionally set focus back to the line edit
    }
}

bool MainWindow::isAlphabetic(const QString &str, QString str1)
{
    QRegularExpression regex(str1);  // Regular expression to match alphabetic characters only
    return regex.match(str).hasMatch();  // Return true if str matches the regular expression
}
