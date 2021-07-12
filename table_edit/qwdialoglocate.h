#ifndef QWDIALOGLOCATE_H
#define QWDIALOGLOCATE_H

#include <QDialog>

namespace Ui {
class qwdialoglocate;
}

class qwdialoglocate : public QDialog
{
    Q_OBJECT

private:
    void closeEvent(QCloseEvent *event);
    void showEvent(QShowEvent *event);

public:
    explicit qwdialoglocate(QWidget *parent = nullptr);
    ~qwdialoglocate();

    void    setSpinRange(int rowCount, int colCount); //设置最大值
    void    setSpinValue(int rowNo, int colNo);//设置初始值

private slots:
    void on_btnSetText_clicked();


private:
    Ui::qwdialoglocate *ui;
};

#endif // QWDIALOGLOCATE_H
