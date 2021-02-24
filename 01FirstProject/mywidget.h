#ifndef MYWIDGET_H
#define MYWIDGET_H //防止头文件重复包含,与#pragma once功能一致

#include <QWidget> //包含窗口头文件

QT_BEGIN_NAMESPACE
namespace Ui { class myWidget; }
QT_END_NAMESPACE

class myWidget : public QWidget
{
    Q_OBJECT //宏 允许类中使用信号和槽（很重要）的机制

public:
    myWidget(QWidget *parent = nullptr);//含参构造函数 nullptr是默认值
    ~myWidget();//析构

private:
    Ui::myWidget *ui;
};
#endif // MYWIDGET_H
