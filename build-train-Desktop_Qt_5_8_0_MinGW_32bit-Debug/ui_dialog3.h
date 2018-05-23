/********************************************************************************
** Form generated from reading UI file 'dialog3.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG3_H
#define UI_DIALOG3_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_Dialog3
{
public:
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QLabel *label_3;
    QTextEdit *textEdit;
    QTextEdit *textEdit_3;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *Dialog3)
    {
        if (Dialog3->objectName().isEmpty())
            Dialog3->setObjectName(QStringLiteral("Dialog3"));
        Dialog3->resize(1000, 762);
        Dialog3->setAutoFillBackground(false);
        Dialog3->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/train2.png);"));
        label = new QLabel(Dialog3);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 71, 16));
        label_2 = new QLabel(Dialog3);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(0, 180, 71, 20));
        lineEdit_2 = new QLineEdit(Dialog3);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(0, 210, 91, 21));
        label_3 = new QLabel(Dialog3);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(670, 0, 81, 16));
        textEdit = new QTextEdit(Dialog3);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(0, 20, 321, 141));
        textEdit_3 = new QTextEdit(Dialog3);
        textEdit_3->setObjectName(QStringLiteral("textEdit_3"));
        textEdit_3->setGeometry(QRect(670, 20, 321, 141));
        pushButton = new QPushButton(Dialog3);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(810, 260, 93, 28));
        pushButton_2 = new QPushButton(Dialog3);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(850, 580, 93, 28));

        retranslateUi(Dialog3);

        QMetaObject::connectSlotsByName(Dialog3);
    } // setupUi

    void retranslateUi(QDialog *Dialog3)
    {
        Dialog3->setWindowTitle(QApplication::translate("Dialog3", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("Dialog3", "\346\234\200\347\237\255\350\267\257\347\272\277\357\274\232", Q_NULLPTR));
        label_2->setText(QApplication::translate("Dialog3", "\346\211\200\351\234\200\346\227\266\351\227\264\357\274\232", Q_NULLPTR));
        label_3->setText(QApplication::translate("Dialog3", "\346\234\200\345\260\221\346\215\242\344\271\230\357\274\232", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Dialog3", "\346\237\245\350\257\242\350\267\257\347\272\277", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("Dialog3", "\350\277\224\345\233\236", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Dialog3: public Ui_Dialog3 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG3_H
