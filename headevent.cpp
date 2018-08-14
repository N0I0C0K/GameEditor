#include "headevent.h"
#include"eventwidget.h"
#include "dayline.h"

HeadEvent::HeadEvent(Dayline* dayline,HeadEvent* parentEvent)
{
    this->Day = dayline;
    this->eventwidget = this->Day->DayWid->eventwidget;
    //Day->DayWid->escroll->resize(500,500);
    if(parentEvent != NULL)
    {
        this->parentEvent = parentEvent;
        this->index = parentEvent->nextEvent.count();
    }
    //this->connect(this,SIGNAL(clicked(bool)),this,SLOT(LeftClick(bool )));
    this->setParent(this->eventwidget);
    this->setText("headevent");
    QFont font("黑体",8,8);
    this->setFont(font);
    this->move(0,(this->Day->DayWid->rect().height())/(Day->event.count()+2));
    this->show();
    //this->LeftClick();`
    qDebug()<<"HeadEvent::HeadEvent(Dayline* dayline),and now event creat,and event index:"<<this->index;
}

void HeadEvent::mousePressEvent(QMouseEvent *e)
{
    qDebug()<<"HeadEvent::mousePressEvent(QMouseEvent *e),press event index:"<<this->index;
    if(e->button() == Qt::RightButton)
    {
        EventlineManager::getInstance()->currentEvent = this;
        int x = this->x()+this->rect().width();
        int y = this->y();
        this->eventwidget->eventbox->move(x,y);
        this->eventwidget->eventbox->show();
        qDebug()<<"click";
        return;
    }
    else if(e->button() == Qt::LeftButton)
    {
        EventlineManager::getInstance()->currentEvent = this;
        if(this->parentEvent != NULL)
        {
            if(this->parentEvent->parentEvent != NULL)
            {

            }
            else
            {
                qDebug()<<"hide head event";
                for(int i=0;i<this->Day->event.count();i++)
                {
                    /*if(i != this->parentEvent->index)
                    {
                        HeadEvent* eve = this->Day->event.at(i);
                        eve->HideAllEvent();
                    }*/
                    if(i != this->parentEvent->index)
                    {
                        HeadEvent* eve = this->Day->event.at(i);
                        for(int j = 0;j<eve->nextEvent.count();j++)
                        {
                            HeadEvent *eve2 = eve->nextEvent.at(j);
                            eve2->HideAllEvent();
                        }
                    }
                }
                qDebug()<<"hide event complete";
            }
        }
    }
    qDebug()<<"_HeadEvent::mousePressEvent(QMouseEvent *e)";
    this->eventwidget->eventbox->hide();
}

void HeadEvent::addNextEvent()
{
    HeadEvent* ev = HeadEvent::create(this->Day,this);
    int h = (this->eventwidget->rect().height())/(this->nextEvent.length()+2);
    if(this->nextEvent.count() == 0)
    {
        ev->move(this->x()+this->width()+15,this->y());
    }
    else
    {
        for(int i = 0;i < this->nextEvent.count();i++)
        {
            this->nextEvent.at(i)->move(this->x()+this->width()+15,(i+1)*h);
        }
        ev->move(this->x()+this->width()+15,(this->nextEvent.count()+1)*h);
    }
    qDebug()<<"HeadEvent::addNextEvent()";
    this->nextEvent.insert(this->nextEvent.count(),ev);
    qDebug()<<"HeadEvent::nextEvent update,now count is:"<<this->nextEvent.count();
    qDebug()<<"and event index is:"<<ev->index;
    qDebug()<<"and nextEvent.at(index).index is"<<this->nextEvent.at(ev->index)->index;
    qDebug()<<"_HeadEvent::addNextEvent()";
    ev->show();
}

void HeadEvent::HideAllEvent(HeadEvent* ev)
{
    qDebug()<<"void HeadEvent::HideAllEvent(HeadEvent* ev),begin hide";
    if(this->nextEvent.count() == 0)
    {
        this->hide();
        qDebug()<<"hide event index:"<<this->index;
    }
    else
    {
        for(int i = 0;i<this->nextEvent.count();i++)
        {
            if(this->nextEvent.at(i)->nextEvent.count() != 0)
            {
                this->nextEvent.at(i)->HideAllEvent();
            }
            else
            {
                this->nextEvent.at(i)->hide();
                qDebug()<<"hide event index:"<<this->nextEvent.at(i)->index;
            }
        }
    }
    qDebug()<<"_HeadEvent::HideAllEvent(HeadEvent* ev),end hide";
}

HeadEvent* HeadEvent::create(Dayline* dayline,HeadEvent* parentEvent)
{
    HeadEvent* event = new HeadEvent(dayline,parentEvent);
    return event;
}
