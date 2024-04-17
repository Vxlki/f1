#ifndef CIRCUITS_H
#define CIRCUITS_H

#include <QDialog>
#include<QSqlDatabase>
#include<QVBoxLayout>
#include<QPushButton>
#include<QScrollArea>
#include<QSqlQuery>
#include<QLabel>
#include<QGridLayout>

namespace Ui {
class Circuits;
}

class Circuits : public QDialog
{
    Q_OBJECT

public:
    explicit Circuits(QSqlDatabase db, QWidget *parent = nullptr);
    ~Circuits();

private:
    Ui::Circuits *ui;

    QSqlDatabase db;

    QScrollArea* scrollArea;
    QWidget* scrollAreaContent;
    QGridLayout* mainLayout;

    void addCircuits(QSqlDatabase db);
};

#endif // CIRCUITS_H
