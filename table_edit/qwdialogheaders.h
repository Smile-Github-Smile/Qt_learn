#ifndef QWDIALOGHEADERS_H
#define QWDIALOGHEADERS_H

#include <QDialog>
#include    <QStringListModel>

namespace Ui {
class qwdialogheaders;
}

class qwdialogheaders : public QDialog
{
    Q_OBJECT

private:
    QStringListModel  *model;

public:
    explicit qwdialogheaders(QWidget *parent = nullptr);
    ~qwdialogheaders();

    void setHeaderList(QStringList& headers);
    QStringList headerList();

private:
    Ui::qwdialogheaders *ui;
};

#endif // QWDIALOGHEADERS_H
