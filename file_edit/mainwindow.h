#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QProgressBar>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    QString         fCurFileName;  //当前文件名
    QLabel          *fLabCurFile;  //状态栏里显示当前的Label
    QProgressBar    *progressBar; //状态栏上的进度条

    void updateCurFile(QString aFile);
    void initUI();  //程序设计UI初始化
    void initSignalSlots();  //手动关联信号与槽

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actFontBold_triggered(bool checked);   //粗体
    void on_actFontItalic_triggered(bool checked); //斜体
    void on_actFontUnder_triggered(bool checked);  //下划线

    void on_actNew_triggered();   //新建文件
    void on_actOpen_triggered();  //打开文件

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
