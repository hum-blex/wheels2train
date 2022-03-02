#include "gamepage.h"//default
#include "ui_gamepage.h"//default
#include <QMessageBox>
#include <QPalette>


gamepage::gamepage(QWidget *parent) ://default
    QMainWindow(parent),//default
    ui(new Ui::gamepage)//default
{
    ui->setupUi(this);//default

    picture = new QPixmap(600,800);//declaring a new Pixmap
    painter =new QPainter(picture);//Painter helps us to paint sth/ perform drawing operations

    painter->fillRect(0,0,600,800,QColor(32,210,250));//color in rgb


    QPalette palette;
    palette.setBrush((this)->backgroundRole(),QBrush(*picture));
    (this)->setPalette(palette);

}

gamepage::~gamepage()//default
{
    delete painter;
    delete picture;
    delete ui;//default
}

void gamepage::on_about_clicked()
{
    message= QString("Its a fucking game.Go get a life.");
    QMessageBox::information(this,"ABOUT THIS GAME!",message);
}


void gamepage::on_howtoplay_clicked()
{
    message=QString("This game has two cars that move between two lanes\n"
                    "You would use the left and the right arrow keys to control the cars\n"
                    "The left arrow key controls the left while the right arrow key controls the right car,\n"
                    "If you miss a single circle of if any car collides with a square, that's game over\n"
                    "Survive for as long as you can!");
    QMessageBox::information(this,"HOW TO PLAY", message);
}


void gamepage::on_play_clicked()
{
    gg.show();
    hide();
}

/*
-QPixmap is one of the four classes for handling image data including QImage, QBitmap,QPicture.
-QPixmap is an off-screen image representation that can be used as a paint device.
-QMessageBox provides a modal dialog for informing the user or for asking the user a question and receivine an answer.
*/
