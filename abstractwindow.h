#ifndef ABSTRACTWINDOW_H
#define ABSTRACTWINDOW_H

#include<QWidget>

class AbstractWindow
{
public:
    AbstractWindow();
protected:
    static void centerWindow(QWidget* parent);
};

#endif // ABSTRACTWINDOW_H
