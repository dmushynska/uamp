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
    ui->progressMusic->setValue(0);
    connect(m_media, &QMediaPlayer::positionChanged, this, &PlayMusic::positionChanged);
    connect(m_media, &QMediaPlayer::stateChanged, this, &PlayMusic::stateChanged);
    connect(ui->sliderVolume, &QSlider::valueChanged, this, [this] {
        m_media->setVolume(ui->sliderVolume->value());
    });
    window = qobject_cast<generalWindow*>(parent);
    this->setTimeMusic(0, 0);
}

PlayMusic::~PlayMusic()
{
    delete ui;
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

void PlayMusic::setNewMusic(const QString& name) {
    ui->progressMusic->setValue(0);
    m_media->setMedia(QUrl::fromLocalFile(name));
    this->setTimeMusic(0, 0);
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
    if (m_media->isAudioAvailable()) {
        ui->progressMusic->setValue((position * 100) / m_media->duration());
        this->setTimeMusic(position, m_media->duration());
    }
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
         std::cout  << 22 <<std::endl;
    }
    std::cout  << 23 <<std::endl;
}

void PlayMusic::on_ButtonFastForward_clicked()
{
    m_media->setPosition(m_media->position() + 10000);
}

void PlayMusic::on_ButtonNext_clicked()
{
    window->nextMusic();
}
