#include "ticketsbuywindow.h"
#include "ui_ticketsbuywindow.h"
#include <QMessageBox>

TicketsBuyWindow::TicketsBuyWindow(std::vector<ITickets*> tickets, C_User* user, QString circname, QString address, QString date, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TicketsBuyWindow)
{
    ui->setupUi(this);

    this->availableTickets = tickets;
    this->user = user;

    this->labelStyle = "font: bold 12pt Arial; "
                       "border-radius: 10px;"
                       "background: #af0034; ";
    this->centralWidget = new QWidget(this);
    this->setCentralWidget(this->centralWidget);
    this->mainLayout = new QVBoxLayout(this->centralWidget);
    this->horizontalLayout = new QHBoxLayout;
    this->horizontalLayout->setSpacing(20);
    //this->titleLabel = new QLabel("Tickets for " + circname);
    this->spinBox = new QSpinBox;
    this->priceLabel = new QLabel("Price: ");
    this->spinBox->setMinimum(1);
    this->spinBox->setMaximum(10);
    connect(spinBox, QOverload<int>::of(&QSpinBox::valueChanged), this, [this]() {
        int value = spinBox->value();
        updateTotalPrice(value, priceAux); // Transmite și priceAux ca argument
    });
    this->buyButton = new QPushButton;
    this->buyButton->setText("Buy ticket(s)");
    connect(buyButton, &QPushButton::clicked, this, &TicketsBuyWindow::handleBuyButtonClicked);
    this->menu = new QMenu;
    actions.push_back(menu->addAction("Day 1 Ticket"));
    actions.push_back(menu->addAction("Day 2 Ticket"));
    actions.push_back(menu->addAction("Race Day Ticket"));
    actions.push_back(menu->addAction("Full Access Ticket"));
    connect(actions[0], &QAction::triggered, this, [this, circname]() { updateButtonText("Day 1 Ticket", circname); });
    connect(actions[1], &QAction::triggered, this, [this, circname]() { updateButtonText("Day 2 Ticket", circname); });
    connect(actions[2], &QAction::triggered, this, [this, circname]() { updateButtonText("Race Day Ticket", circname); });
    connect(actions[3], &QAction::triggered, this, [this, circname]() { updateButtonText("Full Access Ticket", circname); });
    this->selectButton = new QToolButton;
    this->selectButton->setText("Select Type of Ticket");
    this->selectButton->setMenu(menu);
    this->selectButton->setPopupMode(QToolButton::InstantPopup);

    this->aux = new TicketFrame(this->availableTickets[0], user);
    mainLayout->setAlignment(Qt::AlignCenter);
    mainLayout->addWidget(aux);
    mainLayout->addLayout(horizontalLayout);
    horizontalLayout->addWidget(selectButton);
    horizontalLayout->addWidget(spinBox);
    horizontalLayout->addWidget(priceLabel);
    horizontalLayout->addWidget(buyButton);
}

void TicketsBuyWindow::handleBuyButtonClicked()
{
    QMessageBox::information(this, "Bilet cumpărat", "Ai cumpărat biletul!");
    this->user->addTicket(this->desiredTicket);
    this->close();
}

void TicketsBuyWindow::updateButtonText(const QString &text, const QString &cname)
{
    selectButton->setText(text);
    this->selectedOption = text;
    int type = -1;
    if(text == "Day 1 Ticket") type = 1;
    if(text == "Day 2 Ticket") type = 2;
    if(text == "Race Day Ticket") type = 3;
    if(text == "Full Access Ticket") type = 4;
    this->priceAux = this->getPrice(type, cname);
    this->priceLabel->setText("Price: " +  QString::number(this->priceAux) + "€");
}

void TicketsBuyWindow::updateTotalPrice(int value, float price)
{
    this->quantity = value;
    float totalPrice = value * price;
    priceLabel->setText("Total Price: " + QString::number(totalPrice) + "€");
}

float TicketsBuyWindow::getPrice(int type, QString cname)
{
    for(int i=0;i<this->availableTickets.size();i++)
    {
        if(this->availableTickets[i]->getCircuitName()
            == cname)
        {
            switch(type)
            {
            case 1:
            {
                for(int j=i;j<=i+3;j++)
                {
                    if(dynamic_cast<Day1Tickets*>(this->availableTickets[i]))
                    {
                        this->desiredTicket = this->availableTickets[i];
                        this->createTicketFrame();
                        return this->availableTickets[i]->getPrice();
                    }
                }
            } break;
            case 2:
            {
                for(int j=i;j<=i+3;j++)
                {
                    if(dynamic_cast<Day2Tickets*>(this->availableTickets[i]))
                    {
                        this->desiredTicket = this->availableTickets[i];
                        this->createTicketFrame();
                        return this->availableTickets[i]->getPrice();
                    }
                }
            } break;
            case 3:
            {
                for(int j=i;j<=i+3;j++)
                {
                    if(dynamic_cast<RaceDayTickets*>(this->availableTickets[i]))
                    {
                        this->desiredTicket = this->availableTickets[i];
                        this->createTicketFrame();
                        return this->availableTickets[i]->getPrice();
                    }
                }
            } break;
            case 4:
            {
                for(int j=i;j<=i+3;j++)
                {
                    if(dynamic_cast<FATickets*>(this->availableTickets[i]))
                    {
                        this->desiredTicket = this->availableTickets[i];
                        this->createTicketFrame();
                        return this->availableTickets[i]->getPrice();
                    }
                }
            } break;
            default: return -1;
            }
        }
    }
    return -1;
}

void TicketsBuyWindow::createTicketFrame()
{
    this->desiredTicketFrame = new TicketFrame(desiredTicket, user);
    this->mainLayout->replaceWidget(this->aux, this->desiredTicketFrame);
}

TicketsBuyWindow::~TicketsBuyWindow()
{
    delete ui;
    qDebug()<<"Tickets buy window destroyer";
}
