#include "dtagmusic.h"
#include "ui_dtagmusic.h"
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QMessageBox>
#include <QCheckBox>
#include <QtDebug>

DTagMusic::DTagMusic(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DTagMusic)
{
    ui->setupUi(this);
    connect(ui->m_check_box,  &QCheckBox::clicked, this, &DTagMusic::checkBoxChenge);
    this->setModal(true);
//    QImage image("/Users/solianovsk/Desktop/Screen Shot 2020-11-04 at 5.36.40 PM.png");

//            if(image.isNull())
//            {
//                QMessageBox::information(this,"Image Viewer","Error Displaying image");
//                return;
//            }

//            QGraphicsScene scene;
//            QGraphicsPixmapItem item(QPixmap::fromImage(image));
//            scene.addItem(&item);
//            ui->graphicsView->scene()->addItem(new QGraphicsPixmapItem(QPixmap::fromImage(QImage("/Users/solianovsk/Desktop/Screen Shot 2020-11-04 at 5.36.40 PM.png"))));
//            QString filename = "X:/my_image";
//            QImage image("/Users/solianovsk/Desktop/Screen Shot 2020-11-04 at 5.36.40 PM.png");
//            QLabel *a = new QLabel;
//    ui->m_img->setScaledContents(true);
//            ui->m_img->setPixmap(QPixmap::fromImage(image));
//            ui->m_img->

//            ui->label->setPixmap(QPixmap::fromImage(image));
//            ui->graphicsView->setScene(&scene);
//            ui->graphicsView->hide();
//            ui->graphicsView->show();
//    QPixmap myPixmap("/Users/solianovsk/Desktop/AIMP-Player.png");

//    this->ui->m_img->setPixmap(myPixmap);
//    myPixmap.mask();
//    this->ui->m_img->setMask(myPixmap.mask());
//    this->ui->m_img->setStyleSheet("background-image: url(/Users/solianovsk/Desktop/AIMP-Player.png)");
//    this->ui->m_img->show();
//    this->style()->unpolish(this);
//    this->style()->polish(this);
//    this->setModal(true);
    connect(this->ui->buttonBox, &QDialogButtonBox::accepted, this, &DTagMusic::saveChengeTag);
}

void DTagMusic::checkBoxChenge() {
    if (ui->m_check_box->isChecked()) {
        ui->m_artist->setReadOnly(false);
        ui->m_Albom->setReadOnly(false);
        ui->m_Genre->setReadOnly(false);
        ui->m_Title->setReadOnly(false);
    }
    else {
        ui->m_artist->setReadOnly(true);
        ui->m_Albom->setReadOnly(true);
        ui->m_Genre->setReadOnly(true);
        ui->m_Title->setReadOnly(true);
    }
}

void DTagMusic::setTagWindow(const QString& path) {
    ui->m_Path->setText(path);
    TagLib::FileRef f(path.toUtf8().constData());
    ui->m_artist->setText(f.tag()->artist().toCString());
    ui->m_Albom->setText(f.tag()->album().toCString());
    ui->m_Genre->setText(f.tag()->genre().toCString());
    ui->m_Title->setText(f.tag()->title().toCString());
}

void DTagMusic::saveChengeTag(void) {
    if (ui->m_check_box->isChecked()) {
        TagLib::FileRef f(ui->m_Path->text().toUtf8().constData());

        f.tag()->setArtist(ui->m_artist->text().toUtf8().data());
        f.tag()->setAlbum(ui->m_Albom->text().toUtf8().data());
        f.tag()->setGenre(ui->m_Genre->text().toUtf8().data());
        f.tag()->setTitle(ui->m_Title->text().toUtf8().data());
        f.save();
    }
}

DTagMusic::~DTagMusic()
{
    delete ui;
}
