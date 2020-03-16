#include "mainwindowstu.h"
#include "ui_mainwindowstu.h"

MainWindowStu::MainWindowStu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindowStu)
{
    ui->setupUi(this);

}

MainWindowStu::~MainWindowStu()
{
  Handle::Writef(LC[SS.classId],LSStu);
    delete ui;
}

void MainWindowStu::on_tabWidget_stusub_currentChanged(int index)
{

    if(index==1){
        ui->comboBox_stusub->clear();

        ui->comboBox_stusub->insertItem(0,QString::fromLocal8Bit("全部"));

        for(int i=0;i<LC[SS.classId].Sub.size();i++)
        ui->comboBox_stusub->insertItem(i+1,LC[SS.classId].Sub[i].subname);
    }

    else if(index==2){

        ui->label_id->setText(QString::number(SS.id));
        ui->label_name->setText(SS.name);
        ui->label_sex->setText(SS.sex);
        ui->label_phone->setText(SS.phone);
        ui->label_class->setText(LC[SS.classId].className);
    }

}

void MainWindowStu::on_stusubBtn_clicked()
{
ui->tableWidget_stug->verticalHeader()->setVisible(false);
ui->tableWidget_stug->clearContents();
    if(ui->comboBox_stusub->currentIndex()==0){

          int k=LC[SS.classId].Sub.size();

        ui->tableWidget_stug->setColumnCount(4);
        ui->tableWidget_stug->setRowCount(k);
        for(int i=0;i<k;i++){
            QTableWidgetItem *item01 = new QTableWidgetItem(LC[SS.classId].Sub[i].subname);
            ui->tableWidget_stug->setItem(i,0,item01);
            QTableWidgetItem *item02 = new QTableWidgetItem(QString::number(SS.score[i]));
            ui->tableWidget_stug->setItem(i,1,item02);
            int r=Handle::getrank(SS,LSStu,i);
            QTableWidgetItem *item03 = new QTableWidgetItem(QString::number(r));
            ui->tableWidget_stug->setItem(i,2,item03);
            QString GP=QString::number(Handle::getGP(SS.score[i]),'f',2);
            QTableWidgetItem *item04 = new QTableWidgetItem(GP);
            ui->tableWidget_stug->setItem(i,3,item04);
        }
    }
    else{

        ui->tableWidget_stug->setColumnCount(4);
        ui->tableWidget_stug->setRowCount(1);
        int k=ui->comboBox_stusub->currentIndex();
        k--;

        QTableWidgetItem *item01 = new QTableWidgetItem(LC[SS.classId].Sub[k].subname);
        ui->tableWidget_stug->setItem(0,0,item01);
        QTableWidgetItem *item02 = new QTableWidgetItem(QString::number(SS.score[k]));
        ui->tableWidget_stug->setItem(0,1,item02);
        int r=Handle::getrank(SS,LSStu,k);
        QTableWidgetItem *item03 = new QTableWidgetItem(QString::number(r));
        ui->tableWidget_stug->setItem(0,2,item03);
        QString GP=QString::number(Handle::getGP(SS.score[k]),'f',2);
        QTableWidgetItem *item04 = new QTableWidgetItem(GP);
        ui->tableWidget_stug->setItem(0,3,item04);
    }

}

void MainWindowStu::on_revisephoneBtn_clicked()
{
    revisePhone*r=new revisePhone(this);
        r->show();
}

void MainWindowStu::on_rpnewBtn_clicked()
{

    ui->label_phone->setText(SS.phone);

}



void MainWindowStu::on_outgradeBtn_clicked()
{
    Handle::WriteT(LSStu,SS,LC[SS.classId]);
    QMessageBox::information
                   (this,QString::fromLocal8Bit("提示"),
                    QString::fromLocal8Bit("导出成功"));
}



void MainWindowStu::on_rpassword_Btn_clicked()
{
    rstuP*rs=new rstuP();
    rs->show();
}

void MainWindowStu::on_qsubBtn_clicked()
{
    int k=LC[SS.classId].Sub.size();
    ui->tableWidget_stu_sub->verticalHeader()->setVisible(false);

    ui->tableWidget_stu_sub->clearContents();
    ui->tableWidget_stu_sub->setColumnCount(3);
    ui->tableWidget_stu_sub->setRowCount(k);
    for(int i=0;i<k;i++){
        QTableWidgetItem *item01 = new QTableWidgetItem(LC[SS.classId].Sub[i].subname);
        ui->tableWidget_stu_sub->setItem(i,0,item01);
        QTableWidgetItem *item02 = new QTableWidgetItem(QString::number(LC[SS.classId].Sub[i].credit,'f',1));
        ui->tableWidget_stu_sub->setItem(i,1,item02);
        QTableWidgetItem *item03 = new QTableWidgetItem(LC[SS.classId].Sub[i].teacher.name);
        ui->tableWidget_stu_sub->setItem(i,2,item03);

}
}
