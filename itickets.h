#ifndef ITICKETS_H
#define ITICKETS_H
#include "QrCodeGenerator.h"

class ITickets
{
public:
    ITickets();
    virtual void generateQrCode() = 0;
protected:

};

#endif // ITICKETS_H
