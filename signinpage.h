#ifndef SIGNINPAGE_H
#define SIGNINPAGE_H

#include <QDialog>
#include <i_personnel.h>
#include <c_teams.h>
#include "mainwindow.h"

class ServerConnection;

namespace Ui {
class SignInPage;
}

class SignInPage : public QDialog
{
    Q_OBJECT

public slots:
    void handleSignInResponse(const QJsonObject& response);

public:
    explicit SignInPage(std::vector<I_Personnel*> drivers, std::vector<C_Teams*> teams, QWidget *parent = nullptr);
    ~SignInPage();

private slots:
    void on_back_clicked();

    void on_SignIn_clicked();

    void on_checkBox_stateChanged(int arg1);

    void onComboSelectionChanged(int index);
    void onCombo2SelectionChanged(int index);
    void onCombo3SelectionChanged(int index);
    void onCombo4SelectionChanged(int index);
    void onCombo5SelectionChanged(int index);

private:
    Ui::SignInPage *ui;
    ServerConnection* conexiuneServer;
    MainWindow* mainW;

    std::vector<I_Personnel*> drivers;
    std::vector<C_Teams*> teams;
    void populateComboBoxes();
};

#endif // SIGNINPAGE_H
