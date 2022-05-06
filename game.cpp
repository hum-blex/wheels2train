#include "game.h"
#include "ui_game.h"
#include <QMessageBox>

#include <QDebug>

int endg ;
int z;
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
    gameAlreadyEnded= false;
}

void game::spawnCirclesandSquares()
{

    circleOrSquare = rand()%4;
    whichPosition = rand()%4;

     z=sb->getScore();//gets score from score class
    int gameTimer;
    gameTimer = 2400;
    if(z <= 50)
        gameTimer -= (z) * 40;
    else if(z > 50)
        gameTimer = 400;
    timer->start(gameTimer);

    //defining different speed for different scores
    speed = 30;
    if(z <= 50)
        speed -= (z/2) * 1;
    else if(z > 50)
        speed = 5;

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
        current_score =z;

        return;
    }

    gameAlreadyEnded = true;
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

    if (!gameAlreadyEnded){
        sb->increaseScore();
    }
}
