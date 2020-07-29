#include <iostream>
using namespace std;

class Student
{
private:
    string m_name;
    int m_age;
    float m_score;

public:
    Student(string name = "", int age = 0, float score = 0)
    {
        m_name = name;
        m_age = age;
        m_score = score;
    };
    //声明复制构造函数
    Student(Student &stu)
    {
        m_name = stu.m_name;
        m_age = stu.m_age;
        m_score = stu.m_score;
    }
    //类成员函数
    void say();
    ~Student()
    {
        cout << "销毁" << endl;
    }
};

void Student::say()
{
    cout << m_name << "的分数是" << m_score << endl;
}

void say1(Student &p)
{
    p.say();
}
void say11(Student *p)
{
    p->say();
}
void say2(Student p)
{
    p.say();
}
int main()
{
    Student stu("小明", 21, 43.5f);
    stu.say();
    Student s(stu); //把stu对象的值复制到s
    s.say();
    say1(s);   //更节省空间，只是传递别名而已，并不会调用构造函数
    say11(&s); //更节省空间，只是对象指针地址而已，并不会调用构造函数，等效上面
    say2(s);   //需要调用复制构造函数，给p对象分配空间，然后最后还要释放掉
    return 0;
};