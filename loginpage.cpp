#include "loginpage.h"
#include "ui_loginpage.h"
#include "mainwindow.h"
#include<QMessageBox>

LogInPage::LogInPage(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::LogInPage)
{
    ui->setupUi(this);
    ui->lineEdit_pass->setPlaceholderText("Password");
    ui->lineEdit_user->setPlaceholderText("Username");
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



void LogInPage::on_logIn_clicked()
{
    QString user = ui->lineEdit_user->text();
    QString pass = ui->lineEdit_pass->text();

    if(user == "test" && pass == "test")
    {
        QWidget* parentWindow = this->parentWidget();
        parentWindow->close();
        close();
        mainW = new MainWindow(this);
        mainW->show();
    }
    else
    {
        QMessageBox::warning(this, "Log In", "Username or password incorrect!");
    }
}


void LogInPage::on_checkBox_2_stateChanged(int arg1)
{
    if(arg1)
        ui->lineEdit_pass->setEchoMode(QLineEdit::Normal);
    else
        ui->lineEdit_pass->setEchoMode(QLineEdit::Password);
}

