/********************************************************************************
** Form generated from reading UI file 'server.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVER_H
#define UI_SERVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_server
{
public:

    void setupUi(QDialog *server)
    {
        if (server->objectName().isEmpty())
            server->setObjectName("server");
        server->resize(400, 300);

        retranslateUi(server);

        QMetaObject::connectSlotsByName(server);
    } // setupUi

    void retranslateUi(QDialog *server)
    {
        server->setWindowTitle(QCoreApplication::translate("server", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class server: public Ui_server {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVER_H
