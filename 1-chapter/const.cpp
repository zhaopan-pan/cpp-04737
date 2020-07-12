#include <iostream>
using namespace std;

int main()
{
    // int a = 33;
    // int a1=12;
    // int * const p=&a;//p指针地址不能变
    /**  *p=a1;           //通过改变*p改变指针的内容，即a的值 **/
    // cout << "a:" << a << '\n';  //12
    // cout << "a1:" << &a1 << '\n';
    // cout << "*p:" << *p << '\n';//12

    int a = 33;
    int a1 = 12;
    const int * p = &a;         //p指针地址指向的值不能变
    p = &a1;                   //可以改变p指针的指向
    cout << "a:" << a << '\n'; //12
    cout << "a1:" << &a1 << '\n';
    cout << "*p:" << p << '\n'; //12
    return 0;
}