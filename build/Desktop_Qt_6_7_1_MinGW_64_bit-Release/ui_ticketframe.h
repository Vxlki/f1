/********************************************************************************
** Form generated from reading UI file 'ticketframe.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TICKETFRAME_H
#define UI_TICKETFRAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>

QT_BEGIN_NAMESPACE

class Ui_TicketFrame
{
public:

    void setupUi(QFrame *TicketFrame)
    {
        if (TicketFrame->objectName().isEmpty())
            TicketFrame->setObjectName("TicketFrame");
        TicketFrame->resize(400, 300);

        retranslateUi(TicketFrame);

        QMetaObject::connectSlotsByName(TicketFrame);
    } // setupUi

    void retranslateUi(QFrame *TicketFrame)
    {
        TicketFrame->setWindowTitle(QCoreApplication::translate("TicketFrame", "Frame", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TicketFrame: public Ui_TicketFrame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TICKETFRAME_H
