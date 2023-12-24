#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QButtonGroup>
#include <QGridLayout>
#include <QLabel>
#include <QSplitter>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void updateLayout(int plot_num);
    void initLayout();

private:
    Ui::MainWindow *ui;
    QButtonGroup* butGroup;
    int plotNum;

    QGridLayout* grid_layout;
    QList<QLabel*> label_list;
};
#endif // MAINWINDOW_H
