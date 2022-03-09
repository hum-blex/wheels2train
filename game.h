#ifndef GAME_H
#define GAME_H

#include <QTimer>

#include <QWidget>

#include "scene.h"

#include "square.h"
#include "circle.h"

namespace Ui {//default
class game;//default
}

class game : public QWidget//default
{
    Q_OBJECT//default

public://default
    explicit game(QWidget *parent = nullptr);//default

    ~game();//default
    void start();

private://default
    Ui::game *ui;//default

    scene * sc = new scene();
    QTimer * timer = new QTimer();

    int topPositions[4]={50,200,350,500};
    int circleOrSquare;
    int whichPosition;


private slots:
    void spawnCirclesandSquares();
};

#endif // GAME_H
