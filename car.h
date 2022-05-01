#ifndef CAR_H
#define CAR_H

#include <QGraphicsPixmapItem>
#include <QBrush>
#include <QPropertyAnimation>


#include <QGraphicsScene>

class car:public QObject, public QGraphicsPixmapItem
{
public:
    car(int, int,QString);
    void move();
private:
    bool position;
//    QPropertyAnimation *animation = new QPropertyAnimation();
};

#endif // CAR_H
