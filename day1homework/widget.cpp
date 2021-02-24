#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>
#include "newwitget.h"
#include <QString>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //用两个按钮
//    QPushButton * btnOpen = new QPushButton;
//    QPushButton * btnClose = new QPushButton;
//    btnOpen->setParent(this);
//    btnOpen->setText("Open");
//    btnOpen->move(200,180);
//    btnClose->setParent(this);
//    btnClose->setText("Close");
//    btnClose->move(400,180);
//    resize(800,400);

//    newwitget * nw = new newwitget;

//    connect(btnOpen,&QPushButton::clicked,nw,[=](){
//        nw->show();
//    });
//    connect(btnClose,&QPushButton::clicked,nw,[=](){
//        nw->close();
//    });
    //用一个按钮
    QPushButton * btn = new QPushButton;
    btn->setParent(this);
    QString btnT;
    btn->setText(btnT);
    btn->move(150,160);
    resize(400,400);
    int flag=1;
    if(flag){
        btnT="Open";
     }else{
        btnT="Close";
     }
    newwitget * nw = new newwitget;
    connect(btn,&QPushButton::clicked,nw,[=]()mutable{//lambda表达式参数默认不可变，需要另外注明
        flag=(flag+1)/2;
        if(flag){
            btnT="Open";
         }else{
            btnT="Close";
         }
    });
}

Widget::~Widget()
{
    delete ui;
}

