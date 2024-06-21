#ifndef TEAMS_H
#define TEAMS_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QStackedLayout>
#include <QScrollArea>
#include <QPushButton>
#include "pages.h"
#include "clickablelabel.h"
#include "serverconnection.h"
#include "a_personnel.h"
#include "c_teams.h"
#include "c_drivers.h"

namespace Ui {
class Teams;
}

class Teams : public QMainWindow
{
    Q_OBJECT

public:
    explicit Teams(std::vector<I_Personnel*> personnel, std::vector<C_Teams*> teams, QWidget *parent = nullptr);
    void handleLabelClicked();
    ~Teams();

private slots:
    void on_backButton_clicked();

private:
    Ui::Teams *ui;
    QSqlDatabase db;
    ServerConnection* conexiuneServer;
    //std::vector<ClickableLabel*> echipe;
    std::vector<Pages*> pages;
    QPushButton* backButton;

    std::vector<I_Personnel*> personnel;
    std::vector<C_Teams*> teams;

    QStackedLayout* mainLayout;
    QWidget* mainPage;
    QString labelStyle;
    QWidget* scrollAreaContent;
    QVBoxLayout* scrollAreaContentLayout;

    void createPages(QString tname);
    void createDriversPages(I_Personnel* driver);
    void createLabels();
    void showWidgetByPageName(QString pageName);
    void handlebackToTeamsButton();

    //void adaugareLabel(ClickableLabel* label);
};

#endif // TEAMS_H
