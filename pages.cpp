#include "pages.h"
#include "teams.h"

Pages::Pages(QString pageName, QWidget *parent)
    : QWidget{parent}
{
    this->setObjectName(pageName);
    this->mainLayout = new QHBoxLayout(this);
    this->verticalWidget = new QWidget;
    this->verticalLayout = new QVBoxLayout;
    this->verticalWidget->setLayout(this->verticalLayout);
    this->verticalLayout->setAlignment(Qt::AlignCenter);
    this->setLayout(this->mainLayout);
}

void Pages::addImageLabel(QString imgPath)
{
    QLabel* label = new QLabel;
    QPixmap pix(imgPath);
    label->setPixmap(pix);
    label->setMinimumSize(pix.size());
    label->setAlignment(Qt::AlignVCenter);
    this->mainLayout->addWidget(label);
    this->mainLayout->addWidget(this->verticalWidget);
}

void Pages::addTextLabel(QString text, int i, QString labelStyle, QString connectedText)
{
    //i = 0 -> clickable
    //i = 1 -> QLabel
    switch(i)
    {
        case 0:
        {
            ClickableLabel* label = new ClickableLabel;
            this->vectorLabels.push_back(label);
            label->setText(text);
            connect(label, &ClickableLabel::clicked, this, [this, connectedText](){
                emit labelClicked(connectedText);
            });
            this->verticalLayout->addWidget(label);
            label->setStyleSheet(labelStyle);
        } break;
        case 1:
        {
            QLabel* label = new QLabel;
            this->vectorLabels.push_back(label);
            label->setText(text);
            label->setStyleSheet(labelStyle);
            this->verticalLayout->addWidget(label);
        } break;
        default: return;
    }
}



void Pages::addWidgetToLayout(QWidget* widget)
{
    this->verticalLayout->addWidget(widget);
}
