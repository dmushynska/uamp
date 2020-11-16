#include "radio.h"
#include "ui_radio.h"
#include "generalwindow.h"

#include <QMediaPlayer>

radio::radio(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::radio)
{
    ui->setupUi(this);
    m_main = qobject_cast<generalWindow*>(parent);
}

radio::~radio()
{
    delete ui;
}

void radio::on_RadioROKS_clicked()
{
    m_player->setMedia((QUrl("http://online.radioroks.ua/RadioROKS")));
    on_Play_clicked();
}

void radio::on_HitFM_clicked()
{
    m_player->setMedia(QUrl("http://online.hitfm.ua/HitFM"));
    on_Play_clicked();
}

void radio::on_RadioJazz_clicked()
{
    m_player->setMedia(QUrl("http://online.radiojazz.ua/RadioJazz_HD"));
    on_Play_clicked();
}

void radio::on_KissFM_clicked()
{
    m_player->setMedia(QUrl("http://online.kissfm.ua/KissFM"));
    on_Play_clicked();
}

void radio::on_Stop_clicked()
{
    m_player->stop();
}

void radio::pause(void) {
    m_player->stop();
}

void radio::on_Play_clicked()
{
    m_main->pause();
    m_player->play();
}
