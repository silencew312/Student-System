#include "base.h"
#include "ui_base.h"

Base::Base(QWidget *parent) :

    QDialog(parent),
    ui(new Ui::Base)
{

    ui->setupUi(this);
 NewBoxInformation(3);
}

Base::~Base()
{
    delete ui;
}
void Base::Add(long Id,QString Name,QString Sex,QString P,QList<Student>&Stu,int ClassId){
 Student S(Id,Name,Sex,P,ClassId);
 for(int i=0;i<LC[ClassId].Sub.size();i++)
   S.score.append(-1);
    Insert(Stu,S);
}


void Base::on_addBtn_clicked()
{
    if(ui->id->text().isEmpty()){QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("学号不能为空"));ui->boy->setCheckable(false);
        ui->girl->setCheckable(false);
        ui->boy->setCheckable(true);
        ui->girl->setCheckable(true);return;}

    bool ok = 0;
  long Id=ui->id->text().toLong(&ok);
  if(Id<=1000000000||Id>=10000000000){QMessageBox::information
              (this,QString::fromLocal8Bit("提示"),
               QString::fromLocal8Bit("学号不符合规范，请重新输入"));return;}
    QString Name=ui->name->text();
    if(Name.isEmpty()){QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("姓名不能为空"));return;}
    QString Sex;
    if(ui->boy->isChecked())
        Sex=ui->boy->text();
    else if(ui->girl->isChecked())
        Sex=ui->girl->text();
    else{QMessageBox::information(this, QString::fromLocal8Bit("提示"),QString::fromLocal8Bit("请选择性别"));return;}
    QString P=ui->phone->text();

    int n=ui->Box_class->currentIndex();
    if(n==0){QMessageBox::information
                (this,QString::fromLocal8Bit("提示"),
                 QString::fromLocal8Bit("请选择班级"));return;}
     n--;
