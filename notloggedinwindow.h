#ifndef NOTLOGGEDINWINDOW_H
#define NOTLOGGEDINWINDOW_H

#include <QDialog>
#include "databaseconnector.h"

#include "serverconnection.h"
#include "c_drivers.h"
#include "c_teams.h"

class LogInPage;
class SignInPage;

namespace Ui {
class notLoggedInWindow;
}

class notLoggedInWindow : public QDialog
{
    Q_OBJECT

public slots:
    void handlePersonnelResponse(const QJsonObject& response);
    void handleTeamsResponse(const QJsonObject& response);

public:
    explicit notLoggedInWindow(QWidget *parent = nullptr);
    ~notLoggedInWindow();


private slots:
    void on_LogIn_clicked();

    void on_SignIn_clicked();

private:
    DatabaseConnector m_dbConnector;
    Ui::notLoggedInWindow *ui;
    LogInPage* loginW;
    SignInPage* signinW;

    ServerConnection* conexiuneServer;
    std::vector<I_Personnel*> drivers;
    std::vector<C_Teams*> teams;
};

#endif // NOTLOGGEDINWINDOW_H
