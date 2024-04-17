#ifndef MERCHSHOP_H
#define MERCHSHOP_H

#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QSqlDatabase>
#include <QSqlQuery>
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
    QSqlDatabase db;
    Ui::MerchShop *ui;
    QLineEdit* searchLineEdit;
    QPushButton* searchButton;
    QGridLayout* mainLayout;

    void addMerch(QSqlDatabase db);
};

#endif // MERCHSHOP_H