int a1,j1;
Handle::getId_key(j1,a1,LStu,Id);
if(j1<LStu.size())
{QMessageBox::information(this,QString::fromLocal8Bit("提示"),QString::fromLocal8Bit( "此学号已存在"));return;}
    QList<Student>&Stu=LStu[n];
    Add(Id,Name,Sex,P,Stu,n);

    ui->name->clear();
    ui->id->clear();
     ui->phone->clear();
     ui->boy->setCheckable(false);
     ui->girl->setCheckable(false);
     ui->boy->setCheckable(true);
     ui->girl->setCheckable(true);
     NewBoxInformation(1);

    QMessageBox::information(this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("添加成功"));

}
void Base::Query(long Id_key,QString Name_str,int Box_n,QList<QList<Student>>lStu,int classId,QList<CClass>lc){
    ui->tableWidget1->clearContents();
    ui->tableWidget1->verticalHeader()->setVisible(false);
     ui->tableWidget1->setEditTriggers(QAbstractItemView::NoEditTriggers);


     if(Box_n==0){
      int j,a;
      Handle::getId_key(j,a,LStu,Id_key);
      if(j==lc.size()){QMessageBox::information
                  (this, QString::fromLocal8Bit("提示"),
                   QString::fromLocal8Bit("无此学生"));return;}
      Student&S=lStu[j][a];
        QString ID=QString::number(S.id,10);
        QString Name= S.name;
        QString Sex= S.sex;
        QString ClassName=lc[S.classId].className;
        QString Phone= S.phone;
        ui->tableWidget1->setRowCount(1);
        ui->tableWidget1->setColumnCount(5);

       QTableWidgetItem *item0 = new QTableWidgetItem(ID);
       ui->tableWidget1->setItem(0,0,item0);

       QTableWidgetItem *item1= new QTableWidgetItem(Name);
       ui->tableWidget1->setItem(0,1,item1);
       QTableWidgetItem *item2 = new QTableWidgetItem(Sex);
       ui->tableWidget1->setItem(0,2,item2);
       QTableWidgetItem *item3 = new QTableWidgetItem(ClassName);
       ui->tableWidget1->setItem(0,3,item3);
      ui->tableWidget1->resizeColumnToContents(3);
      QTableWidgetItem *item4 = new QTableWidgetItem(Phone);
      ui->tableWidget1->setItem(0,4,item4);



    }
    else if(Box_n==1){



         QList<Student>Stu;
        for(int j=0;j<lc.size();j++){


        QList<int>list_t=Handle::Namesearch(Name_str,lStu[j]);
        if(list_t.size()==0)continue;
        else {for(int i=0;i<list_t.size();i++)
            Stu.append(lStu[j][list_t[i]]);}
        }
        if(Stu.size()==0)
        {QMessageBox::information(this, QString::fromLocal8Bit("提示"),
                                  QString::fromLocal8Bit("无此学生"));return;}
        else {
            ui-> tableWidget1->setRowCount(Stu.size());
            ui->tableWidget1->setColumnCount(5);
            for(int i=0;i<Stu.size();i++)
            {


                QString Id=QString::number(Stu[i].id,10);
                QString Name= Stu[i].name;
                QString Sex= Stu[i].sex;
                QString Phone= Stu[i].phone;
                 QString ClassName=LC[Stu[i].classId].className;
               QTableWidgetItem *item0 = new QTableWidgetItem(Id);
               ui->tableWidget1->setItem(i,0,item0);
               QTableWidgetItem *item1= new QTableWidgetItem(Name);
               ui->tableWidget1->setItem(i,1,item1);
               QTableWidgetItem *item2 = new QTableWidgetItem(Sex);
               ui->tableWidget1->setItem(i,2,item2);
               QTableWidgetItem *item3 = new QTableWidgetItem(ClassName);
               ui->tableWidget1->setItem(i,3,item3);

             QTableWidgetItem *item4 = new QTableWidgetItem(Phone);
            ui->tableWidget1->setItem(i,4,item4);
        }
    }}
else if(Box_n==2){

        int a=classId;
        ui-> tableWidget1->setRowCount(lStu[a].size());
        ui->tableWidget1->setColumnCount(5);
        QList<Student>&Stu=lStu[a];
        for(int i=0;i<Stu.size();i++){

            QString Id=QString::number( Stu.at(i).id);
            QString Name= Stu[i].name;
            QString Sex= Stu[i].sex;
             QString ClassName=LC[a].className;
            QString Phone= Stu[i].phone;
           QTableWidgetItem *item0 = new QTableWidgetItem(Id);
           ui->tableWidget1->setItem(i,0,item0);
           QTableWidgetItem *item1= new QTableWidgetItem(Name);
           ui->tableWidget1->setItem(i,1,item1);
           QTableWidgetItem *item2 = new QTableWidgetItem( Sex);
           ui->tableWidget1->setItem(i,2,item2);
           QTableWidgetItem *item3 = new QTableWidgetItem(ClassName);
           ui->tableWidget1->setItem(i,3,item3);
           QTableWidgetItem *item4 = new QTableWidgetItem(Phone);
           ui->tableWidget1->setItem(i,4,item4);

    }}

    }




void Base::on_qBtn_clicked()
{

if(ui->qEdit->text().isEmpty()){QMessageBox::information
            (this,QString::fromLocal8Bit("提示"),
             QString::fromLocal8Bit("请输入信息"));return;}
    if(ui->qBox->currentIndex()==0){

        bool ok = 0;
        long Id=ui->qEdit->text().toLong(&ok, 10);
        Query(Id,"",0,LStu,0,LC);
    }
    else if(ui->qBox->currentIndex()==1){
        Query(0,ui->qEdit->text(),1,LStu,0,LC);
    }

}
void Base::Delete(int a,QList<Student>&Stu){

    Stu.removeAt(a);

}



