#include "c_manager.h"
#include <QJsonObject>
#include <QDebug>

C_Manager::C_Manager() : A_Personnel() {}

C_Manager::C_Manager(int managerID, int personnelID, const QString& firstName, const QString& lastName, const QString& position,
                     const QDateTime& startDate, const QDateTime& endDate, const QString& teamName)
    : A_Personnel(personnelID, firstName, lastName, position, startDate, endDate, teamName), ManagerID(managerID) {}

QJsonObject C_Manager::serialize() const {
    QJsonObject jsonObj = A_Personnel::serialize();
    jsonObj["ManagerID"] = ManagerID;
    return jsonObj;
}

C_Manager *C_Manager::deserialize(const QJsonObject &jsonObj)
{
    int managerID = jsonObj["ManagerID"].toInt();
    int personnelID = jsonObj["PersonnelID"].toInt();
    QString firstName = jsonObj["FirstName"].toString();
    QString lastName = jsonObj["LastName"].toString();
    QString position = jsonObj["Position"].toString();
    QDateTime startDate = QDateTime::fromString(jsonObj["StartDate"].toString(), Qt::ISODate);
    QDateTime endDate = QDateTime::fromString(jsonObj["EndDate"].toString(), Qt::ISODate);
    QString teamName = jsonObj["TeamName"].toString();

    return new C_Manager(managerID, personnelID, firstName, lastName, position, startDate, endDate, teamName);
}

void C_Manager::print()
{
    qDebug() << "Manager ID:" << ManagerID;
    qDebug() << "Personnel ID:" << PersonnelID;
    qDebug() << "First Name:" << FirstName;
    qDebug() << "Last Name:" << LastName;
    qDebug() << "Position:" << Position;
    //qDebug() << "Address:" << Address.serialize();
    qDebug() << "Start Date:" << StartDate.toString();
    qDebug() << "End Date:" << EndDate.toString();
    qDebug() << "Team Name:" << TeamName;
}
