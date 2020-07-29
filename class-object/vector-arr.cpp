#include <vector>
#include <iostream>
using namespace std;

int main()
{
    int arr[5] = {1, 2, 3, 4, 7};
    vector<int> v(arr, arr + 5); //arr:开始，arr+5：结束
    cout << v.max_size() << endl;
    cout << v.size() << endl;
    cout << "capacity:" << v.capacity() << endl; //初始值为已申请空间大小，超出一个，自动翻倍
    cout << "第一个元素:" << v.front() << endl;  //返回第一个元素
    cout << "最后一个元素:" << v.back() << endl; //返回最后一个元素
    cout << arr + 5 << endl;
    cout << &arr[5] << endl;
    return 0;
}