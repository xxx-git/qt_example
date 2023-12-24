#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    firstRowColNum = 2;
    secondRowColNum = 2;
    for (int i=0; i<6; i++) {
        SubWidget* sub_w = new SubWidget(i);
        sub_list.append(sub_w);
    }
    connect(ui->pb_v, &QPushButton::clicked, this, &MainWindow::hideDownPlot);
    initPlotLayout();
    setStyleSheet("QSplitter::handle:horizontal{"
                  "image:url(/Users/xucheng/workshop/qt5/sixSplitterPlot/sixSplitterPlot/h.png);}"
                  "QSplitter::handle:vertical{"
                  "image:url(/Users/xucheng/workshop/qt5/sixSplitterPlot/sixSplitterPlot/v.png);}");
    v_splitter->setHandleWidth(32);
    up_h_splitter->setHandleWidth(32);
    down_h_splitter->setHandleWidth(32);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initPlotLayout()
{
    v_splitter = new QSplitter(Qt::Vertical, this);
    up_h_splitter = new QSplitter(Qt::Horizontal,v_splitter);
    for (int i=0; i<3; i++) {
        up_h_splitter->addWidget(sub_list[i]);
        up_h_splitter->setStretchFactor(i,1);
    }
    for (int p=firstRowColNum; p<3; p++) {
        sub_list[p]->setVisible(false);
    }
    up_h_splitter->setHandleWidth(3);

    down_h_splitter = new QSplitter(Qt::Horizontal,v_splitter);
    for (int i=3; i<6; i++) {
        down_h_splitter->addWidget(sub_list[i]);
        down_h_splitter->setStretchFactor(i-3,1);
    }
    for (int q=secondRowColNum+3; q<6; q++) {
        sub_list[q]->setVisible(false);
    }
    down_h_splitter->setHandleWidth(3);

    v_splitter->setStretchFactor(0,1);
    v_splitter->setStretchFactor(1,1);
    v_splitter->setHandleWidth(3);
    QHBoxLayout* hbox = new QHBoxLayout(this);
    hbox->addWidget(v_splitter);
    ui->widget->setLayout(hbox);

    v_splitter->setChildrenCollapsible(false);
    up_h_splitter->setChildrenCollapsible(false);
    down_h_splitter->setChildrenCollapsible(false);
}

void MainWindow::hideDownPlot()
{
    for (int i=0; i<3; i++) {
        sub_list[i]->setVisible(true);
        up_h_splitter->setStretchFactor(i,1);
    }
    for (int i=3; i<6; i++) {
        sub_list[i]->setVisible(true);
        down_h_splitter->setStretchFactor(i,1);
    }
}

void MainWindow::initVerticalLayout(QWidget *parent, int num)
{
//    up_h_splitter = new QSplitter(Qt::Horizontal, parent);
//    for (int i=0; i<3; i++) {
//    }
}

