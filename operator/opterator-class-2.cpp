#include <iostream>
using namespace std;

class Numb
{
    int num;

public:
    Numb(int i) { num = i; };
    int operator++();    //前缀++num
    int operator++(int); //后缀num++
    void show() { cout << "num:" << num << endl; }
};

int Numb::operator++(int)
{
    int i = num++;
    return i;
};
int Numb::operator++()
{
    num++;
    return num;
}

int main()
{

    Numb nu(11);
    int a = nu++;
    cout << "a:" << a << endl; //11
    nu.show();                 //12
    int b = ++nu;
    cout << "b:" << b << endl; //13
    nu.show();                 //13
    return 0;
}