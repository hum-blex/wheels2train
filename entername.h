#ifndef ENTERNAME_H
#define ENTERNAME_H

#include <QMainWindow>

namespace Ui {
class entername;
}

class entername : public QMainWindow
{
    Q_OBJECT

public:
    explicit entername(QWidget *parent = nullptr);
    ~entername();

private slots:
    void on_pushButton_clicked();

private:
    Ui::entername *ui;
};

#endif // ENTERNAME_H
