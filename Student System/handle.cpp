#include "handle.h"
Handle::Handle()
{


}
QList<CClass> Handle::Readf(){
    QList<CClass>lcc;
     QString dir_str = QString("C:\\Stumanager_data\\");
       QFile tmpfile(dir_str+"class.dat");
         if(!tmpfile.open(QIODevice::ReadOnly))return lcc;
    QDataStream in(&tmpfile);
    while(!in.atEnd()){
        CClass C;
        QString K;
          in >>C.className>>C.manager.password>>K;
                bool ok = 0;
                int k=K.toInt(&ok);

    for(int j=0;j<k;j++)
    {
     Subject sub;
     QString Cre;
     in>>Cre>>sub.subname>>sub.teacher.name>>sub.teacher.id>>sub.teacher.password;
    sub.credit=Cre.toDouble(&ok);
    C.Sub.append(sub);
    }
       lcc.append(C);
    }

     tmpfile.close();
    return lcc;
}


QList<Student>Handle::Readf(CClass C){
   QList<Student>Stu;
   QString dir_str =QString("C:\\Stumanager_data\\");
      QFile tmpfile(dir_str+C.className+".dat");
     if(!tmpfile.open(QIODevice::ReadOnly))return Stu;
QDataStream in(&tmpfile);
while(!in.atEnd()){
    Student S;
        QString Id;
        QString ClassID;
            in >>Id>>S.name>>S.password>>S.phone>>S.sex>>ClassID;
            bool ok=0;
            S.id=Id.toLong(&ok);
             S.classId=ClassID.toInt(&ok);
             int k=C.Sub.size();
for(int j=0;j<k;j++)
{

 QString Score;
in>>Score;
double sc=Score.toDouble(&ok);
S.score.append(sc);
}
   Stu.append(S);
}

 tmpfile.close();
return Stu;
}
void Handle::Writef(QList<CClass>lcc){
    QString dir_str =QString("C:\\Stumanager_data\\");

    QDir dir;
       if (!dir.exists(dir_str))
       {
           dir.mkpath(dir_str);
       }
    QFile file(dir_str+"class.dat");
        file.open(QIODevice::WriteOnly|QIODevice::Truncate);
      QDataStream out(&file);
for(int p=0;p<lcc.size();p++){
int k=lcc[p].Sub.size();
QString K=QString::number(k);

out<<lcc[p].className<<lcc[p].manager.password<<K;

for(int j=0;j<k;j++)
{

    QString C=QString::number(lcc[p].Sub[j].credit,'f',1);

   out<<C<<lcc[p].Sub[j].subname<<lcc[p].Sub[j].teacher.name<<lcc[p].Sub[j].teacher.id<<lcc[p].Sub[j].teacher.password;
}

       }
        file.close();
}
void Handle::Writef(const CClass&C,const QList<Student>&Stu){
    QString dir_str = QString("C:\\Stumanager_data\\");


    QFile file(dir_str+C.className+".dat");
  file.open(QIODevice::WriteOnly|QIODevice::Truncate);
   QDataStream out(&file);
       int k=C.Sub.size();
       for(int i=0;i<Stu.size();i++){
           QString Id=QString::number(Stu[i].id);
           QString ClassID=QString::number(Stu[i].classId);
               out <<Id<<Stu[i].name<<Stu[i].password<<Stu[i].phone<<Stu[i].sex<<ClassID;
for(int j=0;j<k;j++)
{
    QString Score=QString::number(Stu[i].score[j]);
   out<<Score;
}
       }
        file.close();

}
void Handle::WritePhone(QList<CClass>C,QList<QList<Student>>Stu,int n){
    QString dir_str =QString::fromLocal8Bit( "C:\\Stumanager_班级通讯录\\");


     QDir dir;
        if (!dir.exists(dir_str))
        {
            dir.mkpath(dir_str);
        }
    QFile write_p(dir_str+C[n].className+QString::fromLocal8Bit("班级通讯.txt"));

       write_p.open(QIODevice::WriteOnly|QIODevice::Truncate|QIODevice::Text);
       QTextStream out(&write_p);
       QString str1=QString::fromLocal8Bit("学号");
       QString str2=QString::fromLocal8Bit("姓名");
       QString str3=QString::fromLocal8Bit("手机");
      out<<qSetFieldWidth(20)<<str1<<str2 <<str3 <<endl;

       for ( int i=0; i<Stu[n].size(); i++ )
       {
           QString Id=QString::number(Stu[n][i].id);
           out<<qSetFieldWidth(18)<<Id
             <<Stu[n][i].name<<Stu[n][i].phone<<endl;

       }

       write_p.close();
    }


 int Handle:: BinSearch(long key,QList<Student>Stu){
    int start=0;
    int end=Stu.size()-1;
    while(start<=end){
                int mid=start+(end-start)/2;
                if(key<Stu.at(mid).id){
                    end=mid-1;
                }else if(key>Stu.at(mid).id){
                    start=mid+1;
                }else{
                    return mid;
                }
            }
     return -1;
}

 int Handle::InsertId(long key,QList<Student>Stu,int s,int e){
     if(key>Stu[e].id)return e+1;
     else if(key<Stu[s].id)return s;
     else if((e-s)<=1)return e;
   else {
         int m=s+(e-s)/2;
         if(key>Stu[m].id)
             e=InsertId(key,Stu,m,e);
         else e=InsertId(key,Stu,s,m);
          return e;
     }


 }
