#include <iostream>
#include <iterator>
using namespace std;

void swap(int a, int *p);
void swapArr(int arr[]);
void swapYy(int a, int &);
int main()
{
    int b = 2;
    cout <<"相处"<< 1%7 << endl;
    int c = 3;
    int arr[] = {1, 2};
    swap(1, &b);  //传值和变量地址值传递
    swapYy(1, c); //引用传递
    swapArr(arr);
    cout << "改变后的b=" << b << endl;
    cout << "改变后的c=" << c << endl;
    copy(arr, arr + 2, ostream_iterator<double>(cout, ","));
}
/**
 * @brief  传值和变量地址值传递
 * @note   
 * @param  a: 
 * @param  *p: 
 * @retval None
 */
void swap(int a, int *p)
{
    int temp;
    temp = a;
    a = *p;
    *p = temp;
    cout << "a:" << a << endl;
    cout << "*p:" << *p << endl;
}
/**
 * @brief  引用传递
 * @note   
 * @param  a: 
 * @param  &y: 
 * @retval None
 */
void swapYy(int a, int &y)
{
    int temp;
    temp = a;
    a = y;
    y = temp;
    cout << "swapYy-a:" << a << endl;
    cout << "swapYy-c:" << y << endl;
}
void swapArr(int arr[])
{
    cout << arr[0] << endl;
    cout << arr[1] << endl;
    int temp;
    temp = arr[0];
    arr[0] = arr[1];
    arr[1] = temp;
}