#ifndef TEACHER_H
#define TEACHER_H
#include<QString>
class Teacher
{
public:
    Teacher();
    Teacher(QString Name,QString Id);
    QString name;
    QString id;
    QString password;
};

#endif // TEACHER_H
