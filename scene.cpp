#include "scene.h"
#include <QKeyEvent>

scene::scene()
{
    picture = new QPixmap(600,800);
    painter = new QPainter(picture);
    //here picture becomes the parent of pixmap
    //so when it gets deleted it so does picture

    painter->fillRect(0,0,600,800,Qt::black);//color in rgb
    painter->fillRect(295,0,10,800,Qt::white);

    painter->fillRect(148,0,4,800,Qt::white);
    painter->fillRect(448,0,4,800,Qt::white);
    //here we are drawing the white lines on the road

    addPixmap(*picture);
    addItem(lcar);
    addItem(rcar);
    //adding both cars to the scene
}

void scene::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_Left)
        lcar->move();
    if(event->key()==Qt::Key_Right)
        rcar->move();

}
