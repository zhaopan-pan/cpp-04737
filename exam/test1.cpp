#include <iostream>
using namespace std;

void getCharAndAsc();
void setIntLength100();
int main()
{
    getCharAndAsc();
    setIntLength100();
    return 0;
}

//分别用字符和ASCII码形式输出整数值65和66。
void getCharAndAsc()
{
    int temp1 = 65, temp2 = 66;
    cout << (char)temp1 << " " << (char)temp2 << endl; //把ASCII码数字转成字符串
    cout << temp1 << " " << temp2 << endl;
}

// 编写一个为int型变量分配100个整形量空间的程序。
void setIntLength100()
{
    int *ptr = new int[100];
    ptr[0] = 100;
    cout << *ptr << endl;
    delete[] ptr;
    cout << ptr[0] << endl;
}