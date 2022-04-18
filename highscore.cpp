#include "highscore.h"
#include "ui_highscore.h"


highscore::highscore(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::highscore)
{
    ui->setupUi(this);
    conn.connOpen();

    QSqlQueryModel *modal = new QSqlQueryModel();
        QSqlQuery *qry = new QSqlQuery();
        qry -> prepare("SELECT name, score FROM tbl_userinfo ORDER BY score DESC LIMIT 10");
        qry->exec();
        modal->setQuery(*qry);
        ui -> tableView -> setModel(modal);
//        ui -> tableView -> resizeColumnsToContents();
//        ui -> tableView -> resizeRowsToContents();
//        connClose();

}

highscore::~highscore()
{
    delete ui;
}

void highscore::on_pushButton_clicked()
{
    this->close();
    profile_seen();

}

