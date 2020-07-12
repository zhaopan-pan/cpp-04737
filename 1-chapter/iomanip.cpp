#include <iostream>
#include <iomanip>
using namespace std;

//输出格式
int main()
{
    int num = 123;
    int nums = 321;
    cout << "10进制-dec:" << dec << num << endl;
    cout << "8进制-oct:" << oct << num << endl;
    cout << "16进制-hex:" << hex << num << endl;
    cout << "10进制-dec:" << dec << num << endl;//如果最后不转为10进制，num后面的输出都会是16进制，
    int &b=num;
    b=nums;      //通过引用改变num,这个指针也是如此
    cout <<b<<endl;   //321
    cout <<num<<endl; //321
    return 0;
}