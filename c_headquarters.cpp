// c_headquarters.cpp
#include "c_headquarters.h"

C_Headquarters::C_Headquarters() {}

C_Headquarters::C_Headquarters(int hqid, C_Address *addr)
    : HQID(hqid), address(addr) {}

QJsonObject C_Headquarters::serialize() const {
    QJsonObject jsonObj;
    jsonObj["HQID"] = HQID;
    jsonObj["Address"] = address->serialize();

    return jsonObj;
}

void C_Headquarters::print()
{
    qDebug() << "HQID:" << HQID;
    if (address) {
        qDebug() << "Address:";
        address->print();
    } else {
        qDebug() << "Address: NULL";
    }
}

C_Headquarters *C_Headquarters::deserialize(const QJsonObject& jsonObj) {
    int hqID = jsonObj["HQID"].toInt();
    QJsonObject addressObj = jsonObj["Address"].toObject();
    C_Address* address = C_Address::deserialize(addressObj);

    return new C_Headquarters(hqID, address);
}
