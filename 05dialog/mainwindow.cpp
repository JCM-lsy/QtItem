#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDialog>
#include <QDebug>
#include <QMessageBox>
#include <QColorDialog>
#include <QColor>
#include <QFileDialog>
#include <QFontDialog>
#include <QFont>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //点击新建按钮，弹出一个对话框
    connect(ui->actionNew,&QAction::triggered,[=](){
        //对话框 分类
         //模态对话框-不可以对其他窗口进行操作，非模态对话框-可以
//        /*****模态 阻塞*****/
//        QDialog dlg(this);
//        dlg.resize(200,100);//重置大小也要写在弹出之前，不然会被阻塞
//        dlg.exec();//模态创建
//        qDebug() << "模态对话框弹出";//不显示，因为被模态对话框阻塞了，关掉会打印

//        /*****非模态*****/
////        QDialog dlg2(this);//此时的dlg2包含在lambda即匿名函数中，运行之后会被释放内存，所以会闪退
//        QDialog * dlg2 = new QDialog(this);//创建堆区就不会闪退了
//        dlg2->resize(200,100);//第二种要把原来的dlg.改为dlg-> 指针
//        dlg2->show();//非模态
//        //隐患，如果不释放内存，一直点会造成内存泄漏
//         //这里用添加一个属性来解决
//        dlg2->setAttribute(Qt::WA_DeleteOnClose);//55号 attribute 属性
//        qDebug() << "非模态对话框弹出";

        /*********消息对话框 属于模态****************/
        /**错误对话框**/
//        QMessageBox::critical(this,"critical","error");
        /**信息对话框**/
//        QMessageBox::information(this,"info","information");
        /****///提问对话框(父类，标题，提示内容，关联的按键类型-见帮助文档，默认关联回车的按键)
         //如何判断用户点了哪个选项？
         //有返回值
//        if(QMessageBox::Save==QMessageBox::question\
//                (this,"ques","question",QMessageBox::Save|QMessageBox::Cancel,QMessageBox::Cancel))
//        {
//            qDebug()<<"保存";
//        }else{
//            qDebug()<<"取消";
//        }
        /**警告对话框**/
//        QMessageBox::warning(this,"warning","warning");

        /**其他标准对话框**/
        /*颜色对话框*/
//        QColor color = QColorDialog::getColor(QColor(255,0,0,0));//设置默认颜色
//        qDebug() << "r=" << color.red() << "g=" << color.green() << "b=" << color.blue();
        /*文件对话框 (父类，标题，默认路径，过滤文件格式)*/
        //鼠标悬停到方法名称上可以看它的返回值类型
        //返回值是选取的路径
//        QString str = QFileDialog::getOpenFileName(this,"打开文件","D:\\study","(*.txt)");
//        qDebug()<<str;
        /*字体对话框*/
        bool flag;
        QFont font = QFontDialog::getFont(&flag,QFont("微软雅黑",36));
        qDebug()<<"字体："<<font.family()<<"是否加粗："<<font.bold()<<"是否倾斜："<<font.italic();
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

