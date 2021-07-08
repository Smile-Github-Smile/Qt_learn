#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QTimer>
#include <QTime>

QT_BEGIN_NAMESPACE
namespace Ui { class dialog; }
QT_END_NAMESPACE

class dialog : public QDialog
{
    Q_OBJECT

private:
    QTimer *fTimer;  //定时器
    QTime  fTimeCounter;//计时器

public:
    dialog(QWidget *parent = nullptr);
    ~dialog();

private slots:
    void on_btnGetTime_clicked();  //读取当前时间
    void on_btnStart_clicked();    //启动定时器
    void on_btnStop_clicked();     //停止定时器
    void on_btnSetIntv_clicked();  //设置定时周期

    void on_timer_timeout();       //定时器中断处理槽函数

private:
    Ui::dialog *ui;
};
#endif // DIALOG_H
