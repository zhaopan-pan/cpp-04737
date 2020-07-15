#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

typedef int arr[5]; //省略掉了数组的大小，数组的大小则为初始化时元素的个数
int main()
{
    int len = 5;
    arr arr1 = {1, 2, 3, 4, 5};
    reverse(arr1, arr1 + len); //数组元素反转排列
    // cout << "反转后：" << arr1[0] << endl;

    int arr2[5];
    /**
     * copy(),复制过程是左(包括)闭右(不包括)开的，而且第三个参数是提供另一个有序组的头地址。
     **/ 
    copy(arr1, arr1 + len, arr2);         //把arr1原样复制到arr2中
    reverse_copy(arr1, arr1 + len, arr2); //把arr1逆向复制到arr2中
    // cout << "arr2：" << arr2 << endl;         //直接打印数组，输出数组首位的首地址
    // cout << "arr2【0】：" << arr2[0] << endl; //1

    sort(arr2, arr2 + len); //默认升幂排序
    // cout << "默认排序结果：" << arr2[0] << endl; //1
    sort(arr2, arr2 + len, greater<int>()); //降幂排序
    // cout << "降幂排序结果：" << arr2[4] << endl; //5

    /**
     *find()
     **/
    int *x = find(arr2, arr2 + len, 2); //查找数组内是否存在 2 , x是int类型的指针
                                        //   int *d=find(arr1.begin(),arr1.end(),2);//查找数组内是否存在 2 ,
    if (x == arr2 + len)
    { //如果不存在 则返回arr2.len/arr2.end(),这里需要注意的是，arr2.len/arr2.end()不在查找范围内。
        // cout << "没有2" << endl;
    }
    else
    { //存在就返回所搜索的值'*x','x'是值的指针地址
        // cout << "有值为2的元素" << endl;
    }
    //   cout <<*x<<endl;
    //   cout <<arr2+len<<endl;

    /**
    * copy(arr1,arr1+len,ostream_iterator<Type>(cout,"\n"));
    **/
    //可以将‘ostream_iterator’简单的理解为输出流操作符，尖括号内是数组元素的数据类型，
    //例句将数组内容按照正向输出的方式打印出来，输出的方式已每个元素间以“,”隔开，也可以用‘\n’、空格或其他字符隔开
    // copy(arr1, arr1 + len, ostream_iterator<int>(cout, "\n"));
    // reverse_copy(arr1, arr1 + len, ostream_iterator<int>(cout, ",")); //反转输出数组

    /**
     *一维数组的局部操作
     **/
    cout << '-' << endl;
    double arr3[] = {5.1, 4.3, 2.3, 3.2}, arr4[8] = {8};           //arr4：长度为8、首位元素为8的数组
    copy(arr3 + 2, arr3 + 4, ostream_iterator<double>(cout, ",")); //输出arr3下标为2和4的元素
    cout << endl;
    reverse_copy(arr3 + 2, arr3 + 4, ostream_iterator<double>(cout, ",")); //逆向并输出

    copy(arr3, arr3 + 4, &arr4[4]); //将数组arr复制到数组arr4的尾部
    cout << endl;
    copy(arr4, arr4 + 8, ostream_iterator<double>(cout, ","));
    cout << endl;
    sort(arr3 + 1, arr3 + 3);                                  //对部分数组元素（1-2）升幂排序
    copy(arr3, arr3 + 4, ostream_iterator<double>(cout, ",")); //输出安arr3；
    cout << endl;
    sort(arr4, arr4 + 6, greater<double>()); //对部分(0-5)数组元素进行降幂排列
    copy(arr4, arr4 + 8, ostream_iterator<double>(cout, ","));
    cout << endl;

    /**
     * 对字符数的操作
     **/
    cout << '-' << endl;
    char arrStr1[] = "wearehere!", b[1];
    reverse(arrStr1, arrStr1 + 10); //数组元素逆向
    copy(arrStr1, arrStr1 + 10, ostream_iterator<char>(cout));
    cout << endl;
    copy(arrStr1,arrStr1+11,b);
    sort(arrStr1,arrStr1);//默认升幂
    cout <<arrStr1<<endl;
    cout <<"b："<<b<<endl;
}