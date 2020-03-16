#include "revisephone.h"
#include "ui_revisephone.h"

revisePhone::revisePhone(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::revisePhone)
{
    ui->setupUi(this);
}

revisePhone::~revisePhone()
{
    delete ui;
}

void revisePhone::on_rpBtn_ok_clicked()
{ if(ui->lineEdit_revisep->text().isEmpty()){QMessageBox::information
                (this,QString::fromLocal8Bit("提示"),
                 QString::fromLocal8Bit("请输入手机号"));return;}
    QString P=ui->lineEdit_revisep->text();
    ui->lineEdit_revisep->clear();
    SS.phone=P;
   LSStu[A].phone=P;
     QMessageBox::warning(this, QString::fromLocal8Bit("提示"),QString::fromLocal8Bit("修改成功"), QMessageBox::Yes);
}
