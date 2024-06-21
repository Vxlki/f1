// c_team.cpp
#include "c_teams.h"
#include "qjsonobject.h"
#include <QJsonArray>
C_Teams::C_Teams(QObject *parent) : QObject(parent) {}

C_Teams::C_Teams(int teamID, const QString &teamName, C_Headquarters* hq,  std::vector<QString> sponsors, QObject *parent)
    : QObject(parent), m_teamID(teamID), m_teamName(teamName), m_hq(hq), sponsors(sponsors){}

int C_Teams::teamID() const {
    return m_teamID;
}

QString C_Teams::teamName() const {
    return m_teamName;
}

C_Headquarters *C_Teams::hq() const {
    return m_hq;
}


QJsonObject C_Teams::serialize() const {
    QJsonObject jsonObj;
    jsonObj["teamID"] = m_teamID;
    jsonObj["teamName"] = m_teamName;
    //jsonObj["hqID"] = m_hq->serialize();
    return jsonObj;
}

C_Teams *C_Teams::deserialize(const QJsonObject& jsonObj) {
    int teamID = jsonObj["teamID"].toInt();
    QString teamName = jsonObj["teamName"].toString();
    C_Headquarters* hq = nullptr;
    if (jsonObj.contains("HQID")) {
        QJsonObject hqObj = jsonObj["HQID"].toObject();
        hq = new C_Headquarters();
        hq->deserialize(hqObj);
    }

    std::vector<QString> sponsors;
    QJsonArray sponsorsArray = jsonObj["sponsors"].toArray();
    for(const auto& sponsorsValue : sponsorsArray)
    {
        sponsors.push_back(sponsorsValue.toString());
    }
    return new C_Teams(teamID, teamName, hq, sponsors);
}

void C_Teams::print()
{
    qDebug() << "Team ID:" << m_teamID;
    qDebug() << "Team Name:" << m_teamName;
    if (m_hq) {
        qDebug() << "Headquarters:";
        m_hq->print();
    } else {
        qDebug() << "Headquarters: NULL";
         }
    for(const auto &sponsor : sponsors)
         {
             qDebug()<<sponsor;
         }
}
