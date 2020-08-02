#include <iostream>
using namespace std;

class Numb
{
    int num;

public:
    Numb(int i) { num = i; };
    friend int operator++(Numb &);
    friend int operator++(Numb &, int);
    void show() { cout << "num:" << num << endl; }
};

int operator++(Numb &n)
{
    n.num++;
    return n.num;
};
int operator++(Numb &n, int)
{
    int i = 1 + n.num++;
    return i;
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