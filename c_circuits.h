#ifndef C_CIRCUITS_H
#define C_CIRCUITS_H

#include "c_address.h"
#include <QString>
#include <QDateTime>

class C_Circuits
{
    int m_circuitID;
    QString m_circuitName;
    C_Address m_address;
    float m_length;
    int m_turns;
    QDateTime m_lapRecord;
    int m_nrOfLaps;
    QTime m_firstGP;
    QByteArray m_circuitImage;

public:
    C_Circuits();
    C_Circuits(int circuitID, const QString &circuitName, const C_Address& address, float length,
               int turns, int nrOfLaps);

    static C_Circuits* deserialize(const QJsonObject &jsonObj);

    int getCircuitID() const;
    QString getCircuitName() const;
    C_Address getAddress() const;
    float getLength() const;
    int getTurns() const;
    QDateTime getLapRecord() const;
    int getNrOfLaps() const;
    QTime getFirstGP() const;
    QByteArray getCircuitImage() const;
    QJsonObject serialize() const;
    void print();
};

#endif // C_CIRCUITS_H