void Base::on_dBtn_clicked()
{
    if(ui->rEdit->text().isEmpty()){QMessageBox::information
                (this,QString::fromLocal8Bit("提示"),
                 QString::fromLocal8Bit("学号为空"));ui->boy->setCheckable(false);
        ui->girl->setCheckable(false);
        ui->boy->setCheckable(true);
        ui->girl->setCheckable(true);return;}
    bool ok = 0;
    long key=ui->rEdit->text().toLong(&ok, 10);

    int j;
    int a;
    Handle::getId_key(j,a,LStu,key);

    if(j==LC.size()){QMessageBox::information
                (this,QString::fromLocal8Bit("提示"),
                 QString::fromLocal8Bit("无此学生"));return;}
     Delete(a,LStu[j]);
     ui->rEdit->clear();
     ui->id->clear();
     ui->name->clear();
     ui->phone->clear();
     ui->boy->setCheckable(false);
     ui->girl->setCheckable(false);
     ui->boy->setCheckable(true);
     ui->girl->setCheckable(true);
     NewBoxInformation(1);
     QMessageBox::information
                     (this,QString::fromLocal8Bit("提示"),
                      QString::fromLocal8Bit("删除成功"));
}
void Base::Revise(long Id,QString Name,QString Sex,QString Phone,int ClassId,int j,int a,QList<QList<Student>>&lStu){
    Student S=lStu[j][a];


 if(Id!=-1)
 {
if(ClassId==-1){
    int a1,j1;
    Handle::getId_key(j1,a1,lStu,Id);
    if(j1<lStu.size())
     { QMessageBox::information
                 (this,QString::fromLocal8Bit("提示"),
                  QString::fromLocal8Bit("修改的学号已存在"));return;}

     lStu[j].removeAt(a);
     S.id=Id;
     Insert(lStu[j],S);

}
else {
    int j1,a1;
    Handle::getId_key(j1,a1,lStu,Id);
    if(j1<lStu.size())
     { QMessageBox::information
                 (this,QString::fromLocal8Bit("提示"),
                  QString::fromLocal8Bit("修改的学号已存在"));return;}
    lStu[j].removeAt(a);
    S.id=Id;
    S.classId=ClassId;
    S.score.clear();
    for(int i=0;i<LC[ClassId].Sub.size();i++)
        S.score.append(-1);
    Insert(lStu[ClassId],S);




}
 }
else {
     if(ClassId!=-1){
         lStu[j].removeAt(a);
         S.classId=ClassId;
         S.score.clear();
         for(int i=0;i<LC[ClassId].Sub.size();i++)
             S.score.append(-1);
         Insert(lStu[ClassId],S);

     }

 }
int k=j;
if(ClassId!=-1)k=ClassId;
int a2=Handle::BinSearch(S.id,lStu[k]);

Student&S1=lStu[k][a2];
if(!Name.isEmpty()){
    S1.name=Name;}
if(!Sex.isNull())
    S1.sex=Sex;
if(!Phone.isEmpty())
    S1.phone=Phone;
}

void Base::on_rBtn_clicked()
{
    if(ui->rEdit->text().isEmpty()){QMessageBox::information
                (this,QString::fromLocal8Bit("提示"),
                 QString::fromLocal8Bit("学号为空"));
        ui->boy->setCheckable(false);
        ui->girl->setCheckable(false);
        ui->boy->setCheckable(true);
        ui->girl->setCheckable(true);return;}
    bool ok = 0;
    long key=ui->rEdit->text().toLong(&ok, 10);
    int j;
    int a;
    Handle::getId_key(j,a,LStu,key);
    if(j==LC.size()){QMessageBox::information
                (this,QString::fromLocal8Bit("提示"),
                 QString::fromLocal8Bit("无此学生"));return;}
    QString Sex;
   if(ui->boy->isChecked())
       Sex=ui->boy->text();
   else if(ui->girl->isChecked())
       Sex=ui->girl->text();
   long Id=-1;
if(!ui->id->text().isEmpty()){
   Id=ui->id->text().toLong(&ok);
   if(Id<=1000000000||Id>=10000000000){QMessageBox::information
               (this,QString::fromLocal8Bit("提示"),
                QString::fromLocal8Bit("学号不符合规范，请重新输入"));return;}

}
   int n=ui->Box_class->currentIndex();
     n--;
   Revise(Id,ui->name->text(),Sex,ui->phone->text(),n,j,a,LStu);

    ui->rEdit->clear();
    ui->id->clear();
    ui->name->clear();
    ui->phone->clear();
    ui->boy->setCheckable(false);
    ui->girl->setCheckable(false);
    ui->boy->setCheckable(true);
    ui->girl->setCheckable(true);
    NewBoxInformation(1);
    QMessageBox::information
                   (this,QString::fromLocal8Bit("提示"),
                    QString::fromLocal8Bit("修改成功"));
}


