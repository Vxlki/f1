#include "autologin.h"
#include <QObject>
#include <QFile>
#include <QStandardPaths>
#include <mainwindow.h>
#include <notloggedinwindow.h>

AutoLogIn::AutoLogIn()
{
}

bool AutoLogIn::citireFisier()
{
    QString filePath = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation) + "/autologger.txt";
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Nu s-a putut deschide fișierul pentru citire.";
        return false;
    }

    QTextStream in(&file);
    QString username = in.readLine();
    QString password = in.readLine();

    file.close();

    if (username.isEmpty() || password.isEmpty())
    {
        notLoggedInWindow* window = new notLoggedInWindow;
        window->show();
    }
    else
    {
        this->server = ServerConnection::getInstance();
        connect(this->server, &ServerConnection::sendAutoLogIn, this, &AutoLogIn::handleLogInResponse);
        this->server->autoLogIn(username, password);
    }
    return true;
}

void AutoLogIn::handleLogInResponse(const QJsonObject &response)
{
    C_User* user = C_User::deserialize(response);
    MainWindow* mainW = new MainWindow(user);
    mainW->setAttribute(Qt::WA_DeleteOnClose);
    mainW->showMaximized();
}


