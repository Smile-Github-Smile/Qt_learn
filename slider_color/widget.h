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
    void on_radioBtnDec_clicked();
    void on_radioBtnBin_clicked();
    void on_radioBtnOct_clicked();
    void on_radioBtnHex_clicked();

    void on_dial_valueChanged(int value);
    void on_sliderH_valueChanged(int value);
    void on_sliderV_valueChanged(int value);
    void on_scrollBarH_valueChanged(int value);
    void on_scrollBarV_valueChanged(int value);

    void on_sliderColor_valueCchange(int value);

private:
    Ui::widget *ui;
};
#endif // WIDGET_H
