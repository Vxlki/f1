/********************************************************************************
** Form generated from reading UI file 'grandprixwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRANDPRIXWINDOW_H
#define UI_GRANDPRIXWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GrandPrixWindow
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *GrandPrixWindow)
    {
        if (GrandPrixWindow->objectName().isEmpty())
            GrandPrixWindow->setObjectName("GrandPrixWindow");
        GrandPrixWindow->resize(800, 600);
        centralwidget = new QWidget(GrandPrixWindow);
        centralwidget->setObjectName("centralwidget");
        GrandPrixWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(GrandPrixWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        GrandPrixWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(GrandPrixWindow);
        statusbar->setObjectName("statusbar");
        GrandPrixWindow->setStatusBar(statusbar);

        retranslateUi(GrandPrixWindow);

        QMetaObject::connectSlotsByName(GrandPrixWindow);
    } // setupUi

    void retranslateUi(QMainWindow *GrandPrixWindow)
    {
        GrandPrixWindow->setWindowTitle(QCoreApplication::translate("GrandPrixWindow", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GrandPrixWindow: public Ui_GrandPrixWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRANDPRIXWINDOW_H
