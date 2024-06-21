/********************************************************************************
** Form generated from reading UI file 'circuits.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CIRCUITS_H
#define UI_CIRCUITS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Circuits
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Circuits)
    {
        if (Circuits->objectName().isEmpty())
            Circuits->setObjectName("Circuits");
        Circuits->resize(800, 600);
        centralwidget = new QWidget(Circuits);
        centralwidget->setObjectName("centralwidget");
        Circuits->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Circuits);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 25));
        Circuits->setMenuBar(menubar);
        statusbar = new QStatusBar(Circuits);
        statusbar->setObjectName("statusbar");
        Circuits->setStatusBar(statusbar);

        retranslateUi(Circuits);

        QMetaObject::connectSlotsByName(Circuits);
    } // setupUi

    void retranslateUi(QMainWindow *Circuits)
    {
        Circuits->setWindowTitle(QCoreApplication::translate("Circuits", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Circuits: public Ui_Circuits {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CIRCUITS_H
