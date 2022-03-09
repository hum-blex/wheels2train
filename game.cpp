#include "game.h"
#include "ui_game.h"

#include <QDebug>

game::game(QWidget *parent) ://default
    QWidget(parent),//default
    ui(new Ui::game)//default
{
    ui->setupUi(this);//default

    ui->graphicsView->setScene(sc);
    ui->graphicsView->setFixedSize(600,800);
    sc->setSceneRect(0,0,600,800);

 connect(timer , SIGNAL(timeout()),this,SLOT(spawnCirclesandSquares()));
timer->start(5000);
}


game::~game()//default
{
    delete sc;
    delete timer;
    delete ui;//default
}

void game::start()
{
//    timer->start(5000);
}

void game::spawnCirclesandSquares()
{
    circleOrSquare = rand()%4;
    whichPosition = rand()%4;
//    qDebug()<<circleOrSquare;
//    qDebug()<<whichPosition;

    ///addd a case ehere the both sides get n ietm at the sam time lool
;
    if(circleOrSquare == 1){
        Circle *cc = new Circle(topPositions[whichPosition]);
        sc->addItem(cc);

    }else if(circleOrSquare == 2){
        Square *dd = new Square(topPositions[whichPosition]);
        sc->addItem(dd);
    }else{
        int inside = rand()%2;
        int side = rand()%2;
        if(inside ==0){
            Circle *cc = new Circle(topPositions[side]);
            sc->addItem(cc);
        }else{
            Square *dd = new Square(topPositions[side]);
            sc->addItem(dd);
        }
        inside = rand()%2;
        side = rand()%2;
        if(inside ==0){
            Circle *cc = new Circle(topPositions[side +2]);
            sc->addItem(cc);
        }else{
            Square *dd = new Square(topPositions[side +2]);
            sc->addItem(dd);
        }
    }
}
