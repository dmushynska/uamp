#include "dtagmusic.h"
#include "ui_dtagmusic.h"
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QMessageBox>
#include <QCheckBox>
#include <QtDebug>
#include <QFile>

DTagMusic::DTagMusic(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DTagMusic)
{
    ui->setupUi(this);
    connect(ui->m_check_box,  &QCheckBox::clicked, this, &DTagMusic::checkBoxChenge);
    this->setModal(true);
    connect(this->ui->buttonBox, &QDialogButtonBox::accepted, this, &DTagMusic::saveChengeTag);
}

void DTagMusic::checkBoxChenge() {
    if (ui->m_check_box->isChecked()) {
        ui->m_artist->setReadOnly(false);
        ui->m_Albom->setReadOnly(false);
        ui->m_Genre->setReadOnly(false);
        ui->m_Title->setReadOnly(false);
        ui->m_Lyric->setReadOnly(false);
    }
    else {
        ui->m_artist->setReadOnly(true);
        ui->m_Albom->setReadOnly(true);
        ui->m_Genre->setReadOnly(true);
        ui->m_Title->setReadOnly(true);
        ui->m_Lyric->setReadOnly(true);
    }
}

void DTagMusic::setTagWindow(const QString& path) {
    ui->m_Path->setText(path);
    {
        TagLib::FileRef f(path.toUtf8().constData());
        ui->m_artist->setText(f.tag()->artist().toCString());
        ui->m_Albom->setText(f.tag()->album().toCString());
        ui->m_Genre->setText(f.tag()->genre().toCString());
        ui->m_Title->setText(f.tag()->title().toCString());
        // ui->m_Lyric->setText(f.tag()->lyric().toCString());
    }
}

void DTagMusic::saveChengeTag(void) {
    if (ui->m_check_box->isChecked()) {
        QFile file(ui->m_Path->text());
        file.open(QIODevice::ReadWrite);
        if (!file.isWritable()) {
            QMessageBox messageBox;
            messageBox.critical(this,"Error","PErmision ERROR!");
            messageBox.setFixedSize(500,200);
        }
        else {
            TagLib::FileRef f(ui->m_Path->text().toUtf8().constData());
            f.tag()->setArtist(ui->m_artist->text().toUtf8().data());
            f.tag()->setAlbum(ui->m_Albom->text().toUtf8().data());
            f.tag()->setGenre(ui->m_Genre->text().toUtf8().data());
            f.tag()->setTitle(ui->m_Title->text().toUtf8().data());
            f.save();
        }
        file.close();
    }
}

DTagMusic::~DTagMusic()
{
    delete ui;
}
