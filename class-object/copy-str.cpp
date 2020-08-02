#include <iostream>
#include <cstring>
using namespace std;

class Str
{
    char *st;

public:
    Str(char *s); //构造复制出一个新char类型对象
    Str &operator=(Str &a)
    {
        if (this == &a) //如果调用的对象和传入的（要复制的）对象相同就返回原对象
        {
            return *this;
        }
        st = new char(strlen(a.st) + 1);
        strcpy(st, a.st);
        return *this;
    }
    char *getStr()
    {
        return st;
    }
};

Str::Str(char *s)
{
    st = new char[strlen(s) + 1];
    strcpy(st, s);
};

int main()
{
    char *good = (char *)"good";
    char *bad = (char *)"bad";
    Str str(good);
    Str badstr(bad);
    cout << str.getStr() << endl;
    str = badstr;
    cout << str.getStr() << endl;
    return 0;
}