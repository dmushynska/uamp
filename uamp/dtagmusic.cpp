#include "dtagmusic.h"
#include "ui_dtagmusic.h"
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QMessageBox>
#include <QCheckBox>

DTagMusic::DTagMusic(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DTagMusic)
{
    ui->setupUi(this);
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
            QImage image("/Users/solianovsk/Desktop/Screen Shot 2020-11-04 at 5.36.40 PM.png");
//            QLabel *a = new QLabel;
    ui->m_img->setScaledContents(true);
            ui->m_img->setPixmap(QPixmap::fromImage(image));
            connect(ui->m_check_box,  &QCheckBox::clicked, this, [this]{
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
            });
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
    this->setModal(true);
}

void DTagMusic::setTagWindow(const QString& path) {
    ui->m_Path->setText(path);
}



DTagMusic::~DTagMusic()
{
    delete ui;
}
