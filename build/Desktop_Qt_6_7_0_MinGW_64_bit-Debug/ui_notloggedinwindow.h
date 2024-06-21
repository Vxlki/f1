/********************************************************************************
** Form generated from reading UI file 'notloggedinwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NOTLOGGEDINWINDOW_H
#define UI_NOTLOGGEDINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_notLoggedInWindow
{
public:
    QLabel *label;
    QPushButton *LogIn;
    QPushButton *SignIn;
    QLabel *piclabel;

    void setupUi(QDialog *notLoggedInWindow)
    {
        if (notLoggedInWindow->objectName().isEmpty())
            notLoggedInWindow->setObjectName("notLoggedInWindow");
        notLoggedInWindow->resize(741, 453);
        label = new QLabel(notLoggedInWindow);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 0, 731, 231));
        QFont font;
        font.setPointSize(36);
        label->setFont(font);
        LogIn = new QPushButton(notLoggedInWindow);
        LogIn->setObjectName("LogIn");
        LogIn->setGeometry(QRect(80, 230, 201, 81));
        LogIn->setFont(font);
        SignIn = new QPushButton(notLoggedInWindow);
        SignIn->setObjectName("SignIn");
        SignIn->setGeometry(QRect(460, 230, 201, 81));
        SignIn->setFont(font);
        piclabel = new QLabel(notLoggedInWindow);
        piclabel->setObjectName("piclabel");
        piclabel->setGeometry(QRect(0, 40, 741, 451));
        piclabel->raise();
        label->raise();
        LogIn->raise();
        SignIn->raise();

        retranslateUi(notLoggedInWindow);

        SignIn->setDefault(false);


        QMetaObject::connectSlotsByName(notLoggedInWindow);
    } // setupUi

    void retranslateUi(QDialog *notLoggedInWindow)
    {
        notLoggedInWindow->setWindowTitle(QCoreApplication::translate("notLoggedInWindow", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("notLoggedInWindow", "Welcome! Please log in or sign in!", nullptr));
        LogIn->setText(QCoreApplication::translate("notLoggedInWindow", "Log In", nullptr));
        SignIn->setText(QCoreApplication::translate("notLoggedInWindow", "Sign In", nullptr));
        piclabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class notLoggedInWindow: public Ui_notLoggedInWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOTLOGGEDINWINDOW_H
