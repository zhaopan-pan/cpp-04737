#include <iostream>
#include <complex>
using namespace std;

/**
 * @brief  �ȴ�С
 * @note   
 * @param  a: 
 * @param  b: 
 * @retval 
 */
template <class T>
T maxNum(T a, T b)
{
    return (a > b) ? a : b;
}

/**
 * @brief  ��ӡ���������ʵ������?
 * @note   
 * @param  a: 
 * @retval None
 */
template <typename T>
void priter(complex<T> a)
{
    cout << "ʵ��Ϊ:" << a.real() << endl;
    cout << "�鲿Ϊ��" << a.imag() << endl;
}

int main()
{
    cout << maxNum(1, 2) << endl;
    cout << maxNum(3.4, 2.1) << endl;
    cout << maxNum('A', 'B') << endl;       //�ַ���ת����ASCII��
    cout << maxNum<double>(3, 2.1) << endl; //���Ͳ�ͬ����ǿת
    cout << maxNum((double)3, 2.1) << endl; //���Ͳ�ͬ����ǿת
    cout << (int)1.2 << endl;               //1
    priter(complex<int>(1, 2));
    priter(complex<int>(1.1, 2.2));
    return 0;
}