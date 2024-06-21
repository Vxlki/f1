#include "signinpage.h"
#include "ui_signinpage.h"
#include "serverconnection.h"
#include "c_user.h"
#include "mainwindow.h"
#include <QMessageBox>

void SignInPage::handleSignInResponse(const QJsonObject &response)
{
    C_User* user = C_User::deserialize(response);

    QMessageBox msgBox;
    msgBox.setIcon(QMessageBox::Information);
    msgBox.setText("Te-ai inregistrat cu succes!");
    msgBox.exec();

    this->mainW = new MainWindow(user);
    this->close();
    this->mainW->showMaximized();
}

SignInPage::SignInPage(std::vector<I_Personnel*> drivers, std::vector<C_Teams*> teams, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SignInPage)
{
    ui->setupUi(this);

    this->teams = teams;
    this->drivers = drivers;

    this->conexiuneServer = ServerConnection::getInstance();

    ui->lineEdit_user->setPlaceholderText("Username");
    ui->lineEdit_pass->setPlaceholderText("Password");
    ui->lineEdit_cpass->setPlaceholderText("Confirm password");
    ui->lineEdit_mail->setPlaceholderText("Mail");
    ui->lineEdit_tele->setPlaceholderText("Telephone");

    this->populateComboBoxes();

    connect(ui->comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(onComboSelectionChanged(int)));
    connect(ui->comboBox_2, SIGNAL(currentIndexChanged(int)), this, SLOT(onCombo2SelectionChanged(int)));
    connect(ui->comboBox_3, SIGNAL(currentIndexChanged(int)), this, SLOT(onCombo3SelectionChanged(int)));
    connect(ui->comboBox_4, SIGNAL(currentIndexChanged(int)), this, SLOT(onCombo4SelectionChanged(int)));
    connect(ui->comboBox_5, SIGNAL(currentIndexChanged(int)), this, SLOT(onCombo5SelectionChanged(int)));

    connect(this->conexiuneServer, &ServerConnection::sendSignInResponse, this, &SignInPage::handleSignInResponse);
    qDebug()<<"CONSTRUCTOR GOOD";
}

SignInPage::~SignInPage()
{
    delete ui;
}

void SignInPage::on_back_clicked()
{
    this->close();
    QWidget* parentWindow = this->parentWidget();
    parentWindow->show();
}


void SignInPage::on_SignIn_clicked()
{
    QString user = ui->lineEdit_user->text();
    QString pass = ui->lineEdit_pass->text();
    QString cpass = ui->lineEdit_cpass->text();
    QString mail = ui->lineEdit_mail->text();
    QString tele = ui->lineEdit_tele->text();
    int team1Index = ui->comboBox->currentIndex();
    QString team1 = ui->comboBox->itemText(team1Index);
    int team2Index = ui->comboBox_2->currentIndex();
    QString team2 = ui->comboBox_2->itemText(team2Index);
    int driver1Index = ui->comboBox_3->currentIndex();
    QString driver1 = ui->comboBox_3->itemText(driver1Index);
    int driver2Index = ui->comboBox_4->currentIndex();
    QString driver2 = ui->comboBox_4->itemText(driver2Index);
    int driver3Index = ui->comboBox_5->currentIndex();
    QString driver3 = ui->comboBox_5->itemText(driver3Index);


    std::vector<C_Teams*> favTeams;
    std::vector<C_Drivers*> favDrivers;

    for (const auto& team : teams)
    {
        if(team->teamName() == team1)
            favTeams.push_back(team);
        if(team->teamName() == team2)
            favTeams.push_back(team);
    }

    for (const auto& driver : drivers)
    {
        if(driver->getFirstName() + " " + driver->getLastName() == driver1)
            favDrivers.push_back(dynamic_cast<C_Drivers*>(driver));
        if(driver->getFirstName() + " " + driver->getLastName() == driver2)
            favDrivers.push_back(dynamic_cast<C_Drivers*>(driver));
        if(driver->getFirstName() + " " + driver->getLastName() == driver3)
            favDrivers.push_back(dynamic_cast<C_Drivers*>(driver));
    }
    C_User* user1 = new C_User(user, pass, mail, tele, 0, favDrivers, favTeams);
    this->conexiuneServer->signIn(user1);
}

void SignInPage::on_checkBox_stateChanged(int arg1)
{
    if(arg1)
    {
        ui->lineEdit_pass->setEchoMode(QLineEdit::Normal);
        ui->lineEdit_cpass->setEchoMode(QLineEdit::Normal);
    }
    else
    {
        ui->lineEdit_pass->setEchoMode(QLineEdit::Password);
        ui->lineEdit_cpass->setEchoMode(QLineEdit::Password);
    }
}

void SignInPage::onComboSelectionChanged(int index)
{
    QString selected = ui->comboBox->itemText(index);
}

void SignInPage::onCombo2SelectionChanged(int index)
{
    QString selected= ui->comboBox_2->itemText(index);
}

void SignInPage::onCombo3SelectionChanged(int index)
{
    QString selected = ui->comboBox_3->itemText(index);
}

void SignInPage::onCombo4SelectionChanged(int index)
{
    QString selected = ui->comboBox_4->itemText(index);
}

void SignInPage::onCombo5SelectionChanged(int index)
{
    QString selected = ui->comboBox_5->itemText(index);
}

void SignInPage::populateComboBoxes()
{
    for (const auto& team : teams)
    {
        ui->comboBox->addItem(team->teamName());
    }
    for (const auto& team : teams)
    {
        ui->comboBox_2->addItem(team->teamName());
    }
    for (const auto& driver : drivers)
    {
        ui->comboBox_3->addItem(driver->getFirstName() + " " + driver->getLastName());
    }
    for (const auto& driver : drivers)
    {
        ui->comboBox_4->addItem(driver->getFirstName() + " " + driver->getLastName());
    }
    for (const auto& driver : drivers)
    {
        ui->comboBox_5->addItem(driver->getFirstName() + " " + driver->getLastName());
    }
}

