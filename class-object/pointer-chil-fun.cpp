#include <iostream>
using namespace std;

class A
{
    int val;

public:
    A(int i)
    {
        val = i;
    };
    int value(int v)
    {
        return v + val;
    }
};
/**
 * @brief  指向成员函数的指针
 * @note   
 * @retval 
 */
int main()
{
    int (A::*pFun)(int);//声明指向A类成员函数的指针*pFun
    pFun = A::value;//指明pFun是value()函数
    A aa(10);
    cout << (aa.*pFun)(11) << endl;
    A *aaa = &aa;
    cout << aaa->value(12) << endl;
    return 0;
}