#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include <QSplitter>
#include "SubWidget.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void initPlotLayout();
    void hideDownPlot();
    void initVerticalLayout(QWidget* parent, int num);

private:
    Ui::MainWindow *ui;
    QList<SubWidget* > sub_list;
    int plotNum;
    int rowNum;
    int firstRowColNum;
    int secondRowColNum;

    QSplitter* v_splitter;
    QSplitter* up_h_splitter;
    QSplitter* down_h_splitter;
};
#endif // MAINWINDOW_H
