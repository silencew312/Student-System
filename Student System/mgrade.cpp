#include "mgrade.h"
#include "ui_mgrade.h"

mgrade::mgrade(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mgrade)
{
    ui->setupUi(this);
    NewBoxInformation_class(5);
}
mgrade::~mgrade()
{
    delete ui;
}



void mgrade::on_qBtn_sub_clicked()
{   int n=ui->Box_class_2->currentIndex();
    if(n==0){QMessageBox::information
                (this,QString::fromLocal8Bit("提示"),
                 QString::fromLocal8Bit("请选择班级"));return;}
    n--;
    ui->tableWidget_sub_1->clearContents();
    ui->tableWidget_sub_1->verticalHeader()->setVisible(false);
     ui->tableWidget_sub_1->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui-> tableWidget_sub_1->setRowCount(LC[n].Sub.size());
    ui->tableWidget_sub_1->setColumnCount(4);

    for(int k=0;k<LC[n].Sub.size();k++){

        QString SubName=LC[n].Sub[k].subname;
        QString Credit=QString::number(LC[n].Sub[k].credit,'f',1);



       QString TeacherName=LC[n].Sub[k].teacher.name;
       QTableWidgetItem *item0 = new QTableWidgetItem(SubName);
       ui->tableWidget_sub_1->setItem(k,0,item0);
       QTableWidgetItem *item1= new QTableWidgetItem(Credit);
       ui->tableWidget_sub_1->setItem(k,1,item1);
       QTableWidgetItem *item2 = new QTableWidgetItem(TeacherName);
       ui->tableWidget_sub_1->setItem(k,2,item2);
       QTableWidgetItem *item3 = new QTableWidgetItem(LC[n].Sub[k].teacher.id);
       ui->tableWidget_sub_1->setItem(k,3,item3);
    }


}




void mgrade::on_add_Btn_sub_clicked()
{if(ui->qEdit_sub_1->text().isEmpty()){QMessageBox::information
                (this,QString::fromLocal8Bit("提示"),
                 QString::fromLocal8Bit("课程名为空"));return;}
  if(ui->qEdit_sub_2->text().isEmpty()){QMessageBox::information
              (this,QString::fromLocal8Bit("提示"),
               QString::fromLocal8Bit("学分为空"));return;}
  if(ui->qEdit_sub_4->text().isEmpty()){QMessageBox::information
              (this,QString::fromLocal8Bit("提示"),
               QString::fromLocal8Bit("任课教师为空"));return;}
  if(ui->qEdit_sub_5->text().isEmpty()){QMessageBox::information
              (this,QString::fromLocal8Bit("提示"),
               QString::fromLocal8Bit("教师账号为空"));return;}
    bool ok = 0;
    double Credit=ui->qEdit_sub_2->text().toDouble(&ok);
    if(Credit<=0){QMessageBox::information
                (this,QString::fromLocal8Bit("提示"),
                 QString::fromLocal8Bit("学分不符合规范"));return;}
    int n=ui->Box_class_3->currentIndex();
if(n==0){QMessageBox::information
            (this,QString::fromLocal8Bit("提示"),
             QString::fromLocal8Bit("请选择班级"));return;}
n--;
    int a=Handle::Namesearch(ui->qEdit_sub_1->text(),LC[n].Sub);
    if(a<LC[n].Sub.size()){QMessageBox::information
                (this,QString::fromLocal8Bit("提示"),
                 QString::fromLocal8Bit("已存在此课程"));return;}
    int w=0;
    for(int i=0;i<LC.size();i++)
       { int p=0;
        for(int j=0;j<LC[i].Sub.size();j++)
            if(LC[i].Sub[j].teacher.id==ui->qEdit_sub_5->text()&&ui->qEdit_sub_1->text()!=LC[i].Sub[j].subname)
               { p=1;w=1;break;}
        if(p==1)break;
    }
    if(w==1){QMessageBox::information
                (this,QString::fromLocal8Bit("提示"),
                 QString::fromLocal8Bit("账号已存在"));return;}
    Teacher T(ui->qEdit_sub_4->text(),ui->qEdit_sub_5->text());
    Subject sub(ui->qEdit_sub_1->text(),Credit,T);
    LC[n].Sub.append(sub);
    for(int i=0;i<LStu[n].size();i++)
    {Student&S= LStu[n][i];
        S.score.append(-1);

    }


     QMessageBox::information
                     (this,QString::fromLocal8Bit("提示"),
                      QString::fromLocal8Bit("添加成功"));
}


