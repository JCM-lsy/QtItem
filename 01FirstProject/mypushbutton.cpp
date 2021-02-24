#include "mypushbutton.h"
#include <QDebug> //这里的q是大写，下面的qdebug是小写

MyPushButton::MyPushButton(QWidget *parent) : QPushButton(parent)
{
    qDebug() << "我的按钮类构造调用";
}
MyPushButton::~MyPushButton()
{
    qDebug() << "我的按钮类析构" ;
}
