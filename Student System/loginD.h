#ifndef LOGIND_H
#define LOGIND_H
#include <QDialog>
#include "handle.h"
#include<QMessageBox>
#include "cclass.h"
#include<QString>
extern QList<QList<Student>>LStu;
extern Student SS;
extern int A;
extern QList<int> B;
extern QList<CClass>LC;
extern QList<Student>LSStu;
namespace Ui {
class LoginD;
}

class LoginD : public QDialog
{
    Q_OBJECT

public:
    explicit LoginD(QWidget *parent = 0);
    ~LoginD();

private slots:
    void on_loginBtn_clicked();
public:
    int CM;


private:
    Ui::LoginD *ui;
};

#endif // LOGIND_H
