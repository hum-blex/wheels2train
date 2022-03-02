#include "scene.h"
#include <QKeyEvent>

scene::scene()
{
    picture = new QPixmap(600,800);
    painter = new QPainter(picture);


    painter->fillRect(0,0,600,800,QColor(32,210,250));//color in rgb
    painter->fillRect(295,0,10,800,Qt::white);
    int interval=0;
    for(int i=0 ;i<14;i++){
        painter->fillRect(148,interval,4,40,Qt::white);
        painter->fillRect(448,interval,4,40,Qt::white);
        interval+=60;
    }

    addPixmap(*picture);
    addItem(lcar);
    addItem(rcar);
}

void scene::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_Left)
        lcar->move();
    if(event->key()==Qt::Key_Right)
        rcar->move();

}
