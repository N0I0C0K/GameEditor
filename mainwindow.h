#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include<QMainWindow>
#include<QTreeWidgetItem>
#include<QPushButton>
#include<QTabWidget>
#include<QDockWidget>
#include<QLabel>
#include<QPainter>
#include<QImage>
#include"dayline.h"
#include"edaytab.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void Init();
    ~MainWindow();

public slots:
    void EaddDayTab();
    void EDayTabChange(int index);
    void EaddHeadEvent();
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
