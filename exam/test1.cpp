#include <iostream>
#include <string>
using namespace std;

void getCharAndAsc();
void setIntLength100();
void out79();
int main()
{
    // getCharAndAsc();
    // setIntLength100();
    // out79();
    cout << ("%c\n", " student");
    cout << ("%c\n", "c");
    string s;
    cout << "s" << (s[0] == 0) << endl;
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
    int *ar = new int(10);
    delete ar;
    cout << ptr[0] << endl;
};
//完成程序，使其输出结果为79  15+64
void out79()
{
    int a[6] = {23, 15, 64, 33, 40, 58};
    int s1, s2;
    s1 = s2 = a[0];
    cout << a + 1;
    cout << a + 2;
    for (int *p = a + 1; p < a + 6; p++)
    {
        cout << *p << endl;
        if (s1 > *p)
            s1 = *p;
        if (s2 < *p)
            s2 = *p;
    }
    cout << s1 + s2 << endl;
}
