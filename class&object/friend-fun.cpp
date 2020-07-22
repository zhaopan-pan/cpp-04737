#include <iostream>
using namespace std;

/**
 * @brief   友元（friend）
 *     作用：借助友元，可以使得其他类中的成员函数以及全局范围内的函数访问当前类的 private 成员。
 * 
 *  友元函数：1、在当前类以外定义的、不属于当前类的函数也可以在类中声明，但要在前面加 friend 关键字，这样就构成了友元函数
 *          2、友元函数可以是不属于任何类的非成员函数，也可以是其他类的成员函数。
 *          3、友元函数可以访问当前类中的所有成员，包括 public、protected、private 属性的。
 */


class Student{
public:
    Student(char const *name, int age, float score);
public:
    friend void show(Student *pstu);  //将show()声明为友元函数
private:
    char const *m_name;
    int m_age;
    float m_score;
};
Student::Student(char const *name, int age, float score): m_name(name), m_age(age), m_score(score){ }
/**
 * @brief 非成员函数
 * 注意 ：show() 是一个全局范围内的非成员函数，它不属于任何类，它的作用是输出学生的信息。m_name、m_age、m_score 是 Student 类的 private 成员，
 *       原则上不能通过对象访问，但在 show() 函数中又必须使用这些 private 成员，所以将 show() 声明为 Student 类的友元函数。
 * 
 * @param pstu 
 */
void show(Student *pstu){
    cout<<pstu->m_name<<"的年龄是 "<<pstu->m_age<<"，成绩是 "<<pstu->m_score<<endl;
}
int main(){
    Student stu("小明", 15, 90.6);
    show(&stu);  //调用友元函数
    Student *pstu = new Student("李磊", 16, 80.5);
    show(pstu);  //调用友元函数
    return 0;
}

