#ifndef TICKETSBUYWINDOW_H
#define TICKETSBUYWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <fatickets.h>
#include <day1tickets.h>
#include <day2tickets.h>
#include <racedaytickets.h>
#include <ticketframe.h>
#include <QSpinBox>
#include <c_user.h>
#include <QMenu>
#include <QToolButton>

namespace Ui {
class TicketsBuyWindow;
}

class TicketsBuyWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit TicketsBuyWindow(std::vector<ITickets*> tickets, C_User* user, QString circname, QString address, QString date, QWidget *parent = nullptr);
    ~TicketsBuyWindow();

public slots:
    void updateButtonText(const QString &text, const QString &cname);
    void updateTotalPrice(int value, float price);
    void handleBuyButtonClicked();
private:
    Ui::TicketsBuyWindow *ui;

    QWidget* centralWidget;
    QVBoxLayout* mainLayout;
    QHBoxLayout* horizontalLayout;
    QLabel* titleLabel;
    QLabel* priceLabel;
    QPushButton* buyButton;
    QToolButton* selectButton;
    QMenu* menu;
    QSpinBox* spinBox;
    C_User* user;
    QString labelStyle;
    QString selectedOption;
    std::vector<ITickets*> availableTickets;
    std::vector<QAction *> actions;

    float priceAux;
    int quantity;
    ITickets* desiredTicket;
    TicketFrame* desiredTicketFrame;
    TicketFrame* aux;

    float getPrice(int type, QString cname);
    void createTicketFrame();

public slots:

};

#endif // TICKETSBUYWINDOW_H
