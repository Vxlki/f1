#include "merchshop.h"
#include "ui_merchshop.h"
#include "clothing.h"
#include "accesories.h"
#include "productframe.h"
#include "functiiutile.h"

MerchShop::MerchShop(QSqlDatabase db, QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MerchShop) {
    ui->setupUi(this);

    this->db = db;

    this->searchLineEdit = new QLineEdit;
    this->searchButton = new QPushButton("Search");
    this->searchLineEdit->setPlaceholderText("Search...");
    ui->statusbar->addWidget(searchLineEdit);
    ui->statusbar->addWidget(searchButton);

    QWidget *centralWidget = new QWidget(this);
    this->mainLayout = new QVBoxLayout(centralWidget);

    this->mainScrollArea = new QScrollArea(this);
    this->mainScrollArea->setWidgetResizable(true);
    QWidget *mainScrollWidget = new QWidget;
    mainScrollWidget->setLayout(this->mainLayout);
    this->mainScrollArea->setWidget(mainScrollWidget);

    this->clothingScrollArea = new QScrollArea(this);
    this->clothingScrollArea->setWidgetResizable(true);
    QWidget *clothingScrollWidget = new QWidget;
    this->clothingLayout = new QHBoxLayout(clothingScrollWidget);
    clothingScrollWidget->setLayout(this->clothingLayout);
    this->clothingScrollArea->setWidget(clothingScrollWidget);

    this->accessoriesScrollArea = new QScrollArea(this);
    this->accessoriesScrollArea->setWidgetResizable(true);
    QWidget *accessoriesScrollWidget = new QWidget;
    this->accessoriesLayout = new QHBoxLayout(accessoriesScrollWidget);
    accessoriesScrollWidget->setLayout(this->accessoriesLayout);
    this->accessoriesScrollArea->setWidget(accessoriesScrollWidget);

    this->mainLayout->addWidget(this->clothingScrollArea);
    this->mainLayout->addWidget(this->accessoriesScrollArea);

    this->setCentralWidget(this->mainScrollArea);

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
                QString teamName2 = teamName;
                FunctiiUtile::setBlankSpaceToUnderline(teamName2);
                qDebug()<<teamName2;
                QImage image(":/teams/Teams/" + teamName2 + ".png");
                Accesories* accesoriu = new Accesories(image, image, name, price, size, teamName);
                this->products.push_back(accesoriu);
                ProductFrame* frame = new ProductFrame(accesoriu);
                this->accessoriesLayout->addWidget(frame);
            }

            else
                if(type == "Clothing")
                {
                    QString teamName2 = teamName;
                    FunctiiUtile::setBlankSpaceToUnderline(teamName2);
                    qDebug()<<teamName2;
                    QImage image(":/teams/Teams/" + teamName2 + ".png");
                    Clothing* vestimentara = new Clothing(image, image, name, price, size, teamName);
                    this->products.push_back(vestimentara);
                    ProductFrame* frame = new ProductFrame(vestimentara);
                    this->accessoriesLayout->addWidget(frame);
                }
        }
    }
}

MerchShop::~MerchShop()
{
    delete ui;
}
