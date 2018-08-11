#ifndef EVENTLINE_H
#define EVENTLINE_H
#include<QString>
//#include<QPushButton>
#include<QLabel>
#include<QPushButton>
//#include"headevent.h"

class Eventline
{
public:
    //QLabel *lable;
    Eventline();
private:
    QString eventname;
    int target;
};

class HeadEvent;
class EventlineManager
{
public:
    static EventlineManager* getInstance();
    HeadEvent* currentEvent = NULL;
    int EventCount = 0;
private:

};

#endif // EVENTLINE_H
