#include "mainwindowtea.h"
#include "ui_mainwindowtea.h"

MainWindowTea::MainWindowTea(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindowTea)
{
    ui->setupUi(this);
NewBoxInformation(2);
}

MainWindowTea::~MainWindowTea()
{
    for(int i=0;i<LStu.size();i++)
    {
        Handle::Writef(LC[LStu[i][0].classId],LStu[i]);
    }
    Handle::Writef(LC);
    delete ui;
}

void MainWindowTea::on_gqBtn_clicked()
{   ui->tableWidget_gq->clearContents();
    ui->tableWidget_gq->verticalHeader()->setVisible(false);
    if(ui->gqEdit->text().isEmpty()){
        QMessageBox::information
                        (this,QString::fromLocal8Bit("提示"),
                         QString::fromLocal8Bit("请输入信息"));return;
    }
    if(ui->gqBox->currentIndex()==0){
        bool ok = 0;
        long Id=ui->gqEdit->text().toLong(&ok);
        int j,a;
        Handle::getId_key(j,a,LStu,Id);

        if(j==LStu.size()){QMessageBox::information
                    (this,QString::fromLocal8Bit("提示"),
                    QString::fromLocal8Bit("无此学生"));return;}

         Student&S=LStu[j][a];

        ui->tableWidget_gq->setColumnCount(5);
        ui->tableWidget_gq->setRowCount(1);

        QTableWidgetItem*item01=new QTableWidgetItem(QString::number(S.id));
        ui->tableWidget_gq->setItem(0,0,item01);
        QTableWidgetItem*item02=new QTableWidgetItem(S.name);
        ui->tableWidget_gq->setItem(0,1,item02);

        QTableWidgetItem*item03=new QTableWidgetItem(QString::number(S.score[B[j]]));
        ui->tableWidget_gq->setItem(0,3,item03);
       int r=Handle::getrank(S,LStu[j],B[j]);
        QTableWidgetItem*item04=new QTableWidgetItem(QString::number(r));
        ui->tableWidget_gq->setItem(0,4,item04);
        QTableWidgetItem*item05=new QTableWidgetItem(LC[S.classId].className);
        ui->tableWidget_gq->setItem(0,2,item05);

    }
    else if(ui->gqBox->currentIndex()==1){
        QString Name=ui->gqEdit->text();
        QList<int>list;
        QList<int>k;
         QList<Student>Stu;
        for(int j=0;j<LStu.size();j++){
        list=Handle::Namesearch(Name,LStu[j]);
        if(list.size()==0)continue;
        else {

         for(int i=0;i<list.size();i++ )
                { k.append(j);Stu.append(LStu[j][list[i]]);}

        }}
        if(Stu.size()==0){QMessageBox::information
                    (this,QString::fromLocal8Bit("提示"),
                    QString::fromLocal8Bit("无此学生"));return;}
        else {

            ui->tableWidget_gq->setColumnCount(5);
            ui->tableWidget_gq->setRowCount(Stu.size());
            for(int i=0;i<Stu.size();i++)
            {Student&S=Stu[i];
                QTableWidgetItem*item01=new QTableWidgetItem(QString::number(S.id));
                ui->tableWidget_gq->setItem(i,0,item01);
                QTableWidgetItem*item02=new QTableWidgetItem(S.name);
                ui->tableWidget_gq->setItem(i,1,item02);

                QTableWidgetItem*item03=new QTableWidgetItem(QString::number(S.score[B[k[i]]]));
                ui->tableWidget_gq->setItem(i,3,item03);
               int r=Handle::getrank(S,LStu[k[i]],B[k[i]]);
                QTableWidgetItem*item04=new QTableWidgetItem(QString::number(r));
                ui->tableWidget_gq->setItem(i,4,item04);
                QTableWidgetItem*item05=new QTableWidgetItem(LC[S.classId].className);
                ui->tableWidget_gq->setItem(i,2,item05);
            }
        }
    }




}

