#ifndef MERCHSHOP_H
#define MERCHSHOP_H

#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QScrollArea>
#include <QLabel>
#include "i_product.h"

namespace Ui {
class MerchShop;
}

class MerchShop : public QMainWindow
{
    Q_OBJECT

public:
    explicit MerchShop(QSqlDatabase db, QWidget *parent = nullptr);
    ~MerchShop();

private:
    std::vector<I_Product*> products;
    std::vector<QLabel*> labels;
    QSqlDatabase db;
    Ui::MerchShop *ui;
    QLineEdit* searchLineEdit;
    QPushButton* searchButton;
    QVBoxLayout* mainLayout;
    QScrollArea* mainScrollArea;
    QHBoxLayout* clothingLayout;
    QScrollArea* clothingScrollArea;
    QHBoxLayout* accessoriesLayout;
    QScrollArea* accessoriesScrollArea;

    void addMerch(QSqlDatabase db);
};

#endif // MERCHSHOP_H
