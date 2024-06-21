#ifndef CLICKABLELABEL_H
#define CLICKABLELABEL_H

#include <QLabel>
#include <QWidget>
#include <Qt>

class ClickableLabel : public QLabel {
    Q_OBJECT

public:
    explicit ClickableLabel(QWidget* parent = Q_NULLPTR, Qt::WindowFlags f = Qt::WindowFlags());
    ~ClickableLabel();

    void setName(QString name){this->name=name;};
    QString getName(){return this->name;};

signals:
    void clicked();

protected:
    void mousePressEvent(QMouseEvent* event);
    QString name;

};

#endif // CLICKABLELABEL_H
