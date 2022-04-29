#ifndef HS_H
#define HS_H

#include <QDialog>
#include <QSqlQuery>

namespace Ui {
class hs;
}

class hs : public QDialog
{
    Q_OBJECT

public:
    explicit hs(QWidget *parent = nullptr, QSqlQuery * qry = nullptr);
    ~hs();
private:
    Ui::hs *ui;
};

#endif // HS_H
