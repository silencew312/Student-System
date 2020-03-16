#ifndef MAINWINDOWSTU_H
#define MAINWINDOWSTU_H
#include"loginD.h"
#include <QMainWindow>
#include <QTableWidget>
#include <QTableWidgetItem>
#include"handle.h"
#include "revisephone.h"
#include "rstup.h"
#include<QString>
extern Student SS;
extern QList<Student>LSStu;
extern QList<CClass>LC;
extern int A;
namespace Ui {
class MainWindowStu;
}

class MainWindowStu : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindowStu(QWidget *parent = 0);
    ~MainWindowStu();



private slots:
    void on_tabWidget_stusub_currentChanged(int index);

    void on_stusubBtn_clicked();

    void on_revisephoneBtn_clicked();

    void on_rpnewBtn_clicked();





    void on_outgradeBtn_clicked();



    void on_rpassword_Btn_clicked();

    void on_qsubBtn_clicked();

private:
    Ui::MainWindowStu *ui;
};

#endif // MAINWINDOW_H
