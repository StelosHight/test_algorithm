#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mc = new main_class();
    QList<my_gview *> view_list = mc->get_views();
    QList<QLabel *> label_list = mc->get_labels();
    QVBoxLayout *gy = qobject_cast<QVBoxLayout*>(ui->scrollAreaWidgetContents->layout());
    gy->addWidget(view_list[1]);
    gy->addWidget(label_list[0]);
    gy->addWidget(view_list[2]);
    gy->addWidget(label_list[1]);
}

MainWindow::~MainWindow()
{
    delete mc;
    delete ui;
}

