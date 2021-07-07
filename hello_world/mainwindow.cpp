#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)  //对ui进行赋值操作
{
    ui->setupUi(this);        //对界面进行初始化
}

MainWindow::~MainWindow()
{
    delete ui;
}

