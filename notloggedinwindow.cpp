#include "notloggedinwindow.h"
#include "ui_notloggedinwindow.h"
#include "loginpage.h"
#include "signinpage.h"
#include "c_drivers.h"
#include <QPixmap>

void notLoggedInWindow::handlePersonnelResponse(const QJsonObject &response)
{
    QJsonArray personnelArray = response["personnel"].toArray();
    for(const auto& personnelValue : personnelArray)
    {
        QJsonObject personnelObj = personnelValue.toObject();
        if(personnelObj["Position"]=="Driver")
        {
            C_Drivers* driver = C_Drivers::deserialize(personnelObj);
            driver->print();
            this->drivers.push_back(driver);
        }
    }
    signinW = new SignInPage(this->drivers, this->teams, this);
    signinW->setAttribute(Qt::WA_DeleteOnClose);
    signinW->show();
}

void notLoggedInWindow::handleTeamsResponse(const QJsonObject &response)
{
    QJsonArray teamsArray = response["teams"].toArray();
    for(const auto& teamsValue : teamsArray)
    {
        QJsonObject teamsObj = teamsValue.toObject();
        C_Teams* team = C_Teams::deserialize(teamsObj);
        team->print();
        teams.push_back(team);
    }
    this->conexiuneServer->personnelFunctionRegister();
}

notLoggedInWindow::notLoggedInWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::notLoggedInWindow)
{
    ui->setupUi(this);


    QPixmap pix (":/img/F1-Logo.png");
    int w = ui->piclabel->width();
    int h = ui->piclabel->height();

    this->conexiuneServer = ServerConnection::getInstance();

    ui->piclabel->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));

    connect(this->conexiuneServer, &ServerConnection::sendTeamsFunctionRegister, this, &notLoggedInWindow::handleTeamsResponse);
    connect(this->conexiuneServer, &ServerConnection::sendPersonnelFunctionRegister, this, &notLoggedInWindow::handlePersonnelResponse);
}

notLoggedInWindow::~notLoggedInWindow()
{
    delete ui;
}

void notLoggedInWindow::on_LogIn_clicked()
{
    hide();
    loginW = new LogInPage(this);
    loginW->setAttribute(Qt::WA_DeleteOnClose);
    loginW->show();
}


void notLoggedInWindow::on_SignIn_clicked()
{
    hide();
    this->conexiuneServer->teamsFunctionRegister();
}

