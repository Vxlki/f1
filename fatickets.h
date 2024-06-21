#ifndef FATICKETS_H
#define FATICKETS_H

#include "atickets.h"


class FATickets : public ATickets
{
public:
    FATickets(int raceID,QString cname, QString address, QString date, double price,int stock);
    static FATickets* deserialize(const QJsonObject &obj);
};


#endif // FATICKETS_H
