#include "dayline.h"
#include "headevent.h"
#include "edaytab.h"

Dayline::Dayline(QString strName,int num,EDayTab *wid)
{
    DaylineManager::getInstance()->addline(this,num);
    //qDebug()<<event.count();
    this->name = strName;
    this->index = num;
    this->DayWid = wid;
    this->eventCount = 0;
}

void Dayline::AddHeadEvent()
{
    int n = this->event.count();
    HeadEvent* ev = HeadEvent::create(this);
    this->event.insert(n,ev);
    ev->index = n;
    this->eventCount += 1;
    qDebug()<<"Dayline::AddHeadEvent(),and now event index_pre is "<<ev->index<<"and event.at(index_pre)->index:"<<this->event.at(ev->index)->index;
    qDebug()<<"Dayline::AddHeadEvent(),and now event count is "<<this->event.count();
    qDebug()<<"Dayline::AddHeadEvent(),and event.count() is:"<<this->eventCount;
}

DaylineManager* DaylineManager::getInstance()
{
    static DaylineManager* day = new DaylineManager();
    return day;
}

DaylineManager::DaylineManager()
{
    //this->iterator.operator =(day);
}

void DaylineManager::addline(Dayline *Day,int num)
{
    //QMutableListIterator<Dayline*> iterator(this->day);
    //iterator.insert(day);
    day.insert(num,Day);
    qDebug()<<"DaylineManager::addline(*,*),and now dayline count is "<<this->day.count();
    this->DayCount += 1;

}