void mgrade::on_revise_Btn_sub_clicked()
{    if(ui->qEdit_sub->text().isEmpty()){QMessageBox::information
            (this,QString::fromLocal8Bit("提示"),
             QString::fromLocal8Bit("请输入课程名"));return;}
    QString SubName=ui->qEdit_sub->text();

     int n=ui->Box_class_3->currentIndex();
      if(n==0){QMessageBox::information
                  (this,QString::fromLocal8Bit("提示"),
                   QString::fromLocal8Bit("请选择班级"));return;}
      n--;
         int a=Handle::Namesearch(SubName,LC[n].Sub);
          if(a==LC[n].Sub.size()){QMessageBox::information
                      (this,QString::fromLocal8Bit("提示"),
                       QString::fromLocal8Bit("无此课程"));return;}
         Subject&sub=LC[n].Sub[a];
         if(!ui->qEdit_sub_1->text().isEmpty())sub.subname=ui->qEdit_sub_1->text();

        if(!ui->qEdit_sub_2->text().isEmpty()){
            bool ok=0;
            double Credit=ui->qEdit_sub_2->text().toDouble(&ok);
             if(Credit<=0){QMessageBox::information
                         (this,QString::fromLocal8Bit("提示"),
                          QString::fromLocal8Bit("学分不符合规范,请重新输入"));return;}
            sub.credit=Credit;}

        if(!ui->qEdit_sub_4->text().isEmpty())sub.teacher.name=ui->qEdit_sub_4->text();
        if(!ui->qEdit_sub_5->text().isEmpty()){
            int w=0;
            for(int i=0;i<LC.size();i++)
               { int p=0;
                for(int j=0;j<LC[i].Sub.size();j++)
                    if(LC[i].Sub[j].teacher.id==ui->qEdit_sub_5->text()&&ui->qEdit_sub->text()!=LC[i].Sub[j].subname)
                       { p=1;w=1;break;}
                if(p==1)break;
            }
            if(w==1){QMessageBox::information
                        (this,QString::fromLocal8Bit("提示"),
                         QString::fromLocal8Bit("账号已存在"));return;}
            sub.teacher.id=ui->qEdit_sub_5->text();}

    ui->qEdit_sub->clear();
    ui->qEdit_sub_1->clear();
    ui->qEdit_sub_2->clear();
     ui->qEdit_sub_4->clear();
      ui->qEdit_sub_5->clear();

       QMessageBox::information
                       (this,QString::fromLocal8Bit("提示"),
                        QString::fromLocal8Bit("修改成功"));
}

  void mgrade::on_Del_Btn_sub_clicked()
  {if(ui->qEdit_sub->text().isEmpty()){QMessageBox::information
                  (this,QString::fromLocal8Bit("提示"),
                   QString::fromLocal8Bit("请输入课程名"));return;}
    QString SubName=ui->qEdit_sub->text();
    int n=ui->Box_class_3->currentIndex();
    if(n==0){QMessageBox::information
                (this,QString::fromLocal8Bit("提示"),
                 QString::fromLocal8Bit("请选择班级"));return;}
    n--;
        int a=Handle::Namesearch(SubName,LC[n].Sub);
         if(a==LC[n].Sub.size()){QMessageBox::information
                     (this,QString::fromLocal8Bit("提示"),
                      QString::fromLocal8Bit("无此课程"));return;}
         LC[n].Sub.removeAt(a);
         for(int i=0;i<LStu[n].size();i++)
         {
             Student&S= LStu[n][i];
              S.score.removeAt(a);

         }
          ui->qEdit_sub->clear();

          QMessageBox::information
                               (this,QString::fromLocal8Bit("提示"),
                                QString::fromLocal8Bit("删除成功"));
}

void mgrade::on_tabWidget_currentChanged(int index)
{if(index==0)NewBoxInformation_class(5);
    else if(index==1){
       NewBoxInformation_class(4);

    }
    else if(index==2){
       NewBoxInformation_class(1);
    }
    else if(index==3){
       NewBoxInformation_class(2);
       NewBoxInformation_class(3);
    }
}


void mgrade::on_grqBtn_clicked()
{
    if(ui->gaEdit->text().isEmpty()){QMessageBox::information
            (this,QString::fromLocal8Bit("提示"),
             QString::fromLocal8Bit("请输入学号"));return;}
    bool ok = 0;
    long Id=ui->gaEdit->text().toLong(&ok);
    int j;
    int a;
   Handle::getId_key(j,a,LStu,Id);
    if(j==LC.size()){QMessageBox::information
                (this,QString::fromLocal8Bit("提示"),
                 QString::fromLocal8Bit("无此学生"));return;}
    NewBoxInformation_sub(j,2);

}

