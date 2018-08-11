#include "edaytab.h"

EDayTab::EDayTab(QString strName,int index,QWidget *parent) : QWidget(parent)
{
    Dayline* day = new Dayline(strName,index,this);
    eventbox = new EventBox(this);
    eventbox->hide();
}
