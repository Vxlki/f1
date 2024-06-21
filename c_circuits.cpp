#include "c_circuits.h"

C_Circuits::C_Circuits()
    : m_circuitID(0), m_length(0), m_turns(0), m_nrOfLaps(0) {}

C_Circuits::C_Circuits(int circuitID, const QString &circuitName, const C_Address& address, float length,
                       int turns, int nrOfLaps)
    : m_circuitID(circuitID), m_circuitName(circuitName), m_address(address), m_length(length),
    m_turns(turns), m_nrOfLaps(nrOfLaps) {}

int C_Circuits::getCircuitID() const { return m_circuitID; }
QString C_Circuits::getCircuitName() const { return m_circuitName; }
C_Address C_Circuits::getAddress() const  { return m_address; }
float C_Circuits::getLength() const { return m_length; }
int C_Circuits::getTurns() const { return m_turns; }
//QDateTime C_Circuits::getLapRecord() const { return m_lapRecord; }
int C_Circuits::getNrOfLaps() const { return m_nrOfLaps; }

QTime C_Circuits::getFirstGP() const { return m_firstGP; }
//QByteArray C_Circuits::getCircuitImage() const { return m_circuitImage; }


void C_Circuits::print()
{
    qDebug() << "Circuit ID:" << m_circuitID;
    qDebug() << "Circuit Name:" << m_circuitName;
    qDebug() << "Address:";
    m_address.print();
    qDebug() << "Length:" << m_length;
    qDebug() << "Turns:" << m_turns;
    qDebug() << "Lap Record:" << m_lapRecord.toString("yyyy-MM-dd hh:mm:ss");
    qDebug() << "Number of Laps:" << m_nrOfLaps;
    //qDebug() << "First Grand Prix Time:" << m_firstGP.toString("hh:mm:ss");
    //qDebug() << "Circuit Image:" << m_circuitImage;
}

C_Circuits* C_Circuits::deserialize(const QJsonObject &jsonObj)
{
    int circuitID = jsonObj["circuitID"].toInt();
    QString circuitName = jsonObj["circuitName"].toString();

    C_Address address = *C_Address::deserialize(jsonObj["address"].toObject());

    float length = jsonObj["length"].toDouble();
    int turns = jsonObj["turns"].toInt();
    //QDateTime lapRecord = QDateTime::fromString(jsonObj["lapRecord"].toString(), Qt::ISODate);
    int nrOfLaps = jsonObj["nrOfLaps"].toInt();
    //QTime firstGP = QTime::fromString(jsonObj["firstGP"].toString(), "hh:mm:ss");
    //QByteArray circuitImage = QByteArray::fromBase64(jsonObj["circuitImage"].toString().toUtf8());

    return new C_Circuits(circuitID, circuitName, address, length, turns, nrOfLaps);
}
