#ifndef MUSICWIDGET_H
#define MUSICWIDGET_H

#include <QWidget>
#include <iostream>
#include <QEvent>
#include <QMouseEvent>
#include <QtDebug>
#include <QStyleOption>
#include <QPainter>

namespace Ui {
class musicWidget;
}

class musicWidget : public QWidget
{
    Q_OBJECT

public:
    explicit musicWidget(QWidget *parent = nullptr);
    ~musicWidget();


    void paintEvent(QPaintEvent *)
    {
        QStyleOption opt;
        opt.init(this);
        QPainter p(this);
        style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
    }

    bool eventFilter(QObject *obj, QEvent *event)
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
    };

signals:
    void clicked();
    void rightClicked();
    void dubleClick();

protected:
    void mousePressEvent(QMouseEvent* event);

private:
    Ui::musicWidget *ui;
};

#endif // MUSICWIDGET_H
