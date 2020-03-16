#ifndef MAINWINDOWMANAGER_H
#define MAINWINDOWMANAGER_H
#include "mgrade.h"
#include <QMainWindow>
#include "base.h"
#include"handle.h"
#include<QString>
extern QList<QList<Student>>LStu;
extern QList<CClass>LC;
namespace Ui {
class MainWindowManager;
}

class MainWindowManager : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindowManager(QWidget *parent = 0);
    ~MainWindowManager();



private slots:
    void on_baseBtn_clicked();

    void on_gBtn_clicked();



private:
    Ui::MainWindowManager *ui;
};

#endif // MAINWINDOW3_H
