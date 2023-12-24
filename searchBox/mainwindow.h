#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QComboBox>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void createSearchBox();
    void createSearchBox2();
    QPushButton* createLineEditRightButton(QLineEdit* edit);


private:
    Ui::MainWindow *ui;
    QComboBox* combo;
    QPushButton* pb;
};
#endif // MAINWINDOW_H
