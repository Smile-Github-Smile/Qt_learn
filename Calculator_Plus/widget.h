#ifndef WIDGET_H
#define WIDGET_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class widget; }
QT_END_NAMESPACE

class widget : public QMainWindow
{
    Q_OBJECT

public:
    widget(QWidget *parent = nullptr);
    ~widget();

private slots:
    void on_btnCal_clicked();  //计算总价
    void on_btnDec_clicked();  //十进制转化为其他进制
    void on_btnBin_clicked();  //二进制转化为其他进制
    void on_btnOct_clicked();  //八进制转化为其他进制
    void on_btnHex_clicked();  //十六进制转化为其他进制

private:
    Ui::widget *ui;
};
#endif // WIDGET_H