void mgrade::on_gDelBtn_clicked()
{     if(ui->gaEdit->text().isEmpty()){QMessageBox::information
                (this,QString::fromLocal8Bit("提示"),
                 QString::fromLocal8Bit("请输入学号"));return;}
    int k=ui->subBox_2->currentIndex();
if(k==0){QMessageBox::information
            (this,QString::fromLocal8Bit("提示"),
             QString::fromLocal8Bit("请选择学科"));return;}
k--;
        bool ok = 0;
        long Id=ui->gaEdit->text().toLong(&ok, 10);
        int j;
        int a;
        Handle::getId_key(j,a,LStu,Id);
        if(j==LC.size()){QMessageBox::information
                    (this,QString::fromLocal8Bit("提示"),
                     QString::fromLocal8Bit("无此学生"));return;}
        Student&S=LStu[j][a];
        S.score[k]=-1;

       ui->gaEdit->clear();
         QMessageBox::information
                         (this,QString::fromLocal8Bit("提示"),
                          QString::fromLocal8Bit("删除成功"));
}

void mgrade::on_gqBtn_clicked()
{
    ui->tableWidget_gq->clear();
    if(ui->gqEdit->text().isEmpty()){
        QMessageBox::information
                        (this,QString::fromLocal8Bit("提示"),
                         QString::fromLocal8Bit("请输入信息"));return;
    }
    ui->tableWidget_gq->verticalHeader()->setVisible(false);
    ui->tableWidget_gq->horizontalHeader()->setVisible(false);
    ui->tableWidget_gq->setEditTriggers(QAbstractItemView::NoEditTriggers);

    if(ui->gqBox->currentIndex()==0){
        bool ok = 0;
        long Id=ui->gqEdit->text().toLong(&ok, 10);
        int j;
        int a;
        Handle::getId_key(j,a,LStu,Id);
        if(j==LC.size()){QMessageBox::information
                    (this,QString::fromLocal8Bit("提示"),
                     QString::fromLocal8Bit("无此学生"));return;}
         Student&S=LStu[j][a];

         ui-> tableWidget_gq->setRowCount(2+LC[j].Sub.size());
         ui->tableWidget_gq->setColumnCount(6);

QTableWidgetItem*itemname=new QTableWidgetItem(QString::fromLocal8Bit("学生姓名"));
ui->tableWidget_gq->setItem(0,0,itemname);
QTableWidgetItem*itemName=new QTableWidgetItem(S.name);
ui->tableWidget_gq->setItem(0,1,itemName);
QTableWidgetItem*itemclass=new QTableWidgetItem(QString::fromLocal8Bit("班级"));
ui->tableWidget_gq->setItem(0,2,itemclass);
QTableWidgetItem*itemClass=new QTableWidgetItem(LC[j].className);
ui->tableWidget_gq->setItem(0,3,itemClass);
QTableWidgetItem*itemstr1=new QTableWidgetItem(QString::fromLocal8Bit("科目"));
ui->tableWidget_gq->setItem(1,0,itemstr1);
QTableWidgetItem*itemstr2=new QTableWidgetItem(QString::fromLocal8Bit("成绩"));
ui->tableWidget_gq->setItem(1,1,itemstr2);
QTableWidgetItem*itemstr3=new QTableWidgetItem(QString::fromLocal8Bit("排名"));
ui->tableWidget_gq->setItem(1,2,itemstr3);
QTableWidgetItem*itemstr4=new QTableWidgetItem(QString::fromLocal8Bit("绩点"));
ui->tableWidget_gq->setItem(1,3,itemstr4);
QTableWidgetItem*itemstr5=new QTableWidgetItem(QString::fromLocal8Bit("学分"));
ui->tableWidget_gq->setItem(1,4,itemstr5);
QTableWidgetItem*itemstr6=new QTableWidgetItem(QString::fromLocal8Bit("任课老师"));
ui->tableWidget_gq->setItem(1,5,itemstr6);
for(int i=0;i<S.score.size();i++)
 {QString Score=QString::number(S.score[i]);
    double gp=Handle::getGP(S.score[i]);
  QString GP=QString::number(gp,'f',2);
int rank=Handle::getrank(S,LStu[j],i);
QString Rank=QString::number(rank);
  QString Credit=QString::number(LC[j].Sub[i].credit,'f',1);
  QTableWidgetItem*item1=new QTableWidgetItem(LC[j].Sub[i].subname);

  QTableWidgetItem*item2=new QTableWidgetItem(Score);
   QTableWidgetItem*item3=new QTableWidgetItem(Rank);
   QTableWidgetItem*item4=new QTableWidgetItem(GP);
    QTableWidgetItem*item5=new QTableWidgetItem(Credit);
     QTableWidgetItem*item6=new QTableWidgetItem(LC[j].Sub[i].teacher.name);

   ui->tableWidget_gq->setItem(i+2,0,item1);
   ui->tableWidget_gq->setItem(i+2,1,item2);
   ui->tableWidget_gq->setItem(i+2,2,item3);
   ui->tableWidget_gq->setItem(i+2,3,item4);
   ui->tableWidget_gq->setItem(i+2,4,item5);
    ui->tableWidget_gq->setItem(i+2,5,item6);
             }
    }
    else if(ui->gqBox->currentIndex()==1){
     QString Name=ui->gqEdit->text();
     QList<int>list;

      QList<Student>Stu;
     for(int j=0;j<LC.size();j++){


     list=Handle::Namesearch(Name,LStu[j]);
     if(list.size()==0)continue;
     else {

      for(int i=0;i<list.size();i++ )
             Stu.append(LStu[j][list[i]]);

     }


     }
     if(Stu.size()==0){QMessageBox::information
                 (this,QString::fromLocal8Bit("提示"),
                  QString::fromLocal8Bit("无此学生"));return;}
     else {

         ui-> tableWidget_gq->setRowCount(10);
         ui->tableWidget_gq->setColumnCount(6*Stu.size());
         for(int i=0;i<Stu.size();i++){
             Student&S=Stu[i];
QTableWidgetItem*itemname=new QTableWidgetItem(QString::fromLocal8Bit("学号"));
ui->tableWidget_gq->setItem(0,6*i,itemname);
QString Id=QString::number(S.id);
QTableWidgetItem*itemName=new QTableWidgetItem(Id);
ui->tableWidget_gq->setItem(0,6*i+1,itemName);
QTableWidgetItem*itemclass=new QTableWidgetItem(QString::fromLocal8Bit("班级"));
ui->tableWidget_gq->setItem(0,6*i+2,itemclass);

QTableWidgetItem*itemClass=new QTableWidgetItem(LC[S.classId].className);
ui->tableWidget_gq->setItem(0,6*i+3,itemClass);
QTableWidgetItem*itemstr1=new QTableWidgetItem(QString::fromLocal8Bit("科目"));
ui->tableWidget_gq->setItem(1,6*i,itemstr1);
QTableWidgetItem*itemstr2=new QTableWidgetItem(QString::fromLocal8Bit("成绩"));
ui->tableWidget_gq->setItem(1,6*i+1,itemstr2);
QTableWidgetItem*itemstr3=new QTableWidgetItem(QString::fromLocal8Bit("班级排名"));
ui->tableWidget_gq->setItem(1,6*i+2,itemstr3);
QTableWidgetItem*itemstr4=new QTableWidgetItem(QString::fromLocal8Bit("绩点"));
ui->tableWidget_gq->setItem(1,6*i+3,itemstr4);
QTableWidgetItem*itemstr5=new QTableWidgetItem(QString::fromLocal8Bit("学分"));
ui->tableWidget_gq->setItem(1,6*i+4,itemstr5);
QTableWidgetItem*itemstr6=new QTableWidgetItem(QString::fromLocal8Bit("任课老师"));
ui->tableWidget_gq->setItem(1,6*i+5,itemstr6);
for(int j=0;j<S.score.size();j++)
 {QString Score=QString::number(S.score[j]);
   double gp=Handle::getGP(S.score[j]);
    QString GP=QString::number(gp,'f',2);
    int rank=Handle::getrank(S,LStu[S.classId],j);
    QString Rank=QString::number(rank);
     QString Credit=QString::number(LC[S.classId].Sub[j].credit,'f',1);
  QTableWidgetItem*item1=new QTableWidgetItem(LC[S.classId].Sub[j].subname);
  QTableWidgetItem*item2=new QTableWidgetItem(Score);
   QTableWidgetItem*item3=new QTableWidgetItem(Rank);
   QTableWidgetItem*item4=new QTableWidgetItem(GP);
    QTableWidgetItem*item5=new QTableWidgetItem(Credit);
     QTableWidgetItem*item6=new QTableWidgetItem(LC[S.classId].Sub[j].teacher.name);

   ui->tableWidget_gq->setItem(j+2,6*i,item1);
   ui->tableWidget_gq->setItem(j+2,6*i+1,item2);
   ui->tableWidget_gq->setItem(j+2,6*i+2,item3);
   ui->tableWidget_gq->setItem(j+2,6*i+3,item4);
   ui->tableWidget_gq->setItem(j+2,6*i+4,item5);
   ui->tableWidget_gq->setItem(j+2,6*i+5,item6);
             }
         }
    }
}

}

