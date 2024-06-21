#include "clothing.h"

Clothing::Clothing(QImage image, QImage teamImage, QString name, float price, QString teamName, QString size)
    : A_Product(image, teamImage, name, price, size, teamName) {}
