#include "a_personnel.h"
#include <QJsonDocument>

A_Personnel::A_Personnel()
{
}

A_Personnel::A_Personnel(int personnelID, const QString& firstName, const QString& lastName, const QString& position,
                         /*const C_Address address,*/ const QDateTime& startDate, const QDateTime& endDate,
                         const QString& teamName) : PersonnelID(personnelID),
    FirstName(firstName), LastName(lastName), Position(position), /*Address(*address),*/
    StartDate(startDate), EndDate(endDate), TeamName(teamName) {
}

QJsonObject A_Personnel::serialize() const {
    QJsonObject jsonObj;
    jsonObj["PersonnelID"]=PersonnelID;
    jsonObj["FirstName"] = FirstName;
    jsonObj["LastName"] = LastName;
    jsonObj["Position"] = Position;
    //jsonObj["Address"] = Address.serialize();
    jsonObj["StartDate"] = StartDate.toString();
    jsonObj["EndDate"] = EndDate.toString();
    jsonObj["TeamName"] = TeamName;

    return jsonObj;
}

void A_Personnel::print()
{
    qDebug() << "Personnel ID:" << PersonnelID;
    qDebug() << "First Name:" << FirstName;
    qDebug() << "Last Name:" << LastName;
    qDebug() << "Position:" << Position;
    //qDebug() << "Address:" << Address.getCountry() << ", " << Address.getCity() << ", " << Address.getStreet();
    qDebug() << "Start Date:" << StartDate.toString();
    qDebug() << "End Date:" << EndDate.toString();
    qDebug() << "Team Name:" << TeamName;
}

QString A_Personnel::GetPosition()
{
    return Position;
}
