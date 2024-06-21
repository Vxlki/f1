/********************************************************************************
** Form generated from reading UI file 'profilewindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROFILEWINDOW_H
#define UI_PROFILEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProfileWindow
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ProfileWindow)
    {
        if (ProfileWindow->objectName().isEmpty())
            ProfileWindow->setObjectName("ProfileWindow");
        ProfileWindow->resize(800, 600);
        centralwidget = new QWidget(ProfileWindow);
        centralwidget->setObjectName("centralwidget");
        ProfileWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ProfileWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 25));
        ProfileWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(ProfileWindow);
        statusbar->setObjectName("statusbar");
        ProfileWindow->setStatusBar(statusbar);

        retranslateUi(ProfileWindow);

        QMetaObject::connectSlotsByName(ProfileWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ProfileWindow)
    {
        ProfileWindow->setWindowTitle(QCoreApplication::translate("ProfileWindow", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ProfileWindow: public Ui_ProfileWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROFILEWINDOW_H
