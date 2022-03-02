#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QSqlDatabase mydb = QSqlDatabase :: addDatabase("QSQLITE");
    mydb.setDatabaseName("C:/Users/whyar/Desktop/SQLite3DBs/newdb.db");

    if(mydb.open()){
        ui->label->setText("Conection Established");
    }
    else{
        ui->label->setText("Error connecting...");
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

