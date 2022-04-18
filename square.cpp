#include "square.h"
#include <QGraphicsScene>
#include <QDebug>

Square::Square(){

}

Square::Square(int x)
{
    setRect(x,0,50,50);
    if(x<300){
    setBrush(QBrush(QColor(230, 14, 35),Qt::SolidPattern));
    setPen(QPen(QColor(191, 6, 24)));
    }
    else{
    setBrush(QBrush(QColor(23, 48, 212),Qt::SolidPattern));
    setPen(QPen(QColor(8, 27, 156)));
    }

    //connect
    timer = new QTimer;
    connect(timer,SIGNAL(timeout()),this,SLOT(move())) ;
    timer->start(50);
}
Square::~Square(){
    delete timer;
}

void Square::move(){
    QList<QGraphicsItem *>colliding_items = collidingItems();
        for(auto a: colliding_items){
            if(typeid(*(a))== typeid(car)){
                scene()->removeItem(this);
                delete this;

                EmmitterS::Instance()->CollidedWithSquare(1);
                return;
            }
        }
     setPos(x(),y()+7);

     if(y() >= scene()->height()){
         scene()->removeItem(this);
         delete this;

     }
}

