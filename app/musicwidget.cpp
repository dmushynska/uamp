#include "musicwidget.h"
#include "ui_musicwidget.h"
#include "generalwindow.h"
#include "musiclist.h"
#include <QtDebug>
#include <QMenu>

musicWidget::musicWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::musicWidget)
{
    ui->setupUi(this);
    this->installEventFilter(this);
    m_main = qobject_cast<generalWindow*>(parent);
//    connect(this, &musicWidget::clicked, this, []{
//        std::cout<< "adwadw" << std::endl;
//    });
    connect(this, &musicWidget::rightClicked, this, [this]{
        QMenu rightMenu;
        rightMenu.addAction("Show tag info", this, [this] {
            this->m_main->showEditTagMusic(m_path);
        });
        rightMenu.show();
        rightMenu.exec(QCursor::pos());
        if (QWidget::mapToGlobal(this->pos()).x() > QCursor::pos().x()
            || QWidget::mapToGlobal(this->pos()).x() + this->size().width() < QCursor::pos().x()
            || QWidget::mapToGlobal(this->pos()).y() - this->pos().y() > QCursor::pos().y()
            || QWidget::mapToGlobal(this->pos()).y() - this->pos().y() + this->size().height() < QCursor::pos().y())
        {
            QEvent *leave = new QEvent(QEvent::HoverLeave);
            QApplication::sendEvent(this, leave);
            delete leave;
        }
    });
    connect(this, &musicWidget::dubleClick, this, &musicWidget::clickDubleWidget);
}




void musicWidget::clickDubleWidget(void) {
    m_main->resetObjectName();
    setObjectName("Play");
    this->m_main->playMusic(this->ui->nameMusic->text());
    this->style()->unpolish(this);
    this->style()->polish(this);
}

void musicWidget::setMusic(const QString& name) {
    ui->nameMusic->setText(name);
    m_path = name;
}

QString musicWidget::getMusic(void) {
    return ui->nameMusic->text();
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

void musicWidget::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

bool musicWidget::eventFilter(QObject *obj, QEvent *event)
{
    if (obj == this) {
        if (event->type() == QEvent::MouseButtonDblClick &&  static_cast<QMouseEvent*>(event)->button() == Qt::LeftButton) {
            emit dubleClick();
//            if (event->type() == QEvent::MouseMove) {
//                std::cout << "11" << std::endl;
            return  true;
//            }
//            else if (event->type() == QEvent::MouseButtonDblClick) {
//                    std::cout << "22" << std::endl;
//                QMouseEvent *keyEvent = static_cast<QMouseEvent*>(event);
//                qDebug() << "Ate key press" << keyEvent->button();
//                return true;
//            } else if (event->type() == QEvent::MouseButtonRelease) {
//                            std::cout << "24" << std::endl;
//                        QMouseEvent *keyEvent = static_cast<QMouseEvent*>(event);
//                        qDebug() << "Ate key press" << keyEvent->button();
//                        return true;
//                    } else{
//                return false;
        }
    } else {
        // pass the event on to the parent class
        return eventFilter(obj, event);
    }
    return false;
};
