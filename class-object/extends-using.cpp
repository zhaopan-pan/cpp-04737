#include <iostream>
using namespace std;

class Point
{
    int x, y;

protected:
    int *z;

public:
    Point(){};
    Point(int a)
    {
        x = a;
        y = a + 1;
    };
    int getPointZ()
    {
        return *z;
    };
    int getPointY()
    {
        return *z;
    }
};

class Children : public Point
{
private:
    using Point::getPointY; //将父类的共有方法改为私有

public:
    using Point::z; //将父类的保护对象(本来只能在派生类成员函数中引用)变成自己的实例对象可以访问
    Children(int *a)
    {

        z = a;
    };
    int getParent()
    {
        return *z;
    }
};

int main()
{
    cout << "-------" << endl;
    int a = 10;
    Children ch(&a);
    cout << "getPointZ:" << ch.getPointZ() << endl; //10
    cout << "getParent:" << ch.getParent() << endl; //10
    cout << "z:" << *ch.z << endl;                  //10
    return 0;
}
