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
    car *lcar =new car(50,690,":/images/redcar.png");
    car *rcar =new car(350,690,":/images/bluecar.png");
    QPixmap * picture =nullptr;
    QPainter * painter = nullptr;
};

#endif // SCENE_H
