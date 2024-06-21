#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include "serverconnection.h"
#include"abstractwindow.h"
#include"databaseconnector.h"
#include "c_user.h"
#include "c_circuits.h"
#include "itickets.h"

class MerchShop;
class Teams;
class Circuits;
class Test;
class ticketsWindow;
class GrandPrixWindow;
class ProfileWindow;

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow, AbstractWindow
{
    Q_OBJECT

public:
    MainWindow(C_User* user, QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionTeams_triggered();
    void on_actionCircuits_triggered();
    void on_actionMerch_Shop_triggered();
    void on_actionGrand_Prix_triggered();
    void on_actionTickets_triggered();
    void on_actionProfile_triggered();

public slots:
    void handlePersonnelTeamsWindowResponse(const QJsonObject& response);
    void handleTeamsTeamsWindowResponse(const QJsonObject& response);
    void handleCircuit1WindowResponse(const QJsonObject& response);
    void handleCircuit2WindowResponse(const QJsonObject& response);
    void handleTicketsWindowResponse(const QJsonObject& response);
private:
    static int circuitCounter;

    Ui::MainWindow *ui;
    Teams* teamsW;
    Circuits* circuitsW;
    MerchShop* merchsopW;
    Test* testW;
    ticketsWindow* ticketsW;
    GrandPrixWindow* gpW;
    ProfileWindow* pfW;
    QLabel* backgroundLabel;
    std::vector<I_Personnel*> personnel;
    std::vector<C_Teams*> teams;
    std::vector<C_Circuits*> circuits;
    std::vector<ITickets*> tickets;

    DatabaseConnector m_dbConnector;
    C_User* user;
    ServerConnection* server;

    void connectDatabase();
};
#endif // MAINWINDOW_H
