#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QToolBar>
#include <QScreen>
#include<QStringList>
#include<teams.h>
#include<circuits.h>
#include<merchshop.h>
#include <test.h>
#include <ticketswindow.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    if (m_dbConnector.connectToDatabase("DESKTOP-RTLB2TI\\SQLEXPRESS", "Formula1nou")) {
        qDebug() << "Connected to database successfully!";
    } else {
        qDebug() << "Failed to connect to database!";
    }

    ui->setupUi(this);

    ui->toolBar->setMovable(false);

    circuitsW = new Circuits(m_dbConnector.getDatabase(),this);
    merchsopW = new MerchShop(m_dbConnector.getDatabase(), this);

    centerWindow(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::handleTeamsWindowDestroyed()
{
    this->teamsW = nullptr;
}

void MainWindow::on_actionTeams_triggered()
{
    teamsW = new Teams(m_dbConnector.getDatabase(), this);
    teamsW->show();
    //connect(teamsW, &Teams::destroyed, this, &MainWindow::handleTeamsWindowDestroyed);
}

void MainWindow::on_actionCircuits_triggered()
{
    circuitsW->show();
}

void MainWindow::on_actionMerch_Shop_triggered()
{
    merchsopW->show();
}

void MainWindow::on_actionTickets_triggered()
{
    ticketsW = new ticketsWindow(m_dbConnector.getDatabase(), this);
    ticketsW->show();
}
