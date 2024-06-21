/********************************************************************************
** Form generated from reading UI file 'test.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEST_H
#define UI_TEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Test
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Test)
    {
        if (Test->objectName().isEmpty())
            Test->setObjectName("Test");
        Test->resize(800, 600);
        centralwidget = new QWidget(Test);
        centralwidget->setObjectName("centralwidget");
        Test->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Test);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 25));
        Test->setMenuBar(menubar);
        statusbar = new QStatusBar(Test);
        statusbar->setObjectName("statusbar");
        Test->setStatusBar(statusbar);

        retranslateUi(Test);

        QMetaObject::connectSlotsByName(Test);
    } // setupUi

    void retranslateUi(QMainWindow *Test)
    {
        Test->setWindowTitle(QCoreApplication::translate("Test", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Test: public Ui_Test {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEST_H
