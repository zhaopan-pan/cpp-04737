#include <iostream>
using namespace std;

/**
 * @brief 
 * 
 * this: 1、this 是 C++ 中的一个关键字，也是一个 const 指针，它指向当前对象，通过它可以访问当前对象的所有成员。
 *       2、this 实际上是成员函数的一个形参，在调用成员函数时将对象的地址作为实参传递给 this。不过 this 这个形参是隐式的，它并不出现在代码中，
 *          而是在编译阶段由编译器默默地将它添加到参数列表中。
 *       3、this 作为隐式形参，本质上是成员函数的局部变量，所以只能用在成员函数的内部，并且只有在通过对象调用成员函数时才给 this 赋值。
 * 拓展: 成员函数最终被编译成与对象无关的普通函数，除了成员变量，会丢失所有信息，所以编译时要在成员函数中添加一个额外的参数，把当前对象的首地址传入，以此来关联成员函数和成员变量。
 *       这个额外的参数，实际上就是 this，它是成员函数和成员变量关联的桥梁。
 * 
 * 注意: 1、this 是一个指针，要用->来访问成员变量或成员函数。
 *      2、this 是 const 指针，它的值是不能被修改的，一切企图修改该指针的操作，如赋值、递增、递减等都是不允许的。
 *      3、this 只能在成员函数内部使用，用在其他地方没有意义，也是非法的。
 *      4、只有当对象被创建后 this 才有意义，因此不能在 static 成员函数中使用（后续会讲到 static 成员）。
 */
class Student
{
private:
    char const *name;
    int age;
    double score;

public:
    void setName(char const *name);
    void setAge(int age);
    void setScore(double score);
    void info();
};

void Student::setName(char const *name)
{
    this->name = name;
}
void Student::setAge(int age)
{
    this->age = age;
}
void Student::setScore(double score)
{
    this->score = score;
}
void Student::info()
{
    cout << this->name << "的年龄是" << this->age << "，成绩是" << this->score << endl;
}
int main()
{
    Student *stu = new Student;
    char const *stuName = "zp";
    stu->setName(stuName);
    stu->setAge(24);
    stu->setScore(60.0);
    stu->info();
    return 0;
}