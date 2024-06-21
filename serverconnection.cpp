#include "serverconnection.h"
#include "loginpage.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QCryptographicHash>

ServerConnection::ServerConnection(QObject *parent) : QObject(parent)
{
    socket = new QTcpSocket(this);
    connect(socket, &QTcpSocket::connected, this, &ServerConnection::onConnected);
    connect(socket, &QTcpSocket::disconnected, this, &ServerConnection::onDisconnected);
    connect(socket, &QTcpSocket::readyRead, this, &ServerConnection::onReadyRead);
}

void ServerConnection::connectToServer(const QString &host, quint16 port)
{
    socket->connectToHost(host, port);
}

void ServerConnection::onConnected()
{
    emit connected();
}

void ServerConnection::onDisconnected()
{
    emit disconnected();
}

void ServerConnection::onReadyRead()
{
    QByteArray data = socket->readAll();
    QJsonDocument jsondoc = QJsonDocument::fromJson(data);
    QJsonObject requestObj = jsondoc.object();
    QString requestType = requestObj["type"].toString();
    //qDebug()<<data;
    qDebug()<<"Request TYPE::::::::: "<< requestType;

    if(requestType == "login")
    {
        emit sendLogInResponse(requestObj);
    }
    if(requestType == "teamswindowp")
    {
        emit sendTeamsWindowPersonnel(requestObj);
    }
    if(requestType == "teamswindowt")
    {
        emit sendTeamsWindowTeams(requestObj);
    }
    if(requestType == "circuits1")
    {
        emit sendCircuit1Window(requestObj);
    }
    if(requestType == "circuits2")
    {
        emit sendCircuit2Window(requestObj);
    }
    if(requestType=="changepassword")
    {
        qDebug()<<"CHANGE PASSWORD";
        emit sendChangePassword(requestObj);
    }
    if(requestType == "register")
    {
        emit sendSignInResponse(requestObj);
    }
    if(requestType == "teamsregister")
    {
        emit sendTeamsFunctionRegister(requestObj);
    }
    if(requestType == "personnelregister")
    {
        emit sendPersonnelFunctionRegister(requestObj);
    }
    if(requestType == "autologin")
    {
        emit sendAutoLogIn(requestObj);
    }
    if(requestType == "tickets")
    {
        emit sendTicketsWindow(requestObj);
    }
}

void ServerConnection::circuit1WindowFunction()
{
    QJsonObject messageObject;
    messageObject["type"]="circuits1";
    QJsonDocument messageDoc(messageObject);
    QByteArray messageData = messageDoc.toJson();
    socket->write(messageData);
}

void ServerConnection::circuit2WindowFunction()
{
    QJsonObject messageObject;
    messageObject["type"]="circuits2";
    QJsonDocument messageDoc(messageObject);
    QByteArray messageData = messageDoc.toJson();
    socket->write(messageData);
}

void ServerConnection::teamsWindowFunctionPersonnel()
{
    QJsonObject messageObject;
    messageObject["type"]="teamswindowp";
    QJsonDocument messageDoc(messageObject);
    QByteArray messageData = messageDoc.toJson();
    socket->write(messageData);
}

void ServerConnection::teamsWindowFunctionTeams()
{
    QJsonObject messageObject;
    messageObject["type"]="teamswindowt";
    QJsonDocument messageDoc(messageObject);
    QByteArray messageData = messageDoc.toJson();
    socket->write(messageData);
}

void ServerConnection::teamsFunctionRegister()
{
    QJsonObject messageObject;
    messageObject["type"]="teamsregister";
    QJsonDocument messageDoc(messageObject);
    QByteArray messageData = messageDoc.toJson();
    socket->write(messageData);
}

void ServerConnection::personnelFunctionRegister()
{
    QJsonObject messageObject;
    messageObject["type"]="personnelregister";
    QJsonDocument messageDoc(messageObject);
    QByteArray messageData = messageDoc.toJson();
    socket->write(messageData);
}

void ServerConnection::autoLogIn(QString user, QString pass)
{
    QJsonObject messageObject;
    messageObject["type"]="autologin";
    messageObject["username"] = user;
    messageObject["password"] = ServerConnection::hashPassword(pass);
    QJsonDocument messageDoc(messageObject);
    QByteArray messageData = messageDoc.toJson();
    socket->write(messageData);
}

void ServerConnection::logIn(QString user, QString pass)
{
    QJsonObject messageObject;
    messageObject["type"]="login";
    messageObject["username"] = user;
    messageObject["password"] = ServerConnection::hashPassword(pass);
    QJsonDocument messageDoc(messageObject);
    QByteArray messageData = messageDoc.toJson();
    socket->write(messageData);
}

QString ServerConnection::hashPassword(const QString &password) const
{
    QByteArray passwordBytes = password.toUtf8();
    QByteArray hashBytes = QCryptographicHash::hash(passwordBytes, QCryptographicHash::Sha256); // Calcularea hashului SHA-256

    QString hashedPassword = QString(hashBytes.toHex());

    return hashedPassword;
}

void ServerConnection::signIn(C_User *user)
{
    QJsonObject messageObject = user->serialize();
    messageObject["type"] = "register";
    QJsonDocument messageDoc(messageObject);
    QByteArray messageData = messageDoc.toJson();
    socket->write(messageData);
}

void ServerConnection::changePassword(C_User& user)
{
    user.print();
    QJsonObject messageObject = user.serialize();
    messageObject["type"] = "changepassword";
    QJsonDocument messageDoc(messageObject);
    QByteArray messageData = messageDoc.toJson();
    socket->write(messageData);
}

void ServerConnection::ticketsWindow()
{
    QJsonObject messageObject;
    messageObject["type"] = "sendtickets";
    QJsonDocument messageDoc(messageObject);
    QByteArray messageData = messageDoc.toJson();
    socket->write(messageData);
}

ServerConnection *ServerConnection::getInstance()
{
    if(mpInstance == nullptr)
        mpInstance = new ServerConnection;
    return mpInstance;
}