void Base::on_phoneBtn_clicked()
{
    int n=ui->Box_class_2->currentIndex();
    if(n==0){QMessageBox::information
                (this,QString::fromLocal8Bit("提示"),
                 QString::fromLocal8Bit("请选择班级"));return;}
    n--;
   Handle::WritePhone(LC,LStu,n);
   QMessageBox::information
                  (this,QString::fromLocal8Bit("提示"),
                   QString::fromLocal8Bit("导出成功"));
}


void Base::on_qpasswordBtn_clicked()
{if(ui->Edit_account->text().isEmpty()){QMessageBox::information
                (this,QString::fromLocal8Bit("提示"),
                 QString::fromLocal8Bit("请输入账号"));return;}
    if(ui->radioButton_stu->isChecked()){
        bool ok = 0;
        long key=ui->Edit_account->text().toLong(&ok, 10);
        int j;
        int a;
        Handle::getId_key(j,a,LStu,key);
        if(j==LC.size()){QMessageBox::information
                    (this,QString::fromLocal8Bit("提示"),
                     QString::fromLocal8Bit("无此账号"));return;}
        Student&S=LStu[j][a];
        ui->label_old->setText(S.password);

    }
    else if(ui->radioButton_tea->isChecked())
    {
        QString Id=ui->Edit_account->text();
                int i;
                int j;
                int w=0;
                for(i=0;i<LC.size();i++){
                    for(j=0;j<LC[i].Sub.size();j++){
                    if(Id==LC[i].Sub[j].teacher.id){w=1;break;}

                    }
                    if(w==1)break;

                }
                if(i<LC.size()){
                    ui->label_old->setText(LC[i].Sub[j].teacher.password);
                }
                else QMessageBox::information
                        (this,QString::fromLocal8Bit("提示"),
                         QString::fromLocal8Bit("无此账号"));

    }
    else if(ui->radioButton_m->isChecked()){
        ui->label_old->setText(LC[0].manager.password);}

    else QMessageBox::information
            (this,QString::fromLocal8Bit("提示"),
             QString::fromLocal8Bit("请选择身份信息"));
}


void Base::on_rpass_ok_btn_clicked()
{
     if(ui->Edit_new->text().isEmpty()){QMessageBox::information
                 (this,QString::fromLocal8Bit("提示"),
                  QString::fromLocal8Bit("密码不能为空"));return;}
    if(ui->radioButton_stu->isChecked()){bool ok = 0;
        long key=ui->Edit_account->text().toLong(&ok, 10);
        int j;
        int a;
        Handle::getId_key(j,a,LStu,key);
        if(j==LC.size()){QMessageBox::information
                    (this,QString::fromLocal8Bit("提示"),
                     QString::fromLocal8Bit("无此账号"));return;}

        Student&S=LStu[j][a];
    S.password=ui->Edit_new->text();

    ui->Edit_new->clear();
    QMessageBox::information
                     (this,QString::fromLocal8Bit("提示"),
                      QString::fromLocal8Bit("密码修改成功"));
    }
    else if(ui->radioButton_tea->isChecked())
    {

              int w=0;
              for(int i=0;i<LC.size();i++)
                  for(int j=0;j<LC[i].Sub.size();j++)
                  {
                      if(LC[i].Sub[j].teacher.id==ui->Edit_account->text())
                          {LC[i].Sub[j].teacher.password=ui->Edit_new->text();w=1;}
                  }

              if(w==1) {
                  ui->Edit_new->clear();
                  QMessageBox::information
                      (this,QString::fromLocal8Bit("提示"),
                       QString::fromLocal8Bit("密码修改成功"));}


                else QMessageBox::information
                      (this,QString::fromLocal8Bit("提示"),
                       QString::fromLocal8Bit("无此账号"));

    }
    else if(ui->radioButton_m->isChecked()){
       for(int i=0;i<LC.size();i++)
           LC[i].manager.password=ui->Edit_new->text();

       ui->Edit_new->clear();
       QMessageBox::information
                             (this,QString::fromLocal8Bit("提示"),
                              QString::fromLocal8Bit("密码修改成功"));
}
     else QMessageBox::information
            (this,QString::fromLocal8Bit("提示"),
             QString::fromLocal8Bit("请选择身份信息"));

}

