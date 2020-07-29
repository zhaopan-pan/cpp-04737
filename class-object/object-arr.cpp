#include <iostream>
#include <string>
using namespace std;

class Person
{
    int p_cout;
    string p_name;

public:
    // Person(string name, int cout) : p_name(name), p_cout(cout){};
    void set(string, int);
    void say(string);
} P[3];//全局声明对象数组,相当于 Person P[3];

void Person::set(string name, int cout)
{
    p_name = name;
    p_cout = cout;
}
void Person::say(string name)
{
    cout << name << "说：" << p_name << "一共" << p_cout << endl;
}

int main()
{
    P[0].set("儿子", 12);
    P[0].say("威少");
    P[1].set("威少1", 12);
    P[2].set("威少2", 12);
    return 0;
}