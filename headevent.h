#ifndef HEADEVENT_H

#include"eventline.h"
#define HEADEVENT_H
#include"dayline.h"
#include"eventwidget.h"
#include<QPushButton>
#include<QMouseEvent>
#include<QList>
#include<QDebug>

class Dayline;
class EventWidget;
class HeadEvent : public QPushButton,public Eventline
{
public:
    static HeadEvent* create(Dayline *dayline,HeadEvent* parentEvent = NULL);
    void addNextEvent();
    void HideAllEvent(HeadEvent* ev = NULL);
    void showAllEvent();
    void orderPos();
    void getMaxH(int &MaxH);
    int index = 0;
    Dayline* Day = NULL;
    EventWidget* eventwidget = NULL;
    HeadEvent* parentEvent = NULL;
    QList<HeadEvent*> nextEvent;
public slots:

private:
    virtual void mousePressEvent(QMouseEvent *e);
    HeadEvent(Dayline* dayline,HeadEvent* parentEvent = NULL);
};

#endif // HEADEVENT_H
