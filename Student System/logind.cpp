#include "loginD.h"
#include "ui_logind.h"


LoginD::LoginD(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginD)
{
    ui->setupUi(this);
}

LoginD::~LoginD()
{
    delete ui;
}

void LoginD::on_loginBtn_clicked()
{    LC=Handle::Readf();


    if(ui->SBtn->isChecked()){
        int i;
        bool ok = 0;
        QList<Student>Stu;
          long Id=ui->account->text().toLong(&ok, 10);
          int p;
        for(i=0;i<LC.size();i++)
        {
            Stu=Handle::Readf(LC[i]);
        p=Handle::BinSearch(Id,Stu);
        if(p>=0)break;}

if(i<LC.size())
        {

    if(Stu[p].password==ui->password->text()){
    SS=Stu[p];
            A=p;
            LSStu=Stu;
       accept();
       CM=1;
    }
    else QMessageBox::information
            (this,QString::fromLocal8Bit("提示"),
             QString::fromLocal8Bit("密码错误"));
} else {
    QMessageBox::information
                          (this,QString::fromLocal8Bit("提示"),
                           QString::fromLocal8Bit("用户名错误"));
       }}
    else if(ui->MBtn->isChecked())
    {if(LC.size()==0){
            if(ui->account->text() == tr("manager") &&
                  ui->password->text() =="123456")
           {
                accept();
                CM=3;
           } else if(ui->account->text() != tr("manager")){
                QMessageBox::information
                                      (this,QString::fromLocal8Bit("提示"),
                                       QString::fromLocal8Bit("用户名错误"));
           }
        else if( ui->password->text() !="123456")QMessageBox::information
                    (this,QString::fromLocal8Bit("提示"),
                     QString::fromLocal8Bit("密码错误"));

        }
    else if(ui->account->text()==tr("manager")&&ui->password->text()==LC[0].manager.password)
        {
            for(int i=0;i<LC.size();i++)
            {QList<Student>Stu=Handle::Readf(LC[i]);

                LStu.append(Stu);
            }
             accept();
             CM=3;
        } else {
            if(ui->account->text()!=tr("manager"))
                QMessageBox::information
                                    (this,QString::fromLocal8Bit("提示"),
                                     QString::fromLocal8Bit("用户名错误"));
            else QMessageBox::information
                    (this,QString::fromLocal8Bit("提示"),
                     QString::fromLocal8Bit("密码错误"));
        }
    }
    else if(ui->TBtn->isChecked())
    {    QString Id=ui->account->text();

       int w=0;
        for(int i=0;i<LC.size();i++)
        {

            for(int j=0;j<LC[i].Sub.size();j++)
                {if(Id==LC[i].Sub[j].teacher.id&&ui->password->text()==LC[i].Sub[j].teacher.password)
                {     B.append(j);w=1;
                    QList<Student>Stu=Handle::Readf(LC[i]);

                    LStu.append(Stu);
                    break;
                }
            }

           }



        if(w==1){
            accept();
            CM=2;
        }

            else {
            QMessageBox::information
                                (this,QString::fromLocal8Bit("提示"),
                                 QString::fromLocal8Bit("账号或密码错误"));
           }}
    else {QMessageBox::information
                (this,QString::fromLocal8Bit("提示"),
                 QString::fromLocal8Bit("请选择身份信息"));
        CM=0;
       }
}


