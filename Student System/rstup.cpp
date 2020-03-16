#include "rstup.h"
#include "ui_rstup.h"


rstuP::rstuP(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::rstuP)
{
    ui->setupUi(this);
}

rstuP::~rstuP()
{
    delete ui;
}

void rstuP::on_RBtn_ok_clicked()
{
    if(ui->newEdit->text().isEmpty()){QMessageBox::information
                (this,QString::fromLocal8Bit("提示"),
                 QString::fromLocal8Bit("新密码不能为空"));return;}
    if(ui->oldEdit->text().isEmpty()){QMessageBox::information
                (this,QString::fromLocal8Bit("提示"),
                 QString::fromLocal8Bit("请输入原来的密码"));return;}
    QString Old=ui->oldEdit->text();
    QString New=ui->newEdit->text();
    if(Old==SS.password){
        SS.password=New;
        LSStu[A].password=New;
        ui->newEdit->clear();
        ui->oldEdit->clear();
      QMessageBox::information(this, QString::fromLocal8Bit( "提示"),  QString::fromLocal8Bit("修改成功"));
    }
    else QMessageBox::information(this,  QString::fromLocal8Bit("提示"),  QString::fromLocal8Bit("旧密码不正确"));
}
