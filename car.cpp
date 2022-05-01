#include "car.h"
#include <QPixmap>


car::car(int x, int y, QString z)
{
    setPixmap(QPixmap(z));
    setPos(x,y);
    position =false;
}

void car::move()
{
//    animation->setDuration(1000);
    if(position == false){
        setPos(x()+150,y());
//        animation->setStartValue(QRect(x(),y(),100,30));
//        animation->setEndValue(QRect(x()+150,y(),100,30));
//        animation->start();
        position = true;
    }
    else{
        setPos(x()-150,y());
        position=false;
    }
}


