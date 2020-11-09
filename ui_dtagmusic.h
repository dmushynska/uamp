/********************************************************************************
** Form generated from reading UI file 'dtagmusic.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DTAGMUSIC_H
#define UI_DTAGMUSIC_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DTagMusic
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_7;
    QLabel *label;
    QCheckBox *m_check_box;
    QHBoxLayout *horizontalLayout;
    QLineEdit *m_artist;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *m_Title;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_5;
    QLineEdit *m_Albom;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_2;
    QTextBrowser *m_Lyric;
    QLabel *label_8;
    QHBoxLayout *horizontalLayout_6;
    QLineEdit *m_Genre;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout_7;
    QLineEdit *m_Path;
    QLabel *label_6;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DTagMusic)
    {
        if (DTagMusic->objectName().isEmpty())
            DTagMusic->setObjectName(QString::fromUtf8("DTagMusic"));
        DTagMusic->resize(355, 470);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(DTagMusic->sizePolicy().hasHeightForWidth());
        DTagMusic->setSizePolicy(sizePolicy);
        DTagMusic->setMinimumSize(QSize(355, 470));
        DTagMusic->setMaximumSize(QSize(355, 470));
        widget = new QWidget(DTagMusic);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(6, 13, 340, 465));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_7 = new QLabel(widget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_3->addWidget(label_7);

        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setMaximumSize(QSize(16777215, 40));
        label->setAlignment(Qt::AlignHCenter|Qt::AlignTop);

        horizontalLayout_3->addWidget(label);

        m_check_box = new QCheckBox(widget);
        m_check_box->setObjectName(QString::fromUtf8("m_check_box"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(m_check_box->sizePolicy().hasHeightForWidth());
        m_check_box->setSizePolicy(sizePolicy2);
        m_check_box->setMaximumSize(QSize(16777215, 40));

        horizontalLayout_3->addWidget(m_check_box);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        m_artist = new QLineEdit(widget);
        m_artist->setObjectName(QString::fromUtf8("m_artist"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(m_artist->sizePolicy().hasHeightForWidth());
        m_artist->setSizePolicy(sizePolicy3);
        m_artist->setMaximumSize(QSize(16777215, 20));
        m_artist->setReadOnly(true);

        horizontalLayout->addWidget(m_artist);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);
        label_2->setMinimumSize(QSize(60, 0));
        label_2->setMaximumSize(QSize(60, 20));

        horizontalLayout->addWidget(label_2);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        m_Title = new QLineEdit(widget);
        m_Title->setObjectName(QString::fromUtf8("m_Title"));
        sizePolicy3.setHeightForWidth(m_Title->sizePolicy().hasHeightForWidth());
        m_Title->setSizePolicy(sizePolicy3);
        m_Title->setMaximumSize(QSize(16777215, 20));
        m_Title->setReadOnly(true);

        horizontalLayout_4->addWidget(m_Title);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy1.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy1);
        label_3->setMinimumSize(QSize(60, 20));
        label_3->setMaximumSize(QSize(60, 20));

        horizontalLayout_4->addWidget(label_3);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        m_Albom = new QLineEdit(widget);
        m_Albom->setObjectName(QString::fromUtf8("m_Albom"));
        m_Albom->setMaximumSize(QSize(16777215, 20));
        m_Albom->setReadOnly(true);

        horizontalLayout_5->addWidget(m_Albom);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(60, 0));
        label_4->setMaximumSize(QSize(60, 20));

        horizontalLayout_5->addWidget(label_4);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setSizeConstraint(QLayout::SetMinimumSize);
        m_Lyric = new QTextBrowser(widget);
        m_Lyric->setObjectName(QString::fromUtf8("m_Lyric"));
        sizePolicy2.setHeightForWidth(m_Lyric->sizePolicy().hasHeightForWidth());
        m_Lyric->setSizePolicy(sizePolicy2);
        m_Lyric->setMaximumSize(QSize(16777215, 60));
        m_Lyric->setReadOnly(true);

        horizontalLayout_2->addWidget(m_Lyric);

        label_8 = new QLabel(widget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        sizePolicy1.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy1);
        label_8->setMinimumSize(QSize(60, 0));
        label_8->setMaximumSize(QSize(60, 60));

        horizontalLayout_2->addWidget(label_8);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        m_Genre = new QLineEdit(widget);
        m_Genre->setObjectName(QString::fromUtf8("m_Genre"));
        m_Genre->setMaximumSize(QSize(16777215, 20));
        m_Genre->setReadOnly(true);

        horizontalLayout_6->addWidget(m_Genre);

        label_5 = new QLabel(widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        sizePolicy1.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy1);
        label_5->setMinimumSize(QSize(60, 0));
        label_5->setMaximumSize(QSize(60, 20));

        horizontalLayout_6->addWidget(label_5);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        m_Path = new QLineEdit(widget);
        m_Path->setObjectName(QString::fromUtf8("m_Path"));
        m_Path->setMaximumSize(QSize(16777215, 20));
        m_Path->setReadOnly(true);

        horizontalLayout_7->addWidget(m_Path);

        label_6 = new QLabel(widget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        sizePolicy1.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy1);
        label_6->setMinimumSize(QSize(60, 0));
        label_6->setMaximumSize(QSize(60, 20));

        horizontalLayout_7->addWidget(label_6);


        verticalLayout->addLayout(horizontalLayout_7);

        buttonBox = new QDialogButtonBox(widget);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(DTagMusic);
        QObject::connect(buttonBox, SIGNAL(accepted()), DTagMusic, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DTagMusic, SLOT(reject()));

        QMetaObject::connectSlotsByName(DTagMusic);
    } // setupUi

    void retranslateUi(QDialog *DTagMusic)
    {
        DTagMusic->setWindowTitle(QCoreApplication::translate("DTagMusic", "Dialog", nullptr));
        label_7->setText(QString());
        label->setText(QCoreApplication::translate("DTagMusic", "Settings Tag", nullptr));
        m_check_box->setText(QCoreApplication::translate("DTagMusic", "Edit tag", nullptr));
        label_2->setText(QCoreApplication::translate("DTagMusic", "Artist", nullptr));
        label_3->setText(QCoreApplication::translate("DTagMusic", "Title", nullptr));
        label_4->setText(QCoreApplication::translate("DTagMusic", "Album", nullptr));
        label_8->setText(QCoreApplication::translate("DTagMusic", "Lyric", nullptr));
        label_5->setText(QCoreApplication::translate("DTagMusic", "Genre", nullptr));
        label_6->setText(QCoreApplication::translate("DTagMusic", "Path file", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DTagMusic: public Ui_DTagMusic {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DTAGMUSIC_H
