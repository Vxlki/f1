#ifndef C_MANAGER_H
#define C_MANAGER_H

#include "a_personnel.h"

class C_Manager : public A_Personnel
{
private:
    int ManagerID;

public:
    C_Manager();
    C_Manager(int managerID, int personnelID, const QString& firstName, const QString& lastName, const QString& position,
              const QDateTime& startDate, const QDateTime& endDate, const QString& teamName);

    QJsonObject serialize() const override;
    static C_Manager* deserialize(const QJsonObject& jsonObj);
    void print() override;
};

#endif // C_MANAGER_H
