#include <iostream>
using namespace std;

/**
 * @brief 常对象
 * 
 *  定义：一旦将对象定义为常对象之后，就只能调用类的 const 成员（包括 const 成员变量和 const 成员函数）了。
 * 
 * 定义常对象的语法和定义常量的语法类似：
 *                                  const  class  object(params);
 *                                  class const object(params);
 * 
 * 也可以定义 const 指针：
 *                      const class *p = new class(params);
 *                      class const *p = new class(params);
 * 
 * 以上两种方式定义出来的对象都是常对象。class为类名，object为对象名，params为实参列表，p为指针名。
 * 
 * 注意：  一旦将对象定义为常对象之后，不管是哪种形式，该对象就只能访问被 const 修饰的成员了（包括 const 成员变量和 const 成员函数），
 *         因为非 const 成员可能会修改对象的数据（编译器也会这样假设），C++禁止这样做
 * 
 */

class Student
{
public:
    Student(const char *name, int age, float score);

public:
    void show();
    char const *getname() const;
    int getage() const;
    float getscore() const;

private:
    const char *m_name;
    int m_age;
    float m_score;
};
Student::Student(const char *name, int age, float score) : m_age(age), m_score(score) { this->m_name = name; }
void Student::show()
{
    cout << m_name << "的年龄是" << m_age << "，成绩是" << m_score << endl;
}
char const *Student::getname() const
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
 * @brief 
 *         本例中，stu、pstu 分别是常对象以及常对象指针，它们都只能调用 const 成员函数。
 * @return int 
 */
int main()
{
    const Student stu("小明", 15, 90.6);
    //stu.show();  //error
    cout << stu.getname() << "的年龄是" << stu.getage() << "，成绩是" << stu.getscore() << endl;
    const Student *pstu = new Student("李磊", 16, 80.5);
    //pstu -> show();  //error
    cout << pstu->getname() << "的年龄是" << pstu->getage() << "，成绩是" << pstu->getscore() << endl;
    return 0;
}