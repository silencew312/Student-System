
#include "mainwindowstu.h"
#include <QApplication>
#include "loginD.h"
#include "mainwindowtea.h"
#include "mainwindowmanager.h"
#include<QList>
#include"student.h"
#include "cclass.h"
QList<CClass>LC;
QList<QList<Student>>LStu;
QList<Student>LSStu;
Student SS;
int A;//学生
QList<int>B;//学科
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);



    LoginD dlg;

    if (dlg.exec() == QDialog::Accepted)
    {if(dlg.CM==1){
             MainWindowStu SWin;
           SWin.show();
  return a.exec();}

    else if (dlg.CM==2)
    { MainWindowTea TWin;
        TWin.show();

        return a.exec();
    }
    else if (dlg.CM==3)
        {MainWindowManager MWin;
            MWin.show();
            return a.exec();
        }
    }
    else return 0;
    }


