/********************************************************************************
** Form generated from reading UI file 'ticketsbuywindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TICKETSBUYWINDOW_H
#define UI_TICKETSBUYWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TicketsBuyWindow
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *TicketsBuyWindow)
    {
        if (TicketsBuyWindow->objectName().isEmpty())
            TicketsBuyWindow->setObjectName("TicketsBuyWindow");
        TicketsBuyWindow->resize(800, 600);
        centralwidget = new QWidget(TicketsBuyWindow);
        centralwidget->setObjectName("centralwidget");
        TicketsBuyWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(TicketsBuyWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        TicketsBuyWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(TicketsBuyWindow);
        statusbar->setObjectName("statusbar");
        TicketsBuyWindow->setStatusBar(statusbar);

        retranslateUi(TicketsBuyWindow);

        QMetaObject::connectSlotsByName(TicketsBuyWindow);
    } // setupUi

    void retranslateUi(QMainWindow *TicketsBuyWindow)
    {
        TicketsBuyWindow->setWindowTitle(QCoreApplication::translate("TicketsBuyWindow", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TicketsBuyWindow: public Ui_TicketsBuyWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TICKETSBUYWINDOW_H
