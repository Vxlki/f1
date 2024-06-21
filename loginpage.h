#ifndef LOGINPAGE_H
#define LOGINPAGE_H

#include <QDialog>
#include <QSqlDatabase>
#include "c_user.h"
#include <QJsonArray>
#include "autologin.h"

class ServerConnection;

class MainWindow;

namespace Ui {
class LogInPage;
}

class LogInPage : public QDialog
{
    Q_OBJECT

public:
    explicit LogInPage(QWidget *parent = nullptr);
    ~LogInPage();

private slots:
    void on_back_clicked();

    void on_logIn_clicked();

    void on_checkBox_2_stateChanged(int arg1);

    bool on_checkBox_stateChanged(int arg1);

private:
    ServerConnection* conexiuneServer;
    Ui::LogInPage *ui;
    MainWindow* mainW;

    static bool rememberMe;
    AutoLogIn* autoLogger;

public slots:
    void handleLogInResponse(const QJsonObject& response);
};

#endif // LOGINPAGE_H
