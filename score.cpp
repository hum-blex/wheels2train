#include "score.h"
#include <QFont>
#include <QtDebug>

Score::Score(QGraphicsItem * parent):QGraphicsTextItem(parent),score(0)
{
    //draw the text
    setPlainText(QString("Score: ")+ QString:: number(score)); //Score : 0
    setDefaultTextColor(Qt :: white);
    setFont(QFont("times",15));
}

 void Score::increaseScore()
{
    score++;
    setPlainText(QString("Score: ")+ QString:: number(score));
    qDebug()<<score;
}

int Score::getScore(){
    return score;
}

void Score::resetScore()
{
    score = 0;
    setPlainText(QString("Score: ")+ QString:: number(score));
    qDebug()<<"score";
}
