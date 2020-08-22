#include <vector>
#include <iostream>
using namespace std;

int main()
{
    vector<int> d(15); //15个0
    vector<int> c(20, 2);
    vector<int> a(10, 1);
    vector<char> b(5, 'h');
    a = c;
    cout << a.size() << endl;
    cout << b.size() << endl;
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << endl; //20个2
    }
    return 0;
}