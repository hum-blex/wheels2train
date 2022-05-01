#ifndef HIGHSCORE_H
#define HIGHSCORE_H
#include <QtSql>
#include "stdio.h"
#include <QFileInfo>
#include "entername.h"

#include <QMainWindow>

namespace Ui {
class highscore;
}

class highscore : public QMainWindow
{
    Q_OBJECT

public:
    entername conn;
    explicit highscore(QWidget *parent = nullptr);
    ~highscore();

    QSqlDatabase mydb;

//    void connClose(){
//        mydb.close();
//        mydb.removeDatabase(QSqlDatabase::defaultConnection);
//    }

//    bool connOpen(){
//        mydb = QSqlDatabase :: addDatabase("QSQLITE");
//           mydb.setDatabaseName("D:/QT/wheels2train/db/mydb.db");

//           if(mydb.open()){
//               qDebug()<<("Connected...");
//               return true;
//           }
//           else{
//               qDebug()<<("Fail to open the database");
//               return false;
//           }
//    }

private slots:
    void on_pushButton_clicked();
signals:
    void profile_seen();
private:
    Ui::highscore *ui;
};

#endif // HIGHSCORE_H
