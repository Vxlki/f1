#include "abstractwindow.h"
#include<QGuiApplication>
#include<QScreen>

AbstractWindow::AbstractWindow() {}



void AbstractWindow::centerWindow(QWidget* parent)
{
    // Obține ecranul principal
    QScreen* screen = QGuiApplication::primaryScreen();
    if (!screen) {
        qDebug() << "Eroare: Ecranul principal nu poate fi obținut.";
        return;
    }

    // Obține geometria ecranului
    QRect screenGeometry = screen->geometry();

    // Obține geometria ferestrei
    QRect windowGeometry = parent->frameGeometry();

    // Calculează coordonata x pentru centrat pe axa orizontală
    int x = (screenGeometry.width() - windowGeometry.width()) / 2;

    // Calculează coordonata y pentru centrat pe axa verticală
    int y = (screenGeometry.height() - windowGeometry.height()) / 2;

    // Muta fereastra la noile coordonate
    parent->move(x, y);
}

