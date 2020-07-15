#include <iostream>
#include <complex>
#include <string>
using namespace std;

int main()
{
    complex <int> num1(2,3);
    complex <int> num2(3,6);

    cout<<"num1.real:"<<num1.real()<<endl;
    cout<<"num1.imag:"<<num1.imag()<<endl;
    cout<<"num1+num2"<<num1+num2<<endl;//(5,9)
    cout<<"num1*num2"<<num1*num2<<endl;//(-12,21)
    cout<<"num1/num2"<<num1%num2<<endl;//(-12,21)

    return 0;
}