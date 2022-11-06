#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:
    void digits_numbers();
    void on_pushButton_tochk_clicked();
    void operations();
    void on_pushButton_clear_clicked();
    void math_operations();
    void on_pushButton_ravn_clicked();
};

#endif // MAINWINDOW_H
