// databaseconnector.cpp
#include "databaseconnector.h"
#include <QDebug>
#include<QSqlError>

DatabaseConnector::DatabaseConnector(QObject *parent) : QObject(parent)
{
}

DatabaseConnector::~DatabaseConnector()
{
    disconnectFromDatabase();
}

bool DatabaseConnector::connectToDatabase(const QString &serverName, const QString &dbName)
{
    m_database = QSqlDatabase::addDatabase("QODBC");
    QString dsn = QString("DRIVER={SQL Server};SERVER=%1;DATABASE=%2;Trusted_Connection=Yes;").arg(serverName).arg(dbName);
    m_database.setDatabaseName(dsn);

    return openConnection();
}

void DatabaseConnector::disconnectFromDatabase()
{
    closeConnection();
}

bool DatabaseConnector::openConnection()
{
    if (m_database.isOpen())
        return true;

    if (m_database.open()) {
        qDebug() << "Connected to database successfully!";
        return true;
    } else {
        qDebug() << "Error connecting to database:" << m_database.lastError().text();
        return false;
    }
}

void DatabaseConnector::closeConnection()
{
    if (m_database.isOpen()) {
        m_database.close();
        qDebug() << "Disconnected from database";
    }
}

QStringList DatabaseConnector::getUsernames()
{
    QStringList usernames;

    if (!m_database.isOpen()) {
        qDebug() << "Database connection is not open.";
        return usernames;
    }

    QSqlQuery query("SELECT TeamName FROM Teams", m_database);
    if (query.exec()) {
        while (query.next()) {
            usernames.append(query.value(0).toString());
        }
    } else {
        qDebug() << "Error executing query:" << query.lastError().text();
    }

    return usernames;
}
