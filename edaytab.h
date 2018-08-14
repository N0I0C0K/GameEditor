#ifndef EDAYTAB_H
#define EDAYTAB_H

#include<QWidget>
#include<QTabWidget>
#include<QString>
#include<QScrollArea>
#include<QDebug>
//#include"timeline.h"
#include"dayline.h"
//#include"eventbox.h"
#include"eventwidget.h"

//class EventBox;
class EventWidget;
class EDayTab : public QWidget
{
    Q_OBJECT
public:
    explicit EDayTab(QString strName,int index,QWidget *parent = 0);
    //EventBox* eventbox = NULL;
    QScrollArea* escroll = NULL;
    EventWidget* eventwidget = NULL;
signals:

public slots:
    //void EventButtonClick(bool);
private:
    //virtual void changeEvent(QEvent *);
    virtual void resizeEvent(QResizeEvent *event);
    //EDayTab *tab;
};

#endif // EDAYTAB_H
