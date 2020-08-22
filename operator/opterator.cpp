#include <iostream>
using namespace std;
class complex
{
public:
    complex();
    complex(double real, double imag);

public:
    //声明运算符重载
    complex operator+(const complex &A) const;
    void display() const;

private:
    double m_real; //实部
    double m_imag; //虚部
};
complex::complex() : m_real(0.0), m_imag(0.0) {}
complex::complex(double real, double imag = 0) : m_real(real), m_imag(imag) {}
//实现运算符重载
complex complex::operator+(const complex &A) const
{
    complex B;
    B.m_real = this->m_real + A.m_real;
    B.m_imag = this->m_imag + A.m_imag;
    return B;
}
void complex::display() const
{
    cout << m_real << " + " << m_imag << "i" << endl;
}
/**
 * @brief  类运算符重载
 * @note   
 * @retval 
 */
int main()
{
    complex c1(4.3, 5.8);
    complex c2(2.4, 3.7);
    complex c3;
    complex c4;
    c3 = c1 + c2;
    double d = 5.3;
    c4 = c1 + d;
    c4.display();
    c3.display();
    return 0;
}