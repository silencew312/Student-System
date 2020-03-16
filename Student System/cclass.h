#ifndef CCLASS_H
#define CCLASS_H
#include<QList>
#include"subject.h"
#include<QString>
class CClass
{
public:
    CClass();
     QList<Subject>Sub;
     QString className;
     Teacher manager;
};

#endif // CCLASS_H
