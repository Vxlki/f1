#ifndef ATICKETS_H
#define ATICKETS_H

#include "itickets.h"
#include <QString>
#include <QImage>

class ATickets : public ITickets
{
public:
    ATickets();
    virtual void generateQrCode();
protected:
    float price;
    QString clientName;
    int seatNr;
    QImage qrCode;
};

#endif // ATICKETS_H
