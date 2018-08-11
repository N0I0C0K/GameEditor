#ifndef HEADEVENT_H

#include"eventline.h"
#define HEADEVENT_H
#include"dayline.h"
#include<QPushButton>
#include<QMouseEvent>
#include<QList>
#include<QDebug>

class Dayline;
class HeadEvent : public QPushButton,public Eventline
{
public:
    static HeadEvent* create(Dayline *dayline,HeadEvent* parentEvent = NULL);
    void addNextEvent();
    void HideAllEvent(HeadEvent* ev = NULL);
    int index = 0;
    Dayline* Day = NULL;
    HeadEvent* parentEvent = NULL;
    QList<HeadEvent*> nextEvent;
public slots:

private:
    virtual void mousePressEvent(QMouseEvent *e);
    HeadEvent(Dayline* dayline,HeadEvent* parentEvent = NULL);
};

#endif // HEADEVENT_H
