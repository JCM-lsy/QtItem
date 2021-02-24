#include "student.h"
#include <QDebug>

Student::Student(QObject *parent) : QObject(parent)
{

}

void Student::treat()
{
    qDebug() << "请老师吃饭";
}

void Student::treat(QString foodName)
{
    //如果不做改动 结果为 请老师吃饭，老师要吃: "宫保鸡丁"
    //下面去掉引号
    //需要把 QString -> char*
    //qDebug() << "请老师吃饭，老师要吃:" << foodName;
    qDebug() << "请老师吃饭，老师要吃:" << foodName.toUtf8().data();
    //先.toUtf8()转成QByteArray,再.data()转成char*

}
