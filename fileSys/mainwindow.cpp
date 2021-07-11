#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    model = new QFileSystemModel(this); //提供单独线程
    model->setRootPath(QDir::currentPath());  //设置当前路径为根目录

    ui->treeView->setModel(model);  //设置数据模型
    ui->listView->setModel(model);  //设置数据模型
    ui->tableView->setModel(model); //设置数据模型

    //信号与槽关联
    connect(ui->treeView , SIGNAL(clicked(QModelIndex)) , ui->listView , SLOT(setRootIndex(QModelIndex)));
    connect(ui->treeView , SIGNAL(clicked(QModelIndex)) , ui->tableView , SLOT(setRootIndex(QModelIndex)));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_treeView_clicked(const QModelIndex &index)
{
    ui->chklsDir->setChecked(model->isDir(index)); //获取检测状态
    ui->labPath->setText(model->filePath(index));  //获取文件路径
    ui->labType->setText(model->type(index));      //获取文件类型

    ui->labFileName->setText(model->fileName(index)); //获取文件名字
    int sz = model->size(index) / 1024;

    if(sz < 1024)
    {
        ui->labFileSize->setText(QString("%1 KB").arg(sz));
    }
    else
    {
        ui->labFileSize->setText(QString::asprintf("%.1f MB" , sz / 1024.0));
    }

}
