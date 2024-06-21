#include "teams.h"
#include "ui_teams.h"
#include <QSqlQuery>
#include <QScrollArea>
#include <QLabel>
#include "functiiutile.h"
#include <QPixmap>
#include <QScreen>
#include <QGraphicsDropShadowEffect>
#include <QtSql>
#include "c_drivers.h"
#include "c_engineers.h"
#include "c_manager.h"
#include "c_address.h"


Teams::Teams(std::vector<I_Personnel*> personnel, std::vector<C_Teams*> teams, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Teams)
{
    ui->setupUi(this);

    this->conexiuneServer = ServerConnection::getInstance();
    this->personnel = personnel;
    this->teams = teams;
    // connect(this->conexiuneServer, &ServerConnection::teamsWindowFunctionPersonnel, this, &Teams::handleTeamsWindowPersonnelResponse);
    // connect(this->conexiuneServer, &ServerConnection::sendTeamsWindowTeams,this, &Teams::handleTeamsWindowTeamsResponse);

    QWidget* centralWidget = new QWidget(this);
    this->setCentralWidget(centralWidget);
    this->mainLayout = new QStackedLayout(centralWidget);
    centralWidget->setLayout(this->mainLayout);

    this->mainPage = new QWidget;
    QScrollArea* scrollArea = new QScrollArea(this->mainPage);
    QVBoxLayout* mainPageLayout = new QVBoxLayout(this->mainPage);

    this->scrollAreaContent = new QWidget(scrollArea);
    scrollArea->setWidget(scrollAreaContent);
    scrollArea->setWidgetResizable(true);
    this->scrollAreaContentLayout = new QVBoxLayout(scrollAreaContent);

    scrollAreaContent->setLayout(scrollAreaContentLayout);
    mainPageLayout->addWidget(scrollArea);
    this->mainPage->setLayout(mainPageLayout);

    this->mainLayout->addWidget(this->mainPage);
    this->mainLayout->setCurrentWidget(this->mainPage);

    this->createLabels();
}


void Teams::createDriversPages(I_Personnel* driver)
{
    QString fullName = driver->getLastName() + " " + driver->getFirstName();
    QString position = driver->GetPosition();
    QString startDate = driver->getStartDate();
    QString endDate = driver->getEndDate();
    Pages* pagina = new Pages(fullName);
    QString imgaux = driver->getFirstName() + " " + driver->getLastName();
    QString img = QString(":/drivers/Drivers/%1.jpg").arg(imgaux);
    this->pages.push_back(pagina);
    this->mainLayout->addWidget(pagina);
    qDebug()<<"IMG::::::"<<img;



    pagina->addImageLabel(img);
    pagina->addTextLabel("Name: " + fullName, 1, this->labelStyle);
    pagina->addTextLabel("Position: " + position, 1, this->labelStyle);
    //pagina->addTextLabel("Date of birth: " + dateOfBirth, 1, this->labelStyle);
    //pagina->addTextLabel("Age: " + age, 1, this->labelStyle);
    pagina->addTextLabel("Start date: " + startDate, 1, this->labelStyle);

    if (!endDate.isEmpty())
        pagina->addTextLabel("End date: " + endDate, 1, this->labelStyle);

    QPushButton* backToTeamsButton = new QPushButton;
    backToTeamsButton->setText("Back");
    connect(backToTeamsButton, &QPushButton::clicked, this, &Teams::handlebackToTeamsButton);
    pagina->addWidgetToLayout(backToTeamsButton);
}

void Teams::handlebackToTeamsButton()
{
    this->mainLayout->setCurrentWidget(this->mainPage);
}

void Teams::createLabels()
{
        int labelWidth = this->screen()->geometry().width() / 5;
        int labelHeight = labelWidth / 2;

    for(int i=0; i<this->teams.size();i++)
    {
        QString tname = this->teams[i]->teamName();
        QLabel* teamNameLabel = new QLabel(tname);
        FunctiiUtile::setBlankSpaceToUnderline(tname);
        QString img = QString(":/teams/Teams/%1.png").arg(tname);
        QPixmap pix(img);
        pix = pix.scaled(labelWidth, labelHeight, Qt::KeepAspectRatio);
        ClickableLabel* label = new ClickableLabel;
        label->setPixmap(pix);
        label->setName(tname);
        //adaugareLabel(label);
        label->setMinimumSize(pix.size());
        label->setAlignment(Qt::AlignHCenter);
        teamNameLabel->setAlignment(Qt::AlignHCenter);
        teamNameLabel->setFont(QFont("Arial", 16, QFont::Bold));
        teamNameLabel->setStyleSheet("color: #FF1801; background-color: #333333;");
        teamNameLabel->setAlignment(Qt::AlignCenter);
        teamNameLabel->setWordWrap(true);
        QGraphicsDropShadowEffect *shadowEffect = new QGraphicsDropShadowEffect();
        shadowEffect->setBlurRadius(5);
        shadowEffect->setColor(QColor(0, 0, 0, 160));
        shadowEffect->setOffset(2, 2);
        teamNameLabel->setGraphicsEffect(shadowEffect);
        this->scrollAreaContentLayout->addWidget(label);
        this->scrollAreaContentLayout->addSpacing(0);
        this->scrollAreaContentLayout->addWidget(teamNameLabel);
        this->scrollAreaContentLayout->addSpacing(150);
        label->setStyleSheet("border: 5px solid #FF1801; border-radius: 50px; padding: 25px");
        shadowEffect->setBlurRadius(10);
        shadowEffect->setColor(QColor(0, 0, 0, 160));
        shadowEffect->setOffset(4, 4);
        label->setGraphicsEffect(shadowEffect);
        connect(label, &ClickableLabel::clicked, this, &Teams::handleLabelClicked);
        this->createPages(tname);
    }
    //}
}

