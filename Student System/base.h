#ifndef BASE_H
#define BASE_H
#include<QMessageBox>
#include <QDialog>
#include<QFileDialog>
#include"handle.h"
#include<QString>
#include <QTableWidget>
#include <QTableWidgetItem>
#include<QRadioButton>
extern QList<QList<Student>>LStu;
extern QList<CClass>LC;
namespace Ui {
class Base;
}

class Base : public QDialog
{
    Q_OBJECT

public:
    explicit Base(QWidget *parent = 0);
    ~Base();
    void Query(long Id_key,QString Name_str,int Box_n,QList<QList<Student>>lStu,int classId,QList<CClass>lc);
    void Add(long Id,QString Name,QString Sex,QString P,QList<Student>&Stu,int ClassId);
    void Delete(int a,QList<Student>&Stu);
    void Revise(long Id,QString Name,QString Sex,QString Phone,int ClassId,int j,int a,QList<QList<Student>>&lStu);
    void NewBoxInformation(int i);
   void Insert(QList<Student>&Stu,Student&S);
private slots:
    void on_addBtn_clicked();
    void on_qBtn_clicked();
    void on_dBtn_clicked();
    void on_rBtn_clicked();
    void on_phoneBtn_clicked();
    void on_qpasswordBtn_clicked();
    void on_rpass_ok_btn_clicked();
    void on_add_class_Btn_clicked();
    void on_revise_class_Btn_clicked();
    void on_Del_class_Btn_clicked();
    void on_tabWidget_currentChanged(int index);

    void on_qBtn_class_clicked();

private:
    Ui::Base *ui;
};

#endif // BASE_H
