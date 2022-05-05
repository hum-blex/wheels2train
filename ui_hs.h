/********************************************************************************
** Form generated from reading UI file 'hs.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HS_H
#define UI_HS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_hs
{
public:
    QGridLayout *gridLayout;
    QTableView *tableView;

    void setupUi(QDialog *hs)
    {
        if (hs->objectName().isEmpty())
            hs->setObjectName(QString::fromUtf8("hs"));
        hs->resize(331, 430);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(hs->sizePolicy().hasHeightForWidth());
        hs->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(hs);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tableView = new QTableView(hs);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        gridLayout->addWidget(tableView, 0, 0, 1, 1);


        retranslateUi(hs);

        QMetaObject::connectSlotsByName(hs);
    } // setupUi

    void retranslateUi(QDialog *hs)
    {
        hs->setWindowTitle(QCoreApplication::translate("hs", "Highscore", nullptr));
    } // retranslateUi

};

namespace Ui {
    class hs: public Ui_hs {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HS_H
