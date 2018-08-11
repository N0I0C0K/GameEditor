#include "eventbox.h"

EventBox::EventBox(QWidget *parent)
{
    this->raise();
    this->setParent(parent);
    this->Init();
}

void EventBox::Init()
{
    this->layout = new QGridLayout(this);
    this->button1 = new QPushButton(tr("添加子类"));
    this->button2 = new QPushButton(tr("添加同类"));
    this->layout->addWidget(this->button1,0,0);
    this->layout->addWidget(this->button2,1,0);
    this->setLayout(this->layout);
    this->connect(button1,SIGNAL(pressed()),this,SLOT(Button1Press()));
}

void EventBox::Button1Press()
{
    EventlineManager::getInstance()->currentEvent->addNextEvent();
    this->raise();
    qDebug()<<"EventBox::Button1Press()";
}