QList<int> Handle::Namesearch(QString Name,QList<Student>Stu){
      QList<int>list;
      for(int i=0;i<Stu.size();i++)
      {
          if(Stu.at(i).name==Name)
              list.append(i);
      }
      return list;
 }
int Handle::Namesearch(QString Name,QList<Subject>Sub){
int i=0;
    for(i=0;i<Sub.size();i++)
   { if(Sub.at(i).subname==Name)
        break;
    }
    return i;

}
double Handle:: getGP(double n){
    double gp;

    if(n>=90)gp=4.0;
    else if(n>=85)gp=3.7;
    else if(n>=82)gp=3.3;
    else if(n>=78)gp=3.0;
    else if(n>=75)gp=2.7;
    else if(n>=71)gp=2.3;
    else if(n>=66)gp=2.0;
    else if(n>=62)gp=1.7;
    else if(n>=60)gp=1.3;
    else gp=0;
    return gp;
}
void Handle::Sort(QList<Student>&Stu,QList<int>&Index,int k,int start,int end){
if(start>=end)return;
int i=start;
int j=end;
double key=Stu[Index[i]].score[k];
int p=Index[i];
while (i < j)
{
    while (i < j&&Stu[Index[j]].score[k]<= key)
    {
        j--;
    }
   Index[i]=Index[j];
    while (i < j&&Stu[Index[i]].score[k] > key)
    {
        i++;
    }
     Index[j]=Index[i];


}
Index[i] = p;
Sort(Stu,Index,k,start,i-1);
Sort(Stu,Index,k,i+1,end);

}
int Handle::count(QList<Student>&Stu,int k,double low,double high){
    int num=0;
    for(int i=0;i<Stu.size();i++)
    {
        if(Stu[i].score[k]>=low&&Stu[i].score[k]<high)num++;
    }
    return num;
}
void Handle::WriteT(QList<Student>Stu,CClass C,int k){

    QString dir_str =QString::fromLocal8Bit("C:\\Stumanager_班级成绩信息\\");


     QDir dir;
        if (!dir.exists(dir_str))
        {
            dir.mkpath(dir_str);
        }

    if(k==-1){
        QFile write_p(dir_str+C.className+QString::fromLocal8Bit("全班各科成绩.txt"));

           write_p.open(QIODevice::WriteOnly|QIODevice::Truncate|QIODevice::Text);
           QTextStream out(&write_p);
           QString str1=QString::fromLocal8Bit("学号");
           QString str2=QString::fromLocal8Bit("姓名");

          out<<qSetFieldWidth(10)<<str1
            <<str2;
          for(int i=0;i<C.Sub.size();i++)
              out<<qSetFieldWidth(10) <<C.Sub[i].subname;
          out<<endl;

           for ( int i=0; i<Stu.size(); i++ )
           {
               QString Id=QString::number(Stu.at(i).id);
               out<<qSetFieldWidth(10)<<Id
                 <<Stu.at(i).name;
               for(int j=0;j<Stu[i].score.size();j++){
                  QString score=QString::number(Stu[i].score[j]);
                   out<<qSetFieldWidth(10) <<score;
               }
               out<<endl;

           }

           write_p.close();
    }

    else{
        QFile write_p(dir_str+C.className+QString::fromLocal8Bit("全班")+C.Sub[k].subname+QString::fromLocal8Bit("成绩.txt"));

           write_p.open(QIODevice::WriteOnly|QIODevice::Truncate|QIODevice::Text);
           QTextStream out(&write_p);
           QString str1=QString::fromLocal8Bit("学号");
           QString str2=QString::fromLocal8Bit("姓名");
           QString str3=QString::fromLocal8Bit("成绩");
           QString str4=QString::fromLocal8Bit("排名");
          out<<qSetFieldWidth(10) <<str1
            <<str2<<str3<<str4<<endl;
        QList<int>Index;
        for(int i=0;i<Stu.size();i++)
            Index.append(i);
        Sort(Stu,Index,k,0,Stu.size()-1);
           for (int i=0; i<Stu.size(); i++ )
           {Student S=Stu[Index[i]];
               QString Id=QString::number(S.id);
               QString score=QString::number(S.score[k]);
               QString rank=QString::number(i+1);
               out<<qSetFieldWidth(10)<<Id
                 <<S.name<<score<<rank<<endl;
           }

           write_p.close();
    }
}
void Handle::WriteT(QList<Student>Stu,Student S,CClass C){

    QString dir_str =QString::fromLocal8Bit ("C:\\Stumanager_个人成绩信息\\");


     QDir dir;
        if (!dir.exists(dir_str))
        {
            dir.mkpath(dir_str);
        }
         QString Id=QString::number(S.id);
        QFile write_p(dir_str+C.className+S.name+Id+QString::fromLocal8Bit("成绩.txt"));

            write_p.open(QIODevice::WriteOnly|QIODevice::Truncate|QIODevice::Text);
                   QTextStream out(&write_p);

        QString str1=QString::fromLocal8Bit("学科");
        QString str2=QString::fromLocal8Bit("成绩");
     QString str3=QString::fromLocal8Bit("排名");
        out<<qSetFieldWidth(10)<<str1
          <<str2<<str3<<endl;

         for(int j=0;j<S.score.size();j++)
         {

             int r=Handle::getrank(S,Stu,j);
             QString score=QString::number(S.score[j]);
            QString R=QString::number(r);

        out<<qSetFieldWidth(10)<<C.Sub[j].subname<<score<<R<<endl;
         }

         write_p.close();

}
QList<int> Handle::count(QList<Student>&Stu,int k){
    QList<int>num;
    int all=0;
    for(int i=0;i<5;i++)
        num.append(0);
    for(int i=0;i<Stu.size();i++)
    {if(Stu[i].score[k]>=90)num[0]++;

        else if(Stu[i].score[k]>=80)num[1]++;
        else if(Stu[i].score[k]>=70)num[2]++;

        else if(Stu[i].score[k]>=60)num[3]++;
        else num[4]++;
all+=Stu[i].score[k];

    }
    num.append(all);
    return num;
}
int Handle::Namesearch(QString Name,QList<CClass>lc){
    int i;
    for(i=0;i<lc.size();i++)
        if(lc[i].className==Name)break;
    return i;
}
int Handle::getrank(Student S,QList<Student>Stu,int k){
    int n=1;
    for(int i=0;i<Stu.size();i++)
    {if(S.score[k]<Stu[i].score[k])n++;
    }
    return n;
}
void Handle::getId_key(int&j,int&a,QList<QList<Student>>lStu,long Id){
    for(j=0;j<lStu.size();j++){
        a=Handle::BinSearch(Id,lStu[j]);
     if(a>=0)break;
    }

}
