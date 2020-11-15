#ifndef RADIO_H
#define RADIO_H

#include <QMediaPlayer>
#include <QWidget>

namespace Ui {
class radio;
}

class radio : public QWidget
{
    Q_OBJECT

public:
    explicit radio(QWidget *parent = nullptr);
    ~radio();

private slots:
    void on_RadioROKS_clicked();

    void on_HitFM_clicked();

    void on_Stop_clicked();

    void on_Play_clicked();

    void on_RadioJazz_clicked();

    void on_KissFM_clicked();

private:
    Ui::radio *ui;
    QMediaPlayer *m_player = new QMediaPlayer;
};

#endif // RADIO_H
