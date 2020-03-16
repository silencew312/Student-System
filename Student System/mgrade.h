#ifndef MGRADE_H
#define MGRADE_H
#include "handle.h"
#include <QDialog>
#include<QLineEdit>
#include<QLabel>
#include"cclass.h"
#include<QString>
extern QList<QList<Student>>LStu;
extern QList<CClass>LC;
namespace Ui {
class mgrade;

}

class mgrade : public QDialog
{
    Q_OBJECT

public:
    explicit mgrade(QWidget *parent = 0);
    ~mgrade();
void NewBoxInformation_class(int i);
void NewBoxInformation_sub(int k,int i);
private slots:
    void on_qBtn_sub_clicked();
    void on_add_Btn_sub_clicked();
    void on_revise_Btn_sub_clicked();
    void on_Del_Btn_sub_clicked();
    void on_tabWidget_currentChanged(int index);
    void on_grqBtn_clicked();
    void on_gDelBtn_clicked();
    void on_gqBtn_clicked();
    void on_sortBtn_clicked();
    void on_anBtn_clicked();
    void on_hlBtn_clicked();
    void on_outgradeBtn_clicked();
    void on_outgradeBtn1_clicked();
    void on_Button_class_ok_clicked();
    void on_garBtn_clicked();
    void on_DelallgBtn_clicked();


    void on_gqBtn_2_clicked();

    void on_outgradeBtn1_2_clicked();

private:
    Ui::mgrade *ui;
};

#endif // MGRADE_H
