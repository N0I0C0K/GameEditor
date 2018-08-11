#include"eventline.h"
//#include"headevent.h"
Eventline::Eventline()
{
    EventlineManager::getInstance()->EventCount += 1;
}

EventlineManager* EventlineManager::getInstance()
{
    static EventlineManager* master = new EventlineManager();
    return master;
}
