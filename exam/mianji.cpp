#include <iostream>
#include <string>
using namespace std;

// 设计一个圆类circle和一个桌子类table。circle类包含私有数据成员radius和求圆面积的成员函数getarea( );
// table类包含私有数据成员height和返回高度的成员函数getheight( )。roundtable类继承所有上述类的数据成员和成员函数，
// 添加了私有数据成员color和相应的成员函数。其中，main函数已给出。请完成程序的其他部分。

class circle
{
    double radius;

public:
    circle(double r) : radius(r){};
    double getarea()
    {
        return radius * 2 * 3.14;
    };
};
class table
{
    double height;
    double width;

public:
    table(double h, double w) : height(h), width(w){};
    double getheight()
    {
        return height;
    }
};
class roundtable : public circle, public table
{
    string color;

public:
    roundtable(double a, double b, double w, string c) : circle(a), table(b, w)
    {
        color = c;
    };
    string getcolor()
    {
        return color;
    }
};

int main()
{
    roundtable rt(0.8, 1, 2, "黑色");
    cout << "圆桌属性数据" << endl;
    cout << "高度:" << rt.getheight() << "米" << endl;
    cout << "面积:" << rt.getarea() << "平方米" << endl;
    cout << "颜色:" << rt.getcolor() << endl;
    return 0;
}