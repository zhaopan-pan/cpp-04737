#include <iostream>
using namespace std;

class Point
{
protected:
    int x, y;

public:
    Point(int a, int b)
    {
        cout << "a=" << a << "\n"
             << "b=" << b << endl;
        x = a;
        y = b;
    };
    void show()
    {
        cout << "Point:"
             << "\n"
             << "x==" << x << "\n"
             << "y==" << y << endl;
    }
};
class Point2
{
protected:
    int x, y;

public:
    Point2() {}
    Point2(int a, int b)
    {
        cout << "a=" << a << "\n"
             << "b=" << b << endl;
        x = a;
        y = b;
    };
    void show()
    {
        cout << "Point2:"
             << "\n"
             << "x==" << x << "\n"
             << "y==" << y << endl;
    }
};
class Ractangle : public Point, public Point2
{
private:
    int H, W;

public:
    Ractangle(int a, int b, int c, int d);
};
Ractangle::Ractangle(int a, int b, int c, int d) : Point(a, b), Point2(a, b) //如果Point不存在默认空构造函数，必须显式指出Point的构造函数
{
    cout << "c=" << c << "\n"
         << "d=" << d << endl;
    H = c;
    W = d;
    cout << "Ractangle:"
         << "\n"
         << "a=" << a << "\n"
         << "b=" << b << "\n"
         << "c=" << c << "\n"
         << "d=" << d << endl;
};
int main()
{
    Ractangle ra(1, 2, 3, 4);
    ra.Point2::show();
    Point2 p(11, 12);
    Ractangle rac(5, 6, 7, 8);
    Point2 &pp = rac;//rac属于Point2
    pp.show();
    Ractangle *ppp = &rac;
    ppp->Point::show();
    return 0;
}