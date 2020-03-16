#include "rteacherp.h"
#include "ui_rteacherp.h"

rteacherP::rteacherP(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::rteacherP)
{
    ui->setupUi(this);
}

rteacherP::~rteacherP()
{
    delete ui;
}

void rteacherP::on_RBtn_ok_clicked()
{
    if(ui->newEdit->text().isEmpty()){QMessageBox::information
                (this,QString::fromLocal8Bit("提示"),
                 QString::fromLocal8Bit("新密码不能为空"));return;}
    if(ui->oldEdit->text().isEmpty()){QMessageBox::information
                (this,QString::fromLocal8Bit("提示"),
                 QString::fromLocal8Bit("请输入原来的密码"));return;}
    QString Old=ui->oldEdit->text();
    QString New=ui->newEdit->text();



   Subject&sub=LC[LStu[0][0].classId].Sub[B[0]];
    if(Old==sub.teacher.password){

        for(int j=0;j<B.size();j++)
        LC[j].Sub[B[j]].teacher.password=New;
        ui->newEdit->clear();
        ui->oldEdit->clear();
        QMessageBox::information
                        (this, QString::fromLocal8Bit("提示"),
                        QString::fromLocal8Bit("修改成功"));
    }
    else QMessageBox::information
            (this,QString::fromLocal8Bit("提示"),
            QString::fromLocal8Bit("旧密码不正确"));
}
