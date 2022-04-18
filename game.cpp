#include "game.h"
#include "ui_game.h"
#include <QMessageBox>

#include <QDebug>

game::game(QWidget *parent) ://default
    QWidget(parent),//default
    ui(new Ui::game)//default
{
    ui->setupUi(this);//default

    ui->graphicsView->setScene(sc);
    ui->graphicsView->setFixedSize(600,800);
    sc->setSceneRect(0,0,600,800);
    sc->addItem(sb);

    connect(EmmitterC::Instance(),SIGNAL(CollidedWithCircle()),this,SLOT(IncreaseScore()));
    connect(EmmitterC::Instance(),SIGNAL(ReachedTheEnd(int)),this,SLOT(EndGame(int)));
    connect(EmmitterS::Instance(),SIGNAL(CollidedWithSquare(int)),this,SLOT(EndGame(int)));

//    connect(EmmitterO::Instance(),SIGNAL(scoreten()),this,SLOT(IncreaseSpeed()));
    connect(timer , SIGNAL(timeout()),this,SLOT(spawnCirclesandSquares()));


}


game::~game()//default
{
    delete sc;
     delete sb;
    delete timer;
    delete ui;//default
}

void game::start()
{
    timer->start(3000);
    sb->resetScore();
    GameEnded= false;
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

void game::EndGame(int a){
    if(GameEnded){//this is incase the car still collides or circle reaches the end afeter the game has ended;
        return;
    }
    current_score = sb->getScore();
    GameEnded = true;
    timer->stop();
    QString message{};

    if(a == 1){
        message = "You hit a Square";
    }else{
        message = "You missed a Circle";
    }

    QMessageBox box(QMessageBox::Critical,"GAME OVER!",message,QMessageBox::Ok);
            if(box.exec() == QMessageBox::Ok){
                gameEnded();
                close();
            }
}

void game::IncreaseScore()
{
    if(!GameEnded)
        sb->increaseScore();
}

//void game::IncreaseSpeed()
//{

//}
