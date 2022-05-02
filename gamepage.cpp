#include "gamepage.h"//default
#include "ui_gamepage.h"//default
#include <QMessageBox>
#include <QPalette>
#include "hs.h"
#include "score.h"

gamepage::gamepage(QWidget *parent) ://default
    QMainWindow(parent),//default
    ui(new Ui::gamepage)//default
{
    ui->setupUi(this);//default

    ui->centralwidget->setStyleSheet("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(2, 0, 36, 255), stop:0.367925 rgba(16, 5, 52, 255), stop:1 rgba(0, 164, 255, 255));");

    connect(&gg,SIGNAL(gameEnded()),this,SLOT(enter_name()));
//    connect(&hh,SIGNAL(profile_seen()),this,SLOT(return_to_main_page()));
    connect(&ee,SIGNAL(name_entered()),this,SLOT(return_to_main_page()));

}

gamepage::~gamepage()//default
{
    delete painter;
    delete picture;
    delete ui;//default
}

void gamepage::on_about_clicked()
{


    message= QString("It is a game developed by :\n"
                     "-Pranay Kauri\n"
                     "-Gunjan Thapa\n"
                     "-Drishya Raj Sharma\n"
                     "-Salon Gautam");
    QMessageBox::information(this,"ABOUT THIS GAME!",message);

}


void gamepage::on_howtoplay_clicked()
{
    message=QString("<span style='color:#000;'>This game has two cars that move between two lanes\n"
                    "You would use the left and the right arrow keys to control the cars\n"
                    "The left arrow key controls the left while the right arrow key controls the right car,\n"
                    "If you miss a single circle of if any car collides with a square, that's game over\n"
                    "Survive for as long as you can!</span>").arg(">>>");
    QMessageBox::information(this,"HOW TO PLAY", message);

}


void gamepage::on_play_clicked()
{
    sb->resetScore();
    gg.show();
    gg.start();
    hide();
    return;
}

void gamepage::enter_name()
{
    ee.show();
    return;
}

void gamepage::return_to_main_page()
{
   show();
   return;
}


/*
-QPixmap is one of the four classes for handling image data including QImage, QBitmap,QPicture.
-QPixmap is an off-screen image representation that can be used as a paint device.
-QMessageBox provides a modal dialog for informing the user or for asking the user a question and receivine an answer.
*/

void gamepage::on_profile_clicked()
{
    connOpen();
    QSqlQuery *qry = new QSqlQuery();
    qry -> prepare("SELECT name, score FROM tbl_userinfo ORDER BY score DESC LIMIT 10");
    qry->exec();
    hs highwindow(this, qry);
    highwindow.exec();
    connClose();
    return;
}

