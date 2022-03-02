#include "sqlmainwindow.h"
#include "ui_sqlmainwindow.h"
#include <QtDebug>
#include <QtSql>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QString servername = "GTH\\SQLEXPRESS";
    QString dbname = "wheels2train";

    QSqlDatabase db = QSqlDatabase :: addDatabase("QSQLITE");

    db.setConnectOptions();

    QString dsn = QString("DRIVER = (SQL Native Client); SERVER = %1; DATABASE = %2; UID = admin; PWD = admin;");

    db.setDatabaseName(dsn);

    if(db.open()){

        ui->LabelForConnection->setText("Connection Established");
    }
    else{
        ui->LabelForConnection->setText(db.lastError().text());
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

