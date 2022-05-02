#include "game.h"
#include "ui_game.h"
#include <QMessageBox>

#include <QDebug>

static int endg ;
int speed ;
game::game(QWidget *parent) ://default
    QWidget(parent),//default
    ui(new Ui::game)//default
{
    ui->setupUi(this);//default

    ui->graphicsView->setScene(sc);
    ui->graphicsView->setFixedSize(600,800);
    sc->setSceneRect(0,0,600,800);
    sc->addItem(sb);

    //connections..

    connect(EmmitterC::Instance(),SIGNAL(CollidedWithCircle()),this,SLOT(IncreaseScore()));
    connect(EmmitterC::Instance(),SIGNAL(ReachedTheEnd(int)),this,SLOT(EndGame(int)));
    connect(EmmitterS::Instance(),SIGNAL(CollidedWithSquare(int)),this,SLOT(EndGame(int)));

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
    endg =0;
    int gameTimer = 2400;

    timer->start(gameTimer);
    sb->resetScore();   //resets score to zero
    GameEnded= false;
}

void game::spawnCirclesandSquares()
{

    circleOrSquare = rand()%4;
    whichPosition = rand()%4;

    int z=sb->getScore();//gets score from score class

    int gameTimer;
    gameTimer = 2400;
    if(z <= 60)
        gameTimer -= (z/3) * 100;
    else if(z > 60)
        gameTimer = 300;
    timer->start(gameTimer);

    qDebug()<< gameTimer;

    //defining different speed for different scores
    speed = 25;
    if(z <= 50)
        speed -= (z/5) * 2;
    else if(z > 50)
        speed = 4;
    qDebug()<<z;
    qDebug()<<speed;

    //add a case where the both sides get n item at the same time

    if(circleOrSquare == 1){
        Circle *cc = new Circle(topPositions[whichPosition],speed);
        sc->addItem(cc);
    }
    else if(circleOrSquare == 2){
        Square *dd = new Square(topPositions[whichPosition],speed);
        sc->addItem(dd);
    }
    else{
        int inside = rand()%2;
        int side = rand()%2;
        if(inside ==0){
            Circle *cc = new Circle(topPositions[side],speed);
            sc->addItem(cc);
        }
        else{
            Square *dd = new Square(topPositions[side],speed);
            sc->addItem(dd);
        }
        inside = rand()%2;
        side = rand()%2;
        if(inside ==0){
            Circle *cc = new Circle(topPositions[side +2],speed);
            sc->addItem(cc);
        }else{
            Square *dd = new Square(topPositions[side +2],speed);
            sc->addItem(dd);
        }
    }

}

void game::EndGame(int a){

    if(endg == 0) {

        endg = 1;
    } else {
        current_score = sb->getScore();
        qDebug() << current_score;
        return;
    }
//    if(GameEnded){//this is incase the car still collides or circle reaches the end afeter the game has ended;
//        return;
//    }
//    current_score = sb->getScore();
    qDebug() << current_score;
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
    sb->resetScore();
}

void game::IncreaseScore()
{
    if(!GameEnded)
        sb->increaseScore();
}

