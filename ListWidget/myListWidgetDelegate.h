#ifndef MYLISTWIDGETDELEGATE_H
#define MYLISTWIDGETDELEGATE_H

#include <QStyledItemDelegate>
#include <QPainter>


class myListWidgetDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    explicit myListWidgetDelegate(QObject* pParent = nullptr);
    ~myListWidgetDelegate();

    virtual void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
};

#endif // MYLISTWIDGETDELEGATE_H
