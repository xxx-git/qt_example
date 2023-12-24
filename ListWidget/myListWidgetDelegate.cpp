#include "myListWidgetDelegate.h"

myListWidgetDelegate::myListWidgetDelegate(QObject* pParent)
    : QStyledItemDelegate(pParent)
{

}

myListWidgetDelegate::~myListWidgetDelegate()
{}

void myListWidgetDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QRect rect = option.rect; // 目标矩形
    rect.adjust(2,2,-2,-2); // 缩小一圈，留出空白间隔

    if (index.data(Qt::CheckStateRole) == Qt::Checked)
    {
        painter->setBrush(QColor("#e4f0ff"));
        painter->drawRoundedRect(rect, 2, 2);
    }else
    {
        painter->setBrush(Qt::NoBrush);
        painter->drawRoundedRect(rect, 2, 2);
    }

    QColor color = index.data(Qt::DecorationRole).value<QColor>();
    painter->setPen(color);
    painter->drawRoundedRect(rect, 2, 2);

    rect.adjust(1,1,-1,-1); // 缩小一圈，留出空白间隔
    painter->setPen(Qt::black);
    QString text = index.data(Qt::DisplayRole).value<QString>();
    painter->drawText(rect, Qt::AlignHCenter | Qt::AlignVCenter, text);
}
