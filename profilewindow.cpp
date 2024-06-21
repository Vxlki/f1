#include "profilewindow.h"
#include "ui_profilewindow.h"
#include <QStandardPaths>
#include <QFile>
#include <notloggedinwindow.h>



void ProfileWindow::handleChangePassword(const QJsonObject &obj)
{
    QMessageBox msgBox;
    msgBox.setIcon(QMessageBox::Information);
    msgBox.setText("Parola a fost schimbata cu succes!");
    msgBox.exec();
}

ProfileWindow::ProfileWindow(C_User* user, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ProfileWindow)
{
    ui->setupUi(this);

    this->server = ServerConnection::getInstance();

    connect(this->server, &ServerConnection::sendChangePassword, this, &ProfileWindow::handleChangePassword);

    this->centralWidget = new QWidget(this);
    this->setCentralWidget(this->centralWidget);
    this->stackedLayout = new QStackedLayout(this->centralWidget);
    this->mainLayout = new QFormLayout(this->centralWidget);
    this->driversLayout = new QVBoxLayout;
    this->teamsLayout = new QVBoxLayout;
    this->seeTicketsButton = new QPushButton("See tickets");
    this->changePasswordButton = new QPushButton("Change password");
    this->disconnectButton = new QPushButton("Disconnect");
    connect(this->seeTicketsButton, &QPushButton::clicked, this, &ProfileWindow::onSeeTicketsButtonClicked);
    connect(this->changePasswordButton, &QPushButton::clicked, this, &ProfileWindow::onChgPasswordButtonClicked);
    connect(this->disconnectButton, &QPushButton::clicked, this, &ProfileWindow::onDisconnectButtonClicked);
    this->mainPageWidget = new QWidget;
    mainPageWidget->setLayout(this->mainLayout);
    this->stackedLayout->addWidget(mainPageWidget);

    this->user = user;
    this->username = user->getUsername();
    this->password = user->getPassword();
    this->telephone = user->getTele();
    this->mail = user->getMail();
    this->tickets = user->getTickets();
    this->soferi_preferati = user->getSoferi();
    this->echipe_preferate = user->getTeams();


    this->mainLayout->setAlignment(Qt::AlignHCenter);
    this->mainLayout->setContentsMargins(50, 50, 50, 50);
    this->mainLayout->setSpacing(20);
    this->mainLayout->minimumSize();

    this->makeWindow();
    this->mainLayout->addRow(this->seeTicketsButton, this->changePasswordButton);
    this->mainLayout->addWidget(this->disconnectButton);
    this->createTicketsWindow();
    this->createChgPasswordWindow();
}


void ProfileWindow::makeWindow()
{
    this->labelStyle = "font: bold 12pt Arial; "
                         "border-radius: 10px; "
                         "background: #af0034; "
                         "padding: 3px;";

    QLabel* usernameLabel = new QLabel("Username:");
    QLineEdit* usernameValue = new QLineEdit(this->username);
    usernameValue->setReadOnly(true);
    this->labels.push_back(usernameLabel);
    //this->labels.push_back(usernameValue);

    QLabel* passwordLabel = new QLabel("Password:");
    QLineEdit* passwordValue = new QLineEdit(this->password);
    passwordValue->setEchoMode(QLineEdit::Password);
    passwordValue->setReadOnly(true);
    this->labels.push_back(passwordLabel);
    //this->labels.push_back(passwordValue);

    QLabel* telephoneLabel = new QLabel("Telephone:");
    QLineEdit* telephoneValue = new QLineEdit(this->telephone);
    telephoneValue->setReadOnly(true);
    this->labels.push_back(telephoneLabel);
    //this->labels.push_back(telephoneValue);

    QLabel* mailLabel = new QLabel("Mail:");
    QLineEdit* mailValue = new QLineEdit(this->mail);
    this->labels.push_back(mailLabel);
    //this->labels.push_back(mailValue);

    QLabel* driversLabel = new QLabel("Preferred Drivers:");
    QWidget* driversWidget = new QWidget;
    driversWidget->setLayout(this->driversLayout);
    this->labels.push_back(driversLabel);

    QLabel* teamsLabel = new QLabel("Preferred Teams:");
    QWidget* teamsWidget = new QWidget;
    teamsWidget->setLayout(this->teamsLayout);
    this->labels.push_back(teamsLabel);

    this->mainLayout->addRow(usernameLabel, usernameValue);
    this->mainLayout->addRow(passwordLabel, passwordValue);
    this->mainLayout->addRow(telephoneLabel, telephoneValue);
    this->mainLayout->addRow(mailLabel, mailValue);
    this->mainLayout->addRow(driversLabel, driversWidget);
    this->mainLayout->addRow(teamsLabel, teamsWidget);

    for (int i=0;i<this->soferi_preferati.size();i++)
    {
        QString driverName = this->soferi_preferati[i]->getFirstName() + " " + this->soferi_preferati[i]->getLastName();
        QLineEdit* driverLabel = new QLineEdit(driverName);
        driverLabel->setReadOnly(true);
        this->driversLayout->addWidget(driverLabel);
        //this->labels.push_back(driverLabel);
    }

    for (int i=0;i<this->echipe_preferate.size();i++)
    {
        QString teamName = this->echipe_preferate[i]->teamName();
        QLineEdit* teamLabel = new QLineEdit(teamName);
        teamLabel->setReadOnly(true);
        this->teamsLayout->addWidget(teamLabel);
        //this->labels.push_back(teamLabel);
    }
    for(int i=0;i<this->labels.size();i++)
    {
        this->labels[i]->setStyleSheet(labelStyle);
    }
}

