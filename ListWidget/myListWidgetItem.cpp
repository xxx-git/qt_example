#include "myListWidgetItem.h"

myListWidgetItem::myListWidgetItem(QListWidget *parent)
    : QObject(parent), QListWidgetItem(parent)
{
}

myListWidgetItem::~myListWidgetItem()
{}

bool myListWidgetItem::operator<(const QListWidgetItem &other) const
{
    int this_value = this->data(Qt::UserRole).toInt();
    int other_value = other.data(Qt::UserRole).toInt();
    if(this_value < other_value)
    {
        return true;
    }else{
        return false;
    }
}


