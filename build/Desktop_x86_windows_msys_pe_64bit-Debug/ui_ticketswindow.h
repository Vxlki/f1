/********************************************************************************
** Form generated from reading UI file 'ticketswindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TICKETSWINDOW_H
#define UI_TICKETSWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ticketsWindow
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ticketsWindow)
    {
        if (ticketsWindow->objectName().isEmpty())
            ticketsWindow->setObjectName("ticketsWindow");
        ticketsWindow->resize(800, 600);
        centralwidget = new QWidget(ticketsWindow);
        centralwidget->setObjectName("centralwidget");
        ticketsWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ticketsWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 25));
        ticketsWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(ticketsWindow);
        statusbar->setObjectName("statusbar");
        ticketsWindow->setStatusBar(statusbar);

        retranslateUi(ticketsWindow);

        QMetaObject::connectSlotsByName(ticketsWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ticketsWindow)
    {
        ticketsWindow->setWindowTitle(QCoreApplication::translate("ticketsWindow", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ticketsWindow: public Ui_ticketsWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TICKETSWINDOW_H
