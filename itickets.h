#ifndef ITICKETS_H
#define ITICKETS_H
#include <QString>
#include <QJsonObject>

class ITickets
{
public:
    virtual QString getCircuitName() = 0;
    virtual QString getDate() = 0;
    virtual double getPrice() = 0;
    virtual QJsonObject serialize() = 0;
    virtual int getRaceID() = 0;
    virtual int getStock() = 0;
protected:

};


#endif // ITICKETS_H
