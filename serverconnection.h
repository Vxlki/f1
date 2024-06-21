
#ifndef SERVERCONNECTION_H
#define SERVERCONNECTION_H

#include <QObject>
#include <QTcpSocket>
#include <c_user.h>

class ServerConnection : public QObject
{
    Q_OBJECT
public:
    void circuit1WindowFunction();
    void circuit2WindowFunction();
    void teamsWindowFunctionPersonnel();
    void teamsWindowFunctionTeams();
    void teamsFunctionRegister();
    void personnelFunctionRegister();
    void logIn(QString user, QString pass);
    void autoLogIn(QString user, QString pass);
    void signIn(C_User* user);
    void changePassword(C_User& user);
    void ticketsWindow();
    static ServerConnection* getInstance();
    QString hashPassword(const QString &password) const;
public slots:
    void connectToServer(const QString &host, quint16 port);

private slots:
    void onConnected();
    void onDisconnected();
    void onReadyRead();

signals:
    void connected();
    void disconnected();
    void dataReceived(const QByteArray &data);
    void sendChangePassword(const QJsonObject& obj);
    void sendLogInResponse(const QJsonObject& obj);
    void sendSignInResponse(const QJsonObject& obj);
    void sendTeamsWindowPersonnel(const QJsonObject& obj);
    void sendTeamsWindowTeams(const QJsonObject& obj);
    void sendCircuit1Window(const QJsonObject& obj);
    void sendCircuit2Window(const QJsonObject& obj);
    void sendPersonnelFunctionRegister(const QJsonObject& obj);
    void sendTeamsFunctionRegister(const QJsonObject& obj);
    void sendAutoLogIn(const QJsonObject& obj);
    void sendTicketsWindow(const QJsonObject& obj);
private:
    explicit ServerConnection(QObject *parent = nullptr);
    QTcpSocket *socket;
    static ServerConnection *mpInstance;
};

#endif // SERVERCONNECTION_H
