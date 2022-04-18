#include "circle.h"
#include <QGraphicsScene>
#include <QDebug>


Circle::Circle()
{

}

Circle::Circle(int x)
{
    int y =50;
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
    connect(timer,SIGNAL(timeout()),this,SLOT(move())) ;
    timer->start(y);
}
Circle::~Circle(){
    delete timer;
}

void Circle::move(){
    QList<QGraphicsItem *>colliding_items = collidingItems();
        for(auto a: colliding_items){
            if(typeid(*(a))== typeid(car)){
                scene()->removeItem(this);
                delete this;

                EmmitterC::Instance()->CollidedWithCircle();
                return;

            }
        }
     setPos(x(),y()+7);

     if(y()>=scene()->height()){
         scene()->removeItem(this);
         delete this;//to save memory

    EmmitterC::Instance()->ReachedTheEnd(2);

     }

}



