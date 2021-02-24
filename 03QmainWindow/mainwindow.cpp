#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMenuBar>
#include <QToolBar>
#include <QPushButton>
#include <QStatusBar>
#include <QLabel>
#include <QDockWidget>
#include <QTextEdit>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //重置窗口大小
    resize(800,600);

/*****************菜单栏的创建*******************/
    //程序中 菜单栏最多有一个
    QMenuBar * bar = menuBar();
    //将菜单栏放入窗口 空栏是不会显示的
    setMenuBar(bar);
    //创建菜单
    QMenu * fileMenu = bar->addMenu("Files");
    QMenu * editMenu = bar->addMenu("Edit");
    //创建菜单项
    //fileMenu->addAction("New");
    QAction * newAction = fileMenu->addAction("New");
    //添加分割线
    fileMenu->addSeparator();
    //fileMenu->addAction("Open");
    QAction * openAction = fileMenu->addAction("Open");

/*****************工具栏的创建*******************/
    //工具栏可以有多个
    QToolBar * toolBar = new QToolBar(this);
    addToolBar(Qt::LeftToolBarArea,toolBar);//默认在左侧贴着
    //后期设置 只允许左右停靠
    toolBar->setAllowedAreas(Qt::LeftToolBarArea | Qt::RightToolBarArea);
    //设置浮动 禁止浮动
    toolBar->setFloatable(false);
    //设置移动 （总开关）禁止移动
    toolBar->setMovable(false);
    //工具栏中设置内容
    toolBar->addAction(newAction);
    toolBar->addAction(openAction);
    //工具栏中添加控件
    QPushButton * btn = new QPushButton("button",this);
    toolBar->addWidget(btn);

/******************状态栏的创建*******************/
    QStatusBar * stBar = statusBar();
    //设置到窗口中
    setStatusBar(stBar);
    //放标签控件
    QLabel * label = new QLabel("提示信息",this);
    stBar->addWidget(label);//从左到右
    QLabel * label2 = new QLabel("右侧提示信息",this);
    stBar->addPermanentWidget(label2);//从右到左

/******************铆接部件-浮动窗口*******************/
    //可以有多个-ADD
    QDockWidget * dockWidget = new QDockWidget("Float",this);
    addDockWidget(Qt::BottomDockWidgetArea,dockWidget);
    //设置后期停靠区域，只允许上下
    dockWidget->setAllowedAreas(Qt::TopDockWidgetArea | Qt::BottomDockWidgetArea);

/******************设置中心部件*******************/
    //只能有一个-SET
    //以记事本为例
    QTextEdit * edit = new QTextEdit(this);
    setCentralWidget(edit);
}

MainWindow::~MainWindow()
{
    delete ui;
}

