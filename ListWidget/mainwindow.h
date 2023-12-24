#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidget>
#include <QListWidgetItem>
#include <QPushButton>
#include <QHBoxLayout>
#include <QSplitter>
#include <QRandomGenerator>
#include <QColorDialog>

#include "myListWidgetItem.h"
#include "myListWidgetDelegate.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void initListWidget();
    void initLayout();
    void insertOneItem();
    void slotOnContextMenuPolicy(const QPoint &pos);
    void showColorDialog();
    void changeItemColor(const QColor &color);
    void slotOnItemClicked(QListWidgetItem *item);
    int genRandom();


private:
    Ui::MainWindow *ui;
    QListWidget* list_widget;
    QPushButton* pb_insert;
    QRandomGenerator random_gen;

    QMenu *menu;
    QAction *color_action;
    QColorDialog* color_dialog;
    QList<QColor> color_list;

};
#endif // MAINWINDOW_H
