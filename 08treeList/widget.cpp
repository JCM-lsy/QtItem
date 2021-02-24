#include "widget.h"
#include "ui_widget.h"
#include <QTreeWidget>
#include <QStringList>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    /*************** treeWidget树控件使用 ***************/
    //设置水平头
    ui->treeWidget->setHeaderLabels(QStringList()<<"英雄"<<"英雄介绍");//创建匿名对象
    QTreeWidgetItem * item1 = new QTreeWidgetItem(QStringList()<<"力量");
    QTreeWidgetItem * item2 = new QTreeWidgetItem(QStringList()<<"敏捷");
    QTreeWidgetItem * item3 = new QTreeWidgetItem(QStringList()<<"智慧");
    //加载顶层节点
    ui->treeWidget->addTopLevelItem(item1);
    ui->treeWidget->addTopLevelItem(item2);
    ui->treeWidget->addTopLevelItem(item3);
    //追加子节点
    QStringList heroL1;
    heroL1 << "刚被猪" << "前排坦克，能在吸收伤害的同时造成可观的范围输出";
    QTreeWidgetItem * L1 = new QTreeWidgetItem(heroL1);
    item1->addChild(L1);

    QStringList heroL2;
    heroL2 << "船长" << "前排坦克，能肉能输出能控场的全能英雄";
    QTreeWidgetItem * L2 = new QTreeWidgetItem(heroL2);
    item1->addChild(L2);

    QStringList heroM1;
    heroM1 << "月骑" << "中排物理输出，可以使用分裂利刃攻击多个目标";
    QTreeWidgetItem * M1 = new QTreeWidgetItem(heroM1);
    item2->addChild(M1);

    QStringList heroM2;
    heroM2 << "小鱼人" << "前排战士，擅长偷取敌人的属性来增强自身战力";
    QTreeWidgetItem * M2 = new QTreeWidgetItem(heroM2);
    item2->addChild(M2);

    QStringList heroZ1;
    heroZ1 << "死灵法师" << "前排法师坦克，魔法抗性较高，拥有治疗技能";
    QTreeWidgetItem * Z1 = new QTreeWidgetItem(heroZ1);
    item3->addChild(Z1);

    QStringList heroZ2;
    heroZ2 << "巫医" << "后排辅助法师，可以使用奇特的巫术诅咒敌人与治疗队友";
    QTreeWidgetItem * Z2 = new QTreeWidgetItem(heroZ2);
    item3->addChild(Z2);
}
Widget::~Widget()
{
    delete ui;
}

