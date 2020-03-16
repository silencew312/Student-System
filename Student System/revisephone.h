#ifndef REVISEPHONE_H
#define REVISEPHONE_H
#include<QString>
#include <QDialog>
#include"student.h"
#include<QMessageBox>
extern Student SS;
extern QList<Student>LSStu;

extern int A;

namespace Ui {
class revisePhone;
}

class revisePhone : public QDialog
{
    Q_OBJECT

public:
    explicit revisePhone(QWidget *parent = 0);
    ~revisePhone();

private slots:
    void on_rpBtn_ok_clicked();

private:
    Ui::revisePhone *ui;
};

#endif // REVISEPHONE_H
