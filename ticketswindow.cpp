#include "ticketswindow.h"
#include "ui_ticketswindow.h"
#include <QSqlQuery>
#include <functiiutile.h>
#include <QLabel>
#include <QPushButton>
#include <QJsonArray>


ticketsWindow::ticketsWindow(C_User* user, QSqlDatabase db, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ticketsWindow)
{
    ui->setupUi(this);

    qDebug()<<"Constructor ticketWindow";

    this->db = db;
    this->user = user;

    // int width = this->width();
    // int height = this->height();

    this->setMinimumSize(1080, 720);

    this->labelStyle = "font: bold 12pt Arial; "
                       "border-radius: 100px;"
                       "background: #af0034; ";
    QLabel* titleLabel = new QLabel("Tickets");
    titleLabel->setStyleSheet("font: bold 55pt Arial; "
                              "background-color: #af0034;");
    titleLabel->setAlignment(Qt::AlignCenter);

    this->scrollArea = new QScrollArea(this);
    this->scrollArea->setWidgetResizable(true);
    this->scrollAreaContent = new QWidget(scrollArea);
    this->scrollArea->setWidget(scrollAreaContent);
    this->scrollArea->setMinimumSize(1800,1000);
    this->verticalLayout = new QVBoxLayout(scrollAreaContent);
    this->verticalLayout->addWidget(titleLabel);
    this->mainLayout = new QGridLayout(scrollAreaContent);
    this->mainLayout->setVerticalSpacing(150);
    this->mainLayout->setHorizontalSpacing(200);
    this->verticalLayout->addLayout(this->mainLayout);
    this->verticalLayout->setAlignment(Qt::AlignCenter);
    this->verticalLayout->setSpacing(50);

    this->server = ServerConnection::getInstance();


    addTickets();
}

void ticketsWindow::onBuyButtonClicked() {
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    if (button)
    {
        QString circuitName = button->property("CircuitName").toString();
        QString address = button->property("Address").toString();
        QString date = button->property("Date").toString();
        this->ticketbW = new TicketsBuyWindow(this->tickets, this->user, circuitName, address, date, this);
        this->ticketbW->setAttribute(Qt::WA_DeleteOnClose);
        this->ticketbW->showMaximized();
    }
}

void ticketsWindow::handleTicketsResponse(const QJsonObject &response)
{
    QJsonArray teamsArray = response["teams"].toArray();
    for(const auto& teamsValue : teamsArray)
    {
        QJsonObject teamsObj = teamsValue.toObject();
        QString totalPrice = teamsObj["TotalPrice"].toString();
        int totalUnitsInStock = teamsObj["TotalUnitsInStock"].toInt();
        QString dateOfRace = teamsObj["DateOfRace"].toString();
        QString address = teamsObj["Address"].toString();
        QString circuitName = teamsObj["CircuitName"].toString();
        // ATickets* ticket = new ATickets(circuitName, address, dateOfRace, totalPrice.toFloat());
        // this->tickets.push_back(ticket);

        int ticketType = 1;

        this->createTickets(circuitName, address, dateOfRace, ticketType, totalPrice.toFloat());
    }
}


