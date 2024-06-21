#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QToolBar>
#include <QScreen>
#include<QStringList>
#include <QJsonArray>
#include<teams.h>
#include <c_engineers.h>
#include <c_drivers.h>
#include <c_manager.h>
#include<circuits.h>
#include<merchshop.h>
#include <test.h>
#include <ticketswindow.h>
#include <grandprixwindow.h>
#include <profilewindow.h>
#include "c_circuits.h"
#include <QPixmap>


MainWindow::MainWindow(C_User* user, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    if (m_dbConnector.connectToDatabase(R"(DESKTOP-RTLB2TI\SQLEXPRESS)", "Formula1nou")) {
        //qDebug() << "Connected to database successfully!";
    } else {
        //qDebug() << "Failed to connect to database!";
    }

    this->server = ServerConnection::getInstance();

    connect(this->server, &ServerConnection::sendTeamsWindowPersonnel, this, &MainWindow::handlePersonnelTeamsWindowResponse);
    connect(this->server, &ServerConnection::sendTeamsWindowTeams, this, &MainWindow::handleTeamsTeamsWindowResponse);
    connect(this->server, &ServerConnection::sendCircuit1Window, this, &MainWindow::handleCircuit1WindowResponse);
    connect(this->server, &ServerConnection::sendCircuit2Window, this, &MainWindow::handleCircuit2WindowResponse);
    connect(this->server, &ServerConnection::sendTicketsWindow, this, &MainWindow::handleTicketsWindowResponse);

    ui->setupUi(this);
    this->user = user;

    this->setStyleSheet("QMainWindow {"
                        "background-color: #000000;"
                        "}");

    this->backgroundLabel = new QLabel(this);
    QPixmap backgroundPixmap(":/img/F1-Logo.png");

    backgroundLabel->setPixmap(backgroundPixmap);
    backgroundLabel->setScaledContents(true);
    backgroundLabel->resize(this->size());

    backgroundLabel->lower();

    ui->toolBar->setMovable(false);

    centerWindow(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionTeams_triggered()
{
    this->server->teamsWindowFunctionTeams();
}

void MainWindow::handlePersonnelTeamsWindowResponse(const QJsonObject &response)
{
    QJsonArray personnelArray = response["personnel"].toArray();
    for(const auto& personnelValue : personnelArray)
    {
        QJsonObject personnelObj = personnelValue.toObject();
        if(personnelObj["Position"]=="Driver")
        {
            C_Drivers* driver = C_Drivers::deserialize(personnelObj);
            //driver->print();
            personnel.push_back(driver);
        }
        else
            if(personnelObj["Position"]=="Engineer")
            {
                C_Engineers* engineer = C_Engineers::deserialize(personnelObj);
           // engineer->print();
                personnel.push_back(engineer);
            }
            else
                if(personnelObj["Position"]=="Manager")
                {
                    C_Manager* manager = C_Manager::deserialize(personnelObj);
                    //manager->print();
                    personnel.push_back(manager);
                }
    }
    this->teamsW = new Teams(personnel, teams);
    this->teamsW->setAttribute(Qt::WA_DeleteOnClose);
    this->teamsW->showMaximized();
}

void MainWindow::handleTeamsTeamsWindowResponse(const QJsonObject &response)
{
    QJsonArray teamsArray = response["teams"].toArray();
    for(const auto& teamsValue : teamsArray)
    {
        QJsonObject teamsObj = teamsValue.toObject();
        C_Teams* team = C_Teams::deserialize(teamsObj);
        //team->print();
        teams.push_back(team);
    }

    this->server->teamsWindowFunctionPersonnel();
}

void MainWindow::handleCircuit1WindowResponse(const QJsonObject &response)
{
    QJsonArray circArray = response["circuits"].toArray();
    for(const auto& circValue : circArray)
    {
        QJsonObject circObj = circValue.toObject();
        C_Circuits* circ = C_Circuits::deserialize(circObj);
        circuits.push_back(circ);
    }
    this->server->circuit2WindowFunction();
}

void MainWindow::handleCircuit2WindowResponse(const QJsonObject &response)
{
    QJsonArray circArray = response["circuits"].toArray();
    for(const auto& circValue : circArray)
    {
        QJsonObject circObj = circValue.toObject();
        C_Circuits* circ = C_Circuits::deserialize(circObj);
        circuits.push_back(circ);
    }
    circuitsW = new Circuits(circuits, this);
    circuitsW->setAttribute(Qt::WA_DeleteOnClose);
    circuitsW->showMaximized();
}

void MainWindow::handleTicketsWindowResponse(const QJsonObject &response)
{
    QJsonArray ticketArray = response["tickets"].toArray();
    for (const auto& ticketValue : ticketArray)
    {
        QJsonObject ticketObj = ticketValue.toObject();
        int ticketType = ticketObj["ttype"].toInt();
        ITickets* ticket = nullptr;
        switch (ticketType) {
        case 1:
            ticket = Day1Tickets::deserialize(ticketObj);
            break;
        case 2:
            ticket = Day2Tickets::deserialize(ticketObj);
            break;
        case 3:
            ticket = RaceDayTickets::deserialize(ticketObj);
            break;
        case 4:
            ticket = FATickets::deserialize(ticketObj);
            break;
        default:
            qDebug() << "Unknown ticket type:" << ticketType;
            break;
        }
        if(ticket)
        {
            this->tickets.push_back(ticket);
        }
        else
        {
            qDebug()<<"Atentie! Un ticket nu a fost introdus!";
        }
    }

    ticketsW = new ticketsWindow(user, m_dbConnector.getDatabase(), this);
    ticketsW->setAttribute(Qt::WA_DeleteOnClose);
    ticketsW->showMaximized();
}


void MainWindow::on_actionCircuits_triggered()
{
    this->server->circuit1WindowFunction();
}

void MainWindow::on_actionMerch_Shop_triggered()
{
    merchsopW = new MerchShop(m_dbConnector.getDatabase(), this);
    merchsopW->setAttribute(Qt::WA_DeleteOnClose);
    merchsopW->showMaximized();
}

void MainWindow::on_actionGrand_Prix_triggered()
{
    gpW = new GrandPrixWindow(m_dbConnector.getDatabase(), this);
    gpW->setAttribute(Qt::WA_DeleteOnClose);
    gpW->showMaximized();
}


void MainWindow::on_actionTickets_triggered()
{
    this->server->ticketsWindow();
}

void MainWindow::on_actionProfile_triggered()
{
    pfW = new ProfileWindow(user, this);
    pfW->showMaximized();
}
