/********************************************************************************
** Form generated from reading UI file 'merchshop.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MERCHSHOP_H
#define UI_MERCHSHOP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MerchShop
{
public:
    QWidget *centralwidget;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MerchShop)
    {
        if (MerchShop->objectName().isEmpty())
            MerchShop->setObjectName("MerchShop");
        MerchShop->resize(800, 600);
        centralwidget = new QWidget(MerchShop);
        centralwidget->setObjectName("centralwidget");
        MerchShop->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MerchShop);
        statusbar->setObjectName("statusbar");
        MerchShop->setStatusBar(statusbar);

        retranslateUi(MerchShop);

        QMetaObject::connectSlotsByName(MerchShop);
    } // setupUi

    void retranslateUi(QMainWindow *MerchShop)
    {
        MerchShop->setWindowTitle(QCoreApplication::translate("MerchShop", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MerchShop: public Ui_MerchShop {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MERCHSHOP_H
