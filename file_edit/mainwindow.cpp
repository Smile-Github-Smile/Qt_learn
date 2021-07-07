#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    initUI();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateCurFile(QString aFile) //更新当前文件名，并更新状态栏提示
{
    fCurFileName = aFile;
    fLabCurFile->setText("当前文件："+fCurFileName);
}

void MainWindow::initUI()
{
    //状态栏
    fLabCurFile = new QLabel;  //用于显示当前文件名标签
    fLabCurFile->setMinimumWidth(150);
    fLabCurFile->setText("当前文件：");
    ui->statusBar->addWidget(fLabCurFile);//添加到状态栏

    progressBar = new QProgressBar;//状态栏上的进度条
    progressBar->setMaximumWidth(200);//设置组件最大宽度
    progressBar->setMinimum(5);
    progressBar->setMaximum(50);
    progressBar->setValue(ui->textEdit->font().pointSize());//初始值
    ui->statusBar->addWidget(progressBar); //添加到状态栏

}

void MainWindow::on_actFontBold_triggered(bool checked)  //字体加粗设置
{
    QTextCharFormat fmt; //格式
    fmt = ui->textEdit->currentCharFormat();//获取当前选择文字的格式

    if (checked) //相当于调用ui->actFontBold->isChecked();读取Action的check状态
        fmt.setFontWeight(QFont::Bold); //设置字体宽度
    else
        fmt.setFontWeight(QFont::Normal);

    ui->textEdit->mergeCurrentCharFormat(fmt);
}

void MainWindow::on_actFontItalic_triggered(bool checked) //字体斜体设置
{
    QTextCharFormat fmt;
    fmt = ui->textEdit->currentCharFormat();
    fmt.setFontItalic(checked); //设置斜体
    ui->textEdit->mergeCurrentCharFormat(fmt);
}



void MainWindow::on_actFontUnder_triggered(bool checked) //字体下划线设置
{
    QTextCharFormat fmt;
    fmt = ui->textEdit->currentCharFormat();
    fmt.setFontUnderline(checked); //设置下划线
    ui->textEdit->mergeCurrentCharFormat(fmt);
}

void MainWindow::on_actNew_triggered()  //新建文件
{
    ui->textEdit->clear();  //清楚文本编辑框
//    updateCurFile("");
}

void MainWindow::on_actOpen_triggered() //打开文件
{
    QString curPath , aFileName;
    curPath = QCoreApplication::applicationDirPath(); //获取应用程序的路径

    //调用打开文件对话框打开一个文件
    aFileName = QFileDialog::getOpenFileName(this,tr("打开文件"),curPath,
                 "C源文件(*.c);;C++源文件(*.cpp);;H头文件(*.h);;文本文件(*.txt);;所有文件(*.*)");

    if (!aFileName.isEmpty())
    {
        QFile aFile(aFileName);  //以文件方式读出

        if (aFile.open(QIODevice::ReadWrite | QIODevice::Text))
        {
            QTextStream aStream(&aFile); //用文本流读取文件
            while (!aStream.atEnd())
                ui->textEdit->append(aStream.readLine()); //读取一个文本行
            updateCurFile(aFileName); //更新状态栏显示
        }
        aFile.close();
    }
}
