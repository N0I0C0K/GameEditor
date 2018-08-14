#include "edaytab.h"
#include"eventwidget.h"

EDayTab::EDayTab(QString strName,int index,QWidget *parent) : QWidget(parent)
{
    Dayline* day = new Dayline(strName,index,this);
    this->escroll = new QScrollArea(this);
    this->eventwidget = new EventWidget(this);
    this->eventwidget->move(0,0);
    this->eventwidget->resize(2000,2000);
    this->escroll->setWidget(this->eventwidget);
    this->escroll->setWidgetResizable(false);
    this->escroll->move(0,0);
    this->escroll->setBackgroundRole(QPalette::Shadow);
    qDebug()<<"escroll heigh:"<<this->escroll->size().height()<<"width:"<<this->escroll->size().width();
    //this->escroll->setMinimumSize(this->size().height()+20,this->size().width()-30);
    //this->escroll->resize(500,610);
    this->escroll->resize(this->size().height(),this->size().width());
    qDebug()<<"escroll heigh:"<<this->escroll->size().height()<<"width:"<<this->escroll->size().width();
    //this->escroll->widget()->resize(500,500);
    //this->escroll->setMinimumSize(this->size());
    //this->escroll->resize(this->size());
    /*eventbox = new EventBox(this);
    eventbox->hide();*/
}

void EDayTab::resizeEvent(QResizeEvent *event)
{
    this->escroll->resize(this->size());
}
