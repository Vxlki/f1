#include "loginpage.h"
#include "serverconnection.h"
#include "ui_loginpage.h"
#include "mainwindow.h"
#include <QMessageBox>
#include <QSqlDatabase>
#include <QJsonObject>
#include <QJsonDocument>
#include "c_user.h"
#include <QFile>
#include <QStandardPaths>

bool LogInPage::rememberMe = false;

LogInPage::LogInPage(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::LogInPage)
{
    ui->setupUi(this);
    ui->lineEdit_pass->setPlaceholderText("Password");
    ui->lineEdit_user->setPlaceholderText("Username");
    ui->lineEdit_pass->setEchoMode(QLineEdit::Password);

    this->autoLogger = new AutoLogIn;

    this->conexiuneServer = ServerConnection::getInstance();

    connect(this->conexiuneServer, &ServerConnection::sendLogInResponse, this, &LogInPage::handleLogInResponse);
}

LogInPage::~LogInPage()
{
    delete ui;
}

void LogInPage::on_back_clicked()
{
    hide();
    QWidget* parentWindow = this->parentWidget();
    parentWindow->show();
}

void LogInPage::handleLogInResponse(const QJsonObject& response)
{
    C_User* user = C_User::deserialize(response);
    user->print();

    QString filePath = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation) + "/autologger.txt";
    QFile file(filePath);

    if(rememberMe)
    {
        if (file.open(QIODevice::Append | QIODevice::Text))
        {
            QTextStream out(&file);
            out<<user->getMail()<<"\n";
            out<<user->getTele()<<"\n";
            std::vector<C_Drivers*> drivers = user->getSoferi();
            for(int i=0;i<drivers.size();i++)
            {
                out << drivers[i]->getLastName() + " " + drivers[i]->getFirstName() << "\n";
            }
            std::vector<C_Teams*> teams = user->getTeams();
            for(int i=0;i<teams.size();i++)
            {
                out << teams[i]->teamName()<<"\n";
            }
            file.close();
        }
    }
    else
    {
        file.open(QIODevice::WriteOnly | QIODevice::Text);
        file.close();
    }

    this->mainW = new MainWindow(user);
    this->mainW->setAttribute(Qt::WA_DeleteOnClose);
    this->close();
    this->mainW->showMaximized();
}


void LogInPage::on_checkBox_2_stateChanged(int arg1)
{
    if(arg1)
        ui->lineEdit_pass->setEchoMode(QLineEdit::Normal);
    else
        ui->lineEdit_pass->setEchoMode(QLineEdit::Password);
}

bool LogInPage::on_checkBox_stateChanged(int arg1)
{
    if(arg1)
        return true;
    else
        return false;
}

void LogInPage::on_logIn_clicked()
{
    QString username = ui->lineEdit_user->text();
    QString pass = ui->lineEdit_pass->text();

    rememberMe = ui->checkBox->isChecked();

    QString filePath = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation) + "/autologger.txt";
    QFile file(filePath);
    if (rememberMe)
    {
        qDebug() << filePath;
        if (file.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            QTextStream out(&file);
            out << username << "\n";
            out << pass << "\n";
            file.close();
            if(this->autoLogger->citireFisier())
                return;
        }
        else
        {
            qDebug() << "Nu s-a putut deschide fișierul pentru scriere.";
        }
    }
    else
    {
        file.open(QIODevice::WriteOnly | QIODevice::Text);
        file.close();
        this->conexiuneServer->logIn(username, pass);
    }
}

