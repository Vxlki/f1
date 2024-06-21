#include "c_drivers.h"

C_Drivers::C_Drivers() {}

C_Drivers::C_Drivers(int driverID, int personnelID, const QString& firstName, const QString& lastName,
                     const QString& position,/* const C_Address* address,*/ const QDateTime& startDate,
                     const QDateTime& endDate, const QString& teamName)
    : A_Personnel(personnelID, firstName, lastName, position,/* address,*/ startDate, endDate, teamName),
    DriverID(driverID) {}

QJsonObject C_Drivers::serialize() const {
    QJsonObject jsonObj;

    jsonObj["DriverID"] = DriverID;
    jsonObj["PersonnelID"] = PersonnelID;
    jsonObj["FirstName"] = FirstName;
    jsonObj["LastName"] = LastName;
    jsonObj["Position"] = Position;
  //jsonObj["Address"] = Address.serialize();
    jsonObj["StartDate"] = StartDate.toString(Qt::ISODate);
    jsonObj["EndDate"] = EndDate.toString(Qt::ISODate);
    jsonObj["TeamName"] = TeamName;
    QString base64Image = QString::fromLatin1(ProfileImage.toBase64());
    jsonObj["ProfileImage"] = base64Image;

    return jsonObj;
}

C_Drivers* C_Drivers::deserialize(const QJsonObject& jsonObj) {
    int driverID = jsonObj["DriverID"].toInt();
    int personnelID = jsonObj["PersonnelID"].toInt();
    QString firstName = jsonObj["FirstName"].toString();
    QString lastName = jsonObj["LastName"].toString();
    QString position = jsonObj["Position"].toString();
   // C_Address* address = C_Address::deserialize(jsonObj["Address"].toObject());
    QDateTime startDate = QDateTime::fromString(jsonObj["StartDate"].toString(), Qt::ISODate);
    QDateTime endDate = QDateTime::fromString(jsonObj["EndDate"].toString(), Qt::ISODate);
    QString teamName = jsonObj["TeamName"].toString();

    return new C_Drivers(driverID, personnelID, firstName, lastName, position, /*address,*/ startDate, endDate, teamName);
}

int C_Drivers::driverID()
{
    return DriverID;
}


QByteArray C_Drivers::getProfileImage() const
{
    return ProfileImage;
}

void C_Drivers::setProfileImage(const QByteArray& profileImage)
{
    ProfileImage = profileImage;
}

void C_Drivers::print() {
    qDebug() << "Driver ID:" << DriverID;
    qDebug() << "Personnel ID:" << PersonnelID;
    qDebug() << "First Name:" << FirstName;
    qDebug() << "Last Name:" << LastName;
    qDebug() << "Position:" << Position;
    qDebug() << "Start Date:" << StartDate.toString(Qt::ISODate);
    qDebug() << "End Date:" << EndDate.toString(Qt::ISODate);
    qDebug() << "Team Name:" << TeamName;
    qDebug() << "Profile Image:" << ProfileImage;
}