void mgrade::on_sortBtn_clicked()
{int n=ui->Box_class->currentIndex();
    int k=ui->subBox->currentIndex();
    if(n==0){QMessageBox::information
                (this,QString::fromLocal8Bit("提示"),
                 QString::fromLocal8Bit("请选择班级"));return;}
    if(k==0){QMessageBox::information
                (this,QString::fromLocal8Bit("提示"),
                 QString::fromLocal8Bit("请选择学科"));return;}
    n--;k--;
    QList<int>Index;
    for(int i=0;i<LStu[n].size();i++)
        Index.append(i);
    Handle::Sort(LStu[n],Index,k,0,LStu[n].size()-1);
    ui->tableWidget_sort->clear();
    ui->tableWidget_sort->verticalHeader()->setVisible(false);
    ui->tableWidget_sort->horizontalHeader()->setVisible(false);
     ui->tableWidget_sort->setEditTriggers(QAbstractItemView::NoEditTriggers);
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

        QTableWidgetItem*itemId=new QTableWidgetItem(QString::number(S.id));
        ui->tableWidget_sort->setItem(i+1,0,itemId);
        QTableWidgetItem*itemName=new QTableWidgetItem(S.name);
        ui->tableWidget_sort->setItem(i+1,1,itemName);
        QTableWidgetItem*itemScore=new QTableWidgetItem(QString::number(S.score[k]));
        ui->tableWidget_sort->setItem(i+1,2,itemScore);
        QTableWidgetItem*itemRank=new QTableWidgetItem(QString::number(i+1));
        ui->tableWidget_sort->setItem(i+1,3,itemRank);
    }
}

