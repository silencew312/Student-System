#ifndef SUBJECT_H
#define SUBJECT_H
#include<Qstring>
#include"teacher.h"

class Subject
{
public:
    QString subname;


    double credit;//学分

    Subject();
    Teacher teacher;
    Subject(QString SubName,double Credit,Teacher T);

};

#endif // SUBJECT_H