void MainWindowTea::on_anBtn_clicked()
{

int k=ui->Box_class->currentIndex();
if(k==0){QMessageBox::information
            (this,QString::fromLocal8Bit("提示"),
             QString::fromLocal8Bit("请选择班级"));return;}
k--;
     ui->tableWidget_sort->verticalHeader()->setVisible(false);
     ui->tableWidget_sort->horizontalHeader()->setVisible(false);

     ui->tableWidget_sort->clear();
     ui-> tableWidget_sort->setRowCount(9);
     ui->tableWidget_sort->setColumnCount(4);
     QTableWidgetItem*str01=new QTableWidgetItem(QString::fromLocal8Bit("及格人数"));
     ui->tableWidget_sort->setItem(0,0,str01);
     QTableWidgetItem*str1=new QTableWidgetItem(QString::fromLocal8Bit("及格率"));
     ui->tableWidget_sort->setItem(0,2,str1);
     QTableWidgetItem*str02=new QTableWidgetItem(QString::fromLocal8Bit("优秀人数"));
     ui->tableWidget_sort->setItem(1,0,str02);
     QTableWidgetItem*str2=new QTableWidgetItem(QString::fromLocal8Bit("优秀率"));
     ui->tableWidget_sort->setItem(1,2,str2);
     QTableWidgetItem*str3=new QTableWidgetItem(QString::fromLocal8Bit("最高分"));

     ui->tableWidget_sort->setItem(2,0,str3);
     QTableWidgetItem*str4=new QTableWidgetItem(QString::fromLocal8Bit("最低分"));

     ui->tableWidget_sort->setItem(2,2,str4);
     QTableWidgetItem*str5=new QTableWidgetItem(QString::fromLocal8Bit("平均分"));

     ui->tableWidget_sort->setItem(3,0,str5);
     QTableWidgetItem*str9=new QTableWidgetItem(QString::fromLocal8Bit("90-100分"));
     ui->tableWidget_sort->setItem(4,0,str9);
     QTableWidgetItem*str8=new QTableWidgetItem(QString::fromLocal8Bit("80-90分"));
     ui->tableWidget_sort->setItem(5,0,str8);
     QTableWidgetItem*str7=new QTableWidgetItem(QString::fromLocal8Bit("70-80分"));
     ui->tableWidget_sort->setItem(6,0,str7);
     QTableWidgetItem*str6=new QTableWidgetItem(QString::fromLocal8Bit("60-70分"));
     ui->tableWidget_sort->setItem(7,0,str6);
     QTableWidgetItem*str0=new QTableWidgetItem(QString::fromLocal8Bit("60分以下"));
     ui->tableWidget_sort->setItem(8,0,str0);

     QList<int>num=Handle::count(LStu[k],B[k]);
 double p=double(LStu[k].size()-num[4])/LStu[k].size();
 double g=double(num[0])/LStu[k].size();
 double avg=double(num[5])/LStu[k].size();
 QTableWidgetItem*AVG=new QTableWidgetItem(QString::number(avg,'f',2));
 ui->tableWidget_sort->setItem(3,1,AVG);
     QTableWidgetItem*pass01=new QTableWidgetItem(QString::number(LStu[k].size()-num[4],10));
     ui->tableWidget_sort->setItem(0,1,pass01);


     QTableWidgetItem*pass=new QTableWidgetItem(QString::number(p,'f',2));
     ui->tableWidget_sort->setItem(0,3,pass);

     QTableWidgetItem*good02=new QTableWidgetItem(QString::number(num[0],10));
     ui->tableWidget_sort->setItem(1,1,good02);


     QTableWidgetItem*good=new QTableWidgetItem(QString::number(g,'f',2));
     ui->tableWidget_sort->setItem(1,3,good);
     QList<int>Index;
     for(int i=0;i<LStu[k].size();i++)
         Index.append(i);
     Handle::Sort(LStu[k],Index,B[k],0,LStu[k].size()-1);

     QTableWidgetItem*max=new QTableWidgetItem(QString::number(LStu[k][Index[0]].score[B[k]]));
     ui->tableWidget_sort->setItem(2,1,max);

     QTableWidgetItem*min=new QTableWidgetItem(QString::number(LStu[k][Index[LStu[k].size()-1]].score[B[k]]));
     ui->tableWidget_sort->setItem(2,3,min);


     QTableWidgetItem*s9=new QTableWidgetItem(QString::number(num[0],10));
     ui->tableWidget_sort->setItem(4,1,s9);



     QTableWidgetItem*s8=new QTableWidgetItem(QString::number(num[1],10));
     ui->tableWidget_sort->setItem(5,1,s8);



     QTableWidgetItem*s7=new QTableWidgetItem(QString::number(num[2],10));
     ui->tableWidget_sort->setItem(6,1,s7);


     QTableWidgetItem*s6=new QTableWidgetItem(QString::number(num[3],10));
     ui->tableWidget_sort->setItem(7,1,s6);

     QTableWidgetItem*s0=new QTableWidgetItem(QString::number(num[4],10));
     ui->tableWidget_sort->setItem(8,1,s0);
}

