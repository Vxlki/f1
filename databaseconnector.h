// databaseconnector.h
#ifndef DATABASECONNECTOR_H
#define DATABASECONNECTOR_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>

class DatabaseConnector : public QObject
{
    Q_OBJECT

public:
    explicit DatabaseConnector(QObject *parent = nullptr);
    ~DatabaseConnector();

    bool connectToDatabase(const QString &serverName, const QString &dbName);
    void disconnectFromDatabase();
    QStringList getUsernames(); // Exemplu de metodă pentru a obține lista de utilizatori

    QSqlDatabase getDatabase(){return m_database;};
private:
    QSqlDatabase m_database;

    bool openConnection();
    void closeConnection();
};

#endif // DATABASECONNECTOR_H
