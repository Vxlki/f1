#ifndef TICKETSWINDOW_H
#define TICKETSWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QScrollArea>
#include <QGridLayout>
#include <QStackedLayout>
#include <ticketsbuywindow.h>
#include <c_user.h>
#include <day1tickets.h>
#include <day2tickets.h>
#include <fatickets.h>
#include <racedaytickets.h>
#include <serverconnection.h>

namespace Ui {
class ticketsWindow;
}

class ticketsWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ticketsWindow(C_User* user, QSqlDatabase db, QWidget *parent = nullptr);
    ~ticketsWindow();

public slots:
    void onBuyButtonClicked();
    void handleTicketsResponse(const QJsonObject& response);
private:
    Ui::ticketsWindow *ui;
    QSqlDatabase db;
    C_User* user;
    std::vector<ITickets*> tickets;

    QScrollArea* scrollArea;
    QWidget* scrollAreaContent;
    QGridLayout* mainLayout;
    QVBoxLayout* verticalLayout;
    QString labelStyle;
    TicketsBuyWindow* ticketbW;
    ServerConnection* server;

    void addTickets();
    void insertTicketsInVector();
    void createTickets(QString cname, QString address, QString date, int type, float price);
};

#endif // TICKETSWINDOW_H
