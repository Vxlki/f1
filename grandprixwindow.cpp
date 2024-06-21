#include "grandprixwindow.h"
#include "ui_grandprixwindow.h"
#include <QDebug>
#include <QUrl>

GrandPrixWindow::GrandPrixWindow(QSqlDatabase db, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::GrandPrixWindow)
{
    ui->setupUi(this);

    this->db = db;

    // Creează widget-ul central
    this->mainPage = new QWidget(this);
    this->setCentralWidget(this->mainPage);

    // Creează layout-ul principal pentru widget-ul central
    QVBoxLayout *mainPageLayout = new QVBoxLayout(this->mainPage);

    // Creează zona de derulare pe widget-ul central
    this->scrollArea = new QScrollArea(this->mainPage);
    this->scrollArea->setWidgetResizable(true);

    // Creează conținutul pentru zona de derulare
    this->scrollAreaContent = new QWidget(this->scrollArea);
    this->scrollArea->setWidget(this->scrollAreaContent);

    // Creează layout-ul principal pentru conținutul zonei de derulare
    this->mainLayout = new QVBoxLayout(this->scrollAreaContent);
    this->scrollAreaContent->setLayout(this->mainLayout); // Setează layout-ul pentru conținut

    // Adaugă zona de derulare la layout-ul principal al widget-ului central
    mainPageLayout->addWidget(this->scrollArea);

    qDebug() << "Grand Prix window";

    // Adaugă videoclipurile
    this->addVideos();
}

GrandPrixWindow::~GrandPrixWindow()
{
    delete ui;
}

void GrandPrixWindow::addVideos()
{
    QMediaPlayer* mediaPlayer = new QMediaPlayer;
    QVideoWidget* videoWidget = new QVideoWidget;
    this->audioOutput = new QAudioOutput;
    mediaPlayer->setAudioOutput(this->audioOutput);

    this->mainLayout->addWidget(videoWidget);

    mediaPlayer->setVideoOutput(videoWidget);

    QString videoPath = "C:\\Users\\Axi\\Documents\\F1AppNou\\Videos\\F1Video1.avi";
    mediaPlayer->setSource(QUrl::fromLocalFile(videoPath));
    mediaPlayer->play();

    QHBoxLayout* sliderLayout = new QHBoxLayout;
    this->mainLayout->addLayout(sliderLayout);

    QSlider *positionSlider = new QSlider(Qt::Horizontal);
    positionSlider->setRange(0, 100);
    connect(positionSlider, &QSlider::sliderMoved, this, [=](int position) {
        setPosition(position, mediaPlayer);
    });

    sliderLayout->addWidget(positionSlider, 1);

    connect(mediaPlayer, &QMediaPlayer::positionChanged, this, &GrandPrixWindow::updatePosition);

    ClickableLabel* volumeLabel = new ClickableLabel;
    QPixmap pix(":/icons/Icons/volume.png");
    QPixmap scaledPix = pix.scaled(QSize(25,25), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    volumeLabel->setPixmap(scaledPix);
    sliderLayout->addWidget(volumeLabel);
    this->isSound = true;
    connect(volumeLabel, &ClickableLabel::clicked, this, [=]() {
        handleVolumeLabelClicked(volumeLabel, mediaPlayer);
    });

    this->volumeSlider = new QSlider(Qt::Horizontal);
    volumeSlider->setRange(0, 100);
    connect(volumeSlider, &QSlider::valueChanged, this, [=](int volume) {
        changeVolume(volume, mediaPlayer);
    });

    changeVolume(50, mediaPlayer);

    sliderLayout->addWidget(volumeSlider);
}

void GrandPrixWindow::setPosition(int position, QMediaPlayer* mediaPlayer)
{
    mediaPlayer->setPosition(position * 1000);
}

void GrandPrixWindow::updatePosition(qint64 position)
{
    QSlider *slider = findChild<QSlider *>();
    if (slider)
    {
        slider->setValue(position / 1000);
    }
}

void GrandPrixWindow::handleVolumeLabelClicked(ClickableLabel* label, QMediaPlayer* mediaPlayer)
{
    if(this->isSound == true)
    {
        QPixmap pix(":/icons/Icons/volumemute.png");
        QPixmap scaledPix = pix.scaled(QSize(25,25), Qt::KeepAspectRatio, Qt::SmoothTransformation);
        label->setPixmap(scaledPix);
        changeVolume(0, mediaPlayer);
        this->isSound = false;
    }
    else if(this->isSound == false)
    {
        QPixmap pix(":/icons/Icons/volume.png");
        QPixmap scaledPix = pix.scaled(QSize(25,25), Qt::KeepAspectRatio, Qt::SmoothTransformation);
        label->setPixmap(scaledPix);
        changeVolume(50, mediaPlayer);
        this->isSound = true;
    }
}

void GrandPrixWindow::changeVolume(int volume, QMediaPlayer* mediaPlayer)
{
    qreal linearVolume = QAudio::convertVolume(volume / qreal(100.0), QAudio::LinearVolumeScale, QAudio::LinearVolumeScale);
    qDebug() << linearVolume;
    if (mediaPlayer->audioOutput())
        mediaPlayer->audioOutput()->setVolume(linearVolume);
    this->volumeSlider->setValue(volume);
}
