/********************************************************************************
** Form generated from reading UI file 'teams.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEAMS_H
#define UI_TEAMS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Teams
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Teams)
    {
        if (Teams->objectName().isEmpty())
            Teams->setObjectName("Teams");
        Teams->resize(800, 600);
        centralwidget = new QWidget(Teams);
        centralwidget->setObjectName("centralwidget");
        Teams->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Teams);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 25));
        Teams->setMenuBar(menubar);
        statusbar = new QStatusBar(Teams);
        statusbar->setObjectName("statusbar");
        Teams->setStatusBar(statusbar);

        retranslateUi(Teams);

        QMetaObject::connectSlotsByName(Teams);
    } // setupUi

    void retranslateUi(QMainWindow *Teams)
    {
        Teams->setWindowTitle(QCoreApplication::translate("Teams", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Teams: public Ui_Teams {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEAMS_H
