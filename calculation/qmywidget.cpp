#include "qmywidget.h"
#include "ui_qmywidget.h"
#include <QMetaProperty>

qmywidget::qmywidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::qmywidget)
{
    ui->setupUi(this);

    boy = new QPerson("小明");
    boy->setProperty("score","95");
    boy->setProperty("age","10");
    boy->setProperty("sex","Boy"); //动态属性
    connect(boy,&QPerson::ageChanged,this,&qmywidget::on_ageChanged);

    girl = new QPerson("小丽");
    girl->setProperty("score","85");
    girl->setProperty("age","20");
    girl->setProperty("sex","Girl");
    connect(girl,&QPerson::ageChanged,this,&qmywidget::on_ageChanged);

    ui->spinBoy->setProperty("isBoy",true);  //动态属性
    ui->spinGirl->setProperty("isBoy",false);

    connect(ui->spinBoy,SIGNAL(valueChanged(int)),this,SLOT(on_spin_valueChanged(int)));
    connect(ui->spinGirl,SIGNAL(valueChanged(int)),this,SLOT(on_spin_valueChanged(int)));

}

qmywidget::~qmywidget()
{
    delete ui;
}


void qmywidget::on_btnGirlInc_clicked()
{
    girl->incAge();
}

void qmywidget::on_btnBoyInc_clicked()
{
    boy->incAge();
}

void qmywidget::on_btnClear_clicked()  //清空文本框按钮
{
    ui->textEdit->clear();
}

void qmywidget::on_ageChanged(int value)
{
    Q_UNUSED(value);
    QPerson *aPerson = qobject_cast<QPerson *>(sender()); //类型投射
    QString hisName = aPerson->property("name").toString(); //姓名
    QString hisSex = aPerson->property("sex").toString(); //动态属性
    QString hisScore = aPerson->property("score").toString(); //姓名
    int hisAge = aPerson->age();//通过接口函数获取年龄
    ui->textEdit->append(hisName+","+hisSex+","+hisScore+QString::asprintf(",年龄=%d",hisAge));
}


void qmywidget::on_spin_valueChanged(int arg)//响应界面上spinBox的valueChanged(int)信号
{
    Q_UNUSED(arg);
    QSpinBox *spinBox = qobject_cast<QSpinBox *>(sender());

    if (spinBox->property("isBoy").toBool())
    {
        boy->setAge(spinBox->value());
    }
    else
    {
        girl->setAge(spinBox->value());
    }
}

void qmywidget::on_btnClassInfo_clicked()  //类的元对象信息
{
    const QMetaObject *meta = girl->metaObject();
    ui->textEdit->clear();

    ui->textEdit->append("==元对象信息==\n");
    ui->textEdit->append(QString("类名称：%1\n").arg(meta->className()));
    ui->textEdit->append("property");
    for(int ii = meta->propertyOffset() ; ii < meta->propertyCount() ; ii++)
    {
        const char* propName = meta->property(ii).name();
        ui->textEdit->append(QString("属性名称=%1,属性值=%2").arg(propName).arg(girl->property(propName).toString()));
    }

    meta = boy->metaObject();

    for(int ii = meta->propertyOffset() ; ii < meta->propertyCount() ; ii++)
    {
        const char* propName = meta->property(ii).name();
        ui->textEdit->append(QString("属性名称=%1,属性值=%2").arg(propName).arg(boy->property(propName).toString()));
    }

    ui->textEdit->append("");
    ui->textEdit->append("classInfo");
    for(int ii = meta->classInfoOffset() ; ii < meta->classInfoCount() ; ii++)
    {
        QMetaClassInfo classInfo = meta->classInfo(ii);
         ui->textEdit->append(QString("Name=%1; Value=%2").arg(classInfo.name()).arg(classInfo.value()));
    }
}
