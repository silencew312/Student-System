#ifndef RSTUP_H
#define RSTUP_H
#include"student.h"
#include <QDialog>
#include<QMessageBox>
#include<QString>
extern Student SS;
extern QList<Student>LSStu;

extern int A;
namespace Ui {
class rstuP;
}

class rstuP : public QDialog
{
    Q_OBJECT

public:
    explicit rstuP(QWidget *parent = 0);
    ~rstuP();

private slots:
    void on_RBtn_ok_clicked();

private:
    Ui::rstuP *ui;
};

#endif // RSTUP_H
