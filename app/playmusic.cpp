#include "playmusic.h"
#include "ui_playmusic.h"
#include "generalwindow.h"
//#include <QMediaPlaylist>

PlayMusic::PlayMusic(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PlayMusic)
{
    ui->setupUi(this);
    ui->ButtinStop->hide();
    ui->ButtonPause->hide();
    m_media = new QMediaPlayer;
    connect(m_media, &QMediaPlayer::positionChanged, this, &PlayMusic::positionChanged);
    connect(m_media, &QMediaPlayer::stateChanged, this, &PlayMusic::stateChanged);
    connect(m_media, &QMediaPlayer::mediaStatusChanged, this, &PlayMusic::mediaStatusChanged);
    connect(ui->sliderVolume, &QSlider::valueChanged, this, [this] {
        m_media->setVolume(ui->sliderVolume->value());
    });
    connect(ui->sliderMusic, &QSlider::valueChanged, this, &PlayMusic::valueChangedSliderMusic);
    m_window = qobject_cast<generalWindow*>(parent);
    this->setTimeMusic(0, 0);
    ui->sliderMusic->setTracking(false);

//    QMediaPlaylist *playlist = new QMediaPlaylist;

//    playlist->addMedia(QUrl::fromLocalFile("/Users/solianovsk/Desktop/Ты Врёшь.mp3"));
//    playlist->save(QUrl::fromLocalFile
//                   ("/Users/solianovsk/Desktop/3.m3u"),"m3u");
}

PlayMusic::~PlayMusic()
{
    delete ui;
}

void PlayMusic::mediaStatusChanged(QMediaPlayer::MediaStatus status) {
    if (status == QMediaPlayer::LoadedMedia && this->m_playMusic)
        m_media->play();
    if (status == QMediaPlayer::LoadedMedia)
        this->setTimeMusic(0, m_media->duration());
    if (status == QMediaPlayer::InvalidMedia) {
        if (ui->ButtonPlay->isHidden())
            ui->ButtonPlay->show();
        if (!ui->ButtinStop->isHidden())
            ui->ButtinStop->hide();
        if (!ui->ButtonPause->isHidden())
            ui->ButtonPause->hide();
        this->setTimeMusic(0, 0);
    }
}

QString PlayMusic::getTime(qint64 time) {
    time /= 1000;
    QString strSecond = QString::number(time % 60);
    time /= 60;
    QString strMinute = QString::number(time % 60);
    return strMinute + ":" + strSecond;
}

void PlayMusic::setTimeMusic(qint64 valueTile, qint64 maxTime) {
    ui->labelTime->setText(this->getTime(valueTile) + "/" + this->getTime(maxTime));
}

void PlayMusic::setNewMusic(const QString& name, const QString& path) {
    ui->sliderMusic->setValue(0);
    m_media->setMedia(QUrl::fromLocalFile(path));
    m_playMusic = false;
    ui->NameMusic->setText(name);
}

void PlayMusic::setNewMusicAndPlay(const QString& name, const QString& path) {
    this->setNewMusic(name, path);
    m_playMusic = true;
    this->on_ButtonPlay_clicked();
}


void PlayMusic::stateChanged(QMediaPlayer::State state) {
    if (state == QMediaPlayer::StoppedState) {
        if (!ui->ButtinStop->isHidden())
            ui->ButtinStop->hide();
        if (!ui->ButtonPause->isHidden())
            ui->ButtonPause->hide();
        if (ui->ButtonPlay->isHidden())
            ui->ButtonPlay->show();
        if (m_media->mediaStatus() != QMediaPlayer::EndOfMedia)
            ui->sliderMusic->setValue(0);
        else {
            ui->sliderMusic->setValue(100);
            m_window->nextMusic();
        }
    }
    if (state == QMediaPlayer::PlayingState) {
        if (!ui->ButtonPlay->isHidden())
            ui->ButtonPlay->hide();
        if (ui->ButtinStop->isHidden())
            ui->ButtinStop->show();
        if (ui->ButtonPause->isHidden())
            ui->ButtonPause->show();
    }
    if (state == QMediaPlayer::PausedState) {
        if (!ui->ButtonPause->isHidden())
            ui->ButtonPause->hide();
        if (ui->ButtonPlay->isHidden())
            ui->ButtonPlay->show();
    }
}

void PlayMusic::valueChangedSliderMusic(int value) {
    m_media->blockSignals(true);
    m_media->setPosition(m_media->duration() * value / 100);
    m_media->blockSignals(false);
}

void PlayMusic::positionChanged(qint64 position) {
    if (m_media->isAudioAvailable()) {
        if(!ui->sliderMusic->isSliderDown()) {
            ui->sliderMusic->blockSignals(true);
            ui->sliderMusic->setValue((position * 100) / m_media->duration());
            ui->sliderMusic->blockSignals(false);
        }
        this->setTimeMusic(position, m_media->duration());
    }
}

void PlayMusic::on_ButtonPrevious_clicked()
{
    m_window->previousMusic();
}

void PlayMusic::on_ButtonRewind_clicked()
{
    m_media->setPosition(m_media->position() - 10000);
}

void PlayMusic::on_ButtonPause_clicked()
{
    m_media->pause();
}

void PlayMusic::on_ButtinStop_clicked()
{
    m_media->stop();
}

void PlayMusic::on_ButtonPlay_clicked()
{
    m_media->play();
}

void PlayMusic::on_ButtonFastForward_clicked()
{
    m_media->setPosition(m_media->position() + 10000);
}

void PlayMusic::on_ButtonNext_clicked()
{
    m_window->nextMusic();
}
