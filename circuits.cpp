#include "circuits.h"
#include "ui_circuits.h"
#include "functiiutile.h"


Circuits::Circuits(QSqlDatabase db, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Circuits)
{
    ui->setupUi(this);

    this->db = db;

    // int width = this->width();
    // int height = this->height();

    this->setMinimumSize(1080, 720);

    this->scrollArea = new QScrollArea(this);
    this->scrollArea->setWidgetResizable(true);
    this->scrollAreaContent = new QWidget(scrollArea);
    this->scrollArea->setWidget(scrollAreaContent);
    this->scrollArea->setMinimumSize(1080,720);
    this->mainLayout = new QGridLayout(scrollAreaContent);
    this->mainLayout->setVerticalSpacing(150);
    this->mainLayout->setHorizontalSpacing(200);

    addCircuits(this->db);

}

void Circuits::addCircuits(QSqlDatabase db)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM Circuits C INNER JOIN Address A ON C.AddressID = A.AddressID");

    if(query.exec())
    {
        int i = 0, j=0;
        while(query.next())
        {
            QString CircuitName = query.value(11).toString();
            QString length = query.value(2).toString();
            QString turns = query.value(4).toString();
            QString nrOfLaps = query.value(5).toString();
            QString firstGp = query.value(6).toString();
            QString country = query.value(9).toString();
            QString city = query.value(10).toString();
            QString street = query.value(11).toString();

            QString imgName = CircuitName;
            FunctiiUtile::setBlankSpaceToUnderline(imgName);
            QString labelStyle = "font: bold 12pt Arial; "
                                 "background-color: #af0034;";

            QLabel* imgLabel = new QLabel;
            QLabel* lengthLabel = new QLabel;
            QLabel* turnsLabel = new QLabel;
            QLabel* nrOfLapsLabel = new QLabel;
            QLabel* firstGpLabel = new QLabel;
            QLabel* countryLabel = new QLabel;
            QLabel* cityLabel = new QLabel;
            QLabel* streetLabel = new QLabel;

            lengthLabel->setStyleSheet(labelStyle);
            turnsLabel->setStyleSheet(labelStyle);
            nrOfLapsLabel->setStyleSheet(labelStyle);
            firstGpLabel->setStyleSheet(labelStyle);
            countryLabel->setStyleSheet(labelStyle);
            cityLabel->setStyleSheet(labelStyle);
            streetLabel->setStyleSheet(labelStyle);

            QString img = QString(":/circuits/Circuits/%1.png").arg(imgName);
            //qDebug() << imgName<<"\n";
            QPixmap pix(img);
            QPixmap scaledPix = pix.scaled(QSize(503,503), Qt::KeepAspectRatio, Qt::SmoothTransformation);
            imgLabel->setPixmap(scaledPix);
            imgLabel->setScaledContents(true);
            imgLabel->setMaximumSize(300,200);
            imgLabel->setPixmap(pix);
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
}

Circuits::~Circuits()
{
    delete ui;
}
