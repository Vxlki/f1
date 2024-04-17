#ifndef LOGINPAGE_H
#define LOGINPAGE_H

#include <QDialog>

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

private:
    Ui::LogInPage *ui;
    MainWindow* mainW;
};

#endif // LOGINPAGE_H
