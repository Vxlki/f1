#ifndef I_PRODUCT_H
#define I_PRODUCT_H
#include <QString>

class I_Product
{
public:
    I_Product();
    //I_Product(QString name, float price, QString teamName);
    virtual QString getNameOfProduct() = 0;
    virtual float getPriceOfProduct() = 0;
    virtual QString getTeamNameOfProduct() = 0;
};

#endif // I_PRODUCT_H
