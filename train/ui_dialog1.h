/********************************************************************************
** Form generated from reading UI file 'dialog1.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG1_H
#define UI_DIALOG1_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog1
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *starting;
    QLineEdit *ending;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label_4;

    void setupUi(QDialog *Dialog1)
    {
        if (Dialog1->objectName().isEmpty())
            Dialog1->setObjectName(QStringLiteral("Dialog1"));
        Dialog1->resize(400, 300);
        Dialog1->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/train.png);"));
        label = new QLabel(Dialog1);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(160, 40, 71, 16));
        label_2 = new QLabel(Dialog1);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 90, 101, 16));
        label_3 = new QLabel(Dialog1);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(30, 130, 101, 16));
        starting = new QLineEdit(Dialog1);
        starting->setObjectName(QStringLiteral("starting"));
        starting->setGeometry(QRect(140, 90, 113, 20));
        ending = new QLineEdit(Dialog1);
        ending->setObjectName(QStringLiteral("ending"));
        ending->setGeometry(QRect(140, 130, 113, 20));
        pushButton = new QPushButton(Dialog1);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(110, 190, 75, 23));
        pushButton_2 = new QPushButton(Dialog1);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(300, 260, 75, 23));
        label_4 = new QLabel(Dialog1);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(50, 230, 221, 20));

        retranslateUi(Dialog1);

        QMetaObject::connectSlotsByName(Dialog1);
    } // setupUi

    void retranslateUi(QDialog *Dialog1)
    {
        Dialog1->setWindowTitle(QApplication::translate("Dialog1", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("Dialog1", "\345\242\236\346\267\273\347\253\231\347\202\271", Q_NULLPTR));
        label_2->setText(QApplication::translate("Dialog1", "\345\242\236\345\212\240\347\253\231\347\202\271\345\220\215\347\247\260\357\274\232", Q_NULLPTR));
        label_3->setText(QApplication::translate("Dialog1", "\347\253\231\347\202\271\346\211\200\345\234\250\347\272\277\350\267\257\357\274\232", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Dialog1", "\346\267\273\345\212\240", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("Dialog1", "\350\277\224\345\233\236", Q_NULLPTR));
        label_4->setText(QApplication::translate("Dialog1", "\346\263\250\357\274\232\346\262\241\346\234\2113,7\345\217\267\347\272\277\345\217\21211\357\274\21412\345\217\267\347\272\277", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Dialog1: public Ui_Dialog1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG1_H
