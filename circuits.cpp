#include "circuits.h"
#include "ui_circuits.h"
#include "functiiutile.h"


Circuits::Circuits(std::vector<C_Circuits*> circuits, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Circuits)
{
    ui->setupUi(this);

    this->circuits = circuits;

    this->mainPage = new QWidget(this);
    this->setCentralWidget(mainPage);

    this->labelStyle = "font: bold 12pt Arial; "
                       "background-color: #af0034;";
    QLabel* titleLabel = new QLabel("Circuits");
    titleLabel->setStyleSheet("font: bold 55pt Arial; "
                              "background-color: #af0034;");
    titleLabel->setAlignment(Qt::AlignCenter);

    this->scrollArea = new QScrollArea(mainPage);
    this->scrollArea->setWidgetResizable(true);

    this->scrollAreaContent = new QWidget;
    this->scrollArea->setWidget(scrollAreaContent);

    QVBoxLayout* verticalLayout = new QVBoxLayout(mainPage);
    verticalLayout->addWidget(titleLabel);
    verticalLayout->addWidget(scrollArea);

    this->mainLayout = new QGridLayout(scrollAreaContent);
    this->mainLayout->setVerticalSpacing(150);
    this->mainLayout->setHorizontalSpacing(200);

    addCircuits();
}

void Circuits::addCircuits()
{
    int i = 0, j=0;
    for(int k=0;k<this->circuits.size();k++)
    {
        QString CircuitName = circuits[k]->getCircuitName();
        QString length = QString::number(circuits[k]->getLength());
        QString turns = QString::number(circuits[k]->getTurns());
        QString nrOfLaps = QString::number(circuits[k]->getNrOfLaps());
        QString firstGp = circuits[k]->getFirstGP().toString();
        QString country = circuits[k]->getAddress().getCountry();
        QString city = circuits[k]->getAddress().getCity();
        QString street = circuits[k]->getAddress().getStreet();

        QString imgName = CircuitName;
        FunctiiUtile::setBlankSpaceToUnderline(imgName);
        QLabel* imgLabel = new QLabel;
        QLabel* lengthLabel = new QLabel;
        QLabel* turnsLabel = new QLabel;
        QLabel* nrOfLapsLabel = new QLabel;
        QLabel* firstGpLabel = new QLabel;
        QLabel* countryLabel = new QLabel;
        QLabel* cityLabel = new QLabel;
        QLabel* streetLabel = new QLabel;

        lengthLabel->setStyleSheet(this->labelStyle);
        turnsLabel->setStyleSheet(this->labelStyle);
        nrOfLapsLabel->setStyleSheet(this->labelStyle);
        firstGpLabel->setStyleSheet(this->labelStyle);
        countryLabel->setStyleSheet(this->labelStyle);
        cityLabel->setStyleSheet(this->labelStyle);
        streetLabel->setStyleSheet(this->labelStyle);

        QString img = QString(":/circuits/Circuits/%1.png").arg(imgName);
        //qDebug() << imgName<<"\n";
        QPixmap pix(img);
        QPixmap scaledPix = pix.scaled(QSize(503,503), Qt::KeepAspectRatio, Qt::SmoothTransformation);
        imgLabel->setPixmap(scaledPix);
        imgLabel->setScaledContents(true);
        imgLabel->setMaximumSize(300,200);
        //imgLabel->setPixmap(pix);
        imgLabel->setStyleSheet("border: 8px solid #ff232b; "
                                "border-radius: 20px; ");
        lengthLabel->setText("Length: " + length);
        turnsLabel->setText("Turns: " + turns);
        nrOfLapsLabel->setText("Nr. of lap .: " + nrOfLaps);
        firstGpLabel->setText("Date of firs Grand Prix: " + firstGp);
        countryLabel->setText("Country: " + country);
        cityLabel->setText("City: " + city);
        streetLabel->setText("Street: " + street);

        this->mainLayout->addWidget(imgLabel, i, j++);
        QVBoxLayout* verticalLayout = new QVBoxLayout;
        verticalLayout->addWidget(lengthLabel);
        verticalLayout->addWidget(turnsLabel);
        verticalLayout->addWidget(nrOfLapsLabel);
        verticalLayout->addWidget(firstGpLabel);
        verticalLayout->addWidget(countryLabel);
        verticalLayout->addWidget(cityLabel);
        verticalLayout->addWidget(streetLabel);
        this->mainLayout->addLayout(verticalLayout,i++, j);
        j = 0;
    }
}

Circuits::~Circuits()
{
    delete ui;
}

// void Circuits::handleCircuitsWindowResponse(const QJsonObject &response)
// {

// }
