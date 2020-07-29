#include <iostream>
using namespace std;

class A
{
public:
    A(){};
    virtual void func() { cout << "构造A" << endl; };
    ~A(){};
    virtual void fund() { cout << "清除A" << endl; };
};

class B : public A
{
public:
    B() { func(); };
    void fun()
    {
        cout << "开始" << endl;
        func();
    };
    ~B() { fund(); };
};

class C : public B
{
public:
    C(){};//构造函数不可以为虚函数
    void func() { cout << "类C" << endl; };
    ~C() { fund(); };//析构函数可以为虚函数，且只能有一个
    void fund() { cout << "清除C" << endl; };
};

int main()
{
    C c;
    c.fun();
    return 0;
}
// 构造A
// 开始
// 类C
// 清除C
// 清除A