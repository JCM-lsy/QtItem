#ifndef TEACHER_H
#define TEACHER_H

#include <QObject>

class Teacher : public QObject
{
    Q_OBJECT
public:
    explicit Teacher(QObject *parent = nullptr);

signals:
    //自定义信号写到这里
//自定义信号写法--返回值是void，只需要声明，不需要实现，可以有参数-可以重载(C++ 允许多个函数拥有相同的名字，只要它们的参数列表不同就可以)
    void hungry();//先来个无参的
    //来个重载
    void hungry(QString foodName);
};

#endif // TEACHER_H
