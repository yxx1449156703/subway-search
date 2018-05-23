/********************************************************************************
** Form generated from reading UI file 'ziz.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ZIZ_H
#define UI_ZIZ_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ziz
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ziz)
    {
        if (ziz->objectName().isEmpty())
            ziz->setObjectName(QStringLiteral("ziz"));
        ziz->resize(400, 300);
        ziz->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/train.png);"));
        centralWidget = new QWidget(ziz);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(140, 30, 131, 16));
        label->setStyleSheet(QStringLiteral("font: 9pt \"Adobe Arabic\";"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(40, 70, 75, 23));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(40, 110, 75, 23));
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(40, 150, 75, 23));
        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(40, 190, 75, 23));
        pushButton_5 = new QPushButton(centralWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(300, 230, 75, 23));
        ziz->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(ziz);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        ziz->setStatusBar(statusBar);

        retranslateUi(ziz);

        QMetaObject::connectSlotsByName(ziz);
    } // setupUi

    void retranslateUi(QMainWindow *ziz)
    {
        ziz->setWindowTitle(QApplication::translate("ziz", "ziz", Q_NULLPTR));
        label->setText(QApplication::translate("ziz", "\345\214\227\344\272\254\345\234\260\351\223\201\346\237\245\350\257\242\347\263\273\347\273\237", Q_NULLPTR));
        pushButton->setText(QApplication::translate("ziz", "\347\272\277\350\267\257\346\237\245\350\257\242", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("ziz", "\345\242\236\346\267\273\347\253\231\347\202\271", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("ziz", "\346\237\245\347\234\213\345\234\260\351\223\201", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("ziz", "\350\201\224\347\263\273\346\210\221\344\273\254", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("ziz", "\351\200\200\345\207\272", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ziz: public Ui_ziz {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ZIZ_H
