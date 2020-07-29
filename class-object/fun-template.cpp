#include <iostream>
#include <complex>
using namespace std;

/**
 * @brief  锟饺达拷小
 * @note   
 * @param  a: 
 * @param  b: 
 * @retval 
 */
// template <class T, class T2> //多类型
template <class T>
T maxNum(T a, T b)
{
    return (a > b) ? a : b;
}

/**
 * @brief  锟斤拷印锟斤拷锟斤拷锟斤拷锟斤拷锟绞碉拷锟斤拷锟斤拷椴?
 * @note   
 * @param  a: 
 * @retval None
 */
template <typename T>
void priter(complex<T> a)
{
    cout << "实锟斤拷为:" << a.real() << endl;
    cout << "锟介部为锟斤拷" << a.imag() << endl;
}

int main()
{
    cout << maxNum(1, 2) << endl;
    cout << maxNum(3.4, 2.1) << endl;
    cout << maxNum('A', 'B') << endl;       //锟街凤拷锟斤拷转锟斤拷锟斤拷ASCII锟斤拷
    cout << maxNum<double>(3, 2.1) << endl; //锟斤拷锟酵诧拷同锟斤拷锟斤拷强转
    cout << maxNum((double)3, 2.1) << endl; //锟斤拷锟酵诧拷同锟斤拷锟斤拷强转
    cout << (int)1.2 << endl;               //1
    priter(complex<int>(1, 2));
    priter(complex<int>(1.1, 2.2));
    return 0;
}