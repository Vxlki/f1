#ifndef CLOTHING_H
#define CLOTHING_H

#include "a_product.h"

class Clothing : public A_Product
{
public:
    Clothing(QImage image, QImage teamImage, QString name, float price, QString teamName, QString size);
};

#endif // CLOTHING_H