void ProfileWindow::createTicketsWindow()
{
    if(this->tickets.empty())
        return;
    else
    {
        this->ticketsWindow = new QWidget(this->centralWidget);
        this->ticketsLayout = new QVBoxLayout(this->ticketsWindow);
        QLabel* ticketsLabel = new QLabel("Your tickets");

        this->labels.push_back(ticketsLabel);
        this->ticketsLayout->addWidget(ticketsLabel);
        this->stackedLayout->addWidget(this->ticketsWindow);

        ticketsLabel->setStyleSheet(labelStyle);
        ticketsLabel->setAlignment(Qt::AlignCenter);

        for(int i=0;i<this->tickets.size();i++)
        {
            TicketFrame* frame = new TicketFrame(this->tickets[i], this->user);
            this->ticketsFrame.push_back(frame);
            this->ticketsLayout->addWidget(frame);
        }
        QPushButton* backButton = new QPushButton("Back to profile");
        connect(backButton, &QPushButton::clicked, this, &ProfileWindow::onBackFromTicketsButtonClicked);
        this->ticketsLayout->addWidget(backButton);
    }
}

void ProfileWindow::createChgPasswordWindow()
{
    this->chgPassWindow = new QWidget(this->centralWidget);
    this->chgPassLayout = new QFormLayout(this->chgPassWindow);
    this->stackedLayout->addWidget(this->chgPassWindow);

    QLabel* label = new QLabel("Change password");
    label->setStyleSheet(this->labelStyle); // Folosește labelStyle pentru a aplica stilul
    label->setAlignment(Qt::AlignCenter);
    this->chgPassLayout->addWidget(label);

    QLabel* newPasswordLabel = new QLabel("Parolă nouă:");
    newPasswordLabel->setStyleSheet(this->labelStyle);
    QLineEdit* newPasswordEdit = new QLineEdit;
    newPasswordEdit->setEchoMode(QLineEdit::Password);
    chgPassLayout->addRow(newPasswordLabel, newPasswordEdit);

    QLabel* confirmPasswordLabel = new QLabel("Confirma parola noua:");
    confirmPasswordLabel->setStyleSheet(this->labelStyle);
    QLineEdit* confirmPasswordEdit = new QLineEdit;
    confirmPasswordEdit->setEchoMode(QLineEdit::Password);
    chgPassLayout->addRow(confirmPasswordLabel, confirmPasswordEdit);

    QPushButton* submitButton = new QPushButton("Schimbă parola");
    QPushButton* showNewP = new QPushButton("Afiseaza parolele");
    connect(submitButton, &QPushButton::clicked, [=]() {
        QString newPassword = newPasswordEdit->text();
        QString confirmedPassword = confirmPasswordEdit->text();
        this->changePassword(newPassword, confirmedPassword);
    });

    connect(showNewP, &QPushButton::pressed, [newPasswordEdit, confirmPasswordEdit]() {
        newPasswordEdit->setEchoMode(QLineEdit::Normal);
        confirmPasswordEdit->setEchoMode(QLineEdit::Normal);
    });

    connect(showNewP, &QPushButton::released, [newPasswordEdit, confirmPasswordEdit]() {
        newPasswordEdit->setEchoMode(QLineEdit::Password);
        confirmPasswordEdit->setEchoMode(QLineEdit::Password);
    });


    chgPassLayout->addWidget(submitButton);
    chgPassLayout->addWidget(showNewP);
}


void ProfileWindow::onSeeTicketsButtonClicked()
{
    if(this->tickets.empty())
    {
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setText("Nu aveti bilete cumparate!");
        msgBox.exec();
    }
    else
        this->stackedLayout->setCurrentWidget(this->ticketsWindow);
}

void ProfileWindow::onChgPasswordButtonClicked()
{
    this->stackedLayout->setCurrentWidget(this->chgPassWindow);
}

void ProfileWindow::onBackFromTicketsButtonClicked()
{
    this->stackedLayout->setCurrentWidget(this->mainPageWidget);
}

void ProfileWindow::changePassword(QString newp, QString confirmp)
{
    if(newp == confirmp)
    {
        this->user->changePassword(newp);
        this->server->changePassword(*(this->user));
        this->stackedLayout->setCurrentWidget(this->mainPageWidget);
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setText("Parola nu a fost schimbata! Parolele nu coincid!");
        msgBox.exec();
    }
}

void ProfileWindow::onDisconnectButtonClicked()
{
    QString filePath = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation) + "/autologger.txt";
    QFile file(filePath);

    file.open(QIODevice::WriteOnly | QIODevice::Text);
    file.close();

    QWidget* parentWidget = this->parentWidget();
    parentWidget->close();
    this->close();
}

ProfileWindow::~ProfileWindow()
{
    delete ui;
}
