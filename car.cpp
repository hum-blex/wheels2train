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

    if(position == false){
        setPos(x()+150,y());
        position = true;
    }
    else{
        setPos(x()-150,y());
        position=false;
    }
}


