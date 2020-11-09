/********************************************************************************
** Form generated from reading UI file 'musicwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MUSICWIDGET_H
#define UI_MUSICWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_musicWidget
{
public:
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *Artist;
    QLabel *divis;
    QLabel *nameMusic;
    QLabel *time;

    void setupUi(QWidget *musicWidget)
    {
        if (musicWidget->objectName().isEmpty())
            musicWidget->setObjectName(QString::fromUtf8("musicWidget"));
        musicWidget->resize(481, 42);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(musicWidget->sizePolicy().hasHeightForWidth());
        musicWidget->setSizePolicy(sizePolicy);
        musicWidget->setMaximumSize(QSize(16777215, 42));
        horizontalLayout_2 = new QHBoxLayout(musicWidget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(5, 5, 5, 5);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        Artist = new QLabel(musicWidget);
        Artist->setObjectName(QString::fromUtf8("Artist"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(Artist->sizePolicy().hasHeightForWidth());
        Artist->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(Artist);

        divis = new QLabel(musicWidget);
        divis->setObjectName(QString::fromUtf8("divis"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(divis->sizePolicy().hasHeightForWidth());
        divis->setSizePolicy(sizePolicy2);

        horizontalLayout->addWidget(divis);

        nameMusic = new QLabel(musicWidget);
        nameMusic->setObjectName(QString::fromUtf8("nameMusic"));
        sizePolicy1.setHeightForWidth(nameMusic->sizePolicy().hasHeightForWidth());
        nameMusic->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(nameMusic);

        time = new QLabel(musicWidget);
        time->setObjectName(QString::fromUtf8("time"));
        sizePolicy.setHeightForWidth(time->sizePolicy().hasHeightForWidth());
        time->setSizePolicy(sizePolicy);
        time->setLayoutDirection(Qt::LeftToRight);
        time->setTextFormat(Qt::AutoText);
        time->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(time);


        horizontalLayout_2->addLayout(horizontalLayout);


        retranslateUi(musicWidget);

        QMetaObject::connectSlotsByName(musicWidget);
    } // setupUi

    void retranslateUi(QWidget *musicWidget)
    {
        musicWidget->setWindowTitle(QCoreApplication::translate("musicWidget", "Form", nullptr));
        Artist->setText(QCoreApplication::translate("musicWidget", "Autor", nullptr));
        divis->setText(QCoreApplication::translate("musicWidget", "-", nullptr));
        nameMusic->setText(QCoreApplication::translate("musicWidget", "NameMusic", nullptr));
        time->setText(QCoreApplication::translate("musicWidget", "time", nullptr));
    } // retranslateUi

};

namespace Ui {
    class musicWidget: public Ui_musicWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MUSICWIDGET_H
