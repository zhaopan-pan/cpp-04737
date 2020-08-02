#include <iostream>
#include <fstream>
using namespace std;

class InOut
{
    int a;
    float b;
    char c;

public:
    InOut(int d = 0, float e = 0, char f = '\0') : a(d), b(e), c(f){};
    friend void operator<<(ostream &out, InOut);       //输出对象信息
    friend istream &operator>>(istream &out, InOut &); //输入对象信息 必须输入到引用地址
};

void operator<<(ostream &out, InOut io)
{
    out << io.a << ",";
    out << io.b << ",";
    out << io.c << endl;
}
istream &operator>>(istream &in, InOut &io)
{
    in >> io.a;
    in >> io.b;
    in >> io.c;
    return in;
}

int main()
{

    InOut io(123, 2.5, 'W');
    operator<<(cout, io);
    InOut i, o;
    cout << "输入i：";
    operator>>(cin, i);
    cout << "输入o：";
    operator>>(cin, o);
    cout << "输出i：";
    operator<<(cout, i);
    cout << "输出o：";
    operator<<(cout, o);
    return 0;
}