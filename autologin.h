#ifndef AUTOLOGIN_H
#define AUTOLOGIN_H

#include <fstream>
#include <QObject>
#include "c_user.h"
#include "serverconnection.h"

class AutoLogIn : public QObject
{
    Q_OBJECT

public:
    AutoLogIn();
    bool citireFisier();

private:
    C_User* user;
    ServerConnection* server;

public slots:
    void handleLogInResponse(const QJsonObject& response);

};

#endif // AUTOLOGIN_H
