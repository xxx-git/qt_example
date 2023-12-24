#include "SubWidget.h"
#include "ui_SubWidget.h"

SubWidget::SubWidget(int id, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SubWidget)
{
    ui->setupUi(this);
    ui->label_name->setText(QString::number(id));
    connect(ui->pb_del, &QPushButton::clicked, this, &SubWidget::hideSubWidget);
//    setMinimumSize(300,300);
    setStyleSheet("background-color:rgba(230,230,250,0.5)");
}

SubWidget::~SubWidget()
{
    delete ui;
}

void SubWidget::hideSubWidget()
{
    this->setVisible(false);
}
