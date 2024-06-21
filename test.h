#ifndef TEST_H
#define TEST_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QStackedLayout>
#include <QScrollArea>
#include "clickablelabel.h"
#include "databaseconnector.h"

namespace Ui {
class Test;
}

class Test : public QMainWindow
{
    Q_OBJECT

public:
    explicit Test(QSqlDatabase db, QWidget *parent = nullptr);
    ~Test();

private:
    Ui::Test *ui;
    QSqlDatabase db;
    std::vector<ClickableLabel*> echipe;
    std::vector<QWidget*> pages;

    QStackedLayout* mainLayout;
    QWidget* mainPage;

    void createPages(QString pname);
    void createLabels(QVBoxLayout* layout);
    void handleLabelClicked();
    void adaugareLabel(ClickableLabel* label);
};

#endif // TEST_H
