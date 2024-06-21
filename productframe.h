#ifndef PRODUCTFRAME_H
#define PRODUCTFRAME_H

#include <QFrame>
#include <QImage>
#include <QString>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include "i_product.h"

namespace Ui {
class ProductFrame;
}

class ProductFrame : public QFrame
{
    Q_OBJECT

public:
    explicit ProductFrame(I_Product* product, QWidget *parent = nullptr);
    ~ProductFrame();

private:
    Ui::ProductFrame *ui;
    I_Product* product;

    std::vector<QLabel*> labels;
    QHBoxLayout* hLayout;
    QVBoxLayout* vLayout;
};

#endif // PRODUCTFRAME_H
