/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionTeams;
    QAction *actionCircuits;
    QAction *actionGrand_Prix;
    QAction *actionTickets;
    QAction *actionMerch_Shop;
    QAction *actionProfile;
    QWidget *centralwidget;
    QToolBar *toolBar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        actionTeams = new QAction(MainWindow);
        actionTeams->setObjectName("actionTeams");
        actionTeams->setMenuRole(QAction::NoRole);
        actionCircuits = new QAction(MainWindow);
        actionCircuits->setObjectName("actionCircuits");
        actionCircuits->setMenuRole(QAction::NoRole);
        actionGrand_Prix = new QAction(MainWindow);
        actionGrand_Prix->setObjectName("actionGrand_Prix");
        actionGrand_Prix->setMenuRole(QAction::NoRole);
        actionTickets = new QAction(MainWindow);
        actionTickets->setObjectName("actionTickets");
        actionTickets->setMenuRole(QAction::NoRole);
        actionMerch_Shop = new QAction(MainWindow);
        actionMerch_Shop->setObjectName("actionMerch_Shop");
        actionMerch_Shop->setMenuRole(QAction::NoRole);
        actionProfile = new QAction(MainWindow);
        actionProfile->setObjectName("actionProfile");
        actionProfile->setMenuRole(QAction::NoRole);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        MainWindow->setCentralWidget(centralwidget);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName("toolBar");
        sizePolicy.setHeightForWidth(toolBar->sizePolicy().hasHeightForWidth());
        toolBar->setSizePolicy(sizePolicy);
        toolBar->setLayoutDirection(Qt::LeftToRight);
        MainWindow->addToolBar(Qt::ToolBarArea::TopToolBarArea, toolBar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        toolBar->addAction(actionTeams);
        toolBar->addSeparator();
        toolBar->addAction(actionCircuits);
        toolBar->addAction(actionGrand_Prix);
        toolBar->addAction(actionTickets);
        toolBar->addAction(actionProfile);
        toolBar->addAction(actionMerch_Shop);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionTeams->setText(QCoreApplication::translate("MainWindow", "Teams", nullptr));
        actionCircuits->setText(QCoreApplication::translate("MainWindow", "Circuits", nullptr));
        actionGrand_Prix->setText(QCoreApplication::translate("MainWindow", "Grand Prix", nullptr));
        actionTickets->setText(QCoreApplication::translate("MainWindow", "Tickets", nullptr));
        actionMerch_Shop->setText(QCoreApplication::translate("MainWindow", "Merch Shop", nullptr));
        actionProfile->setText(QCoreApplication::translate("MainWindow", "Profile", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
