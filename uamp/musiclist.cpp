#include "musiclist.h"
#include "ui_musiclist.h"

MusicList::MusicList(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MusicList)
{
    ui->setupUi(this);
}

MusicList::~MusicList()
{
    delete ui;
}
