#include "hs.h"
#include "ui_hs.h"
#include <QSqlQueryModel>

hs::hs(QWidget *parent, QSqlQuery * qry) :
    QDialog(parent),
    ui(new Ui::hs)
{
    ui->setupUi(this);
    QSqlQueryModel *modal = new QSqlQueryModel();
    modal->setQuery(*qry);
    ui -> tableView -> setModel(modal);
}

hs::~hs()
{
    delete ui;
}
