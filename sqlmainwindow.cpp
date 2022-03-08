#include "sqlmainwindow.h"
#include "ui_sqlmainwindow.h"
#include <QtDebug>
#include <QtSql>
#include <QFileInfo>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QSqlDatabase mydb = QSqlDatabase :: addDatabase("QSQLITE");
    mydb.setDatabaseName("C:/Users/whyar/Desktop/SQLite3DBs/wheels2trainDB.db");

    if(mydb.open()){

        ui->LabelForConnection->setText("Conection Established");
    }
    else{
        ui->LabelForConnection->setText(mydb.lastError().text());
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

