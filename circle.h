#ifndef CIRCLE_H
#define CIRCLE_H


#include <QObject>
#include <QTimer>
#include <QGraphicsEllipseItem>


#include "car.h"
#include "Singleton.h"
class Circle: public QObject, public QGraphicsEllipseItem
{
    Q_OBJECT
public:
    Circle();
    Circle(int,int);
    ~Circle();
signals:
    void CollidedWithCircle();
    void ReachedTheEnd(int);
private:
    QTimer * timer;
private slots:
    void move();
};
typedef Singleton<Circle> EmmitterC;

#endif // CIRCLE_H
