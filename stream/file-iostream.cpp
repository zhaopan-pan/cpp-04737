#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main()
{

    char ch[13], *p = (char *)"justin";
    ofstream myFile;
    myFile.is_open();
    myFile.open("myText.txt"); //同样可以写成    ofstream myFile("myText.txt");
    myFile << p;
    myFile << " bieber";
    myFile.close();
    ifstream getText("myText.txt");
    for (int i = 0; i < strlen(p) + 7; i++)
    {
        cout << ch << endl;
        getText >> ch[i];
    }
    ch[strlen(p) + 8] = '\0';
    getText.close();
    cout << "ch:" << ch;
    return 0;
}
