#ifndef EVENTBOX_H
#define EVENTBOX_H
#include<QWidget>
#include<QMainWindow>
#include<QGroupBox>
#include<QPushButton>
#include<QGridLayout>
#include<QDebug>
#include"headevent.h"

class EventBox : public QGroupBox
{
    Q_OBJECT
public:
    EventBox(QWidget *parent);
    void Init();
private slots:
    void Button1Press();
private:
    QGridLayout* layout;
    QPushButton* button1;
    QPushButton* button2;
};

#endif // EVENTBOX_H
