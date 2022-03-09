#include "square.h"
#include <QGraphicsScene>
#include <QDebug>

Square::Square(){

}

Square::Square(int x)
{
    setRect(x,0,50,50);
    if(x<300){
    setBrush(QBrush(QColor(5, 235, 55),Qt::SolidPattern));//green
    setPen(QPen(QColor(15, 150, 22)));
    }
    else{
    setBrush(QBrush(QColor(235, 235, 5),Qt::SolidPattern));//yellow
    setPen(QPen(QColor(235, 181, 5)));
    }

    //connect
    timer = new QTimer;
    connect(timer,SIGNAL(timeout()),this,SLOT(move())) ;
    timer->start(100);
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

                return;
            }
        }
     setPos(x(),y()+5);

     if(y() >= scene()->height()){
         scene()->removeItem(this);
         delete this;

     }

}

