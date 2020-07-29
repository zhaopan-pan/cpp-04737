#include <iostream>
using namespace std;

class Point
{
    int x, y;

public:
    Point(int a, int b)
    {
        x = a;
        y = b;
    };
    void show()
    {
        cout << "point:" << x << "--"
             << y << endl;
    }
};

template <class T>
class Line : public Point  //类模板继承非模板类
{
    T x1, y1;

public:
    Line(T a, T b) : Point(a, b){};
    void show()
    {
        Point::show();
        cout << "line:" << x1 << "--"
             << y1 << endl;
    }
};

main()
{
    Line<int> line(3, 5);
    line.show();
    return 0;
}