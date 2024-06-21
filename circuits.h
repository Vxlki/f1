#ifndef CIRCUITS_H
#define CIRCUITS_H

#include<QMainWindow>
#include<QSqlDatabase>
#include<QVBoxLayout>
#include<QPushButton>
#include<QScrollArea>
#include<QSqlQuery>
#include<QLabel>
#include<QGridLayout>
#include <c_circuits.h>

namespace Ui {
class Circuits;
}

class Circuits : public QMainWindow
{
    Q_OBJECT

public:
    explicit Circuits(std::vector<C_Circuits*> circuits, QWidget *parent = nullptr);
    ~Circuits();

public slots:
    //void handleCircuitsWindowResponse(const QJsonObject& response);

private:
    Ui::Circuits *ui;

    QWidget* mainPage;
    QScrollArea* scrollArea;
    QWidget* scrollAreaContent;
    QGridLayout* mainLayout;
    QVBoxLayout* verticalLayout;
    QString labelStyle;
    std::vector<C_Circuits*> circuits;

    void addCircuits();
};

#endif // CIRCUITS_H
