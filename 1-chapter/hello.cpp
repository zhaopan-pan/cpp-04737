#include <iostream>
using namespace std;//c++标准中的标准类库的变量与函数都属于命名空间std
int result(int,int);
const int k=2;
struct Point //结构体对象
{
  int x,y;
};

int main() {
  int z(0),b(50);//初始化整数对象
  Point a;
  std::cout << "Hello World!\n";
  std::cin >> a.x>>a.y;
  z=(a.x+a.y)*k;
  z=result(z,b);
  std::cout << z << endl << b;
  return 0;

}

int result(int a,int b){
    return a+b;
}