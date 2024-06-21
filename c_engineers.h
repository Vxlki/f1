#include "a_personnel.h"

class C_Engineers : public A_Personnel
{
private:
    int EngineerID;

public:
    C_Engineers();
    C_Engineers(int engineerID, int personnelID, const QString& firstName, const QString& lastName, const QString& position,
                const QDateTime& startDate, const QDateTime& endDate, const QString& teamName);

    QJsonObject serialize() const override;
    static C_Engineers* deserialize(const QJsonObject& jsonObj);
    void print() override;
};
