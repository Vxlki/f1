#include "day1tickets.h"

Day1Tickets::Day1Tickets(int raceID,QString cname, QString address, QString date, double price,int stock) :ATickets(raceID,cname, address, date, price, stock) {}

ATickets *Day1Tickets::deserialize(const QJsonObject &obj)
{
    QString m_circuitName = obj["circuitName"].toString();
    QString m_address = obj["address"].toString();
    QString m_date = obj["date"].toString();
    double m_price = obj["price"].toDouble();
    int m_type = obj["type"].toInt();
    int m_raceID=obj["raceID"].toInt();
    int m_stock=obj["stock"].toInt();

    return new Day1Tickets(m_raceID,m_circuitName,m_address,m_date,m_price,m_stock);
}
