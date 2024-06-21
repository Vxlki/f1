#include "atickets.h"
#include "qjsonobject.h"

ATickets::ATickets(int m_raceID, QString m_cname, QString m_address, QString m_date, double m_price,int m_stock)
{
    this->circuitName = m_cname;
    this->address = m_address;
    this->date = m_date;
    this->price = m_price;
    this->raceID = m_raceID;
    this->stock = m_stock;
}

QString ATickets::getCircuitName()
{
    return this->circuitName;
}

double ATickets::getPrice()
{
    return this->price;
}

QString ATickets::getDate()
{
    return this->date;
}

int ATickets::getRaceID()
{
    return this->raceID;
}

int ATickets::getStock()
{
    return this->stock;
}

QJsonObject ATickets::serialize()
{
    QJsonObject obj;
    obj["circuitName"] = circuitName;
    obj["address"] = address;
    obj["date"] = date;
    obj["price"] = price;
    obj["type"] = type;
    return obj;
}

ATickets* ATickets::deserialize(const QJsonObject &obj)
{
    QString m_circuitName = obj["circuitName"].toString();
    QString m_address = obj["address"].toString();
    QString m_date = obj["date"].toString();
    double m_price = obj["price"].toDouble();
    //int m_type = obj["type"].toInt();
    int m_raceID=obj["raceID"].toInt();
    int m_stock=obj["stock"].toInt();

    return new ATickets(m_raceID,m_circuitName,m_address,m_date,m_price,m_stock);
}
