#include "musicwidget.h"
#include "ui_musicwidget.h"

musicWidget::musicWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::musicWidget)
{
    ui->setupUi(this);
    this->installEventFilter(this);
    connect(this, &musicWidget::clicked, this, []{
        std::cout<< "adwadw" << std::endl;
    });
    connect(this, &musicWidget::rightClicked, this, [this]{
        std::cout<< "adwadw2" << std::endl;
        ui->Number->setText("2");
//        qobject_cast<QVBoxLayout*>(this->parent())->

    });
    connect(this, &musicWidget::dubleClick, this, []{
        std::cout<< "adwadw3" << std::endl;
    });
}

musicWidget::~musicWidget()
{
    delete ui;
}

void musicWidget::mousePressEvent(QMouseEvent* event) {

   if (event->button() == Qt::LeftButton)
        emit clicked();
   if (event->button() == Qt::RightButton)
        emit rightClicked();
}
