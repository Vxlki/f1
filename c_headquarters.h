#ifndef C_HEADQUARTERS_H
#define C_HEADQUARTERS_H

#include "c_address.h"

class C_Headquarters
{
private:
    int HQID;
    C_Address* address;

public:
    C_Headquarters();
    C_Headquarters(int hqid, C_Address* addr);
    QJsonObject serialize() const;
    void print();
    static C_Headquarters* deserialize(const QJsonObject& jsonObj);
};



#endif // C_HEADQUARTERS_H
