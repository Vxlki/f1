#include "ticketframe.h"
#include "QrCodeGenerator.h"
#include "ui_ticketframe.h"

TicketFrame::TicketFrame(ITickets* ticket, C_User* user, QWidget *parent)
    : QFrame(parent)
    , ui(new Ui::TicketFrame)
{
    ui->setupUi(this);

    this->user = user;
    this->ticket = ticket;

    this->vLayout = new QVBoxLayout(this);
    this->hLayout1 = new QHBoxLayout;
    this->hLayout2 = new QHBoxLayout;
    this->vLayout->addLayout(this->hLayout1);
    this->vLayout->addLayout(this->hLayout2);
    this->setLayout(this->vLayout);

    this->generateQrCode();

    // Label-uri pentru text
    QLabel* circLabel = new QLabel("Circuit:  " + this->ticket->getCircuitName());
    circLabel->setStyleSheet("font-size: 30px; color: violet;"); // Exemplu de stil CSS
    this->hLayout1->addWidget(circLabel);
    this->labels.push_back(circLabel);

    QLabel* dateLabel = new QLabel("Date:  " + this->ticket->getDate());
    dateLabel->setStyleSheet("font-size: 30px; color: red;"); // Exemplu de stil CSS
    this->hLayout1->addWidget(dateLabel);
    this->labels.push_back(dateLabel);

    if(this->user)
    {
        QLabel* userLabel = new QLabel("Username:  " + this->user->getUsername());
        userLabel->setStyleSheet("font-size: 30px; color: green;"); // Exemplu de stil CSS
        this->hLayout2->addWidget(userLabel);
        this->labels.push_back(userLabel);

        QLabel* mailLabel = new QLabel("E-Mail:  " + this->user->getMail());
        mailLabel->setStyleSheet("font-size: 30px; color: orange;"); // Exemplu de stil CSS
        this->hLayout2->addWidget(mailLabel);
        this->labels.push_back(mailLabel);

        // Redimensionează și adaugă imaginea QR
        QLabel* qrLabel = new QLabel;
        qrLabel->setAlignment(Qt::AlignCenter);
        QPixmap pix = QPixmap::fromImage(this->qrCode).scaled(100, 100, Qt::KeepAspectRatio); // Redimensionează imaginea
        qrLabel->setPixmap(pix);
        this->hLayout2->addWidget(qrLabel);
        this->labels.push_back(qrLabel);

        this->setStyleSheet("QFrame {"
                            "background-color: white;"
                            "border: 2px solid black;"
                            "border-radius: 10px;"
                            "}");
    }
}


void TicketFrame::generateQrCode()
{
    QrCodeGenerator generator;
    QString data = this->ticket->getCircuitName() +
                   " " + this->ticket->getDate() +
                    " " + this->user->getUsername() +
                    " " + this->user->getMail();
    this->qrCode = generator.generateQr(data);
}

TicketFrame::~TicketFrame()
{
    delete ui;
}
