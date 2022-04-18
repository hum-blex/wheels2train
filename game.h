 #ifndef GAME_H
#define GAME_H

#include <QTimer>

#include <QWidget>

#include "scene.h"

#include "square.h"
#include "circle.h"
#include "score.h"

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
    int getCurrentScore(){return current_score;}

signals:
    void gameEnded();

private://default
    Ui::game *ui;//default

    scene * sc = new scene();
    Score * sb  = new Score();
    QTimer * timer = new QTimer();

    int topPositions[4]={50,200,350,500};
    int circleOrSquare;
    int whichPosition;

    bool GameEnded{false};
    int current_score{0};


private slots:
    void spawnCirclesandSquares();
    void EndGame(int);
    void IncreaseScore();
//    void IncreaseSpeed();
};

#endif // GAME_H
