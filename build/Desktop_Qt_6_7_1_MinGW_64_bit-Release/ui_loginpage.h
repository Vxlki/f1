/********************************************************************************
** Form generated from reading UI file 'loginpage.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINPAGE_H
#define UI_LOGINPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_LogInPage
{
public:
    QPushButton *back;
    QCheckBox *checkBox;
    QPushButton *logIn;
    QLineEdit *lineEdit_user;
    QLineEdit *lineEdit_pass;
    QCheckBox *checkBox_2;

    void setupUi(QDialog *LogInPage)
    {
        if (LogInPage->objectName().isEmpty())
            LogInPage->setObjectName("LogInPage");
        LogInPage->resize(675, 430);
        back = new QPushButton(LogInPage);
        back->setObjectName("back");
        back->setGeometry(QRect(130, 320, 141, 51));
        checkBox = new QCheckBox(LogInPage);
        checkBox->setObjectName("checkBox");
        checkBox->setGeometry(QRect(160, 230, 171, 31));
        logIn = new QPushButton(LogInPage);
        logIn->setObjectName("logIn");
        logIn->setGeometry(QRect(350, 320, 141, 51));
        lineEdit_user = new QLineEdit(LogInPage);
        lineEdit_user->setObjectName("lineEdit_user");
        lineEdit_user->setGeometry(QRect(160, 40, 341, 81));
        lineEdit_pass = new QLineEdit(LogInPage);
        lineEdit_pass->setObjectName("lineEdit_pass");
        lineEdit_pass->setGeometry(QRect(160, 140, 341, 81));
        checkBox_2 = new QCheckBox(LogInPage);
        checkBox_2->setObjectName("checkBox_2");
        checkBox_2->setGeometry(QRect(160, 270, 171, 31));

        retranslateUi(LogInPage);

        QMetaObject::connectSlotsByName(LogInPage);
    } // setupUi

    void retranslateUi(QDialog *LogInPage)
    {
        LogInPage->setWindowTitle(QCoreApplication::translate("LogInPage", "Dialog", nullptr));
        back->setText(QCoreApplication::translate("LogInPage", "Back", nullptr));
        checkBox->setText(QCoreApplication::translate("LogInPage", "Keep Me Logged In", nullptr));
        logIn->setText(QCoreApplication::translate("LogInPage", "Log In", nullptr));
        lineEdit_user->setText(QString());
        lineEdit_pass->setText(QString());
        checkBox_2->setText(QCoreApplication::translate("LogInPage", "Show Password", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LogInPage: public Ui_LogInPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINPAGE_H
