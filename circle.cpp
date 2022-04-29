#include "circle.h"
#include <QGraphicsScene>
#include <QDebug>


Circle::Circle()
{

}

Circle::Circle(int x,int y)
{
    setRect(x,0,50,50);//positon and size of circle
    if(x<300){//for lanes with red car
    setBrush(QBrush(QColor(230, 14, 35),Qt::SolidPattern));//circle color
    setPen(QPen(QColor(191, 6, 24)));//border color
    }
    else{//for lanes with blue car
    setBrush(QBrush(QColor(23, 48, 212),Qt::SolidPattern));//circle color
    setPen(QPen(QColor(8, 27, 156)));//border color
    }

    //connecting the circle to move function when timeout occurs.
    connect(timer,SIGNAL(timeout()),this,SLOT(move())) ;
    timer->start(y);//y is passed from the game class. it is passed such as to change the speed of circles on the basis of scores achieved.
}
Circle::~Circle(){
    delete timer;
}

void Circle::move(){
    //incase the circle collides with car, we delete the circle and send a signal to game class to increase the score
    QList<QGraphicsItem *>colliding_items = collidingItems();
        for(auto a: colliding_items){
            if(typeid(*(a))== typeid(car)){
                scene()->removeItem(this);
                delete this;

                EmmitterC::Instance()->CollidedWithCircle();
                return;

            }
        }
     //if the circle didn't collide then it moves 7 units down in y axis.
     setPos(x(),y()+7);

     //if the circle exceeds the screen size then , delete the circle to save memory and send signal to game class.
     if(y()>=scene()->height()){
         scene()->removeItem(this);
         delete this;//to save memory

    EmmitterC::Instance()->ReachedTheEnd(2);

     }

}