void mgrade::on_anBtn_clicked()
{
    int n=ui->Box_class->currentIndex();
    int k=ui->subBox->currentIndex();
    if(n==0){QMessageBox::information
                (this,QString::fromLocal8Bit("提示"),
                 QString::fromLocal8Bit("请选择班级"));return;}
    if(k==0){QMessageBox::information
                (this,QString::fromLocal8Bit("提示"),
                 QString::fromLocal8Bit("请选择学科"));return;}
    n--;k--;

    ui->tableWidget_sort->clear();
    ui->tableWidget_sort->verticalHeader()->setVisible(false);
    ui->tableWidget_sort->horizontalHeader()->setVisible(false);

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
    QList<int>num=Handle::count(LStu[n],k);
double pass_g=double(LStu[n].size()-num[4])/LStu[n].size();
double good_g=double(num[0])/LStu[n].size();
double avg=double(num[5])/LStu[n].size();
QTableWidgetItem*AVG=new QTableWidgetItem(QString::number(avg,'f',2));
ui->tableWidget_sort->setItem(3,1,AVG);
    QTableWidgetItem*pass01=new QTableWidgetItem(QString::number(LStu[n].size()-num[4],10));
    ui->tableWidget_sort->setItem(0,1,pass01);
    QTableWidgetItem*pass=new QTableWidgetItem(QString::number(pass_g,'f',2));
    ui->tableWidget_sort->setItem(0,3,pass);
    QTableWidgetItem*good02=new QTableWidgetItem(QString::number(num[0],10));
    ui->tableWidget_sort->setItem(1,1,good02);
    QTableWidgetItem*good=new QTableWidgetItem(QString::number(good_g,'f',2));
    ui->tableWidget_sort->setItem(1,3,good);
    QList<int>Index;
    for(int i=0;i<LStu[n].size();i++)
        Index.append(i);
    Handle::Sort(LStu[n],Index,k,0,LStu[n].size()-1);

    QTableWidgetItem*max=new QTableWidgetItem(QString::number(LStu[n][Index[0]].score[k]));
    ui->tableWidget_sort->setItem(2,1,max);
    QTableWidgetItem*min=new QTableWidgetItem(QString::number(LStu[n][Index[LStu[n].size()-1]].score[k]));
    ui->tableWidget_sort->setItem(2,3,min);
    QTableWidgetItem*s9=new QTableWidgetItem(QString::number(num[0]));
    ui->tableWidget_sort->setItem(4,1,s9);
    QTableWidgetItem*s8=new QTableWidgetItem(QString::number(num[1]));
    ui->tableWidget_sort->setItem(5,1,s8);
    QTableWidgetItem*s7=new QTableWidgetItem(QString::number(num[2]));
    ui->tableWidget_sort->setItem(6,1,s7);
    QTableWidgetItem*s6=new QTableWidgetItem(QString::number(num[3]));
    ui->tableWidget_sort->setItem(7,1,s6);
    QTableWidgetItem*s0=new QTableWidgetItem(QString::number(num[4]));
    ui->tableWidget_sort->setItem(8,1,s0);

}

