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
    this->move(0,(this->eventwidget->rect().height())/(Day->event.count()+2));
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
    }
    qDebug()<<"_HeadEvent::mousePressEvent(QMouseEvent *e)";
    this->eventwidget->eventbox->hide();
}

void HeadEvent::addNextEvent()
{
    qDebug()<<"HeadEvent::addNextEvent()";
    HeadEvent* ev = HeadEvent::create(this->Day,this);
    int MaxHeight = 0;
    if(this->nextEvent.count() != 0)
        this->nextEvent.at(this->nextEvent.count()-1)->getMaxH(MaxHeight);
    else if(this->nextEvent.count() == 0)
        MaxHeight = this->y();
    else if(this->parentEvent != NULL && this->parentEvent->nextEvent.count() != 0)
    {
        this->parentEvent->nextEvent.at(this->parentEvent->nextEvent.count()-1)->getMaxH(MaxHeight);
    }
    this->nextEvent.insert(this->nextEvent.count(),ev);
    //HeadEvent* ev = this;
    qDebug()<<"MaxHeight:"<<MaxHeight;
    //ev->move(this->parentEvent->x()+this->parentEvent->width()+15,MaxHeight);
    ev->move(ev->parentEvent->x()+ev->parentEvent->width()+15,MaxHeight);
    this->Day->OrderAllPos();
    qDebug()<<"HeadEvent::nextEvent update,now count is:"<<this->nextEvent.count();
    qDebug()<<"and event index is:"<<ev->index;
    qDebug()<<"and nextEvent.at(index).index is"<<this->nextEvent.at(ev->index)->index;
    qDebug()<<"_HeadEvent::addNextEvent()";
    ev->show();
}

void HeadEvent::getMaxH(int &MaxH)
{
    if(this->nextEvent.count() == 0)
        MaxH = (this->y()+this->height());
    else
        this->nextEvent.at(this->nextEvent.count()-1)->getMaxH(MaxH);

}

void HeadEvent::orderPos()
{
    if(this->parentEvent == NULL)
    {
        if(this->index == 0)
        {
            this->move(0,0);
            if(this->nextEvent.count() != 0)
            {
                for(int j = 0;j < this->nextEvent.count();j++)
                {
                    this->nextEvent.at(j)->orderPos();
                }
            }
        }
        else
        {
            int MaxHeight;
            this->Day->event.at(this->index-1)->getMaxH(MaxHeight);
            this->move(0,MaxHeight);
            if(this->nextEvent.count() != 0)
            {
                for(int j = 0;j < this->nextEvent.count();j++)
                {
                    this->nextEvent.at(j)->orderPos();
                }
            }
        }
    }
    else
    {
        for(int i = 0;i < this->parentEvent->nextEvent.count();i++)
        {
            if(this->index == 0)
            {
                this->move(this->parentEvent->x()+this->parentEvent->width()+15,this->parentEvent->y());
                if(this->nextEvent.count() != 0)
                {
                    for(int j = 0;j < this->nextEvent.count();j++)
                    {
                        this->nextEvent.at(j)->orderPos();
                    }
                }
            }
            else
            {
                int MaxHeight;
                this->parentEvent->nextEvent.at(this->index-1)->getMaxH(MaxHeight);
                this->move(this->parentEvent->x()+this->parentEvent->width()+15,MaxHeight);
                if(this->nextEvent.count() != 0)
                {
                    for(int j = 0;j < this->nextEvent.count();j++)
                    {
                        this->nextEvent.at(j)->orderPos();
                    }
                }
            }
        }
    }
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

void HeadEvent::showAllEvent()
{
    qDebug()<<"HeadEvent::showAllEvent(),show all childen event begin";
    if(this->nextEvent.count() != 0)
    {
        for(int i = 0;i < this->nextEvent.count();i++)
        {
            if(this->nextEvent.at(i)->nextEvent.count() != 0)
            {
                this->nextEvent.at(i)->showAllEvent();
            }
            else
            {
                this->nextEvent.at(i)->show();
            }
        }
    }
}

HeadEvent* HeadEvent::create(Dayline* dayline,HeadEvent* parentEvent)
{
    HeadEvent* event = new HeadEvent(dayline,parentEvent);
    return event;
}
