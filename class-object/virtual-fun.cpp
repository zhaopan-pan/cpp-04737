#include <iostream>
using namespace std;
//基类People
class People
{
public:
    People(char const *name, int age);
    virtual void display(); // 为了方便，你可以只将基类中的函数声明为虚函数，这样所有派生类中具有遮蔽关系的同名函数都将自动成为虚函数。
    virtual void getName()
    {
        cout << m_name << endl;
    };

protected:
    char const *m_name;
    int m_age;
};
People::People(char const *name, int age) : m_name(name), m_age(age) {}
void People::display()
{
    cout << m_name << "今年" << m_age << "岁了，是个无业游民。" << endl;
}
//派生类Teacher
class Teacher : public People
{
public:
    Teacher(char const *name, int age, int salary);
    void display();
    void getName(char const *str)
    {
        cout << *str << endl;
    };

private:
    int m_salary;
};
Teacher::Teacher(char const *name, int age, int salary) : People(name, age), m_salary(salary) {}
void Teacher::display()
{
    cout << m_name << "今年" << m_age << "岁了，是一名教师，每月有" << m_salary << "元的收入。" << endl;
}
int main()
{
    People *p = new People("王志刚", 23);
    p->display();                        //王志刚今年23岁了，是个无业游民。
    p = new Teacher("赵宏佳", 45, 8200); //
    p->display();                        //赵宏佳今年45岁了，是一名教师，每月有8200元的收入。
    p->getName();                        //调用基类方法，虽然派生类Teacher中也有getName()，但是因为参数不同，所以不够生多态的条件
    //以下也可以用引用实现
    // People p("王志刚", 23);
    // Teacher t("赵宏佳", 45, 8200);
    // People &rp = p;
    // People &rt = t;
    // rp.display();
    // rt.display();
    return 0;
}

/**
 * @brief   虚函数：可以通过基类指针对所有派生类（包括直接派生和间接派生）的成员变量和成员函数进行“全方位”的访问，尤其是成员函数。
 *                 如果没有多态，我们只能访问成员变量
 * 
 *            作用： 有了虚函数，基类指针指向基类对象时就使用基类的成员（包括成员函数和成员变量），指向派生类对象时就使用派生类的成员。换句话说，基类指针可以按照基类的方式来做事，
 *                  也可以按照派生类的方式来做事，它有多种形态，或者说有多种表现方式，我们将这种现象称为多态（Polymorphism）。
 *          
 *构成多态多态的条件：1、必须存在继承关系；
 *                 2、继承关系中必须有同名的虚函数，并且它们是覆盖关系（函数原型相同）。
 *                 3、存在基类的指针，通过该指针调用虚函数。
 *              
 *            注意：1、当在基类中定义了虚函数时，如果派生类没有定义新的函数来遮蔽此函数，那么将使用基类的虚函数。
 *                 2、为了方便，你可以只将基类中的函数声明为虚函数，这样所有派生类中具有遮蔽关系的同名函数都将自动成为虚函数。
 *                 3、只有派生类的虚函数覆盖基类的虚函数（函数原型相同）才能构成多态（通过基类指针访问派生类函数）。例如基类虚函数的原型为virtual void func();，
 *                  派生类虚函数的原型为virtual void func(int);，那么当基类指针 p 指向派生类对象时，语句p -> func(100);将会出错，而语句p -> func();将调用基类的函数。
 *                 4、构造函数不能是虚函数。对于基类的构造函数，它仅仅是在派生类构造函数中被调用，这种机制不同于继承。
 *                  也就是说，派生类不继承基类的构造函数，将构造函数声明为虚函数没有什么意义。
 *                 5、析构函数可以声明为虚函数，而且有时候必须要声明为虚函数，这点我们将在下节中讲解。
 * 
 * 什么时候声明虚函数: 1、首先看成员函数所在的类是否会作为基类
 *                  2、看成员函数在类的继承后有无可能被更改功能，如果希望更改其功能的，一般应该将它声明为虚函数。
 *                  3、如果成员函数在类被继承后功能不需修改，或派生类用不到该函数，则不要把它声明为虚函数。

 * 
 */