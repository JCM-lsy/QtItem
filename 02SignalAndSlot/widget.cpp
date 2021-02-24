#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>
#include <QDebug>

//目标
    //Teacher类
    //Student类
    //场景：下课后，老师会触发一个信号--饿了，学生响应信号--请客吃饭

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);//这个是为了设计文档，暂时不用管，怕出错所以先不删除

    //创建老师对象+学生对象
    this->teacher = new Teacher(this);
    this->student = new Student(this);
/******************************** version1 *****************************************/
//     老师饿了->学生请客的连接 无参
//    connect(teacher,&Teacher::hungry,student,&Student::treat);

//    //调用下课函数
//    this->classIsOver();

/******************************** version2 *****************************************/
    //老师饿了->学生请客的连接 含参
    //函数指针可以指向函数地址
        //某个类的成员函数的函数指针，声明时要标清作用域即所属的类
//    void(Teacher:: *teacherSignal)(QString) = &Teacher::hungry;
//    void(Student:: *studentSlot)(QString) = &Student::treat;
//    connect(teacher,teacherSignal,student,studentSlot);

//报错，连接方法相同，函数地址无法区分是否含参
//    //调用下课函数
//    classIsOver();

    //点击一个下课按钮再下课
    QPushButton * btn = new QPushButton("下课",this);
    this->resize(600,400);//重置窗口大小
    //点击按钮触发下课
    connect(btn,&QPushButton::clicked,this,&Widget::classIsOver);
    /*
     * 含参的信号无法连接按钮点击信号,信号和槽的数据类型不同
     * 因为clicked是bool型，无法与QString连接，但void是无参，相当于零，bool型相当于一个参数，所以可以来连接
    */

/******************************** version3 *****************************************/
    //无参信号和槽的连接
    void(Teacher:: *teacherSignal)(void) = &Teacher::hungry;
    void(Student:: *studentSlot)(void) = &Student::treat;
    connect(teacher,teacherSignal,student,studentSlot);
    //信号连接信号
    connect(btn,&QPushButton::clicked,teacher,teacherSignal);

    //断开信号
    disconnect(teacher,teacherSignal,student,studentSlot);//按钮失效

    /**************** 拓展 **************/
    /*
    1.信号可以连接信号
    2.一个信号可以连接多个槽函数
    3.多个信号可以连接同一个槽函数
    4.信号和槽函数的参数需要按顺序一一对应 相同但顺序不对也不行
    5.但是，对于信号和槽的参数个数--信号参数的个数可以多于槽函数
例如
void(Teacher:: *teacherSignal)(QString，int) = &Teacher::hungry; 宫保鸡丁，2（份）    宫保鸡丁
void(Student:: *studentSlot)(QString) = &Student::treat;         收到               收到，几份？
    6.
    */

    /*********************** 难点 lambda表达式 匿名函数 最常用[=](){} ***********************/

//    [=](){ //[]中 “=”-值传递 或 “&”-引用传递 用来让表达式认识上面的btn局部变量，否则会报错
//        btn->setText("aaaa");
//    }();

//    QPushButton * btn2 = new QPushButton;
//    [btn](){ //[]中 “=”-值传递（推荐） 或 “&”-引用传递 用来让表达式认识上面的btn局部变量，否则会报错
//        btn->setText("aaaa");
//        btn2->setText("bbbb");//btn2看不到
//    }();

//    int ret = []()->int{return 1000;}();
//    qDebug() << "ret=" <<ret;

    //利用lambda表达式 实现点击按钮->关闭窗口
    QPushButton * btn2 = new QPushButton;
    btn2->setText("close");
    btn2->move(100,100);
    btn2->setParent(this);
    connect(btn2,&QPushButton::clicked,this,[=](){
//        this->close();
//        emit teacher->hungry("Bread");
        btn2->setText("click");
    });
    //练习
}

void Widget::classIsOver()
{
    //下课函数，调用后，触发老师饿了信号
    //触发的关键字 emit
    //emit teacher->hungry();
    emit teacher->hungry("宫保鸡丁");
}

Widget::~Widget()
{
    delete ui;
}