void mgrade::on_hlBtn_clicked()
{    int n=ui->Box_class->currentIndex();
     int k=ui->subBox->currentIndex();
    if(n==0){QMessageBox::information
                (this,QString::fromLocal8Bit("提示"),
                 QString::fromLocal8Bit("请选择班级"));return;}
    if(k==0){QMessageBox::information
                (this,QString::fromLocal8Bit("提示"),
                 QString::fromLocal8Bit("请选择学科"));return;}
    n--;k--;
    if(ui->lineEdit_low->text().isEmpty()){QMessageBox::information
                (this,QString::fromLocal8Bit("提示"),
                 QString::fromLocal8Bit("请输入最低分"));return;}
    else if(ui->lineEdit_high->text().isEmpty()){QMessageBox::information
                (this,QString::fromLocal8Bit("提示"),
                 QString::fromLocal8Bit("请输入最高分"));return;}
    bool ok = 0;

    double low=ui->lineEdit_low->text().toDouble(&ok);
     double high=ui->lineEdit_high->text().toDouble(&ok);
if(low>=high){QMessageBox::information
            (this,QString::fromLocal8Bit("提示"),
             QString::fromLocal8Bit("最低分必须小于最高分"));return;}
     QList<int>Index;
     for(int i=0;i<LStu[n].size();i++)
         Index.append(i);
     Handle::Sort(LStu[n],Index,k,0,LStu[n].size()-1);
      ui->tableWidget_sort->clear();
     ui->tableWidget_sort->horizontalHeader()->setVisible(false);
     ui->tableWidget_sort->verticalHeader()->setVisible(false);
      ui->tableWidget_sort->setEditTriggers(QAbstractItemView::NoEditTriggers);
     ui->tableWidget_sort->setColumnCount(4);
     ui->tableWidget_sort->setRowCount(1);

     QTableWidgetItem*itemid=new QTableWidgetItem(QString::fromLocal8Bit("学号"));
     ui->tableWidget_sort->setItem(0,0,itemid);
     QTableWidgetItem*itemname=new QTableWidgetItem(QString::fromLocal8Bit("姓名"));
     ui->tableWidget_sort->setItem(0,1,itemname);
     QTableWidgetItem*itemscore=new QTableWidgetItem(QString::fromLocal8Bit("成绩"));
     ui->tableWidget_sort->setItem(0,2,itemscore);
      QTableWidgetItem*itemrank=new QTableWidgetItem(QString::fromLocal8Bit("排名"));
      ui->tableWidget_sort->setItem(0,3,itemrank);
    int p=1;
for(int i=0;i<LStu[n].size();i++)
{
   int j=Index[i];
   Student S=LStu[n][j];

   if(S.score[k]>=low&&S.score[k]<=high)
   {
       ui->tableWidget_sort->insertRow(p);
       QTableWidgetItem*itemid=new QTableWidgetItem(QString::number(S.id));
       ui->tableWidget_sort->setItem(p,0,itemid);
       QTableWidgetItem*itemname=new QTableWidgetItem(S.name);
       ui->tableWidget_sort->setItem(p,1,itemname);
       QTableWidgetItem*itemscore=new QTableWidgetItem(QString::number(S.score[k]));
       ui->tableWidget_sort->setItem(p,2,itemscore);
       QTableWidgetItem*itemrank=new QTableWidgetItem(QString::number(i+1));
       ui->tableWidget_sort->setItem(p,3,itemrank);
       p++;

   }
}
}

void mgrade::on_outgradeBtn_clicked()
{

   int n=ui->Box_class->currentIndex();
  int k=ui->subBox->currentIndex();
  if(n==0){QMessageBox::information
              (this,QString::fromLocal8Bit("提示"),
               QString::fromLocal8Bit("请选择班级"));return;}
  if(k==0){QMessageBox::information
              (this,QString::fromLocal8Bit("提示"),
               QString::fromLocal8Bit("请选择学科"));return;}
  n--;k--;
Handle::WriteT(LStu[n],LC[n],k);
QMessageBox::information
                    (this,QString::fromLocal8Bit("提示"),
                     QString::fromLocal8Bit("导出成功"));
}

