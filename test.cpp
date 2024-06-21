#include "test.h"
#include "ui_test.h"
#include <QSqlQuery>
#include <QScrollArea>
#include <QLabel>
#include "functiiutile.h"
#include <QPixmap>
#include <QScreen>
#include <QGraphicsDropShadowEffect>

Test::Test(QSqlDatabase db, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Test)
{
    ui->setupUi(this);

    this->db = db;

    QWidget* centralWidget = new QWidget(this);
    this->setCentralWidget(centralWidget);
    this->mainLayout = new QStackedLayout(centralWidget);
    centralWidget->setLayout(this->mainLayout);

    this->mainPage = new QWidget;
    QScrollArea* scrollArea = new QScrollArea(this->mainPage);
    QVBoxLayout* mainPageLayout = new QVBoxLayout(this->mainPage);

    QWidget* scrollAreaContent = new QWidget(scrollArea);
    scrollArea->setWidget(scrollAreaContent);
    scrollArea->setWidgetResizable(true);
    QVBoxLayout* scrollAreaContentLayout = new QVBoxLayout(scrollAreaContent);

    scrollAreaContent->setLayout(scrollAreaContentLayout);
    mainPageLayout->addWidget(scrollArea);
    this->mainPage->setLayout(mainPageLayout);

    this->mainLayout->addWidget(this->mainPage);
    this->mainLayout->setCurrentWidget(this->mainPage);

    this->createLabels(scrollAreaContentLayout);
}

void Test::adaugareLabel(ClickableLabel* label)
{
    this->echipe.push_back(label);
}

void Test::createLabels(QVBoxLayout* layout)
{
    QSqlQuery query;
    query.prepare("SELECT TeamName FROM Teams");

    if(query.exec())
    {
        int labelWidth = this->screen()->geometry().width() / 5;
        int labelHeight = labelWidth / 2;
        while(query.next())
        {
            QString tname = query.value(0).toString();
            QLabel* teamNameLabel = new QLabel(tname);
            FunctiiUtile::setBlankSpaceToUnderline(tname);
            QString pname =  tname + "_page";
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
            layout->addWidget(label);
            layout->addWidget(teamNameLabel);
            label->setStyleSheet("border: 5px solid #FF1801; border-radius: 50px; padding: 25px");
            shadowEffect->setBlurRadius(10);
            shadowEffect->setColor(QColor(0, 0, 0, 160));
            shadowEffect->setOffset(4, 4);
            label->setGraphicsEffect(shadowEffect);
            connect(label, &ClickableLabel::clicked, this, &Test::handleLabelClicked);
            this->createPages(pname);
        }
    }
}

void Test::handleLabelClicked() {
    // Obține obiectul care a emis semnalul
    ClickableLabel* senderLabel = qobject_cast<ClickableLabel*>(sender());
    QString pname = senderLabel->getName();
    pname += "_page";
    qDebug()<<"Handle clicked pentru "<<pname<<"\n";
    for(int i=0;i<this->pages.size();i++)
    {
        if(this->pages[i]->objectName() == pname)
        {
            // qDebug()<<pages[i]<<"\n";
            this->mainLayout->setCurrentWidget(this->pages[i]);
        }
    }
}

void Test::createPages(QString pname)
{
    qDebug()<<pname<<'\n';
    QWidget* pagina = new QWidget;
    pagina->setObjectName(pname);
    this->mainLayout->addWidget(pagina);
    this->pages.push_back(pagina);
}

Test::~Test()
{
    delete ui;
}
