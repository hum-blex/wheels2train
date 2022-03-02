#ifndef CAR_H
#define CAR_H

#include <QGraphicsPixmapItem>

#include <QGraphicsScene>

class car:public QGraphicsPixmapItem
{
public:
    car(int, int,QString);
    void move();
private:
    bool position;
};

#endif // CAR_H
