#include "c_user.h"
#include <QJsonArray>
#include <QCryptographicHash>

C_User::C_User(QObject *parent)  : QObject{parent}
{
    username="invalid";
    password={};
}

C_User::C_User(QString name, QString pass, QString mail, QString telephone, int userId,
               std::vector<C_Drivers*> soferi_preferati, std::vector<C_Teams*> echipe_preferate) : userId(userId), username(name),
    password(pass), mail(mail), telephone(telephone),
    soferi_preferati(std::move(soferi_preferati)), echipe_preferate(std::move(echipe_preferate)){}

QString C_User::hashPassword(const QString &password) const
{
    QByteArray passwordBytes = password.toUtf8();
    QByteArray hashBytes = QCryptographicHash::hash(passwordBytes, QCryptographicHash::Sha256); // Calcularea hashului SHA-256

    QString hashedPassword = QString(hashBytes.toHex());

    return hashedPassword;
}

QJsonObject C_User::serialize() const
{
    QJsonObject obj;
    obj["userId"]=userId;
    obj["username"] = username;
    obj["password"] = hashPassword(password);
    obj["mail"] = mail;
    obj["telephone"] = telephone;

    QJsonArray driversArray;
    for (const auto& driver : soferi_preferati) {
        driversArray.append(driver->serialize());
    }
    obj["favorite_drivers"] = driversArray;


    QJsonArray teamsArray;
    for (const auto& team : echipe_preferate) {
        teamsArray.append(team->serialize());
    }
    obj["favorite_teams"] = teamsArray;

    return obj;
}

C_User *C_User::deserialize(const QJsonObject& jsonObj)
{
    int userId = jsonObj["userId"].toInt();
    QString username = jsonObj["username"].toString();
    QString password = jsonObj["password"].toString();
    QString mail = jsonObj["mail"].toString();
    QString telephone = jsonObj["telephone"].toString();


    std::vector<C_Drivers*> driversList;
    QJsonArray driversArray = jsonObj["favorite_drivers"].toArray();
    for (const auto& driverValue : driversArray) {
        QJsonObject driverObj = driverValue.toObject();
        C_Drivers* driver = C_Drivers::deserialize(driverObj);
        driversList.push_back(driver);
    }


    std::vector<C_Teams*> teamsList;
    QJsonArray teamsArray = jsonObj["favorite_teams"].toArray();
    for (const auto& teamValue : teamsArray) {
        QJsonObject teamObj = teamValue.toObject();
        C_Teams* team = C_Teams::deserialize(teamObj);
        teamsList.push_back(team);
    }

    return new C_User(username, password, mail, telephone, userId, std::move(driversList), std::move(teamsList));
}


void C_User::print()
{
    qDebug() << "User ID:" << userId;
    qDebug() << "Password:" << password;
    qDebug() << "Email:" << mail;
    qDebug() << "Telephone:" << telephone;

    qDebug() << "Favorite Drivers:";
    for (const auto& driver : soferi_preferati) {
        driver->print();
    }

    qDebug() << "Favorite Teams:";
    for (const auto& team : echipe_preferate) {
        team->print();
    }
}


QString C_User::getUsername() const {
    return username;
}

QString C_User::getPassword() const {
    return password;
}

std::vector<C_Drivers *> C_User::getSoferi() const
{
    return this->soferi_preferati;
}

std::vector<C_Teams *> C_User::getTeams() const
{
    return this->echipe_preferate;
}

std::vector<ITickets *> C_User::getTickets() const
{
    return this->tickets;
}

void C_User::addTicket(ITickets* ticket)
{
    this->tickets.push_back(ticket);
}
