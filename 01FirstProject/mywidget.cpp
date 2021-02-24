#include "mywidget.h"
#include "ui_mywidget.h"
#include <QPushButton>
#include "mypushbutton.h"
#include <QDebug> //这里的q是大写，下面的qdebug是小写

// 命名规范 C++基础
    //类名 首字母大写，驼峰命名
    //函数名、变量名首字母小写，驼峰命名
//快捷键
    //帮助文档F1
    //整行移动 ctrl+shift+↑/↓
    //自动对齐 ctrl+i
    //同名 .h .cpp 切换 F4
myWidget::myWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::myWidget)
{
    //创建一个按钮
    QPushButton * btn = new QPushButton;
    //btn->show();//show 默认是以顶层方式单独弹出，所以会有两个窗口，一个空白、一个按钮...
    //让btn对象依赖在myWidget窗口上
    //widget是个窗口，是底层的基类，想让后面的控件在窗口里面，只需要把控件设为widget的子类
    btn->setParent(this);//设置父类
    //按钮上显示文本
    btn->setText("button1");

    //创建第二个按钮
    QPushButton * btn2 = new QPushButton("button2",this);//会按照控件大小设置窗口，所以单纯的这种方法不太好

    //重置窗口大小
    resize(600,400);//resize(宽，高)
    //设置固定的窗口大小（用户不可更改
    setFixedSize(600,400);

    //重置按钮大小
    btn2->resize(50,20);

    //但此时第二个按钮会把第一个挡住
    //移动btn2
    btn2->move(200,0);

    //设置窗口标题
    setWindowTitle("第一个窗口");

    //创建一个自己的按钮对象
    MyPushButton * myBtn = new MyPushButton;
    myBtn->setText("我自己的按钮");
    myBtn->move(200,100);
    myBtn->setParent(this);//设置到对象树中

    //需求 点击我的按钮 关闭窗口
    //【信号发送者，发送的信号(函数的地址，不用写括号)，信号接收者，接收者的行为】   槽-slot 信号-signal
    connect(myBtn,&QPushButton::clicked,this,&myWidget::close);//myWidget也是qWidget的子类，所以也可以调用close
}

myWidget::~myWidget()
{
    qDebug() << "myWidget的析构调用";//在控制台打印？
    //本质上是先析构我的按钮类，再析构myWidget。但是，先打印这句话，再析构他儿子，他儿子没儿子，所以最后析构myWeidget，
    //析构顺序确实是从下到上，但是这句话先打印
    //也可以记为，打印顺序与析构顺序相反
}

