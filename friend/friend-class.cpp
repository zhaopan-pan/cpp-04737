#include <iostream>
using namespace std;
/**
 * @brief 友元类：
 *        不仅可以将一个函数声明为一个类的“朋友”，还可以将整个类声明为另一个类的“朋友”，这就是友元类。友元类中的所有成员函数都是另外一个类的友元函数。
 * 
 * 总结：1、友元的关系是单向的而不是双向的。如果声明了类 B 是类 A 的友元类，不等于类 A 是类 B 的友元类，类 A 中的成员函数不能访问类 B 中的 private 成员。
 *      2、友元的关系不能传递。如果类 B 是类 A 的友元类，类 C 是类 B 的友元类，不等于类 C 是类 A 的友元类。
 * 
 * 注意：除非有必要，一般不建议把整个类声明为友元类，而只将某些成员函数声明为友元函数，这样更安全一些。
 */

class Address; //提前声明Address类

//声明Student类
class Student
{
public:
    Student(char const *name, int age, float score);

public:
    void show(Address *addr);

private:
    char const *m_name;
    int m_age;
    float m_score;
};

//声明Address类
class Address
{
public:
    Address(char const *province, char const *city, char const *district);

public:
    //将Student类声明为Address类的友元类
    friend class Student;

private:
    char const *m_province; //省份
    char const *m_city;     //城市
    char const *m_district; //区（市区）
};

//实现Student类
Student::Student(char const *name, int age, float score) : m_name(name), m_age(age), m_score(score) {}
void Student::show(Address *addr)
{
    cout << m_name << "的年龄是 " << m_age << "，成绩是 " << m_score << endl;
    cout << "家庭住址：" << addr->m_province << "省" << addr->m_city << "市" << addr->m_district << "区" << endl;
}

//实现Address类
Address::Address(char const *province, char const *city, char const *district)
{
    m_province = province;
    m_city = city;
    m_district = district;
}

int main()
{
    Student stu("小明", 16, 95.5f);
    Address addr("陕西", "西安", "雁塔");
    stu.show(&addr);

    Student *pstu = new Student("李磊", 16, 80.5);
    Address *paddr = new Address("河北", "衡水", "桃城");
    pstu->show(paddr);

    return 0;
}