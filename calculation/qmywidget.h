#ifndef QMYWIDGET_H
#define QMYWIDGET_H

#include <QWidget>
#include "qperson.h"

QT_BEGIN_NAMESPACE
namespace Ui { class qmywidget; }
QT_END_NAMESPACE

class qmywidget : public QWidget
{
    Q_OBJECT

private:
    QPerson *boy;
    QPerson *girl;


public:
    qmywidget(QWidget *parent = nullptr);
    ~qmywidget();

private slots:
    //自定义的槽函数
    void on_ageChanged(int value);
    void on_spin_valueChanged(int arg);
    //界面按钮的槽函数
    void on_btnGirlInc_clicked();   //女生加1
    void on_btnBoyInc_clicked();    //男生加1
    void on_btnClear_clicked();     //清除编辑区
    void on_btnClassInfo_clicked(); //类信息

private:
    Ui::qmywidget *ui;
};
#endif // QMYWIDGET_H
