/********************************************************************************
** Form generated from reading UI file 'signinpage.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNINPAGE_H
#define UI_SIGNINPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_SignInPage
{
public:
    QPushButton *back;
    QPushButton *SignIn;
    QLabel *label;
    QComboBox *comboBox;
    QComboBox *comboBox_2;
    QLabel *label_2;
    QComboBox *comboBox_3;
    QComboBox *comboBox_4;
    QComboBox *comboBox_5;
    QLineEdit *lineEdit_user;
    QLineEdit *lineEdit_pass;
    QLineEdit *lineEdit_cpass;
    QLineEdit *lineEdit_mail;
    QLineEdit *lineEdit_tele;
    QCheckBox *checkBox;

    void setupUi(QDialog *SignInPage)
    {
        if (SignInPage->objectName().isEmpty())
            SignInPage->setObjectName("SignInPage");
        SignInPage->resize(851, 559);
        back = new QPushButton(SignInPage);
        back->setObjectName("back");
        back->setGeometry(QRect(20, 460, 141, 71));
        SignIn = new QPushButton(SignInPage);
        SignIn->setObjectName("SignIn");
        SignIn->setGeometry(QRect(200, 460, 151, 71));
        label = new QLabel(SignInPage);
        label->setObjectName("label");
        label->setGeometry(QRect(490, 40, 321, 61));
        QFont font;
        font.setPointSize(24);
        label->setFont(font);
        label->setFrameShape(QFrame::StyledPanel);
        comboBox = new QComboBox(SignInPage);
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(490, 130, 321, 31));
        comboBox_2 = new QComboBox(SignInPage);
        comboBox_2->setObjectName("comboBox_2");
        comboBox_2->setGeometry(QRect(490, 180, 321, 31));
        label_2 = new QLabel(SignInPage);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(490, 250, 321, 61));
        label_2->setFont(font);
        label_2->setFrameShape(QFrame::StyledPanel);
        comboBox_3 = new QComboBox(SignInPage);
        comboBox_3->setObjectName("comboBox_3");
        comboBox_3->setGeometry(QRect(490, 340, 321, 31));
        comboBox_4 = new QComboBox(SignInPage);
        comboBox_4->setObjectName("comboBox_4");
        comboBox_4->setGeometry(QRect(490, 390, 321, 31));
        comboBox_5 = new QComboBox(SignInPage);
        comboBox_5->setObjectName("comboBox_5");
        comboBox_5->setGeometry(QRect(490, 440, 321, 31));
        lineEdit_user = new QLineEdit(SignInPage);
        lineEdit_user->setObjectName("lineEdit_user");
        lineEdit_user->setGeometry(QRect(20, 40, 331, 61));
        lineEdit_pass = new QLineEdit(SignInPage);
        lineEdit_pass->setObjectName("lineEdit_pass");
        lineEdit_pass->setGeometry(QRect(20, 120, 331, 61));
        lineEdit_pass->setEchoMode(QLineEdit::Password);
        lineEdit_cpass = new QLineEdit(SignInPage);
        lineEdit_cpass->setObjectName("lineEdit_cpass");
        lineEdit_cpass->setGeometry(QRect(20, 200, 331, 61));
        lineEdit_cpass->setEchoMode(QLineEdit::Password);
        lineEdit_mail = new QLineEdit(SignInPage);
        lineEdit_mail->setObjectName("lineEdit_mail");
        lineEdit_mail->setGeometry(QRect(20, 310, 331, 61));
        lineEdit_tele = new QLineEdit(SignInPage);
        lineEdit_tele->setObjectName("lineEdit_tele");
        lineEdit_tele->setGeometry(QRect(20, 390, 331, 61));
        checkBox = new QCheckBox(SignInPage);
        checkBox->setObjectName("checkBox");
        checkBox->setGeometry(QRect(110, 270, 151, 21));
        QFont font1;
        font1.setPointSize(14);
        checkBox->setFont(font1);

        retranslateUi(SignInPage);

        QMetaObject::connectSlotsByName(SignInPage);
    } // setupUi

    void retranslateUi(QDialog *SignInPage)
    {
        SignInPage->setWindowTitle(QCoreApplication::translate("SignInPage", "Dialog", nullptr));
        back->setText(QCoreApplication::translate("SignInPage", "Back", nullptr));
        SignIn->setText(QCoreApplication::translate("SignInPage", "Sign In", nullptr));
        label->setText(QCoreApplication::translate("SignInPage", "Your favorite teams", nullptr));
        label_2->setText(QCoreApplication::translate("SignInPage", "Your favorite drivers", nullptr));
        lineEdit_user->setText(QString());
        lineEdit_pass->setText(QString());
        lineEdit_cpass->setText(QString());
        lineEdit_mail->setText(QString());
        lineEdit_tele->setText(QString());
        checkBox->setText(QCoreApplication::translate("SignInPage", "Show Password", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SignInPage: public Ui_SignInPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNINPAGE_H
