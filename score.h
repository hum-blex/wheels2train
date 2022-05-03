#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>
#include "Singleton.h"

class Score : public QGraphicsTextItem
{
    Q_OBJECT
public:
    Score(QGraphicsItem * parent =0);
    void increaseScore();
    int getScore();
    void resetScore();
private:
    int score;
};
typedef Singleton<Score> EmmitterO;

#endif // SCORE_H
