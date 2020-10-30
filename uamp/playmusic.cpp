#include "playmusic.h"
#include "ui_playmusic.h"
#include "generalwindow.h"

PlayMusic::PlayMusic(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PlayMusic)
{
    ui->setupUi(this);
    ui->ButtinStop->hide();
    ui->ButtonPause->hide();
    m_media = new QMediaPlayer;
//    m_media->setMedia(QUrl::fromLocalFile("/Users/solianovsk/Desktop/Ты Врёшь.mp3"));
    m_media->setVolume(30);
    ui->progressMusic->setValue(0);
    connect(m_media, &QMediaPlayer::positionChanged, this, &PlayMusic::positionChanged);
    connect(m_media, &QMediaPlayer::stateChanged, this, &PlayMusic::stateChanged);
    window = qobject_cast<generalWindow*>(parent);
}

PlayMusic::~PlayMusic()
{
    delete ui;
}


void PlayMusic::setNewMusic(const QString& name) {
    ui->progressMusic->setValue(0);
    m_media->setMedia(QUrl::fromLocalFile(name));
}

void PlayMusic::setNewMusicAndPlay(const QString& name) {
    this->setNewMusic(name);
    this->on_ButtonPlay_clicked();
}


void PlayMusic::stateChanged(QMediaPlayer::State state) {
    if (state == QMediaPlayer::StoppedState && m_playMusic) {
        if (ui->ButtonPlay->isHidden())
            ui->ButtonPlay->show();
        if (!ui->ButtinStop->isHidden())
            ui->ButtinStop->hide();
        if (!ui->ButtonPause->isHidden())
            ui->ButtonPause->hide();
        ui->progressMusic->setValue(100);
    }
}

void PlayMusic::positionChanged(qint64 position) {
    if (m_media->isAudioAvailable())
        ui->progressMusic->setValue((position * 100) / m_media->duration());
}

void PlayMusic::on_ButtonPrevious_clicked()
{
    window->previousMusic();
}

void PlayMusic::on_ButtonRewind_clicked()
{
    m_media->setPosition(m_media->position() - 10000);
}

void PlayMusic::on_ButtonPause_clicked()
{
    if (ui->ButtonPlay->isHidden())
        ui->ButtonPlay->show();
    if (!ui->ButtonPause->isHidden())
        ui->ButtonPause->hide();
    m_media->pause();
}

void PlayMusic::on_ButtinStop_clicked()
{
    if (ui->ButtonPlay->isHidden())
        ui->ButtonPlay->show();
    if (!ui->ButtinStop->isHidden())
        ui->ButtinStop->hide();
    if (!ui->ButtonPause->isHidden())
        ui->ButtonPause->hide();
    m_media->stop();
    ui->progressMusic->setValue(0);
}

void PlayMusic::on_ButtonPlay_clicked()
{
    if (m_media->isAudioAvailable()) {
        if (!ui->ButtonPlay->isHidden())
            ui->ButtonPlay->hide();
        if (ui->ButtinStop->isHidden())
            ui->ButtinStop->show();
        if (ui->ButtonPause->isHidden())
            ui->ButtonPause->show();
        m_media->play();
        m_playMusic = true;
    }
}

void PlayMusic::on_ButtonFastForward_clicked()
{
    m_media->setPosition(m_media->position() + 10000);
}

void PlayMusic::on_ButtonNext_clicked()
{
    window->nextMusic();

}
