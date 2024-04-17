#include "a_product.h"

A_Product::A_Product(QString name, float price, QString teamName, QString size)
{
    this->name = name;
    this->price = price;
    this->teamName = teamName;
    this->size = size;
}

QString A_Product::getNameOfProduct()
{
    return this->name;
}

float A_Product::getPriceOfProduct()
{
    return this->price;
}

QString A_Product::getTeamNameOfProduct()
{
    return this->teamName;
}
