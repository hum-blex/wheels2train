#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>

#include "car.h"
#include <QPainter>
#include <QPixmap>

class scene : public QGraphicsScene
{
public:
    scene();
protected:
    void keyPressEvent(QKeyEvent * event) override;
private:
    car *lcar =new car(50,670,":/images/redcar.png"); //left car aka red car
    car *rcar =new car(350,670,":/images/bluecar.png");//right car aka blue car
    QPixmap * picture =nullptr;
    QPainter * painter = nullptr;
};

#endif // SCENE_H