void Base::on_add_class_Btn_clicked()
{
    if(ui->lineEdit_class->text().isEmpty())
    {QMessageBox::information
                (this,QString::fromLocal8Bit("提示"),
                 QString::fromLocal8Bit("班级名称不能为空"));return;}
    int a=Handle::Namesearch(ui->lineEdit_class->text(),LC);
    if(a<LC.size()){QMessageBox::information
                (this,QString::fromLocal8Bit("提示"),
                 QString::fromLocal8Bit("该班级已存在"));return;}
   CClass C;
   C.className=ui->lineEdit_class->text();
   LC.append(C);
   QList<Student>Stu;
   LStu.append(Stu);

  ui->lineEdit_class->clear();
  NewBoxInformation(2);
  QMessageBox::information
                        (this,QString::fromLocal8Bit("提示"),
                         QString::fromLocal8Bit("添加成功"));

}
void Base::NewBoxInformation(int i){
    if(i==2){
        ui->Box_class_2->clear();
        ui->Box_class_2->insertItem(0,QString::fromLocal8Bit("请选择班级"));
        for(int j=0;j<LC.size();j++)
            ui->Box_class_2->insertItem(j+1,LC[j].className);
    }
    else if(i==1){
        ui->Box_class->clear();
         ui->Box_class->insertItem(0,QString::fromLocal8Bit("请选择班级"));
        for(int j=0;j<LC.size();j++)
            ui->Box_class->insertItem(j+1,LC[j].className);
    }
    else if(i==3){
        ui->Box_class_3->clear();
         ui->Box_class_3->insertItem(0,QString::fromLocal8Bit("请选择班级"));
        for(int j=0;j<LC.size();j++)
            ui->Box_class_3->insertItem(j+1,LC[j].className);
    }
}
void Base::on_revise_class_Btn_clicked()
{

    if(ui->lineEdit_class->text().isEmpty())
    {QMessageBox::information
                (this,QString::fromLocal8Bit("提示"),
                 QString::fromLocal8Bit("班级名称不能为空"));return;}
    int n=ui->Box_class_2->currentIndex();
    if(n==0){QMessageBox::information
                (this,QString::fromLocal8Bit("提示"),
                 QString::fromLocal8Bit("请选择班级"));return;}

    int a=Handle::Namesearch(ui->lineEdit_class->text(),LC);
    if(a<LC.size()){QMessageBox::information
                (this,QString::fromLocal8Bit("提示"),
                 QString::fromLocal8Bit("该班级已存在"));return;}
    n--;
    LC[n].className=ui->lineEdit_class->text();
    ui->lineEdit_class->clear();
    NewBoxInformation(2);
    QMessageBox::information
                          (this,QString::fromLocal8Bit("提示"),
                           QString::fromLocal8Bit("修改成功"));
}

void Base::on_Del_class_Btn_clicked()
{
    int n=ui->Box_class_2->currentIndex();
    n--;
    LC.removeAt(n);
    LStu.removeAt(n);
     ui->lineEdit_class->clear();
    NewBoxInformation(2);
    QMessageBox::information
                          (this,QString::fromLocal8Bit("提示"),
                           QString::fromLocal8Bit("删除成功"));

}

void Base::on_tabWidget_currentChanged(int index)
{if(index==0)NewBoxInformation(3);
    else if(index==1)
    {
       NewBoxInformation(1);
    }
    else if(index==3){
        ui->Edit_new->clear();
       NewBoxInformation(2);
    }

}
void Base::Insert(QList<Student>&Stu,Student&S){
    if(Stu.size()==0)Stu.append(S);
    else{int a=Handle::InsertId(S.id,Stu,0,Stu.size()-1);
    Stu.insert(a,S);}
}

void Base::on_qBtn_class_clicked()
{int n=ui->Box_class_3->currentIndex();
    if(n==0) {QMessageBox::information
            (this,QString::fromLocal8Bit("提示"),
             QString::fromLocal8Bit("请选择班级"));return;}
    n--;
        Query(0,"",2,LStu,n,LC);

}
