#include <iostream>
using namespace std;
class Test
{
    public:
    int num;

public:
    Test(int i) { num = i; };
    int getNum()
    {
        return num;
    }
};
/**
 * @brief  数组对象
 * @note
 * @retval
 */
int main()
{
    // Test two[2] = {2, 3}, *p;
    Test *two[2]{new Test(1), new Test(2)};
    cout << *two << endl; //指针首元素
    cout << two << endl;  //指针地址
    for (int i = 0; i < 2; i++)
    {
        // cout << two[i].getNum() << endl;
        cout << two[i]->getNum() << endl;
    }
    const int num = 12;
    int arrs[num];
    for (int i = 0; i <= num; i++)
    {
        arrs[i] = i;
    }
    cout << arrs[4] << endl;

    return 0;
}