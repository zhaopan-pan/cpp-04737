#include <iostream>
using namespace std;

template <class T1, typename T2>
class Max
{
    T1 x;
    T2 y;

public:
    T1 getX();
    Max(T1 a, T2 b)
    {
        x = a;
        y = b;
    };
    T1 getMax()
    {
        return x > y ? x : y;
    };
};
template <class T1, class T2>
T1 Max<T1, T2>::getX()
{
    return x;
}
int main()
{
    Max<int, float> m(1, 2.2);
    cout << m.getMax() << endl;
    return 0;
}