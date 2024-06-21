#include "c_address.h"

C_Address::C_Address() {
    // Constructorul clasei C_Address
}

C_Address::C_Address(const QString& country, const QString& city, const QString& street) :
    Country(country), City(city), Street(street) {
    // Constructor cu parametri
}

QJsonObject C_Address::serialize() const {
    QJsonObject jsonObj;
    jsonObj["Country"] = Country;
    jsonObj["City"] = City;
    jsonObj["Street"] = Street;

    return jsonObj;
}

void C_Address::print()
{
    qDebug() << "Country:" << Country;
    qDebug() << "City:" << City;
    qDebug() << "Street:" << Street;
}

C_Address *C_Address::deserialize(const QJsonObject& jsonObj) {
    QString country = jsonObj["Country"].toString();
    QString city = jsonObj["City"].toString();
    QString street = jsonObj["Street"].toString();

    return new C_Address(country, city, street);
}

QString C_Address::getCountry()
{
    return this->Country;
}

QString C_Address::getCity()
{
    return this->City;
}

QString C_Address::getStreet()
{
    return this->Street;
}
