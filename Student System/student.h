#ifndef STUDENT_H
#define STUDENT_H
#include "subject.h"
#include<QList>
#include <QString>
#include"cclass.h"
class Student
{
public:
      long id;
      QString name;
       QString sex;
       QString phone;
       QString password;
       int classId;
       QList<double>score;
       Student();
      Student(long Id,QString Name,QString Sex,QString Phone,int ClassId);
};

#endif // STUDENT_H
