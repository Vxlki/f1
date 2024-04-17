#include "notloggedinwindow.h"
#include "ui_notloggedinwindow.h"
#include "loginpage.h"
#include "signinpage.h"
#include <QPixmap>

notLoggedInWindow::notLoggedInWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::notLoggedInWindow)
{
    ui->setupUi(this);



    QPixmap pix (":/img/F1-Logo.png");
    int w = ui->piclabel->width();
    int h = ui->piclabel->height();

    ui->piclabel->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
}

notLoggedInWindow::~notLoggedInWindow()
{
    delete ui;
}

void notLoggedInWindow::on_LogIn_clicked()
{
    hide();
    loginW = new LogInPage(this);
    loginW->show();
}


void notLoggedInWindow::on_SignIn_clicked()
{
    hide();
    signinW = new SignInPage(this);
    signinW->show();
}

