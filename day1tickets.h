#ifndef DAY1TICKETS_H
#define DAY1TICKETS_H

#include "atickets.h"

class Day1Tickets : public ATickets
{
public:
    Day1Tickets(int raceID,QString cname, QString address, QString date, double price,int stock);
    static ATickets* deserialize(const QJsonObject &obj);
};


#endif // DAY1TICKETS_H
