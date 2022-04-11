#ifndef HIGHSCORE_H
#define HIGHSCORE_H

#include <QMainWindow>

namespace Ui {
class highscore;
}

class highscore : public QMainWindow
{
    Q_OBJECT

public:
    explicit highscore(QWidget *parent = nullptr);
    ~highscore();

private slots:
    void on_pushButton_clicked();

private:
    Ui::highscore *ui;
};

#endif // HIGHSCORE_H
