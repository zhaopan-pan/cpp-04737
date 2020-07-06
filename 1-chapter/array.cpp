#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

typedef int arr[5];//省略掉了数组的大小，数组的大小则为初始化时元素的个数
int main() {
  int len=5;
  arr arr1={1,2,3,4,5};
  reverse(arr1,arr1+len);//数组元素反转排列
  cout <<"反转后："<< arr1[0]<<endl;

  int arr2[5];
  copy(arr1,arr1+len,arr2);//把arr1原样复制到arr2中
  reverse_copy(arr1,arr1+len,arr2);//把arr1逆向复制到arr2中
  cout <<"arr2："<< arr2<<endl;    //直接打印数组，输出数组首位的首地址
  cout <<"arr2【0】："<< arr2[0]<<endl;//1

  sort(arr2,arr2+len);//默认升幂排序
  cout <<"默认排序结果："<<arr2[0]<<endl;//1

  sort(arr2,arr2+len,greater<int>());//降幂排序
  cout <<"降幂排序结果："<<arr2[4]<<endl;//5

  int *x=find(arr2,arr2+len,1);//查找数组内是否存在 2
  if(x==arr2+len){    
      cout <<"没有2"<<endl;
  }else{
      cout <<"有值为2的元素"<<endl;
  }
  cout <<x<<endl;
  cout <<*x<<endl;
  
}