void ticketsWindow::addTickets()
{
    this->insertTicketsInVector();
    qDebug()<<this->tickets.size() <<" TICKETE";

    QSqlQuery query;
    QString sqlQuery =
        "SELECT "
        "MIN(T.Price) AS TotalPrice, "
        "SUM(T.UnitsInStock) AS TotalUnitsInStock, "
        "R.DateOfRace, "
        "CONCAT(A.Country, ', ', A.City, ', ', A.Street) AS Address, "
        "C.CircuitName "
        "FROM "
        "Tickets T "
        "INNER JOIN "
        "Races R ON T.RaceID = R.RaceID "
        "INNER JOIN "
        "Circuits C ON C.CircuitID = R.CircuitID "
        "INNER JOIN "
        "Address A ON A.AddressID = C.CircuitID "
        "GROUP BY "
        "C.CircuitName, R.DateOfRace, CONCAT(A.Country, ', ', A.City, ', ', A.Street);";

   //this->server->tickets();

    query.prepare(sqlQuery);

    if(query.exec())
    {
        int i = 0, j = 0;
        while(query.next())
        {
            QString CircuitName = query.value(4).toString();
            QString address = query.value(3).toString();
            QString dateOfRace = query.value(2).toString();
            int unitsInStock = query.value(1).toInt();
            float price = query.value(0).toFloat();
            QString imgName = CircuitName;
            FunctiiUtile::setBlankSpaceToUnderline(imgName);

            QString img = QString(":/circuits/Circuits/%1.png").arg(imgName);
            QLabel* imgLabel = new QLabel;
            //qDebug() << imgName<<"\n";
            QPixmap pix(img);
            QPixmap scaledPix = pix.scaled(QSize(503,503), Qt::KeepAspectRatio, Qt::SmoothTransformation);
            imgLabel->setPixmap(scaledPix);
            imgLabel->setScaledContents(true);
            imgLabel->setMaximumSize(300,200);
            imgLabel->setPixmap(pix);
            imgLabel->setStyleSheet("border: 8px solid #ff232b; "
                                    "border-radius: 20px; ");

            QVBoxLayout* verticalLayout = new QVBoxLayout;
            QLabel* circuitnameLabel = new QLabel;
            QLabel* addressLabel = new QLabel;
            QLabel* dateOfRaceLabel = new QLabel;
            QLabel* priceLabel = new QLabel;
            QLabel* unitsLabel = new QLabel;
            QPushButton* buttonBuy = new QPushButton;
            buttonBuy->setProperty("CircuitName", CircuitName);
            buttonBuy->setProperty("Adress", address);
            buttonBuy->setProperty("Date", dateOfRace);
            buttonBuy->setText("Buy ticket");
            connect(buttonBuy, &QPushButton::clicked, this, &ticketsWindow::onBuyButtonClicked);
            circuitnameLabel->setStyleSheet(labelStyle);
            addressLabel->setStyleSheet(labelStyle);
            dateOfRaceLabel->setStyleSheet(labelStyle);
            priceLabel->setStyleSheet(labelStyle);
            unitsLabel->setStyleSheet(labelStyle);
            circuitnameLabel->setText("Numele circuitului: " + CircuitName);
            addressLabel->setText("Adresa: " + address);
            dateOfRaceLabel->setText("Data Grand Prix-ului: " + dateOfRace);
            priceLabel->setText("Incepand de la: " + QString::number(price, 'f', 3) + "€");
            unitsLabel->setText("Pe stoc: " + QString::number(unitsInStock));
            verticalLayout->addWidget(circuitnameLabel);
            verticalLayout->addWidget(addressLabel);
            verticalLayout->addWidget(dateOfRaceLabel);
            verticalLayout->addWidget(priceLabel);
            verticalLayout->addWidget(unitsLabel);
            verticalLayout->addWidget(buttonBuy);
            this->mainLayout->addLayout(verticalLayout,i++,j);
            j = 0;
        }
    }
}

void ticketsWindow::insertTicketsInVector()
{
    QSqlQuery query;
    QString sqlQuery =
        "SELECT T.Price, T.TicketType, R.DateOfRace, CONCAT(A.Country,', ', A.City, ', ' ,A.Street) AS Address, C.CircuitName FROM Tickets T INNER JOIN Races R ON T.RaceID = R.RaceID INNER JOIN Circuits C  ON C.CircuitID = R.CircuitID INNER JOIN Address A ON A.AddressID = C.CircuitID";

    query.prepare(sqlQuery);

    if(query.exec())
    {
        while(query.next())
        {
            QString CircuitName = query.value(4).toString();
            QString address = query.value(3).toString();
            QString dateOfRace = query.value(2).toString();
            int ticketType = query.value(1).toInt();
            float price = query.value(0).toFloat();
            this->createTickets(CircuitName, address, dateOfRace, ticketType, price);
        }
    }
}

void ticketsWindow::createTickets(QString cname, QString address, QString date, int type, float price)
{
    switch(type)
    {
        case 1:
        {
            Day1Tickets* ticket = new Day1Tickets(1, cname, address, date, price, 100);
            this->tickets.push_back(ticket);
        } break;
        case 2:
        {
            Day2Tickets* ticket = new Day2Tickets(1,cname, address, date, price,100);
            this->tickets.push_back(ticket);
        } break;
        case 3:
        {
            RaceDayTickets* ticket = new RaceDayTickets(1,cname, address, date, price,100);
            this->tickets.push_back(ticket);
        } break;
        case 4:
        {
            FATickets* ticket = new FATickets(1,cname, address, date, price,100);
            this->tickets.push_back(ticket);
        } break;
        default: return;
    }
}

ticketsWindow::~ticketsWindow()
{
    delete ui;
    qDebug()<< "Destructor ticketWindow";
}
