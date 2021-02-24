#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    resize(800,600);
    //TableWidge控件
    //设置列数
    ui->tableWidget->setColumnCount(3);
    //设置水平表头
    ui->tableWidget->setHorizontalHeaderLabels(QStringList()<<"姓名"<<"性别"<<"年龄");
    //设置行数
    ui->tableWidget->setRowCount(5);
    //设置正文
//    ui->tableWidget->setItem(0,0,new QTableWidgetItem("亚瑟"));
    QStringList namelist;
    namelist<<"a"<<"b"<<"c"<<"d"<<"e";

    QList<QString> genderlist;
    genderlist<<"man"<<"woman"<<"man"<<"woman"<<"man";

    for(int i=0;i<5;i++){
        int col=0;
        ui->tableWidget->setItem(i,col++,new QTableWidgetItem(namelist[i]));
        ui->tableWidget->setItem(i,col++,new QTableWidgetItem(genderlist[i]));
        //int转为QString
        ui->tableWidget->setItem(i,col++,new QTableWidgetItem(QString::number(i+18)));
    }
}

Widget::~Widget()
{
    delete ui;
}

