#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //cout<<"hhh";
    connect(ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(EaddDayTab()));
    connect(ui->tabWidget,SIGNAL(currentChanged(int)),this,SLOT(EDayTabChange(int)));
    connect(ui->pushButton_2,SIGNAL(clicked(bool)),this,SLOT(EaddHeadEvent()));
    this->Init();
}

void MainWindow::Init()
{
    QString str;
    str.sprintf("%s %i","Day",ui->tabWidget->count()+1);
    EDayTab* tab = new EDayTab(str,ui->tabWidget->count()+1,NULL);
    ui->tabWidget->addTab(tab,str);
    ui->tabWidget->setCurrentIndex(ui->tabWidget->count()-1);
}

void MainWindow::EaddDayTab()
{
    QString str;
    str.sprintf("%s %i","Day",ui->tabWidget->count()+1);
    EDayTab* tab = new EDayTab(str,ui->tabWidget->count()+1,NULL);
    ui->tabWidget->addTab(tab,str);
    ui->tabWidget->setCurrentIndex(ui->tabWidget->count()-1);

}

void MainWindow::EDayTabChange(int index)
{
    ui->lineEdit->setText(DaylineManager::getInstance()->day.at(index)->name);
    QString str;
    str.sprintf("%i",index);
    ui->lineEdit_2->setText(str);
}

void MainWindow::EaddHeadEvent()
{
    DaylineManager::getInstance()->day.at(ui->tabWidget->currentIndex())->AddHeadEvent();
    /*QLabel *lab = new QLabel(DaylineManager::getInstance()->day.at(ui->tabWidget->currentIndex())->DayWid);
    lab->setText("23");
    lab->show();*/
}

MainWindow::~MainWindow()
{
    delete ui;
}
