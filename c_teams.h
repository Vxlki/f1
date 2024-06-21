#ifndef C_TEAMS_H
#define C_TEAMS_H
// c_team.h

#include "c_headquarters.h"
#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QString>

class C_Teams : public QObject
{
    Q_OBJECT
public:
    explicit C_Teams(QObject *parent = nullptr);
    C_Teams(int teamID, const QString &teamName,C_Headquarters* hq, std::vector<QString> sponsors, QObject *parent = nullptr);

    // Metode pentru accesul la date
    int teamID() const;
    QString teamName() const;
    C_Headquarters* hq() const;

    QJsonObject serialize() const;
    static C_Teams* deserialize(const QJsonObject& jsonObj);
    void print();

    std::vector<QString> getSponsors() { return this->sponsors; }

private:
    int m_teamID;
    QString m_teamName;
    C_Headquarters* m_hq;
    std::vector<QString> sponsors;
};

#endif // C_TEAMS_H
