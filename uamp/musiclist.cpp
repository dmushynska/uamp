#include "musiclist.h"
#include "ui_musiclist.h"
#include "musicwidget.h"

MusicList::MusicList(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MusicList)
{
    ui->setupUi(this);
    ui->layaoutPlayMusicList->insertWidget(0, new musicWidget(ui->layaoutPlayMusicList->widget()));
    ui->layaoutPlayMusicList->insertWidget(0, new musicWidget(ui->layaoutPlayMusicList->widget()));
    ui->layaoutPlayMusicList->insertWidget(0, new musicWidget(ui->layaoutPlayMusicList->widget()));
}

MusicList::~MusicList()
{
    delete ui;
}
