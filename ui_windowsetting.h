/********************************************************************************
** Form generated from reading UI file 'windowsetting.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOWSETTING_H
#define UI_WINDOWSETTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_WindowSetting
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label_3;
    QFormLayout *formLayout;
    QLabel *label;
    QComboBox *TypeSort;
    QLabel *label_2;
    QComboBox *TypePlay;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_Cancel;
    QPushButton *pushButton_Save;

    void setupUi(QDialog *WindowSetting)
    {
        if (WindowSetting->objectName().isEmpty())
            WindowSetting->setObjectName(QString::fromUtf8("WindowSetting"));
        WindowSetting->resize(350, 200);
        WindowSetting->setMinimumSize(QSize(350, 200));
        WindowSetting->setMaximumSize(QSize(350, 200));
        verticalLayout = new QVBoxLayout(WindowSetting);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_3 = new QLabel(WindowSetting);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_3);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(WindowSetting);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(1, QFormLayout::FieldRole, label);

        TypeSort = new QComboBox(WindowSetting);
        TypeSort->addItem(QString());
        TypeSort->addItem(QString());
        TypeSort->addItem(QString());
        TypeSort->addItem(QString());
        TypeSort->addItem(QString());
        TypeSort->setObjectName(QString::fromUtf8("TypeSort"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(TypeSort->sizePolicy().hasHeightForWidth());
        TypeSort->setSizePolicy(sizePolicy);
        TypeSort->setMinimumSize(QSize(170, 0));
        TypeSort->setMaximumSize(QSize(170, 16777215));

        formLayout->setWidget(2, QFormLayout::LabelRole, TypeSort);

        label_2 = new QLabel(WindowSetting);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(2, QFormLayout::FieldRole, label_2);

        TypePlay = new QComboBox(WindowSetting);
        TypePlay->addItem(QString());
        TypePlay->addItem(QString());
        TypePlay->addItem(QString());
        TypePlay->addItem(QString());
        TypePlay->setObjectName(QString::fromUtf8("TypePlay"));
        TypePlay->setMinimumSize(QSize(170, 0));
        TypePlay->setMaximumSize(QSize(170, 16777215));

        formLayout->setWidget(1, QFormLayout::LabelRole, TypePlay);


        verticalLayout->addLayout(formLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        pushButton_Cancel = new QPushButton(WindowSetting);
        pushButton_Cancel->setObjectName(QString::fromUtf8("pushButton_Cancel"));

        horizontalLayout_3->addWidget(pushButton_Cancel);

        pushButton_Save = new QPushButton(WindowSetting);
        pushButton_Save->setObjectName(QString::fromUtf8("pushButton_Save"));

        horizontalLayout_3->addWidget(pushButton_Save);


        verticalLayout->addLayout(horizontalLayout_3);


        retranslateUi(WindowSetting);

        QMetaObject::connectSlotsByName(WindowSetting);
    } // setupUi

    void retranslateUi(QDialog *WindowSetting)
    {
        WindowSetting->setWindowTitle(QCoreApplication::translate("WindowSetting", "Setting", nullptr));
        label_3->setText(QCoreApplication::translate("WindowSetting", "Settings", nullptr));
        label->setText(QCoreApplication::translate("WindowSetting", "Type play music next", nullptr));
        TypeSort->setItemText(0, QCoreApplication::translate("WindowSetting", "Users sorting", nullptr));
        TypeSort->setItemText(1, QCoreApplication::translate("WindowSetting", "Artist", nullptr));
        TypeSort->setItemText(2, QCoreApplication::translate("WindowSetting", "Title", nullptr));
        TypeSort->setItemText(3, QCoreApplication::translate("WindowSetting", "Album", nullptr));
        TypeSort->setItemText(4, QCoreApplication::translate("WindowSetting", "Genre", nullptr));

        label_2->setText(QCoreApplication::translate("WindowSetting", "Sorting music Queue", nullptr));
        TypePlay->setItemText(0, QCoreApplication::translate("WindowSetting", "One single song", nullptr));
        TypePlay->setItemText(1, QCoreApplication::translate("WindowSetting", "Loop Queue", nullptr));
        TypePlay->setItemText(2, QCoreApplication::translate("WindowSetting", "Repeat a single song", nullptr));
        TypePlay->setItemText(3, QCoreApplication::translate("WindowSetting", "Random music", nullptr));

        pushButton_Cancel->setText(QCoreApplication::translate("WindowSetting", "Cancel", nullptr));
        pushButton_Save->setText(QCoreApplication::translate("WindowSetting", "Save", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WindowSetting: public Ui_WindowSetting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOWSETTING_H
