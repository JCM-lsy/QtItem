#ifndef STUDENT_H
#define STUDENT_H

#include <QObject>

class Student : public QObject
{
    Q_OBJECT
public:
    explicit Student(QObject *parent = nullptr);
    //槽函数写到这里
//自定义槽函数写法--返回值是void，需要声明也需要实现，可以有参数--可以重载
    void treat();//在.h声明 在.cpp实现
    //也来个重载
    void treat(QString foodName);

signals:

};

#endif // STUDENT_H
