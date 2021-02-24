#include "mywidget.h" //包含头文件

#include <QApplication> //包含应用程序类的头文件

//main入口
int main(int argc, char *argv[])//argc-命令行变量的数量，argv-命令行变量的数组
{
    //a应用程序对象，在Qt中，应用程序对象，有且只有一个
    QApplication a(argc, argv);
    //窗口对象 myWidget的父类 -> QWidge(空窗口)
    myWidget w;
    //窗口对象默认不显示，必须调用show方法显示窗口
    w.show();
    //让应用程序进入消息循环-捕捉消息，不闪退，只有点了“X”才会退出
    //让代码阻塞到这行
    return a.exec();
}
