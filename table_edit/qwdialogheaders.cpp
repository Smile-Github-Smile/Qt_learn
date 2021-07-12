#include "qwdialogheaders.h"
#include "ui_qwdialogheaders.h"
#include    <QMessageBox>

qwdialogheaders::qwdialogheaders(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::qwdialogheaders)
{
    ui->setupUi(this);
    model= new QStringListModel;
    ui->listView->setModel(model);
}

qwdialogheaders::~qwdialogheaders()
{
    QMessageBox::information(this,"提示","设置表头标题对话框被删除");
    delete ui;
}

void qwdialogheaders::setHeaderList(QStringList &headers)
{
    model->setStringList(headers);
}

QStringList qwdialogheaders::headerList()
{
    return  model->stringList();
}
