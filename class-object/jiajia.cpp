#include <iostream>
using namespace std;

int main()
{
    int a = 1, b = 2;
    cout << (++a / b) * b-- << endl;//2
    cout << b << '\n';//1
    return 0;
}