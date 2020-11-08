#include "musicwidget.h"
#include "ui_musicwidget.h"
#include "generalwindow.h"
#include "musiclist.h"
#include <QtDebug>
#include <QMenu>
#include <QFileDialog>

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
//    connect(this, &musicWidget::rightClicked, this, [this]{
//        QMenu rightMenu;
//        rightMenu.addAction("Show tag info music", this, [this] {
//            this->m_main->showEditTagMusic(m_path);
//        });
////        rightMenu.addAction("Add new music", this, [this] {
////            qDebug() << QFileDialog::getOpenFileName(
////                            this,
////                            tr("Open Track"),
////                            QDir::currentPath(),
////                            tr("Audio-Files(*.mp3, *.wav, *.mp4, *.flac)"));
////        });
//        rightMenu.addAction("Delete music to Queue", this, [this] {
////            this->m_main->showEditTagMusic(m_path);
//            this->m_main->cleanListMusic();
////            delete this;
////            return;
//        });
//        rightMenu.show();
//        rightMenu.exec(QCursor::pos());
//        if (QWidget::mapToGlobal(this->pos()).x() > QCursor::pos().x()
//            || QWidget::mapToGlobal(this->pos()).x() + this->size().width() < QCursor::pos().x()
//            || QWidget::mapToGlobal(this->pos()).y() - this->pos().y() > QCursor::pos().y()
//            || QWidget::mapToGlobal(this->pos()).y() - this->pos().y() + this->size().height() < QCursor::pos().y())
//        {
//            QEvent *leave = new QEvent(QEvent::HoverLeave);
//            QApplication::sendEvent(this, leave);
//            delete leave;
//        }
//    });
    connect(this, &musicWidget::dubleClick, this, &musicWidget::clickDubleWidget);
}




void musicWidget::clickDubleWidget(void) {
    m_main->resetObjectName();
    setObjectName("Play");
    this->m_main->playMusic(this->ui->nameMusic->text(), this->m_path);
    this->style()->unpolish(this);
    this->style()->polish(this);
}


bool musicWidget::setMusic(const QString& path) {
    TagLib::FileRef f(path.toUtf8().constData());
    ui->Artist->setText(f.tag()->artist().toCString());
    ui->nameMusic->setText(f.tag()->title().toCString());
    m_ChekFile.addPath(path);
    connect(&m_ChekFile, &QFileSystemWatcher::fileChanged, this, &musicWidget::fileChanged);
    m_path = path;
    return true;
}

void musicWidget::fileChanged(const QString &path) {
    TagLib::FileRef f(path.toUtf8().constData());
    ui->Artist->setText(f.tag()->artist().toCString());
    ui->nameMusic->setText(f.tag()->title().toCString());
    m_main->setSort(this->m_main->getSortType());
}

QString musicWidget::getPathMusic(void) {
    return m_path;
}

musicWidget::~musicWidget()
{
    delete ui;
}

//void musicWidget::mousePressEvent(QMouseEvent* event) {

////   if (event->button() == Qt::LeftButton)
////        emit clicked();
////   else if (event->button() == Qt::RightButton)
////        emit rightClicked();
//}

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
//        else if (event->type() == QEvent::MouseButtonPress && static_cast<QMouseEvent*>(event)->button() == Qt::RightButton) {
//            emit rightClicked();
//            return true;
//        }
//        else if (event->type() == QEvent::MouseButtonRelease) {
//            return true;
//        }
//        if (event->type() == QEvent::customContextMenuRequested)
    } else {
        // pass the event on to the parent class
        return eventFilter(obj, event);
    }
    return false;
};