void mgrade::on_outgradeBtn1_clicked()
{
    if(ui->gqBox->currentIndex()==0){
        bool ok=0;
        long Id=ui->gqEdit->text().toLong(&ok);
        int j;
        int a;
         Handle::getId_key(j,a,LStu,Id);
        if(j==LStu.size()){QMessageBox::information
                    (this,QString::fromLocal8Bit("提示"),
                     QString::fromLocal8Bit("无此学生"));return;}
      else{ Student&S=LStu[j][a];

       Handle::WriteT(LStu[S.classId],S,LC[S.classId]);
       QMessageBox::information
                           (this,QString::fromLocal8Bit("提示"),
                            QString::fromLocal8Bit("导出成功"));}
    }
    else if(ui->gqBox->currentIndex()==1){
        QList<int>list;
        QString Name=ui->gqEdit->text();
         QList<Student>Stu;
        for(int j=0;j<LC.size();j++){


        list=Handle::Namesearch(Name,LStu[j]);
        if(list.size()==0)continue;
        else {

         for(int i=0;i<list.size();i++ )
                Stu.append(LStu[j][list[i]]);

        }


        }
        if(Stu.size()==0){QMessageBox::information
                    (this,QString::fromLocal8Bit("提示"),
                     QString::fromLocal8Bit("无此学生"));return;}
else{
        for(int i=0;i<Stu.size();i++ )
        {
            Student&S=Stu[i];
             Handle::WriteT(LStu[S.classId],S,LC[S.classId]);
        }

        QMessageBox::information
                            (this,QString::fromLocal8Bit("提示"),
                             QString::fromLocal8Bit("导出成功"));}
    }

}


void mgrade::on_Button_class_ok_clicked()
{
    int n=ui->Box_class->currentIndex();
    if(n==0){QMessageBox::information
                (this,QString::fromLocal8Bit("提示"),
                 QString::fromLocal8Bit("请选择班级"));return;}
    n--;
   NewBoxInformation_sub(n,1);
}

void mgrade::on_garBtn_clicked()
{
    if(ui->gaEdit->text().isEmpty()){QMessageBox::information
            (this,QString::fromLocal8Bit("提示"),
             QString::fromLocal8Bit("请输入学号"));return;}
    bool ok=0;
    long Id=ui->gaEdit->text().toLong(&ok);
    int k=ui->subBox_2->currentIndex();
    if(k==0){QMessageBox::information
                (this,QString::fromLocal8Bit("提示"),
                 QString::fromLocal8Bit("请选择学科"));return;}
    k--;
    int j;
    int a;
     Handle::getId_key(j,a,LStu,Id);
    if(j==LC.size()){QMessageBox::information
                (this,QString::fromLocal8Bit("提示"),
                 QString::fromLocal8Bit("无此学生"));return;}
    Student&S=LStu[j][a];

    double s=ui->rscoreEdit->text().toDouble(&ok);
    if(s>100||s<0){QMessageBox::information
                (this,QString::fromLocal8Bit("提示"),
                 QString::fromLocal8Bit("成绩不符合规范,请重新输入"));return;}
    S.score[k]=s;
    ui->rscoreEdit->clear();

    QMessageBox::information
                        (this,QString::fromLocal8Bit("提示"),
                         QString::fromLocal8Bit("添加/修改成功"));
}


