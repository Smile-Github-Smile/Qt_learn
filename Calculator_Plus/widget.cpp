#include "widget.h"
#include "ui_widget.h"

widget::widget(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::widget)
{
    ui->setupUi(this);
    this->setWindowTitle("计算器"); //设置软件标题
}

widget::~widget()
{
    delete ui;
}


void widget::on_btnCal_clicked()  //计算总价
{
    float num = ui->editNum->text().toFloat();
    float price = ui->editPrice->text().toFloat();
    float total = num * price; //相乘计算

    QString str;
    str = str.sprintf("%.2f" , total);
    ui->editTotal->setText(str);
}

void widget::on_btnDec_clicked() //十进制转化
{
    int value = ui->editDce->text().toInt();
    QString str = QString::number(value , 16);
    str = str.toUpper(); //小写转大写
    ui->editHex->setText(str);

    str = QString::number(value , 8);
    ui->editOct->setText(str);

    str = QString::number(value , 2);
    ui->editBin->setText(str);
}

void widget::on_btnBin_clicked() //二进制转化
{
    bool ok;
    int value = ui->editBin->text().toInt(&ok , 2);//以二进制数读入
    QString str = QString::number(value , 10);
    ui->editDce->setText(str);

    str = QString::number(value , 8);
    ui->editOct->setText(str);

    str = QString::number(value , 16);
    str = str.toUpper(); //小写转大写
    ui->editHex->setText(str);
}

void widget::on_btnOct_clicked() //八进制转化
{
    bool ok;
    int value = ui->editOct->text().toInt(&ok , 8);
    QString str = QString::number(value , 10);
    ui->editDce->setText(str);

    str = QString::number(value , 2);
    ui->editBin->setText(str);

    str = QString::number(value , 16);
    str = str.toUpper(); //小写转大写
    ui->editHex->setText(str);
}

void widget::on_btnHex_clicked() //十六进制转化
{
    bool ok;
    int value = ui->editHex->text().toInt(&ok , 16);
    QString str = QString::number(value , 10);
    ui->editDce->setText(str);

    str = QString::number(value , 2);
    ui->editBin->setText(str);

    str = QString::number(value , 8);
    ui->editOct->setText(str);
}
