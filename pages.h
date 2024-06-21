#ifndef PAGES_H
#define PAGES_H

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QPixmap>
#include <clickablelabel.h>
#include <QPushButton>

class Pages : public QWidget
{
    Q_OBJECT
public:
    explicit Pages(QString pageName, QWidget *parent = nullptr);
    void addImageLabel(QString imgPath);
    void addTextLabel(QString text, int i, QString labelStyle, QString connectedText = "NULL");
    void addWidgetToLayout(QWidget*);
private:
    QHBoxLayout* mainLayout;
    QVBoxLayout* verticalLayout;
    QWidget* verticalWidget;
    std::vector<QLabel*> vectorLabels;
signals:
    void labelClicked(QString pageName);
};

#endif // PAGES_H
