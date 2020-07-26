#include <iostream>
using namespace std;

class Student
{
private:
    string m_name;
    int m_age;
    float m_score;

public:
    Student()
    {
        m_name = "";
        m_age = 0;
        m_score = 0;
    };
    //自定义构造函数 给成员变量初始化
    Student(string name, int age, float score)
    {
        m_name = name;
        m_age = age;
        m_score = score;
    }
    //类成员函数
    void say();
};

void Student::say()
{
    cout << m_name << "的分数是" << m_score << endl;
}

int main()
{
    Student stu("小明", 21, 43.5f);
    stu.say();
    Student *s = new Student();
    s->say();
    return 0;
};