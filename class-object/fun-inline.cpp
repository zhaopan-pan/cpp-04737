#include <iostream>
using namespace std;

inline void fun()
{

    cout << "我就是内联函数"
         << "\n";
}
int main()
{
    fun();
    return 0;
}