/********************************************************************************
** Form generated from reading UI file 'playmusic.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLAYMUSIC_H
#define UI_PLAYMUSIC_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PlayMusic
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QSlider *sliderMusic;
    QLabel *labelTime;
    QHBoxLayout *horizontalLayout;
    QLabel *NameMusic;
    QPushButton *ButtonPrevious;
    QPushButton *ButtonRewind;
    QPushButton *ButtonPlay;
    QPushButton *ButtonPause;
    QPushButton *ButtinStop;
    QPushButton *ButtonFastForward;
    QPushButton *ButtonNext;
    QSlider *sliderVolume;

    void setupUi(QWidget *PlayMusic)
    {
        if (PlayMusic->objectName().isEmpty())
            PlayMusic->setObjectName(QString::fromUtf8("PlayMusic"));
        PlayMusic->resize(635, 60);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(PlayMusic->sizePolicy().hasHeightForWidth());
        PlayMusic->setSizePolicy(sizePolicy);
        PlayMusic->setMinimumSize(QSize(0, 60));
        PlayMusic->setMaximumSize(QSize(16777215, 60));
        verticalLayout = new QVBoxLayout(PlayMusic);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        sliderMusic = new QSlider(PlayMusic);
        sliderMusic->setObjectName(QString::fromUtf8("sliderMusic"));
        sliderMusic->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(sliderMusic);

        labelTime = new QLabel(PlayMusic);
        labelTime->setObjectName(QString::fromUtf8("labelTime"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(labelTime->sizePolicy().hasHeightForWidth());
        labelTime->setSizePolicy(sizePolicy1);
        labelTime->setMinimumSize(QSize(50, 20));
        labelTime->setMaximumSize(QSize(50, 20));
        QFont font;
        font.setPointSize(7);
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        labelTime->setFont(font);
        labelTime->setLayoutDirection(Qt::LeftToRight);
        labelTime->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(labelTime);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        NameMusic = new QLabel(PlayMusic);
        NameMusic->setObjectName(QString::fromUtf8("NameMusic"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(NameMusic->sizePolicy().hasHeightForWidth());
        NameMusic->setSizePolicy(sizePolicy2);

        horizontalLayout->addWidget(NameMusic);

        ButtonPrevious = new QPushButton(PlayMusic);
        ButtonPrevious->setObjectName(QString::fromUtf8("ButtonPrevious"));

        horizontalLayout->addWidget(ButtonPrevious);

        ButtonRewind = new QPushButton(PlayMusic);
        ButtonRewind->setObjectName(QString::fromUtf8("ButtonRewind"));

        horizontalLayout->addWidget(ButtonRewind);

        ButtonPlay = new QPushButton(PlayMusic);
        ButtonPlay->setObjectName(QString::fromUtf8("ButtonPlay"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(ButtonPlay->sizePolicy().hasHeightForWidth());
        ButtonPlay->setSizePolicy(sizePolicy3);

        horizontalLayout->addWidget(ButtonPlay);

        ButtonPause = new QPushButton(PlayMusic);
        ButtonPause->setObjectName(QString::fromUtf8("ButtonPause"));

        horizontalLayout->addWidget(ButtonPause);

        ButtinStop = new QPushButton(PlayMusic);
        ButtinStop->setObjectName(QString::fromUtf8("ButtinStop"));

        horizontalLayout->addWidget(ButtinStop);

        ButtonFastForward = new QPushButton(PlayMusic);
        ButtonFastForward->setObjectName(QString::fromUtf8("ButtonFastForward"));

        horizontalLayout->addWidget(ButtonFastForward);

        ButtonNext = new QPushButton(PlayMusic);
        ButtonNext->setObjectName(QString::fromUtf8("ButtonNext"));

        horizontalLayout->addWidget(ButtonNext);

        sliderVolume = new QSlider(PlayMusic);
        sliderVolume->setObjectName(QString::fromUtf8("sliderVolume"));
        sliderVolume->setMinimumSize(QSize(100, 0));
        sliderVolume->setMaximumSize(QSize(100, 16777215));
        sliderVolume->setMaximum(100);
        sliderVolume->setValue(100);
        sliderVolume->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(sliderVolume);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(PlayMusic);

        QMetaObject::connectSlotsByName(PlayMusic);
    } // setupUi

    void retranslateUi(QWidget *PlayMusic)
    {
        PlayMusic->setWindowTitle(QCoreApplication::translate("PlayMusic", "Form", nullptr));
        labelTime->setText(QString());
        NameMusic->setText(QString());
        ButtonPrevious->setText(QCoreApplication::translate("PlayMusic", "< ||", nullptr));
        ButtonRewind->setText(QCoreApplication::translate("PlayMusic", "<<", nullptr));
        ButtonPlay->setText(QCoreApplication::translate("PlayMusic", "play", nullptr));
        ButtonPause->setText(QCoreApplication::translate("PlayMusic", "||", nullptr));
        ButtinStop->setText(QCoreApplication::translate("PlayMusic", "stop", nullptr));
        ButtonFastForward->setText(QCoreApplication::translate("PlayMusic", ">>", nullptr));
        ButtonNext->setText(QCoreApplication::translate("PlayMusic", "|| >", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PlayMusic: public Ui_PlayMusic {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAYMUSIC_H
