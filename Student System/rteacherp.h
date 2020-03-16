#ifndef RTEACHERP_H
#define RTEACHERP_H
#include "student.h"
#include"cclass.h"
#include <QDialog>
#include<QMessageBox>
#include<QString>
extern QList<QList<Student>>LStu;
extern QList<int> B;
extern QList<CClass>LC;
namespace Ui {
class rteacherP;
}

class rteacherP : public QDialog
{
    Q_OBJECT

public:
    explicit rteacherP(QWidget *parent = 0);
    ~rteacherP();

private slots:
    void on_RBtn_ok_clicked();

private:
    Ui::rteacherP *ui;
};

#endif // RTEACHERP_H
