#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QPushButton>//新建时选了非目标类不要紧，这里更改一下即可

class MyPushButton : public QPushButton
{
    Q_OBJECT
public:
    explicit MyPushButton(QWidget *parent = nullptr);//构造
    ~MyPushButton();//析构

signals:

};

#endif // MYPUSHBUTTON_H
