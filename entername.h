#ifndef ENTERNAME_H
#define ENTERNAME_H

#include <QMainWindow>
#include <QtSql>
#include <QFileInfo>
#include <stdio.h>
#include "game.h"

namespace Ui {
class entername;
}

class entername : public QMainWindow
{
    Q_OBJECT

public:
    explicit entername(QWidget *parent = nullptr);
    ~entername();

    QSqlDatabase mydb;//defining database object mydb

    //functiont to close data base
    void connClose(){
        mydb.close();
        mydb.removeDatabase(QSqlDatabase::defaultConnection);
    }

   //checking if the data base is open or not
    bool connOpen(){
        mydb = QSqlDatabase :: addDatabase("QSQLITE");
           mydb.setDatabaseName(QDir::currentPath()+"/../wheels2train/db/mydb.db"); //access the database

           if(mydb.open()){
               qDebug()<<("Connected...");
               return true;
           }
           else{
               qDebug()<<("Fail to open the database");
               return false;
           }
    }


signals:
    void name_entered();
private slots:
    void on_pushButton_clicked();

private:
    game gg;

    Ui::entername *ui;

};

#endif // ENTERNAME_H
