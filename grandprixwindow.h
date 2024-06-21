#ifndef GRANDPRIXWINDOW_H
#define GRANDPRIXWINDOW_H

#include <QMainWindow>
#include <QScrollArea>
#include <QWidget>
#include <QSqlDatabase>
#include <QVBoxLayout>

#include <QCamera>
#include <QLabel>
#include <QAudioOutput>
#include <QVideoWidget>
#include <QMediaPlayer>
#include <QSlider>
#include <QAudioFormat>
#include <clickablelabel.h>
#include <QPixmap>

namespace Ui {
class GrandPrixWindow;
}

class GrandPrixWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit GrandPrixWindow(QSqlDatabase db, QWidget *parent = nullptr);
    ~GrandPrixWindow();

private:
    Ui::GrandPrixWindow *ui;

    std::vector<QMediaPlayer*> mediaPlayers;
    std::vector<QVideoWidget*> videoWidgets;
    QAudioOutput* audioOutput;
    QSlider* volumeSlider;

    QSqlDatabase db;
    QWidget* mainPage;
    QScrollArea* scrollArea;
    QWidget* scrollAreaContent;
    QVBoxLayout* mainLayout;
    QLabel* liveLabel;
    std::vector<QLabel*> videoLabels;
    bool isSound;

    void addVideos();

    void setPosition(int position, QMediaPlayer* mediaPlayer);
    void updatePosition(qint64 position);
    void changeVolume(int volume, QMediaPlayer* mediaPlayer);
    void handleVolumeLabelClicked(ClickableLabel* label, QMediaPlayer* mediaPlayer);
};

#endif // GRANDPRIXWINDOW_H
