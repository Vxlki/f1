#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"abstractwindow.h"
#include"databaseconnector.h"

class MerchShop;
class Teams;
class Circuits;
class Test;
class ticketsWindow;

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow, AbstractWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionTeams_triggered();
    void on_actionCircuits_triggered();
    void on_actionMerch_Shop_triggered();
    void on_actionTickets_triggered();
    void handleTeamsWindowDestroyed();
private:
    Ui::MainWindow *ui;
    Teams* teamsW;
    Circuits* circuitsW;
    MerchShop* merchsopW;
    Test* testW;
    ticketsWindow* ticketsW;

    DatabaseConnector m_dbConnector;

    void connectDatabase();
};
#endif // MAINWINDOW_H
