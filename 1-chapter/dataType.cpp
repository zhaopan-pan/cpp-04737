#include <iostream>
using namespace std;

void TypeString();
int main()
{
    TypeString();
    return 0;
}

void TypeString()
{
    string str = "hello";
    cout << str.find("e") << endl;//返回字符所在位置索引
    cout << str.size() << endl;
}