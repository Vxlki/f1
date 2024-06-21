#ifndef A_PERSONNEL_H
#define A_PERSONNEL_H

#include "i_personnel.h"
#include "c_address.h"
#include <QDateTime>
#include <QByteArray>

class A_Personnel : public I_Personnel
{
protected:
    int PersonnelID;
    QString FirstName;
    QString LastName;
    QString Position;
    C_Address Address;
    QDateTime StartDate;
    QDateTime EndDate;
    QString TeamName;

public:
    A_Personnel();
    A_Personnel(int personnelID, const QString& firstName, const QString& lastName, const QString& position,
               /* const C_Address* address,*/ const QDateTime& startDate, const QDateTime& endDate,
                const QString& teamName);
    virtual QJsonObject serialize() const override;
    virtual void print() override ;
    QString GetPosition() override;

    QString getFirstName() override { return this->FirstName; }
    QString getLastName() override { return this->LastName; }
    QString getPosition() override { return this->Position; }
    C_Address getAddress() override { return this->Address; }
    QString getStartDate() override { return this->StartDate.toString(); }
    QString getEndDate() override { return this->EndDate.toString(); }
    QString getTeamName() override { return this->TeamName;}

    static A_Personnel* deserialize(const QJsonObject obj);
};



#endif // A_PERSONNEL_H
