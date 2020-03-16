#ifndef HANDLE_H
#define HANDLE_H
#include <QList>
#include "cclass.h"
#include"student.h"
#include<QMessageBox>
#include <QTextStream>
#include<QDataStream>
#include<QFile>
#include<QString>
#include<QDir>
class Handle
{
public:
    Handle();
    static  QList<CClass>Readf();
    static  QList<Student>Readf(CClass C);
    static void Writef(const CClass&C,const QList<Student>&Stu);
    static void Writef(QList<CClass>lcc);
    static void WritePhone(QList<CClass>C,QList<QList<Student>>Stu,int n);
    static void WriteT(QList<Student>Stu,CClass C,int k);//全班各科
    static void WriteT(QList<Student>Stu,Student S,CClass C);//学生个人
    static int BinSearch(long key,QList<Student>Stu);
    static QList<int>Namesearch(QString Name,QList<Student>Stu);
    static int Namesearch(QString Name,QList<Subject>Sub);
    static int Namesearch(QString Name,QList<CClass>lc);
    static int InsertId(long key,QList<Student>Stu,int s,int e);
    static double getGP(double score);
    static void Sort(QList<Student>&Stu,QList<int>&Index,int k,int start,int end);
    static int count(QList<Student>&Stu,int k,double low,double high);
    static QList<int> count(QList<Student>&Stu,int k);
    static int getrank(Student S,QList<Student>Stu,int k);
    static void getId_key(int&j,int&a,QList<QList<Student>>lStu,long Id);

};

#endif // HANDLE_H
