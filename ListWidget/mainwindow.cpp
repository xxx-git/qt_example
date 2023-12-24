#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    color_list.append(Qt::red);
    color_list.append(Qt::yellow);
    color_list.append(Qt::green);
    initLayout();
    initListWidget();
    connect(pb_insert, &QPushButton::clicked, this, &MainWindow::insertOneItem);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::insertOneItem()
{
    //QListWidgetItem* item = new QListWidgetItem(list_widget);
    QListWidgetItem* item = new myListWidgetItem(list_widget);
    int num = genRandom();
    int type = random_gen.bounded(0,3);
    QString text = QString("%1-%2").arg(num).arg(type);
    item->setData(Qt::DisplayRole, text);
    item->setData(Qt::UserRole, type);
    item->setData(Qt::DecorationRole, color_list[type]);
    item->setCheckState(Qt::Checked);
    list_widget->sortItems();
}

void MainWindow::slotOnContextMenuPolicy(const QPoint &pos)
{
    Q_UNUSED(pos);
    // 在鼠标光标位置显示右键快捷菜单
    menu->exec(QCursor::pos());
}

void MainWindow::showColorDialog()
{
    color_dialog->move(QCursor().pos().x()+10, QCursor().pos().y()+10);
    color_dialog->exec();
}

void MainWindow::changeItemColor(const QColor &color)
{
    QListWidgetItem* item = list_widget->currentItem();
    item->setData(Qt::DecorationRole, color);
}

void MainWindow::slotOnItemClicked(QListWidgetItem *item)
{
    if(item->checkState() == Qt::Checked)
    {
        item->setCheckState(Qt::Unchecked);
    }else
    {
        item->setCheckState(Qt::Checked);
    }
}
void MainWindow::initListWidget()
{
    //通过一下方式开启排序，则listwidget会自动排序，但当修改item内容时，会改变item顺序（排序内容相等，修改item会在最上面）
    //本项目采用手动启动排序，只有增加item时进行排序
//    list_widget->setSortingEnabled(true);
    list_widget->setItemDelegate(new myListWidgetDelegate);
    connect(list_widget, &QListWidget::itemClicked, this, &MainWindow::slotOnItemClicked);

    list_widget->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(list_widget, &QListWidget::customContextMenuRequested, this, &MainWindow::slotOnContextMenuPolicy);

    menu = new QMenu(this);
    color_action = new QAction("change color");
    menu->addAction(color_action);
    color_dialog = new QColorDialog(this);
    connect(color_action, &QAction::triggered, this, &MainWindow::showColorDialog);
    connect(color_dialog, &QColorDialog::colorSelected, this, &MainWindow::changeItemColor);
}

void MainWindow::initLayout()
{
    QHBoxLayout* h1 = new QHBoxLayout;
    list_widget = new QListWidget(this);
    h1->addWidget(list_widget);
    QHBoxLayout* h2 = new QHBoxLayout;
    h2->addWidget(new QSplitter(Qt::Horizontal, this));
    pb_insert = new QPushButton(this);
    pb_insert->setText("insert");
    h2->addWidget(pb_insert);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(h1);
    mainLayout->addLayout(h2);
    this->centralWidget()->setLayout(mainLayout);
}

int MainWindow::genRandom()
{
    return random_gen.bounded(0,100);
}

