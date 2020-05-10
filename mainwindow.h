#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <main_class.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    main_class *mc;
};
#endif // MAINWINDOW_H
