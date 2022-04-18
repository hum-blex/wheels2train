#include "entername.h"
#include "ui_entername.h"
#include <QDebug>


entername::entername(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::entername)
{
    ui->setupUi(this);

  connOpen();
        if(mydb.open()){
            ui->label->setText("Enter Your Name");
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
        int highscore = gg.getCurrentScore();
//        qDebug()<<highscore;
//        if(!mydb.isOpen()){
//            qDebug()<<"Fail";
//            return;
//        }

        QSqlQuery update;
        update.prepare("insert into tbl_userinfo ( name, score) values ( :uname, :uscore) ");
        update.bindValue(":uname", name);
        update.bindValue(":uscore", highscore);
        update.exec();
//        if(update.exec()){
//            qDebug()<<"hey";
//        }
        this->close();
        name_entered();
        connClose();
}

