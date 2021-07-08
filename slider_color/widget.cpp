#include "widget.h"
#include "ui_widget.h"

widget::widget(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::widget)
{
    ui->setupUi(this);
    connect(ui->sliderRed,SIGNAL(valueChanged(int)),this,SLOT(on_sliderColor_valueCchange(int)));
    connect(ui->sliderGreen,SIGNAL(valueChanged(int)),this,SLOT(on_sliderColor_valueCchange(int)));
    connect(ui->sliderBlue,SIGNAL(valueChanged(int)),this,SLOT(on_sliderColor_valueCchange(int)));

}

widget::~widget()
{
    delete ui;
}

void widget::on_dial_valueChanged(int value)
{
    ui->lcdDisplay->display(value);
}

void widget::on_radioBtnDec_clicked() //LCD十进制显示
{
    ui->lcdDisplay->setDigitCount(3);
    ui->lcdDisplay->setDecMode();
}

void widget::on_radioBtnBin_clicked() //LCD二进制显示
{
    ui->lcdDisplay->setDigitCount(8);
    ui->lcdDisplay->setBinMode();
}

void widget::on_radioBtnOct_clicked() //LCD八进制显示
{
    ui->lcdDisplay->setDigitCount(4);
    ui->lcdDisplay->setOctMode();
}

void widget::on_radioBtnHex_clicked() //LCD十六进制显示
{
    ui->lcdDisplay->setDigitCount(3);
    ui->lcdDisplay->setHexMode();
}

void widget::on_sliderH_valueChanged(int value)
{
   ui->progBarH->setValue(value);
   ui->scrollBarH->setValue(value);
}

void widget::on_sliderV_valueChanged(int value)
{
    ui->progBarV->setValue(value);
    ui->scrollBarV->setValue(value);
}

void widget::on_scrollBarH_valueChanged(int value)
{
    ui->progBarH->setValue(value);
}

void widget::on_scrollBarV_valueChanged(int value)
{
    ui->progBarV->setValue(value);
}

void widget::on_sliderColor_valueCchange(int value)
{
    Q_UNUSED(value);
    QColor color;

    int R = ui->sliderRed->value();
    int G = ui->sliderGreen->value();
    int B = ui->sliderBlue->value();
    int alpha = ui->sliderAlpha->value();

    color.setRgb(R,G,B,alpha);

    QPalette pal = ui->textEdit->palette();
    pal.setColor(QPalette::Base,color);
    ui->textEdit->setPalette(pal);
}
