#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "stepcounteralgo.h"
#include "label.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Ui::MainWindow *ui;
    StepCounterAlgo *temp;
    QThread *thread;
    Label *label;
    bool checkButton;

private slots:
    void on_Start_clicked();
    void on_Stop_clicked();
    void on_reset_clicked();

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

};
#endif // MAINWINDOW_H