void mgrade::on_DelallgBtn_clicked()
{if(ui->DelsubEdit->text().isEmpty()){QMessageBox::information
            (this,QString::fromLocal8Bit("提示"),
             QString::fromLocal8Bit("请输入科目"));return;}
    if(ui->Box_class_4->currentIndex()==0){QMessageBox::information
                (this,QString::fromLocal8Bit("提示"),
                 QString::fromLocal8Bit("请选择班级"));return;}
    else if(ui->Box_class_4->currentIndex()==1){
    int w=0;
    for(int j=0;j<LC.size();j++)
        for(int k=0;k<LC[j].Sub.size();k++)
            if(LC[j].Sub[k].subname==ui->DelsubEdit->text()){

             for(int i=0;i<LStu[j].size();i++)
                 LStu[j][i].score[k]=-1;
             w=1;
            }
    if(w==1) QMessageBox::information
            (this,QString::fromLocal8Bit("提示"),
             QString::fromLocal8Bit("删除成功"));
    else
        QMessageBox::information
                            (this,QString::fromLocal8Bit("提示"),
                             QString::fromLocal8Bit("无此学科"));}
    else{
        int n=ui->Box_class_4->currentIndex();
        n-=2;
        int w=0;
        for(int k=0;k<LC[n].Sub.size();k++)
            if(LC[n].Sub[k].subname==ui->DelsubEdit->text())
            { for(int i=0;i<LStu[n].size();i++)
                    LStu[n][i].score[k]=-1;
               w=1;break;
            }
        if(w==1) QMessageBox::information
                (this,QString::fromLocal8Bit("提示"),
                 QString::fromLocal8Bit("删除成功"));
        else
            QMessageBox::information
                                (this,QString::fromLocal8Bit("提示"),
                                 QString::fromLocal8Bit("无此学科"));
    }

}
void mgrade::NewBoxInformation_class(int i){
    if(i==1){
        ui->Box_class->clear();
        ui->Box_class->insertItem(0,QString::fromLocal8Bit("请选择班级"));
        for(int j=0;j<LC.size();j++)
            ui->Box_class->insertItem(j+1,LC[j].className);
    }
    else if(i==2){
        ui->Box_class_2->clear();
        ui->Box_class_2->insertItem(0,QString::fromLocal8Bit("请选择班级"));
        for(int j=0;j<LC.size();j++)
            ui->Box_class_2->insertItem(j+1,LC[j].className);
    }
    else if(i==3){
        ui->Box_class_3->clear();
        ui->Box_class_3->insertItem(0,QString::fromLocal8Bit("请选择班级"));
        for(int j=0;j<LC.size();j++)
            ui->Box_class_3->insertItem(j+1,LC[j].className);
    }
    else if(i==4){
        ui->Box_class_4->clear();
        ui->Box_class_4->insertItem(0,QString::fromLocal8Bit("请选择班级"));
        ui->Box_class_4->insertItem(1,QString::fromLocal8Bit("全部班级"));
        for(int j=0;j<LC.size();j++)
        ui->Box_class_4->insertItem(j+2,LC[j].className);
    }
    else if(i==5){
        ui->Box_class_5->clear();
        ui->Box_class_5->insertItem(0,QString::fromLocal8Bit("请选择班级"));

        for(int j=0;j<LC.size();j++)
        ui->Box_class_5->insertItem(j+1,LC[j].className);
    }
}
void mgrade::NewBoxInformation_sub(int k,int i)
{
    if(i==1)
    {ui->subBox->clear();
        ui->subBox->insertItem(0,QString::fromLocal8Bit("请选择学科"));
        for(int j=0;j<LC[k].Sub.size();j++)
        {ui->subBox->insertItem(j+1,LC[k].Sub[j].subname);

        }
    }
    else if(i==2)
    {  ui->subBox_2->clear();
        ui->subBox_2->insertItem(0,QString::fromLocal8Bit("请选择学科"));

                for(int j=0;j<LC[k].Sub.size();j++)
                {ui->subBox_2->insertItem(j+1,LC[k].Sub[j].subname);

                }
    }
}



void mgrade::on_gqBtn_2_clicked()
{ui->tableWidget_gq->clear();
    int n=ui->Box_class_5->currentIndex();
    if(n==0){ QMessageBox::information
                (this,QString::fromLocal8Bit("提示"),
                 QString::fromLocal8Bit("请选择班级"));return;}
    n--;
    ui->tableWidget_gq->verticalHeader()->setVisible(false);
    ui->tableWidget_gq->horizontalHeader()->setVisible(false);
    ui->tableWidget_gq->setEditTriggers(QAbstractItemView::NoEditTriggers);





        ui-> tableWidget_gq->setRowCount(1+LStu[n].size());
        ui->tableWidget_gq->setColumnCount(2+LC[n].Sub.size());
        QTableWidgetItem*itemid=new QTableWidgetItem(QString::fromLocal8Bit("学号"));
        ui->tableWidget_gq->setItem(0,0,itemid);
        QTableWidgetItem*itemname=new QTableWidgetItem(QString::fromLocal8Bit("姓名"));
        ui->tableWidget_gq->setItem(0,1,itemname);
        for(int i=0;i<LC[n].Sub.size();i++){
            QTableWidgetItem*itemstr=new QTableWidgetItem(LC[n].Sub[i].subname);
            ui->tableWidget_gq->setItem(0,i+2,itemstr);}
        for(int i=0;i<LStu[n].size();i++){
            Student&S=LStu[n][i];
            QString Id=QString::number(S.id);
            QTableWidgetItem*itemId=new QTableWidgetItem(Id);
            ui->tableWidget_gq->setItem(i+1,0,itemId);
            QTableWidgetItem*itemName=new QTableWidgetItem(S.name);
            ui->tableWidget_gq->setItem(i+1,1,itemName);
            for(int j=0;j<S.score.size();j++)
            {QString Score=QString::number(S.score[j]);
                QTableWidgetItem*item=new QTableWidgetItem(Score);
                ui->tableWidget_gq->setItem(i+1,j+2,item);
            }


}
}
void mgrade::on_outgradeBtn1_2_clicked()
{

       int n=ui->Box_class_5->currentIndex();
       if(n==0){ QMessageBox::information
                   (this,QString::fromLocal8Bit("提示"),
                    QString::fromLocal8Bit("请选择班级"));return;}
       n--;
        Handle::WriteT(LStu[n],LC[n],-1);
        QMessageBox::information
                            (this,QString::fromLocal8Bit("提示"),
                             QString::fromLocal8Bit("导出成功"));

}


