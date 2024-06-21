#ifndef C_USER_H
#define C_USER_H
#include <QObject>
#include<QJsonObject>
#include "c_drivers.h"
#include "c_teams.h"
#include "itickets.h"

class C_User : public QObject
{
    Q_OBJECT
    int userId;
    QString username;
    QString password;
    QString mail;
    QString telephone;
    std::vector<C_Drivers*> soferi_preferati;
    std::vector<C_Teams*> echipe_preferate;
    std::vector<ITickets*> tickets;

public:
    explicit C_User(QObject *parent = nullptr);
    C_User(QString name, QString pass, QString mail, QString telephone, int userId,
           std::vector<C_Drivers*> soferi_preferati, std::vector<C_Teams*> echipe_preferate);
    QJsonObject serialize() const;
    static C_User* deserialize(const QJsonObject& jsonObj);
    void print();
    QString hashPassword(const QString &password) const;
    QString getUsername() const;
    QString getPassword() const;
    QString getMail() const {return this->mail;}
    QString getTele() const {return this->telephone;}
    std::vector<C_Drivers*> getSoferi() const;
    std::vector<C_Teams*> getTeams()  const;
    std::vector<ITickets*> getTickets() const;
    void addTicket(ITickets* ticket);
    void changePassword(QString pass) {this->password = pass; }
};


#endif // C_USER_H
