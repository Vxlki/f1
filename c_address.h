#ifndef C_ADDRESS_H
#define C_ADDRESS_H

#include <QObject>
#include <QJsonObject>
#include <QByteArray> // Adăugăm header-ul necesar pentru QByteArray

class C_Address
{
private:
    QString Country;
    QString City;
    QString Street;

public:
    C_Address();
    QJsonObject serialize() const; // Funcția va returna QByteArray
    C_Address(const QString& country, const QString& city, const QString& street); // Constructor cu parametri
    void print();
    static C_Address* deserialize(const QJsonObject& jsonObj);

    QString getCountry();
    QString getCity();
    QString getStreet();
};

#endif // C_ADDRESS_H
