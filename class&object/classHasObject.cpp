#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class School
{
    string schoolName;

public:
    School() : schoolName("")
    {
        cout << "学校：init" << endl;
    }
    School(string name) : schoolName(name)
    {
        cout << "学校：" << schoolName << endl;
    }
};

class Students
{
    const string s_name;
    string s_schName1;
    string s_schName2;
    School school1;
    School school2;

public:
    Students()
    {
        cout << "Students,init" << endl;
    }
    Students(string name, string schName1, string schName2) : s_name(name), school1(schName1), school2(schName2)
    {
        cout << s_name << "上过两个学校,分别是" << schName1 << "和" << schName2 << endl;
    }
};

int main()
{

    Students ss, stu("赵攀", "北京大学", "清华大学");
    cout << sqrt(2) << endl;
    return 0;
}
