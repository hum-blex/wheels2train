#include "highscore.h"
#include "ui_highscore.h"
#include <QtSql>
#include "stdio.h"
#include <QFileInfo>

highscore::highscore(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::highscore)
{
    ui->setupUi(this);
    QSqlQueryModel *modal = new QSqlQueryModel();
        QSqlQuery *qry = new QSqlQuery();
        qry -> prepare("SELECT Name, Score FROM highscore ORDER BY Score DESC LIMIT 10");
        qry->exec();
        modal->setQuery(*qry);
        ui -> tableView -> setModel(modal);
        ui -> tableView -> resizeColumnsToContents();
        ui -> tableView -> resizeRowsToContents();
}

highscore::~highscore()
{
    delete ui;
}

void highscore::on_pushButton_clicked()
{
    this->close();

}

