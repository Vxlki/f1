#ifndef ATICKETS_H
#define ATICKETS_H

#include "itickets.h"
#include "qjsonobject.h"
#include <QString>
#include <QImage>

class ATickets : public ITickets
{
public:
    ATickets(int raceID, QString cname, QString address, QString date, double price,int stock);
    virtual QString getCircuitName() override;
    double getPrice() override;
    QString getDate() override;
    int getRaceID() override;
    int getStock() override;
    QJsonObject serialize() override;
    static ATickets* deserialize(const QJsonObject &obj);
protected:
    double price;
    QString circuitName;
    QString address;
    QString date;
    int type;
    int raceID;
    int stock;
};



#endif // ATICKETS_H
