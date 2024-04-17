#ifndef ACCESORIES_H
#define ACCESORIES_H

#include "a_product.h"

class Accesories : public A_Product
{
public:
    Accesories(QString name, float price, QString teamName, QString size);
};

#endif // ACCESORIES_H
