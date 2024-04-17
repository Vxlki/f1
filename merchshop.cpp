#include "merchshop.h"
#include "ui_merchshop.h"
#include "clothing.h"
#include "accesories.h"

MerchShop::MerchShop(QSqlDatabase db, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MerchShop)
{
    ui->setupUi(this);

    this->db = db;

    this->searchLineEdit = new QLineEdit;
    this->searchButton = new QPushButton("Search");
    this->searchLineEdit->setPlaceholderText("Search...");
    ui->statusbar->addWidget(searchLineEdit);
    ui->statusbar->addWidget(searchButton);

    this->mainLayout = new QGridLayout(this);

    addMerch(this->db);

}

void MerchShop::addMerch(QSqlDatabase db)
{
    QSqlQuery query;
    query.prepare("SELECT P.Name, P.Price, P.Size, P.Type, T.TeamName FROM Products P INNER JOIN Teams T ON P.TeamID = T.TeamID");

    if(query.exec())
    {
        while(query.next())
        {
            QString name = query.value(0).toString();
            float price = query.value(1).toString().toDouble();
            QString size = query.value(2).toString();
            QString type = query.value(3).toString();
            QString teamName = query.value(4).toString();
            if(type == "Accessories")
            {
                Accesories* accesoriu = new Accesories(name, price, size, teamName);
                this->products.push_back(accesoriu);
            }

            if(type == "Clothing")
            {
                Clothing* vestimentara = new Clothing(name, price, size, teamName);
                this->products.push_back(vestimentara);
            }
        }
    }
}

MerchShop::~MerchShop()
{
    delete ui;
}
