#include "game.h"
#include "ui_game.h"

game::game(QWidget *parent) ://default
    QWidget(parent),//default
    ui(new Ui::game)//default
{
    ui->setupUi(this);//default
    ui->graphicsView->setScene(sc);
    ui->graphicsView->setFixedSize(600,800);
    sc->setSceneRect(0,0,600,800);



}

game::~game()//default
{
    delete sc;
    delete ui;//default
}
