#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    label = new Label;
    label->output.setParent(this);
    label->output.setAlignment(Qt::AlignCenter);
    label->output.setGeometry(130,140,100,41);
    label->start();
    temp = new StepCounterAlgo(label);
    checkButton = true;
}

MainWindow::~MainWindow()
{
    delete ui;
    ui = nullptr;
    delete temp;
    temp = nullptr;

}

void MainWindow::on_Start_clicked()
{
    temp->start();
}


void MainWindow::on_Stop_clicked()
{
    temp->checkButton = false;
}


void MainWindow::on_reset_clicked()
{
    temp->reset();
}

