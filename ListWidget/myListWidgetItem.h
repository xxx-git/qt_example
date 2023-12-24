#ifndef MYLISTWIDGETITEM_H
#define MYLISTWIDGETITEM_H

#include <QListWidgetItem>
#include <QObject>

class myListWidgetItem : public QObject, public QListWidgetItem
{
    Q_OBJECT

public:
    explicit myListWidgetItem(QListWidget *parent = nullptr);
    ~myListWidgetItem();

    bool operator<(const QListWidgetItem &other) const;


private:
};

#endif // MYLISTWIDGETITEM_H
