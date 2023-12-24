#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    plotNum = 0;
    ui->setupUi(this);
    butGroup = new QButtonGroup(this);
    butGroup->addButton(ui->rb1,1);
    butGroup->addButton(ui->rb2,2);
    butGroup->addButton(ui->rb4,4);
    butGroup->addButton(ui->rb6,6);
    butGroup->setExclusive(true);
    ui->rb6->setChecked(true);
    for (int i=0; i<6; i++)
    {
        QLabel* label = new QLabel();
        label->setText(QString::number(i));
        label->setStyleSheet("border:2px solid red");
        label_list.append(label);
    }
    initLayout();
    connect(butGroup, QOverload<const int>::of(&QButtonGroup::buttonClicked), this, &MainWindow::updateLayout);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initLayout()
{
    plotNum = butGroup->checkedId();
    grid_layout = new QGridLayout(this);
    ui->widget->setLayout(grid_layout);
    for (int i=0; i<plotNum; i++) {
        int row = i%2;
        int col = i/2;
        grid_layout->addWidget(label_list[i], row, col);
    }
}

void MainWindow::updateLayout(int plot_num)
{
    if(plot_num == plotNum){
        return;
    }else if(plot_num > plotNum)
    {
        for (int i=plotNum; i<plot_num; i++) {
            int row = i%2;
            int col = i/2;
            label_list[i] = new QLabel();
            label_list[i]->setText("add");
            label_list[i]->setStyleSheet("border:2px solid red");
            grid_layout->addWidget(label_list[i], row, col);
            label_list[i]->setVisible(true);
        }
    }else
    {
        for(int i=plotNum-1; i>=plot_num; i--)
        {
            grid_layout->removeWidget(label_list[i]);
            label_list[i]->setVisible(false);
            delete label_list[i];
            label_list[i] = nullptr;
        }
    }
    plotNum = plot_num;
}
