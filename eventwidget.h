#ifndef EVENTWIDGET_H
#define EVENTWIDGET_H

#include<QWidget>
#include<QScrollArea>
#include"eventbox.h"

class EventBox;
class EventWidget : public QWidget
{
    Q_OBJECT
public:
    explicit EventWidget(QWidget *parent = 0);
    EventBox* eventbox = NULL;
signals:

public slots:
};

#endif // EVENTWIDGET_H
