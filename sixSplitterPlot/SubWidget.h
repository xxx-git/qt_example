#ifndef SUBWIDGET_H
#define SUBWIDGET_H

#include <QWidget>

namespace Ui {
class SubWidget;
}

class SubWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SubWidget(int id, QWidget *parent = nullptr);
    ~SubWidget();
    void hideSubWidget();

private:
    Ui::SubWidget *ui;
};

#endif // SUBWIDGET_H
