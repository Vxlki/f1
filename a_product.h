#ifndef A_PRODUCT_H
#define A_PRODUCT_H

#include "i_product.h"

class A_Product : public I_Product
{
public:
    A_Product(QString name, float price, QString teamName, QString size);
    virtual QString getNameOfProduct() override;
    virtual float getPriceOfProduct() override;
    virtual QString getTeamNameOfProduct() override;
protected:
    QString name;
    float price;
    QString teamName;
    QString size;
};

#endif // A_PRODUCT_H
