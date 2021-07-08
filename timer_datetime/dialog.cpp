#include "dialog.h"
#include "ui_dialog.h"
#include <QDateTime>

dialog::dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::dialog)
{
    ui->setupUi(this);
    setWindowTitle("日历与定时器");
    fTimer = new QTimer(this); //创建定时器
    fTimer->stop();
    fTimer->setInterval(1000); //设置定时器周期，单位：毫秒
    connect(fTimer , SIGNAL(timeout()) , this , SLOT(on_timer_timeout()));
}

dialog::~dialog()
{
    delete ui;
}


void dialog::on_btnGetTime_clicked()
{
    QDateTime curDateTime = QDateTime::currentDateTime();

    ui->timeEdit->setTime(curDateTime.time()); //设置时间
    ui->editTime->setText(curDateTime.toString("hh:mm:ss"));

    ui->dateEdit->setDate(curDateTime.date()); //设置日期
    ui->editDate->setText(curDateTime.toString("yyyy-mm-dd"));

    ui->dateTimeEdit->setDateTime(curDateTime); //设置日期时间
    ui->editDateTime->setText(curDateTime.toString("yyyy-mm-dd hh:mm:ss"));

    ui->calendarWidget->setSelectedDate(curDateTime.date()); //更新日历日期
}

void dialog::on_btnStart_clicked()
{
    fTimer->start(); //启动定时器
    fTimeCounter.start(); //启动计时器

    ui->btnStart->setEnabled(false);
    ui->btnStop->setEnabled(true);
    ui->btnSetIntv->setEnabled(false);
}

void dialog::on_btnStop_clicked()
{
    fTimer->stop(); //停止定时器
    int tmMsec = fTimeCounter.elapsed(); //毫秒数
    int ms = tmMsec % 1000; //毫秒
    int sec = tmMsec / 1000; //秒

    QString str = QString::asprintf("流逝时间：%d 秒，%d 毫秒" , sec , ms);
    ui->labElapsTime->setText(str);
    ui->btnStart->setEnabled(true);
    ui->btnStop->setEnabled(false);
    ui->btnSetIntv->setEnabled(true);
}

void dialog::on_btnSetIntv_clicked() //设置定时器的周期值
{
    fTimer->setInterval(ui->spinBoxIntv->value());
}

void dialog::on_timer_timeout()       //定时器中断处理槽函数
{
    QTime curTime = QTime::currentTime();

    ui->lcdHour->display(curTime.hour());  //显示时
    ui->lcdMin->display(curTime.minute()); //显示分
    ui->lcdSec->display(curTime.second()); //显示秒
}
