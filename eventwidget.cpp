#include "eventwidget.h"
#include"eventbox.h"


EventWidget::EventWidget(QWidget *parent) : QWidget(parent)
{
    //this->escroll = new QScrollArea()
    this->eventbox = new EventBox(this);
    this->eventbox->hide();
}
