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
    cout << str.find("e", 1) << endl;  //返回字符所在位置索引,第二个参数为开始搜索的下标，不指明的情况下默认从0开始
    cout << str.rfind("e", 1) << endl; //~  和find()的区别在于第二个参数，查找到第二个参数所指定的下标为止，找不到返回无穷大数
    cout << str.find_first_of("e") << endl; //检测字符串首次出现的位置
    cout << str.size() << endl;        //字符串长度，同下
    cout << str.length() << endl;

    //删除
    str.erase(4);
    cout << "指定开始-删除后：" << str << "\n";
    str.erase(1, 3);
    cout << "指定开始和删除长度-删除后：" << str << "\n";

    //插入
    str.insert(1, "ello world");
    cout << "插入后：" << str << "\n";

    //获取字符串
    cout << "获取从下标1开始长度为3字符：" << str.substr(1, 3) << "\n";
}