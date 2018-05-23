/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

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

class Ui_Dialog
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label_4;
    QLineEdit *starting;
    QLineEdit *ending;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(400, 300);
        Dialog->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/train.png);"));
        label = new QLabel(Dialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(170, 40, 54, 12));
        label_2 = new QLabel(Dialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 90, 91, 16));
        label_3 = new QLabel(Dialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(30, 140, 91, 16));
        pushButton = new QPushButton(Dialog);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(100, 220, 75, 23));
        pushButton_2 = new QPushButton(Dialog);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(310, 260, 75, 23));
        label_4 = new QLabel(Dialog);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(60, 180, 191, 16));
        starting = new QLineEdit(Dialog);
        starting->setObjectName(QStringLiteral("starting"));
        starting->setGeometry(QRect(130, 80, 113, 21));
        ending = new QLineEdit(Dialog);
        ending->setObjectName(QStringLiteral("ending"));
        ending->setGeometry(QRect(130, 130, 113, 21));

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("Dialog", "\347\272\277\350\267\257\346\237\245\350\257\242", Q_NULLPTR));
        label_2->setText(QApplication::translate("Dialog", "\350\257\267\350\276\223\345\205\245\350\265\267\345\247\213\347\253\231\357\274\232", Q_NULLPTR));
        label_3->setText(QApplication::translate("Dialog", "\350\257\267\350\276\223\345\205\245\347\273\210\347\202\271\347\253\231\357\274\232", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Dialog", "\346\237\245\350\257\242", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("Dialog", "\350\277\224\345\233\236", Q_NULLPTR));
        label_4->setText(QApplication::translate("Dialog", "\346\263\250\357\274\232\346\202\250\345\275\223\345\211\215\346\211\200\345\234\250\347\253\231\344\270\272\345\244\247\346\234\233\350\267\257", Q_NULLPTR));
        starting->setText(QApplication::translate("Dialog", "\345\244\247\346\234\233\350\267\257", Q_NULLPTR));
        ending->setText(QApplication::translate("Dialog", "\345\233\275\350\264\270", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
