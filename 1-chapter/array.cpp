#include <iostream>
#include <algorithm>
#include <functional>
#include <iterator>
using namespace std;

typedef int arr[5]; //省略掉了数组的大小，数组的大小则为初始化时元素的个数
int main()
{

  int len = 5;
  arr arr1 = {1, 2, 3, 4, 5};
  cout << arr1 << endl;     //arr1默认数组第一个元素的地址
  cout << &arr1[0] << endl; //等于arr1

  cout << arr1 + 1 << endl; //arr1==arr1[1],也就是数组的第二个元素
  cout << &arr1[1] << endl; //等于arr1+1

  reverse(arr1, arr1 + len); //数组元素反转排列
  cout << "反转后：" << arr1[0] << endl;

  int arr2[5];
  copy(arr1, arr1 + len, arr2);             //把arr1原样复制到arr2中
  reverse_copy(arr1, arr1 + len, arr2);     //把arr1逆向复制到arr2中
  cout << "arr2：" << arr2 << endl;         //直接打印数组，输出数组首位的首地址
  cout << "arr2【0】：" << arr2[0] << endl; //1

  sort(arr2, arr2 + len);                      //默认升幂排序
  cout << "默认排序结果：" << arr2[0] << endl; //1

  sort(arr2, arr2 + len, greater<int>());      //降幂排序
  cout << "降幂排序结果：" << arr2[4] << endl; //5

  int *x = find(arr2, arr2 + len, 11); //查找数组内是否存在 2, 存在则会返回元素指针

  if (x == arr2 + len) //arr2 + len元素相当于arr2[5]，arr[5]不存在
  {
    cout << "没有2" << endl;
  }
  else
  {
    cout << "有值为2的元素" << endl;
  }
  cout << x << endl;
  cout << *x << endl;
  copy(arr2, arr2 + len, ostream_iterator<int>(cout, "-"));//正常输出
  reverse_copy(arr2,arr2+len,ostream_iterator<int>(cout,"-"));//反转输出

  cout << "arr2输出:" << arr2 << endl;

  // cout <<'arr2反转输出:'<<
}