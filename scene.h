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
    car *lcar =new car(50,700,":/images/audio.png");
    car *rcar =new car(350,700,":/images/no-audio.png");
    QPixmap * picture =nullptr;
    QPainter * painter = nullptr;
};

#endif // SCENE_H
