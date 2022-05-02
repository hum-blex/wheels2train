#ifndef GAMEPAGE_H
#define GAMEPAGE_H

#include <QMainWindow>//default
#include <QPainter>
#include <QBrush>
#include <QFile>
#include "game.h"
#include "score.h"

#include "entername.h"
//#include "hs.h"

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
    Score * sb  = new Score();
    game gg;// defining game
    entername ee;
    QSqlDatabase mydb;
    void connClose(){
        mydb.close();
        mydb.removeDatabase(QSqlDatabase::defaultConnection);
    }

    bool connOpen(){
        mydb = QSqlDatabase :: addDatabase("QSQLITE");
           mydb.setDatabaseName("D:/ProjectFinal/wheels2train/db/mydb.db");

           if(mydb.open()){
               qDebug()<<("Connecteddd...");
               return true;
           }
           else{
               qDebug()<<("Fail to open the database");
               return false;
           }
    }

    QString message;

    int highscore;
};

#endif // GAMEPAGE_H
