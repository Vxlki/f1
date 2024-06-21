#include "c_engineers.h"
#include <QJsonObject>
#include <QDebug>

C_Engineers::C_Engineers() : A_Personnel() {}

C_Engineers::C_Engineers(int engineerID, int personnelID, const QString& firstName, const QString& lastName, const QString& position,
                         const QDateTime& startDate, const QDateTime& endDate, const QString& teamName)
    : A_Personnel(personnelID, firstName, lastName, position, startDate, endDate, teamName), EngineerID(engineerID) {}

QJsonObject C_Engineers::serialize() const {
    QJsonObject jsonObj = A_Personnel::serialize();
    jsonObj["EngineerID"] = EngineerID;
    return jsonObj;
}

C_Engineers* C_Engineers::deserialize(const QJsonObject& jsonObj)
{
    int engineerID = jsonObj["EngineerID"].toInt();
    int personnelID = jsonObj["PersonnelID"].toInt();
    QString firstName = jsonObj["FirstName"].toString();
    QString lastName = jsonObj["LastName"].toString();
    QString position = jsonObj["Position"].toString();
    QDateTime startDate = QDateTime::fromString(jsonObj["StartDate"].toString(), Qt::ISODate);
    QDateTime endDate = QDateTime::fromString(jsonObj["EndDate"].toString(), Qt::ISODate);
    QString teamName = jsonObj["TeamName"].toString();

    return new C_Engineers(engineerID, personnelID, firstName, lastName, position, startDate, endDate, teamName);
}

void C_Engineers::print()
{
    qDebug() << "Engineer ID:" << EngineerID;
    qDebug() << "Personnel ID:" << PersonnelID;
    qDebug() << "First Name:" << FirstName;
    qDebug() << "Last Name:" << LastName;
    qDebug() << "Position:" << Position;
  //  qDebug() << "Address:" << Address.serialize();
    qDebug() << "Start Date:" << StartDate.toString();
    qDebug() << "End Date:" << EndDate.toString();
    qDebug() << "Team Name:" << TeamName;
}
