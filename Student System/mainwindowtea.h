#ifndef MAINWINDOWTEA_H
#define MAINWINDOWTEA_H
#include "rteacherp.h"
#include <QMainWindow>
#include"handle.h"
#include<QString>
extern QList<int> B;
extern QList<QList<Student>>LStu;
extern QList<CClass>LC;
namespace Ui {
class MainWindowTea;
}

class MainWindowTea : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindowTea(QWidget *parent = 0);
    ~MainWindowTea();

void query(long key,QString str,int n,QList<Student>Stu);

void NewBoxInformation(int i);
private slots:
    void on_gqBtn_clicked();

    void on_anBtn_clicked();

    void on_hlBtn_clicked();

    void on_tabWidget_currentChanged(int index);

    void on_trBtn_clicked();





    void on_outgradeBtn_clicked();

    void on_sortBtn_clicked();

    void on_agBtn_clicked();

    void on_dgBtn_clicked();

    void on_qBtn_class_clicked();

private:
    Ui::MainWindowTea *ui;
};

#endif // MAINWINDOW2_H
