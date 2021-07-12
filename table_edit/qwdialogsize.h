#ifndef QWDIALOGSIZE_H
#define QWDIALOGSIZE_H

#include <QDialog>

namespace Ui {
class qwdialogsize;
}

class qwdialogsize : public QDialog
{
    Q_OBJECT

public:
    explicit qwdialogsize(QWidget *parent = nullptr);
    ~qwdialogsize();

    int     rowCount();//获取对话框输入的行数
    int     columnCount();//获取对话框输入的列数
    void    setRowColumn(int row, int column); //初始对话框上两个SpinBox的值

private:
    Ui::qwdialogsize *ui;
};

#endif // QWDIALOGSIZE_H
