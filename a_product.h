#ifndef A_PRODUCT_H
#define A_PRODUCT_H

#include "i_product.h"

class A_Product : public I_Product
{
public:
    A_Product(QImage image, QImage teamImage, QString name, float price, QString teamName, QString size);
    virtual QString getNameOfProduct() override;
    virtual float getPriceOfProduct() override;
    virtual QString getTeamNameOfProduct() override;
    virtual QImage getImage() override;
    virtual QImage getTeamImage() override;
protected:
    QString name;
    float price;
    QString teamName;
    QString size;
    QImage image;
    QImage teamImage;
};

#endif // A_PRODUCT_H
