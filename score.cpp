#include "score.h"
#include <QFont>
#include <QtDebug>

Score::Score(QGraphicsItem * parent):QGraphicsTextItem(parent)
{
    //draw the text
    score=0;
    setPlainText(QString("Score: ")+ QString:: number(score)); //Score : 0
    setDefaultTextColor(Qt :: white);
    setFont(QFont("times",15));
}

void Score::increaseScore()
{
    score++;
    setPlainText(QString("Score: ")+ QString:: number(score));

}

int Score::getScore(){
    qDebug()<<"hey:"<<score;
    return score;
}

void Score::resetScore()
{
    score =0;
    setPlainText(QString("Score: ")+ QString:: number(score));
}
