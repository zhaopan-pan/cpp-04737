#include <iostream>
using namespace std;

//间接基类A
class A
{
protected:
    int m_a;
};
//直接基类B
class B : virtual public A
{ //虚继承
protected:
    int m_b;
};
//直接基类C
class C : virtual public A
{ //虚继承
protected:
    int m_c;
};
//派生类D
class D : public B, public C
{
public:
    /**
 * @brief  直接访问成员变量 m_a，结果发生了错误，因为类 B 和类 C 中都有成员变量 m_a（从 A 类继承而来），
 *           编译器不知道选用哪一个，所以产生了歧义。
 * @note   
 * @param  a: 
 * @retval None
 */
    void seta(int a) { m_a = a; } //
    void setb(int b) { m_b = b; } //正确
    void setc(int c) { m_c = c; } //正确
    void setd(int d) { m_d = d; } //正确
private:
    int m_d;
};
/**
 * @brief  虚继承的目的是让某个类做出声明，承诺愿意共享它的基类。其中，这个被共享的基类就称为虚基类（Virtual Base Class）
 * @note   
 * @retval 
 */
int main()
{
    D d;
    d.seta(12);
    return 0;
}