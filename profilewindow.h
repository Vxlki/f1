#ifndef PROFILEWINDOW_H
#define PROFILEWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QLabel>
#include <QPushButton>
#include <QScrollArea>
#include <QString>
#include <QStackedLayout>
#include <QLineEdit>
#include <QMessageBox>
#include "c_drivers.h"
#include "c_teams.h"
#include "itickets.h"
#include "c_user.h"
#include "ticketframe.h"
#include "serverconnection.h"

namespace Ui {
class ProfileWindow;
}

class ProfileWindow : public QMainWindow
{
    Q_OBJECT

public slots:
    void handleChangePassword(const QJsonObject& obj);

public:
    explicit ProfileWindow(C_User* user, QWidget *parent = nullptr);
    ~ProfileWindow();

private:
    Ui::ProfileWindow *ui;
    QWidget* centralWidget;
    QWidget* mainPageWidget;
    QFormLayout* mainLayout;
    QStackedLayout* stackedLayout;
    QVBoxLayout* driversLayout;
    QVBoxLayout* teamsLayout;
    QPushButton* seeTicketsButton;
    QPushButton* changePasswordButton;
    QPushButton* disconnectButton;
    QWidget* ticketsWindow;
    QVBoxLayout* ticketsLayout;
    QWidget* chgPassWindow;
    QFormLayout* chgPassLayout;
    std::vector<QLabel*> labels;
    QString labelStyle;
    ServerConnection* server;

    QString username;
    QString password;
    QString mail;
    QString telephone;
    C_User* user;
    std::vector<C_Drivers*> soferi_preferati;
    std::vector<C_Teams*> echipe_preferate;
    std::vector<ITickets*> tickets;
    std::vector<TicketFrame*> ticketsFrame;

    void makeWindow();
    void createTicketsWindow();
    void createChgPasswordWindow();

private slots:
    void onSeeTicketsButtonClicked();
    void onChgPasswordButtonClicked();
    void onBackFromTicketsButtonClicked();
    void changePassword(QString newp, QString confirmp);
    void onDisconnectButtonClicked();
};

#endif // PROFILEWINDOW_H
