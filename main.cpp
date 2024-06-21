#include "notloggedinwindow.h"
#include"mainwindow.h"
#include"loginpage.h"
#include"databaseconnector.h"
#include <QApplication>
#include "serverconnection.h"
#include <c_user.h>
#include "autologin.h"

ServerConnection* ServerConnection::mpInstance = nullptr;

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    a.setWindowIcon(QIcon(":/icons/icon.png"));

    ServerConnection* server = ServerConnection::getInstance();
    server->connectToServer("192.168.1.146", 12346);

    QObject::connect(server, &ServerConnection::connected, [&]() {
        qDebug() << "Conexiune la server reușită!";
    });

    AutoLogIn* autoLogger = new AutoLogIn;
    bool check = autoLogger->citireFisier();



    return a.exec();
}
