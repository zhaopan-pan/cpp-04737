#include <iostream>
using namespace std;

/**
 * @brief 将其他类的成员函数声明为友元函数
 *        friend 函数不仅可以是全局函数（非成员函数），还可以是另外一个类的成员函数。如下：
 *   总结：  1、哪个类中定义了友元函数，就可以在这个类中访问到此类的私有变量
 *          2、一个函数可以被多个类声明为友元函数，这样就可以访问多个类中的 private 成员。   
 */

class Address; //提前声明Address类 一般情况下，类必须在正式声明之后才能使用；但是某些情况下，只要做好提前声明，也可以先使用。
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
private:
    char const *m_province; //省份
    char const *m_city;     //城市
    char const *m_district; //区（市区）
public:
    Address(char const *province, char const *city, char const *district);
    //将Student类中的成员函数show()声明为友元函数
    friend void Student::show(Address *addr);
};
//实现Student类
Student::Student(char const *name, int age, float score) : m_name(name), m_age(age), m_score(score){};

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
