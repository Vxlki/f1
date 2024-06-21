#ifndef C_DRIVERS_H
#define C_DRIVERS_H

#include "a_personnel.h"


class C_Drivers : public A_Personnel
{
private:
    int DriverID;
    QByteArray ProfileImage;

public:
    C_Drivers();
    C_Drivers(int driverID, int personnelID, const QString& firstName, const QString& lastName,
              const QString& position, /*const C_Address address,*/ const QDateTime& startDate,
              const QDateTime& endDate, const QString& teamName);
    QJsonObject serialize() const override;
    static C_Drivers* deserialize(const QJsonObject& jsonObj);
    int driverID();
    QByteArray getProfileImage() const;
    void setProfileImage(const QByteArray &profileImage);
    void print() override;
};



#endif // C_DRIVERS_H
