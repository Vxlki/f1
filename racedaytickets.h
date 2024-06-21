#ifndef RACEDAYTICKETS_H
#define RACEDAYTICKETS_H

#include "atickets.h"

class RaceDayTickets : public ATickets
{
public:
    RaceDayTickets(int raceID,QString cname, QString address, QString date, double price,int stock);
    static RaceDayTickets* deserialize(const QJsonObject &obj);
};


#endif // RACEDAYTICKETS_H