void MainWindowTea::on_hlBtn_clicked()
{
    if(ui->lineEdit_low->text().isEmpty()){QMessageBox::information
                (this,QString::fromLocal8Bit("提示"),
                 QString::fromLocal8Bit("请输入最低分"));return;}
    else if(ui->lineEdit_high->text().isEmpty()){QMessageBox::information
                (this,QString::fromLocal8Bit("提示"),
                 QString::fromLocal8Bit("请输入最高分"));return;}
        bool ok = 0;

        double low=ui->lineEdit_low->text().toDouble(&ok);
         double high=ui->lineEdit_high->text().toDouble(&ok);
int k=ui->Box_class->currentIndex();
if(k==0){QMessageBox::information
            (this,QString::fromLocal8Bit("提示"),
             QString::fromLocal8Bit("请选择班级"));return;}
k--;

         QList<int>Index;
         for(int i=0;i<LStu[k].size();i++)
             Index.append(i);
         Handle::Sort(LStu[k],Index,B[k],0,LStu[k].size()-1);
         ui->tableWidget_sort->setColumnCount(3);
         ui->tableWidget_sort->setRowCount(1);
         ui->tableWidget_sort->verticalHeader()->setVisible(false);
         ui->tableWidget_sort->horizontalHeader()->setVisible(false);
         QTableWidgetItem*itemid=new QTableWidgetItem(QString::fromLocal8Bit("学号"));
         ui->tableWidget_sort->setItem(0,0,itemid);
         QTableWidgetItem*itemname=new QTableWidgetItem(QString::fromLocal8Bit("姓名"));
         ui->tableWidget_sort->setItem(0,1,itemname);
         QTableWidgetItem*itemscore=new QTableWidgetItem(QString::fromLocal8Bit("成绩"));
         ui->tableWidget_sort->setItem(0,2,itemscore);
         QTableWidgetItem*itemrank=new QTableWidgetItem(QString::fromLocal8Bit("排名"));
         ui->tableWidget_sort->setItem(0,3,itemrank);
        int p=1;
    for(int i=0;i<LStu[k].size();i++)
    {
       int j=Index[i];
       Student S=LStu[k][j];

       if(S.score[B[k]]>=low&&S.score[B[k]]<=high)
       {
           ui->tableWidget_sort->insertRow(p);
           QTableWidgetItem*itemid=new QTableWidgetItem(QString::number(S.id,10));
           ui->tableWidget_sort->setItem(p,0,itemid);
           QTableWidgetItem*itemname=new QTableWidgetItem(S.name);
           ui->tableWidget_sort->setItem(p,1,itemname);
           QTableWidgetItem*itemscore=new QTableWidgetItem(QString::number(S.score[B[k]]));
           ui->tableWidget_sort->setItem(p,2,itemscore);
           QTableWidgetItem*itemrank=new QTableWidgetItem(QString::number(i+1));
           ui->tableWidget_sort->setItem(p,3,itemrank);
           p++;

       }
    }
}

