#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QMessageBox"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    int checkRadioButton();

    void checkFalse();

    void questInitial();

    void visibleFalse();

    void on_begin_pushButton_clicked();

    void on_tests_pushButton_clicked();

    void on_exit_pushButton_clicked();

    void on_basdai_pushButton_clicked();

    void on_basfi_pushButton_clicked();

    void on_next_pushButton_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
