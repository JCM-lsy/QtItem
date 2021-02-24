#include "mainwindow.h"
#include "ui_mainwindow.h" //Qt编译生成的类定义文件

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)//构造函数
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()//析构函数
{
    delete ui;
}