void MainWindowTea::on_tabWidget_currentChanged(int index)
{if(index==0){
    NewBoxInformation(2);
    }
    else if(index==2){
        NewBoxInformation(1);

    }
    else if(index==3){


       Subject&sub=LC[LStu[0][0].classId].Sub[B[0]];
        ui->label_tname->setText(sub.teacher.name);
        ui->label_tid->setText(sub.teacher.id);
        ui->label_subname->setText(sub.subname);
        ui->label_subcredit->setText(QString::number(sub.credit,'f',1));
        int n=LStu.size();
        ui->tableWidget_class->setColumnCount(1);
        ui->tableWidget_class->setRowCount(n);
        ui->tableWidget_class->verticalHeader()->setVisible(false);
        ui->tableWidget_class->horizontalHeader()->setVisible(false);
        for(int k=0;k<n;k++)
        {
            QTableWidgetItem *item0 = new QTableWidgetItem(LC[LStu[k][0].classId].className);
            ui->tableWidget_class->setItem(k,0,item0); }
    }
}





void MainWindowTea::on_trBtn_clicked()
{
    rteacherP*rt=new rteacherP(this);
        rt->show();
}





void MainWindowTea::on_outgradeBtn_clicked()
{
   int k=ui->Box_class->currentIndex();
   if(k==0){QMessageBox::information
               (this,QString::fromLocal8Bit("提示"),
                QString::fromLocal8Bit("请选择班级"));return;}
   k--;

   Handle::WriteT(LStu[k],LC[LStu[k][0].classId],B[k]);
   QMessageBox::information
                   (this,QString::fromLocal8Bit("提示"),
                    QString::fromLocal8Bit("导出成功"));
}

void MainWindowTea::on_sortBtn_clicked()
{
    int n=ui->Box_class->currentIndex();
    if(n==0){QMessageBox::information
                (this,QString::fromLocal8Bit("提示"),
                 QString::fromLocal8Bit("请选择班级"));return;}
    n--;
    QList<int>Index;
    for(int i=0;i<LStu[n].size();i++)
        Index.append(i);
    ui->tableWidget_sort->clear();
    ui->tableWidget_sort->verticalHeader()->setVisible(false);
    ui->tableWidget_sort->horizontalHeader()->setVisible(false);

    Handle::Sort(LStu[n],Index,B[n],0,LStu[n].size()-1);
    ui-> tableWidget_sort->setRowCount(1+LStu[n].size());
    ui->tableWidget_sort->setColumnCount(4);
    QTableWidgetItem*itemid=new QTableWidgetItem(QString::fromLocal8Bit("学号"));
    ui->tableWidget_sort->setItem(0,0,itemid);
    QTableWidgetItem*itemname=new QTableWidgetItem(QString::fromLocal8Bit("姓名"));
    ui->tableWidget_sort->setItem(0,1,itemname);
    QTableWidgetItem*itemscore=new QTableWidgetItem(QString::fromLocal8Bit("成绩"));
    ui->tableWidget_sort->setItem(0,2,itemscore);
    QTableWidgetItem*itemrank=new QTableWidgetItem(QString::fromLocal8Bit("班级排名"));
    ui->tableWidget_sort->setItem(0,3,itemrank);
    for(int i=0;i<LStu[n].size();i++)
    {    Student&S=LStu[n][Index[i]];

        QTableWidgetItem*itemId=new QTableWidgetItem(QString::number(S.id,10));
        ui->tableWidget_sort->setItem(i+1,0,itemId);
        QTableWidgetItem*itemName=new QTableWidgetItem(S.name);
        ui->tableWidget_sort->setItem(i+1,1,itemName);
        QTableWidgetItem*itemScore=new QTableWidgetItem(QString::number(S.score[B[n]]));
        ui->tableWidget_sort->setItem(i+1,2,itemScore);
        QTableWidgetItem*itemRank=new QTableWidgetItem(QString::number(i+1));
        ui->tableWidget_sort->setItem(i+1,3,itemRank);
    }
}

