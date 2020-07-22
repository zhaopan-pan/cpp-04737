#include <iostream>
using namespace std;

/**
 * @file const-fun.cpp
 * @author zp
 * @brief 
 * @version 0.1
 * @date 2020-07-20
 * 
 * @copyright Copyright (c) 2020
 * 
 * 
 * 常成员函数：const 成员函数可以使用类中的所有成员变量，但是不能修改它们的值，这种措施主要还是为了保护数据而设置的。
 *            const 成员函数也称为常成员函数。
 */
class Student
{
public:
    Student(char *name, int age, float score);
    void show();
    //声明常成员函数
    char *getname() const;
    int getage() const;
    float getscore() const;

private:
    char *m_name;
    int m_age;
    float m_score;
};

Student::Student(char *name, int age, float score) : m_name(name), m_age(age), m_score(score) {}
void Student::show()
{
    cout << m_name << "的年龄是" << m_age << "，成绩是" << m_score << endl;
}
//定义常成员函数
char *Student::getname() const
{
    return m_name;
}
int Student::getage() const
{
    return m_age;
}
float Student::getscore() const
{
    return m_score;
}

/**
 * @brief 随堂小记
 * 
 *                注意： 必须在成员函数的声明和定义处同时加上 const 关键字。 char *getname() const和char *getname()是两个不同的函数原型，
 *                      如果只在一个地方加 const 会导致声明和定义处的函数原型冲突。
 * 
 * 区分一下 const 的位置：1、函数开头的 const 用来修饰函数的返回值，表示返回值是 const 类型，也就是不能被修改，例如const char * getname()。
 *                     2、函数头部的结尾加上 const 表示常成员函数，这种函数只能读取成员变量的值，而不能修改成员变量的值，例如char * getname() const。
 */