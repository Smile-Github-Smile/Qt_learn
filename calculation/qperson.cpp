#include "qperson.h"

QPerson::QPerson(QString fName,QObject *parent):QObject(parent)
{
    m_name = fName;
}

int QPerson::age() //返回年龄
{
    return m_age;
}

void QPerson::setAge(int value) //设置年龄
{
    m_age = value;
    emit ageChanged(m_age); //发射信号
}

void QPerson::incAge() //递增年龄
{
    m_age++;
    emit ageChanged(m_age);  //发射信号
}