void MainWindowTea::on_agBtn_clicked()
{
    if(ui->gEdit_id->text().isEmpty()){QMessageBox::information(this, "提示", "学号为空");return;}
    if(ui->gEdit_score->text().isEmpty()){QMessageBox::information(this, "提示", "成绩为空");return;}
    bool ok = 0;
    long Id=ui->gEdit_id->text().toLong(&ok);
    int j,a;

Handle::getId_key(j,a,LStu,Id);
    if(j==LStu.size()){QMessageBox::information
                (this,QString::fromLocal8Bit("提示"),
                 QString::fromLocal8Bit("无此学生"));return;}


     Student&S=LStu[j][a];

     double score=ui->gEdit_score->text().toDouble(&ok);
     if(score>100||score<0){QMessageBox::information
                 (this,QString::fromLocal8Bit("提示"),
                  QString::fromLocal8Bit("成绩不符合规范,请重新输入"));return;}
     S.score[B[j]]=score;
   ui->gEdit_id->clear();
   ui->gEdit_score->clear();
   QMessageBox::information
                   (this,QString::fromLocal8Bit("提示"),
                    QString::fromLocal8Bit("添加/修改成功"));
}



void MainWindowTea::on_dgBtn_clicked()
{
    if(ui->gEdit_id->text().isEmpty()){QMessageBox::information(this, "提示", "学号为空");return;}
    bool ok = 0;
    long Id=ui->gEdit_id->text().toLong(&ok, 10);
    int j,a;
    Handle::getId_key(j,a,LStu,Id);
    if(j==LStu.size()){QMessageBox::information
                (this,QString::fromLocal8Bit("提示"),
                 QString::fromLocal8Bit("无此学生"));return;}


     Student&S=LStu[j][a];
     S.score[B[j]]=-1;
   ui->gEdit_id->clear();
   ui->gEdit_score->clear();
   QMessageBox::information
                   (this,QString::fromLocal8Bit("提示"),
                    QString::fromLocal8Bit("删除成功"));
}

void MainWindowTea::NewBoxInformation(int i){
    if(i==2){
        ui->Box_class_2->clear();
        ui->Box_class_2->insertItem(0,QString::fromLocal8Bit("请选择班级"));
        for(int j=0;j<LStu.size();j++)
        {
            ui->Box_class_2->insertItem(j+1,LC[LStu[j][0].classId].className);
    }}
    else if(i==1){
        ui->Box_class->clear();
         ui->Box_class->insertItem(0,QString::fromLocal8Bit("请选择班级"));
        for(int j=0;j<LStu.size();j++)
        {
            ui->Box_class->insertItem(j+1,LC[LStu[j][0].classId].className);}
    }

}
void MainWindowTea::on_qBtn_class_clicked()
{
      ui->tableWidget_gq->clearContents();
        ui->tableWidget_gq->verticalHeader()->setVisible(false);

            int a=ui->Box_class_2->currentIndex();
            if(a==0){QMessageBox::information(this, "提示", "请选择班级");return;}
            a--;

            QList<int>Index;
               for(int i=0;i<LStu[a].size();i++)
               {
                   Index.append(i);
               }


           Handle::Sort(LStu[a],Index,B[a],0,LStu[a].size()-1);
            ui->tableWidget_gq->setColumnCount(5);
            ui->tableWidget_gq->setRowCount(LStu[a].size());
            for(int i=0;i<LStu[a].size();i++)
            {
                         Student&S=LStu[a][Index[i]];
                                QTableWidgetItem*item01=new QTableWidgetItem(QString::number(S.id));
                                ui->tableWidget_gq->setItem(i,0,item01);
                                QTableWidgetItem*item02=new QTableWidgetItem(S.name);
                                ui->tableWidget_gq->setItem(i,1,item02);
                                QTableWidgetItem*item03=new QTableWidgetItem(QString::number(S.score[B[a]]));
                                ui->tableWidget_gq->setItem(i,3,item03);

                                QTableWidgetItem*item04=new QTableWidgetItem(QString::number(i+1));
                                ui->tableWidget_gq->setItem(i,4,item04);

                                QTableWidgetItem*item05=new QTableWidgetItem(LC[S.classId].className);
                                ui->tableWidget_gq->setItem(i,2,item05);
            }


}

