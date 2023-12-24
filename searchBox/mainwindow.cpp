#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    createSearchBox();
    createSearchBox2();

//    combo = new QComboBox(this);
//    combo->addItem("1");
//    combo->addItem("2");
//    combo->addItem("3");
//    pb = new QPushButton(this);

//如果不用下面代码，qaction中的图标会不清晰
#if (QT_VERSION >= QT_VERSION_CHECK(5,6,0))
    {
        QGuiApplication::setAttribute(Qt::AA_EnableHighDpiScaling );
        QGuiApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);
    }
#endif

}

MainWindow::~MainWindow()
{
    delete ui;
}

QPushButton* MainWindow::createLineEditRightButton(QLineEdit *edit)
{
    QPushButton* button = new QPushButton();
    QHBoxLayout* layout = new QHBoxLayout();
    //鼠标在QLineEdit中会变成竖线表示输入，以下这句会让其变为箭头
    button->setCursor(Qt::ArrowCursor);
    layout->addStretch();
    layout->addWidget(button);
    layout->setContentsMargins(0, 0, 0, 0);
    edit->setLayout(layout);
    return button;
}

void MainWindow::createSearchBox()
{
    QLineEdit *edit = new QLineEdit(this);
    QPushButton *button = createLineEditRightButton(edit);
    edit->setGeometry(20, 20, 200, 26);
    QObject::connect(button, &QPushButton::clicked, [edit] {
        qDebug() << "搜索：" << edit->text();
    });
    QString style_str = "QLineEdit{border:1px solid #eee;border-radius: 4px;"
                        "padding-right: 14px;}"
                        "QLineEdit:focus{border-color: #bbbec4;}"
                        "QLineEdit QPushButton {width: 16px;height: 16px;qproperty-flat: true;"
                        "margin-right: 4px;border: none;border-width: 0;"
                        "border-image: url(/Users/xucheng/workshop/qt5/searchBox/searchBox/search.png) 0 0 0 0 stretch stretch;}";
    edit->setStyleSheet(style_str);
}

void MainWindow::createSearchBox2()
{
    QLineEdit *edit = new QLineEdit(this);
    QAction *searchAction = new QAction(edit);
    edit->setGeometry(20, 60, 200, 26);
    searchAction->setIcon(QIcon("/Users/xucheng/workshop/qt5/searchBox/searchBox/search.png"));
    edit->addAction(searchAction,QLineEdit::TrailingPosition );//编辑框左侧
    //QLineEdit::TrailingPosition 在右侧
    //QLineEdit::LeadingPosition 在左侧
    QObject::connect(searchAction, &QAction::triggered, [edit] {
        qDebug() << "搜索：" << edit->text();
    });
}

