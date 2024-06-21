/********************************************************************************
** Form generated from reading UI file 'productframe.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRODUCTFRAME_H
#define UI_PRODUCTFRAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>

QT_BEGIN_NAMESPACE

class Ui_ProductFrame
{
public:

    void setupUi(QFrame *ProductFrame)
    {
        if (ProductFrame->objectName().isEmpty())
            ProductFrame->setObjectName("ProductFrame");
        ProductFrame->resize(400, 300);

        retranslateUi(ProductFrame);

        QMetaObject::connectSlotsByName(ProductFrame);
    } // setupUi

    void retranslateUi(QFrame *ProductFrame)
    {
        ProductFrame->setWindowTitle(QCoreApplication::translate("ProductFrame", "Frame", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ProductFrame: public Ui_ProductFrame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRODUCTFRAME_H
