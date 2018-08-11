#ifndef EDAYTAB_H
#define EDAYTAB_H

#include<QWidget>
#include<QTabWidget>
#include<QString>
//#include"timeline.h"
#include"dayline.h"
#include"eventbox.h"

class EventBox;
class EDayTab : public QWidget
{
    Q_OBJECT
public:
    explicit EDayTab(QString strName,int index,QWidget *parent = 0);
    EventBox* eventbox = NULL;
signals:

public slots:
    //void EventButtonClick(bool);
private:
    //EDayTab *tab;
};

#endif // EDAYTAB_H
