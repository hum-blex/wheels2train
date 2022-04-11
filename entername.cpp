#include "entername.h"
#include "ui_entername.h"
#include <QtSql>
#include <QFileInfo>
#include <stdio.h>

entername::entername(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::entername)
{
    ui->setupUi(this);
    QSqlDatabase mydb = QSqlDatabase :: addDatabase("QSQLITE");
        mydb.setDatabaseName("C:/Users/whyar/Desktop/SQLite3DBs/wheels2trainDB.db");

        if(mydb.open()){
            ui->label->setText("Conection Established");
            /*QSqlQuery qry;

            if(qry.exec("SELECT * FROM highscore")){
                while(qry.next()){
                    QString a = qry.value(1).toString();
                    ui->LabelForConnection->setText(a);
                }
            }
            else{

            }
    */
           // ui->LabelForConnection->setText("Conection Closed");
        }
        else{
            ui->label->setText(mydb.lastError().text());
        }

}

entername::~entername()
{
    delete ui;
}

void entername::on_pushButton_clicked()
{
    QString name = ui -> lineEdit -> text();
        qDebug() << name ;
        int highscore = 40 ;

        QSqlQuery update;
        update.prepare("insert into highscore (ID, Name, Score) values (7, :uname, :uscore) ");
        update.bindValue(":uname", name);
        update.bindValue(":uscore", highscore);
        update.exec();
}

