#ifndef DAY2TICKETS_H
#define DAY2TICKETS_H

#include "atickets.h"


class Day2Tickets : public ATickets
{
public:
    Day2Tickets(int raceID,QString cname, QString address, QString date, double price,int stock);
    static ATickets* deserialize(const QJsonObject &obj);
};


#endif // DAY2TICKETS_H
