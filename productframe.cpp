#include "productframe.h"
#include "ui_productframe.h"

ProductFrame::ProductFrame(I_Product* product, QWidget *parent)
    : QFrame(parent)
    , ui(new Ui::ProductFrame)
{
    ui->setupUi(this);

    this->product = product;

    this->hLayout = new QHBoxLayout(this);
    this->vLayout = new QVBoxLayout;
    QLabel* imgLabel = new QLabel;
    QPixmap pix = QPixmap::fromImage(this->product->getImage()).scaled(100, 100, Qt::KeepAspectRatio);
    imgLabel->setPixmap(pix);
    this->labels.push_back(imgLabel);

    QLabel* timgLabel = new QLabel;
    QPixmap tpix = QPixmap::fromImage(this->product->getTeamImage()).scaled(100, 100, Qt::KeepAspectRatio);
    imgLabel->setPixmap(tpix);
    this->labels.push_back(timgLabel);

    QLabel* nameLabel = new QLabel(this->product->getNameOfProduct());
    QLabel* teamLabel = new QLabel(this->product->getTeamNameOfProduct());
    QLabel* priceLabel = new QLabel(QString::fromStdString(std::to_string(this->product->getPriceOfProduct())));
    nameLabel->setStyleSheet("font-size: 30px; color: red;");
    teamLabel->setStyleSheet("font-size: 30px; color: red;");
    priceLabel->setStyleSheet("font-size: 30px; color: red;");
    this->labels.push_back(nameLabel);
    this->labels.push_back(teamLabel);
    this->labels.push_back(priceLabel);

    this->hLayout->addWidget(imgLabel);
    this->hLayout->addWidget(timgLabel);
    this->hLayout->addLayout(this->vLayout);
    this->vLayout->addWidget(nameLabel);
    this->vLayout->addWidget(teamLabel);
    this->vLayout->addWidget(priceLabel);

    this->setStyleSheet("QFrame {"
                        "background-color: white;"
                        "border: 5px solid black;"
                        // "border-radius: 10px;"
                        "}");
}

ProductFrame::~ProductFrame()
{
    delete ui;
}