void Teams::handleLabelClicked()
{
    ClickableLabel* senderLabel = qobject_cast<ClickableLabel*>(sender());
    QString pname = senderLabel->getName();
    pname += "_page";
    //qDebug()<<"Handle clicked pentru "<<pname<<"\n";
    for(int i=0;i<this->pages.size();i++)
    {
        if(this->pages[i]->objectName() == pname)
        {
            // qDebug()<<pages[i]<<"\n";
            this->mainLayout->setCurrentWidget(this->pages[i]);
        }
    }
}

void Teams::on_backButton_clicked()
{
    this->mainLayout->setCurrentWidget(this->mainPage);
}


void Teams::createPages(QString tname)
{
    qDebug()<<"CREATE PAGES!!!!!!!!!!!!!!";
    qDebug()<<tname<<" TNAME";
    QString pname =  tname + "_page";
    Pages* pagina = new Pages(pname);
    this->mainLayout->addWidget(pagina);
    this->pages.push_back(pagina);

    QString img = QString(":/teams/Teams/%1.png").arg(tname);
    pagina->addImageLabel(img);
    QString tname1 = tname;

    FunctiiUtile::setUnderlinetoBlankSpace(tname1);

    QString teamname = tname;
    QString driver1 = "NULL";
    QString driver2 = "NULL";
    QString inginer = "NULL";
    QString manager = "NULL";
    QString sponsors = "Sponsors:\n\n\t";

    this->labelStyle = "color: #FF1801;"
                       "background-color: #333333;"
                       "font: bold 16px Roboto;"
                       "text-align: center;"
                       "padding: 20px;"
                       "border-radius: 5px;";

    for(int i=0;i<this->teams.size();i++)
    {
        if(this->teams[i]->teamName() == tname1)
        {
            std::vector<QString> sponsorsvec = this->teams[i]->getSponsors();
            for(int j=0;j<sponsorsvec.size();j++)
            {
                sponsors += sponsorsvec[j] + "\n\t";
            }
        }
    }

    for(int i=0;i<this->personnel.size();i++)
    {
        if(this->personnel[i]->getTeamName() == tname1)
        {
            qDebug()<<teamname<<" create pages " << this->personnel[i];
            if(this->personnel[i]->getPosition() == "Driver" && driver1 == "NULL")
            {
                QString lname = this->personnel[i]->getLastName();
                QString fname = this->personnel[i]->getFirstName();
                this->createDriversPages(this->personnel[i]);
                driver1 = "Driver 1: " + lname + " " + fname;
                pagina->addTextLabel(driver1, 0, labelStyle, lname + " " + fname);
            }

            else if(this->personnel[i]->getPosition() == "Driver" && driver2 == "NULL")
            {
                QString lname = this->personnel[i]->getLastName();
                QString fname = this->personnel[i]->getFirstName();
                this->createDriversPages(this->personnel[i]);
                driver2 = "Driver 2: " + lname + " " + fname;
                pagina->addTextLabel(driver2, 0, labelStyle, lname + " " + fname);
            }

            if(this->personnel[i]->getPosition() == "Engineer")
            {
                QString lname = this->personnel[i]->getLastName();
                QString fname = this->personnel[i]->getFirstName();
                inginer = "Engineer: " + lname + " " + fname;
            }

            if(this->personnel[i]->getPosition() == "Manager")
            {
                QString lname = this->personnel[i]->getLastName();
                QString fname = this->personnel[i]->getFirstName();
                manager = "Manager: " + lname + " " + fname;
            }
        }
    }

    pagina->addTextLabel(tname1, 1,labelStyle);
    pagina->addTextLabel(manager, 1, labelStyle);
    pagina->addTextLabel(inginer, 1, labelStyle);
    pagina->addTextLabel(sponsors, 1, labelStyle);
    connect(pagina, &Pages::labelClicked, this, &Teams::showWidgetByPageName);

    this->backButton = new QPushButton;
    connect(this->backButton, &QPushButton::clicked, this, &Teams::on_backButton_clicked);
    this->backButton->setText("Back");
    pagina->addWidgetToLayout(this->backButton);
}

void Teams::showWidgetByPageName(QString pageName)
{
    qDebug() <<"PAGENAME:: "<<pageName;
    for (int i = 0; i < this->pages.size(); i++)
    {
        if (this->pages[i]->objectName() == pageName)
        {
            this->mainLayout->setCurrentWidget(this->pages[i]);
            return;
        }
    }
}


Teams::~Teams()
{
    // for(int i=0;i<this->pages.size();i++)
    // {
    //     delete[] this->pages[i];
    // }
    // delete this->mainLayout;
    // delete this->mainPage;
    // qDebug()<<"destructor\n";
    // delete ui;
}
