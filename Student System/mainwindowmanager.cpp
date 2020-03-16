#include "mainwindowmanager.h"
#include "ui_mainwindowmanager.h"


MainWindowManager::MainWindowManager(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindowManager)
{
    ui->setupUi(this);
}

MainWindowManager::~MainWindowManager()
{

        delete ui;
    if(LC.size()!=0){
    Handle::Writef(LC);

    for(int j=0;j<LC.size();j++)
        Handle::Writef(LC[j],LStu[j]);}

}


void MainWindowManager::on_baseBtn_clicked()
{
    Base*b=new Base(this);
    b->show();
}

void MainWindowManager::on_gBtn_clicked()
{  mgrade*m=new mgrade(this);
    m->show();

}

