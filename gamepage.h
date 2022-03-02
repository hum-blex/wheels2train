#ifndef GAMEPAGE_H
#define GAMEPAGE_H

#include <QMainWindow>//default
#include <QPainter>
#include <QBrush>
#include <QFile>
#include "game.h"

namespace Ui {//default
class gamepage;//default
}

class gamepage : public QMainWindow//default
{
    Q_OBJECT//default//macro :helps in controlling signals and slots

public:
    explicit gamepage(QWidget *parent = nullptr);//default//constructor
    ~gamepage();//default//destructor

private slots:
    void on_about_clicked();

    void on_howtoplay_clicked();

    void on_play_clicked();

private:
    Ui::gamepage *ui;//default
    QPixmap * picture = nullptr;
    QPainter *painter = nullptr;

    game gg;// defining game

    QString message;
};

#endif // GAMEPAGE_H
