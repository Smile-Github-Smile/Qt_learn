#include "qwdialogsize.h"
#include "ui_qwdialogsize.h"
#include    <QMessageBox>

qwdialogsize::qwdialogsize(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::qwdialogsize)
{
    ui->setupUi(this);
}

qwdialogsize::~qwdialogsize()
{
    QMessageBox::information(this,"提示","设置表格行列数对话框被删除");
    delete ui;
}

int qwdialogsize::rowCount()
{ //用于主窗口调用获得行数的输入值
    return  ui->spinBoxRow->value();
}

int qwdialogsize::columnCount()
{//用于主窗口调用获得列数的输入值
    return  ui->spinBoxColumn->value();
}

void qwdialogsize::setRowColumn(int row, int column)
{ //初始化数据显示
    ui->spinBoxRow->setValue(row);
    ui->spinBoxColumn->setValue(column);
}
