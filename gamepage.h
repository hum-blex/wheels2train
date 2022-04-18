#ifndef GAMEPAGE_H
#define GAMEPAGE_H

#include <QMainWindow>//default
#include <QPainter>
#include <QBrush>
#include <QFile>
#include "game.h"
#include "highscore.h"
#include "entername.h"

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

    void enter_name();

    void return_to_main_page();

    void on_profile_clicked();

private:
    Ui::gamepage *ui;//default
    QPixmap * picture = nullptr;
    QPainter *painter = nullptr;

    game gg;// defining game
    highscore hh;
    entername ee;

    QString message;

    int highscore;
};

#endif // GAMEPAGE_H
