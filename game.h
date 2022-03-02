#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include "scene.h"

namespace Ui {//default
class game;//default
}

class game : public QWidget//default
{
    Q_OBJECT//default

public://default
    explicit game(QWidget *parent = nullptr);//default
    ~game();//default

private://default
    Ui::game *ui;//default

    scene * sc = new scene();
};

#endif // GAME_H
