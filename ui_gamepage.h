/********************************************************************************
** Form generated from reading UI file 'gamepage.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEPAGE_H
#define UI_GAMEPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_gamepage
{
public:
    QWidget *centralwidget;
    QPushButton *play;
    QPushButton *profile;
    QLineEdit *title;
    QPushButton *howtoplay;
    QPushButton *about;
    QGraphicsView *graphicsView;

    void setupUi(QMainWindow *gamepage)
    {
        if (gamepage->objectName().isEmpty())
            gamepage->setObjectName(QString::fromUtf8("gamepage"));
        gamepage->resize(600, 800);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(gamepage->sizePolicy().hasHeightForWidth());
        gamepage->setSizePolicy(sizePolicy);
        gamepage->setMaximumSize(QSize(600, 800));
        gamepage->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(gamepage);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        play = new QPushButton(centralwidget);
        play->setObjectName(QString::fromUtf8("play"));
        play->setGeometry(QRect(185, 224, 241, 241));
        sizePolicy.setHeightForWidth(play->sizePolicy().hasHeightForWidth());
        play->setSizePolicy(sizePolicy);
        play->setStyleSheet(QString::fromUtf8("#play{\n"
"background-color:transparent;\n"
"	border-image: url(:/images/playbutton.jpeg);\n"
"\n"
"border: none;\n"
"background-repeat:none;\n"
"}\n"
""));
        profile = new QPushButton(centralwidget);
        profile->setObjectName(QString::fromUtf8("profile"));
        profile->setGeometry(QRect(240, 470, 130, 125));
        profile->setStyleSheet(QString::fromUtf8("#profile{\n"
"background-color:transparent;\n"
"	border-image: url(:/images/weirdstuff.png);\n"
"\n"
"border: none;\n"
"background-repeat:none;\n"
"}\n"
""));
        title = new QLineEdit(centralwidget);
        title->setObjectName(QString::fromUtf8("title"));
        title->setGeometry(QRect(50, 70, 511, 141));
        title->setStyleSheet(QString::fromUtf8("\n"
"\n"
"#title{\n"
"background-color:transparent;\n"
"	border-image: url(:/images/wheels2train.png);\n"
"\n"
"border: none;\n"
"background-repeat:none;\n"
"}\n"
""));
        howtoplay = new QPushButton(centralwidget);
        howtoplay->setObjectName(QString::fromUtf8("howtoplay"));
        howtoplay->setGeometry(QRect(350, 580, 101, 91));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(howtoplay->sizePolicy().hasHeightForWidth());
        howtoplay->setSizePolicy(sizePolicy1);
        howtoplay->setStyleSheet(QString::fromUtf8("#howtoplay{\n"
"background-color:transparent;\n"
"	border-image: url(:/images/bulb.png);\n"
"\n"
"border: none;\n"
"background-repeat:none;\n"
"}\n"
""));
        about = new QPushButton(centralwidget);
        about->setObjectName(QString::fromUtf8("about"));
        about->setGeometry(QRect(180, 590, 61, 72));
        sizePolicy1.setHeightForWidth(about->sizePolicy().hasHeightForWidth());
        about->setSizePolicy(sizePolicy1);
        about->setStyleSheet(QString::fromUtf8("#about{\n"
"background-color:transparent;\n"
"	border-image: url(:/images/about.png);\n"
"\n"
"border: none;\n"
"background-repeat:none;\n"
"}\n"
""));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(0, 0, 600, 800));
        sizePolicy.setHeightForWidth(graphicsView->sizePolicy().hasHeightForWidth());
        graphicsView->setSizePolicy(sizePolicy);
        graphicsView->setMaximumSize(QSize(600, 800));
        graphicsView->setStyleSheet(QString::fromUtf8("\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(2, 0, 36, 255), stop:0.367925 rgba(16, 5, 52, 255), stop:1 rgba(0, 164, 255, 255));\n"
""));
        gamepage->setCentralWidget(centralwidget);
        graphicsView->raise();
        play->raise();
        profile->raise();
        title->raise();
        howtoplay->raise();
        about->raise();

        retranslateUi(gamepage);

        QMetaObject::connectSlotsByName(gamepage);
    } // setupUi

    void retranslateUi(QMainWindow *gamepage)
    {
        gamepage->setWindowTitle(QCoreApplication::translate("gamepage", "Wheels2Train", nullptr));
        play->setText(QString());
        profile->setText(QString());
        title->setText(QString());
        howtoplay->setText(QString());
        about->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class gamepage: public Ui_gamepage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEPAGE_H
