

#include <iostream>
using namespace std;

/**
 * @file static-fun.cpp
 * @author zp
 * @brief 
 * @version 0.1
 * @date 2020-07-20
 * 
 * 
 * 静态成员函数： 在类中，static 除了可以声明静态成员变量，还可以声明静态成员函数。
 *              普通成员函数可以访问所有成员（包括成员变量和成员函数），静态成员函数只能访问静态成员。
 * 
 * 静态成员函数与普通成员函数区别：普通成员函数有 this 指针，可以访问类中的任意成员；而静态成员函数没有 this 指针，
 *                            只能访问静态成员（包括静态成员变量和静态成员函数）
 * 
 */
class Student
{
public:
    Student(const char *name, int age, float score);
    void show();

public: //声明静态成员函数
    static int getTotal();
    static float getPoints();

private:
    static int m_total;    //总人数
    static float m_points; //总成绩
private:
    const char *m_name;
    int m_age;
    float m_score;
};
int Student::m_total = 0;
float Student::m_points = 0.0;
Student::Student(const char *name, int age, float score) : m_age(age), m_score(score)
{
    this->m_name = name;
    m_total++;
    m_points += score;
}
void Student::show()
{
    cout << m_name << "的年龄是" << m_age << "，成绩是" << m_score << endl;
}
//定义静态成员函数
int Student::getTotal()
{
    return m_total;
}
float Student::getPoints()
{
    return m_points;
}
int main()
{
    (new Student("小明", 15, 90.6))->show();
    (new Student("李磊", 16, 80.5))->show();
    (new Student("张华", 16, 99.0))->show();
    (new Student("王康", 14, 60.8))->show();
    // Student *ss=new Student("王康2", 14, 60.8);
    // int total = ss->getTotal();
    int total = Student::getTotal();
    float points = Student::getPoints();
    cout << "当前共有" << total << "名学生，总成绩是" << points << "，平均分是" << points / total << endl;

    return 0;
}