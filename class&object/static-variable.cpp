#include <iostream>
using namespace std;

/**
 * @file static.cpp
 * @author zp
 * @brief 
 * @version 0.1
 * @date 2020-07-20
 * 
 * @copyright Copyright (c) 2020
 * 
 * 对象的内存中包含了成员变量，不同的对象占用不同的内存，这使得不同对象的成员变量相互独立，它们的值不受其他对象的影响。
 * 例如有两个相同类型的对象 a、b，它们都有一个成员变量 m_name，那么修改 a.m_name 的值不会影响 b.m_name 的值。
 * 可是有时候我们希望在多个对象之间共享数据，对象 a 改变了某份数据后对象 b 可以检测到。共享数据的典型使用场景是计数，以前面的 Student 类为例，
 * 如果我们想知道班级中共有多少名学生，就可以设置一份共享的变量，每次创建对象时让该变量加 1。
 * 
 * static:在C++中，我们可以使用静态成员变量来实现多个对象共享数据的目标。静态成员变量是一种特殊的成员变量，它被关键字static修饰
 */
class Student
{
private:
    /* data */
    const char *m_name;
    int m_age;
    float m_score;

private: //静态成员变量
    //static修饰的成员变量属于类，不属于某个具体的对象，即使创建多个对象，也只为 m_total 分配一份内存，
    //所有对象使用的都是这份内存中的数据。当某个对象修改了 m_total，也会影响到其他对象。
    static int m_total;

public:
    static int aaa;
    Student(const char *name, int age, float score);
    void show();
    ~Student();
};
//初始化静态成员变量
int Student::m_total = 0;
int Student::aaa = 0;

Student::Student(const char *name, int age, float score)
{
    this->m_name = name;
    this->m_age = age;
    this->m_score = score;
    m_total++; //操作静态成员变量
};
void Student::show()
{
    cout << m_name << "的年龄是" << m_age << "，成绩是" << m_score << "（当前共有" << m_total << "名学生）" << endl;
};
Student::~Student()
{
    cout << "结束" << endl;
}

int main()
{
    //创建匿名对象 (因为只访问show()函数，所以用了匿名对象，但使用匿名对象无法回收内存，会导致内存泄露，在中大型程序中不建议使用。)
    (new Student("小明", 15, 90))->show();
    (new Student("李磊", 16, 80))->show();
    (new Student("张华", 16, 99))->show();
    (new Student("王康", 14, 60))->show();
    cout << (new Student("王康", 14, 60))->aaa << endl;
    return 0;
}
//初始化 static成员变量的方式
//      int Student::m_total = 10;      //通过类类访问 static 成员变量
//      //访问 static成员变量的方式
//      Student stu("小明", 15, 92.5f); //通过对象来访问 static 成员变量
//      stu.m_total = 20;
//      //通过对象指针来访问 static 成员变量
//      Student *pstu = new Student("李华", 16, 96);
//      pstu -> m_total = 20;

/**
 * @brief  随堂小记
 * 初始化：static 成员变量必须在类声明的外部初始化，具体形式为：type class::name = value; 
 *        private、protected、public 修饰的静态成员变量都可以用这种方式初始化。
 * 
 *  注意：static 成员变量的内存既不是在声明类时分配，也不是在创建对象时分配，而是在（类外）初始化时分配。
 *       反过来说，没有在类外初始化的 static 成员变量不能使用。
 * 
 *  总结: 1、一个类中可以有一个或多个静态成员变量，所有的对象都共享这些静态成员变量，都可以引用它。
 * 
 *       2、static 成员变量和普通 static 变量一样，都在内存分区中的全局数据区分配内存，到程序结束时才释放。
 *         这就意味着，static 成员变量不随对象的创建而分配内存，也不随对象的销毁而释放内存。而普通成员变量在对象创建时分配内存，在对象销毁时释放内存。
 * 
 *       3、静态成员变量必须初始化，而且只能在类体外进行。初始化时可以赋初值，也可以不赋值。如果不赋值，那么会被默认初始化为 0。
 *         全局数据区的变量都有默认的初始值 0，而动态数据区（堆区、栈区）变量的默认值是不确定的，一般认为是垃圾值。
 * 
 *       4、静态成员变量既可以通过对象名访问，也可以通过类名访问，但要遵循 private、protected 和 public 关键字的访问权限限制。
 *         当通过对象名访问时，对于不同的对象，访问的是同一份内存。
 */