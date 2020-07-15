#include <iostream>
#include <string>
using namespace std;

/**
 * @brief 
 * 
 * 析构函数：
 *      析构函数（Destructor）也是一种特殊的成员函数，没有返回值，不需要程序员显式调用（程序员也没法显式调用），而是在销毁对象时自动执行。
 *      构造函数的名字和类名相同，而析构函数的名字是在类名前面加一个~符号
 * 
 * 动机：析构函数在对象被销毁时调用，而对象的销毁时机与它所在的内存区域有关。
 *      在所有函数之外创建的对象是全局对象，它和全局变量类似，位于内存分区中的全局数据区，程序在结束执行时会调用这些对象的析构函数。
 *      在函数内部创建的对象是局部对象，它和局部变量类似，位于栈区，函数执行结束时会调用这些对象的析构函数。
 * 
 * @注意:析构函数没有参数，不能被重载，因此一个类只能有一个析构函数。如果用户没有定义，编译器会自动生成一个默认的析构函数。
 */
class Demo
{
public:
    Demo(string s);
    ~Demo();

private:
    string m_s;
};
Demo::Demo(string s) : m_s(s) {}
Demo::~Demo() { cout << m_s << endl; }
void func()
{
    //局部对象
    Demo obj1("1");
}
//全局对象
Demo obj2("2");
int main()
{
    //局部对象
    Demo obj3("3");
    //new创建的对象
    Demo *pobj4 = new Demo("4"); //new 创建的对象位于堆区，通过 delete 删除时才会调用析构函数；如果没有 delete，析构函数就不会被执行。
    func();                      //程序在结束执行时会调用这些对象的析构函数。
    cout << "main" << endl;

    return 0;
}
// 打印结果：
// 1
// main
// 3
// 2