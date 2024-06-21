#include "a_product.h"

A_Product::A_Product(QImage image, QImage teamImage, QString name, float price, QString teamName, QString size)
{
    this->name = name;
    this->price = price;
    this->teamName = teamName;
    this->size = size;
    this->image = image;
    this->teamImage = teamImage;
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

QImage A_Product::getImage()
{
    return this->image;
}

QImage A_Product::getTeamImage()
{
    return this->teamImage;
}
