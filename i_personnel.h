#ifndef I_PERSONNEL_H
#define I_PERSONNEL_H


#include "QJsonObject"
#include "c_address.h"

class I_Personnel
{
public:
    virtual ~I_Personnel() = default;
    virtual QJsonObject serialize() const = 0;
    virtual void print()=0;
    virtual QString GetPosition()=0;

    virtual QString getFirstName() = 0;
    virtual QString getLastName() = 0;
    virtual QString getPosition() = 0;
    virtual C_Address getAddress() = 0;
    virtual QString getStartDate() = 0;
    virtual QString getEndDate() = 0;
    virtual QString getTeamName() = 0;
};

#endif // I_PERSONNEL_H
