/********************************************************************************
** Form generated from reading UI file 'serverconnection.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVERCONNECTION_H
#define UI_SERVERCONNECTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ServerConnection
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ServerConnection)
    {
        if (ServerConnection->objectName().isEmpty())
            ServerConnection->setObjectName("ServerConnection");
        ServerConnection->resize(800, 600);
        centralwidget = new QWidget(ServerConnection);
        centralwidget->setObjectName("centralwidget");
        ServerConnection->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ServerConnection);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 25));
        ServerConnection->setMenuBar(menubar);
        statusbar = new QStatusBar(ServerConnection);
        statusbar->setObjectName("statusbar");
        ServerConnection->setStatusBar(statusbar);

        retranslateUi(ServerConnection);

        QMetaObject::connectSlotsByName(ServerConnection);
    } // setupUi

    void retranslateUi(QMainWindow *ServerConnection)
    {
        ServerConnection->setWindowTitle(QCoreApplication::translate("ServerConnection", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ServerConnection: public Ui_ServerConnection {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVERCONNECTION_H
