#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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

private slots:
    void number_pressed();
    void on_divide_released();
    void on_decimal_released();
    void on_clear_pressed();
    void on_multiply_pressed();
    void on_equals_released();
    void on_minus_released();
    void on_plus_released();
};
#endif // MAINWINDOW_H
