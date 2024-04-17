#include "atickets.h"

ATickets::ATickets() {}

void ATickets::generateQrCode()
{
    QrCodeGenerator generator;
    QString data = "https://www.google.com";
    this->qrCode = generator.generateQr(data);
}
