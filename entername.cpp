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
        }
        else{
            ui->label->setText(mydb.lastError().text());
        }
        connClose();

}

entername::~entername()
{
    delete ui;
}

void entername::on_pushButton_clicked()
{
    connOpen();
    QString name = ui -> lineEdit -> text();//taking name as input
        qDebug() << name ;
        int highscore = gg.getCurrentScore();//passing the score from game class after the game ended to a variable highscore
        qDebug()<< highscore;
        // query update after name and highscore is obtained
        QSqlQuery update;
        update.prepare("insert into tbl_userinfo ( name, score) values ( :uname, :uscore) ");
        update.bindValue(":uname", name);
        update.bindValue(":uscore", highscore);
        if(update.exec()) qDebug() << "Written to database";
        this->close();
        highscore = 0;
        name_entered();//signal connect to return to homepage
        connClose();
}

