#ifndef SQUARE_H
#define SQUARE_H

#include <QObject>
#include <QTimer>
#include <QGraphicsRectItem>

#include "car.h"
#include "Singleton.h"

class Square: public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    Square();
    Square(int,int);
    ~Square();
signals:
    void CollidedWithSquare(int);
private:
    QTimer * timer;
private slots:
    void move();
};
typedef Singleton<Square> EmmitterS;

#endif // CIRCLE_H
