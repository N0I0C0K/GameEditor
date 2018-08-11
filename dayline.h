#ifndef DAYLINE_H
#define DAYLINE_H
#include"timeline.h"
#include<QList>
#include<QString>
#include<QDebug>
#include"edaytab.h"
#include"headevent.h"

class HeadEvent;
class EDayTab;
class Dayline : public Timeline
{
public:
    Dayline(QString strName,int index,EDayTab *wid);
    void AddHeadEvent();
    //virtual void addline();
    QList<HeadEvent*> event;
    EDayTab *DayWid = NULL;
    QString name;
    int eventCount;
    int index;
};

class DaylineManager : public TimelineManager
{
public:
    static DaylineManager* getInstance();
    void addline(Dayline* Day,int num);

    QList<Dayline*> day;
private:
    DaylineManager();
    int DayCount = 0;
    //QMutableListIterator<Dayline*> iterator;
};

#endif // DAYLINE_H
