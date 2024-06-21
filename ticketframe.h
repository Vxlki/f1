#ifndef TICKETFRAME_H
#define TICKETFRAME_H

#include <QFrame>
#include <QImage>
#include <QString>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include "c_user.h"
#include "itickets.h"

namespace Ui {
class TicketFrame;
}

class TicketFrame : public QFrame
{
    Q_OBJECT

public:
    explicit TicketFrame(ITickets* ticket, C_User* user = nullptr, QWidget *parent = nullptr);
    ~TicketFrame();

private:
    Ui::TicketFrame *ui;

    C_User* user;
    ITickets* ticket;
    QImage qrCode;

    QVBoxLayout* vLayout;
    QHBoxLayout* hLayout1;
    QHBoxLayout* hLayout2;
    std::vector<QLabel*> labels;

    void generateQrCode();
};

#endif // TICKETFRAME_H
