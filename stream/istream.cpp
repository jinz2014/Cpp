#include <iostream>
#include <string>
using namespace std;

int main()
{
    char ch;
    char charBuf[11];
    string strBuf;

    cout << "cin >>ch" << endl;
    // input: Hello World\n
    // output: HelloWorld
    while (cin >> ch)
        cout << ch;

    cout << "cin.get(ch)" << endl;
    // input: Hello World\n
    // output: Hello World
    // get() does not read in a newline character! 
    while (cin.get(ch))
        cout << ch;

    cout << "cin.get(charBuf, 11)" << endl;
    cin.get(charBuf, 11);
    cout << charBuf << endl;
 
    cout << "cin.getline(charBuf, 11)" << endl;
    // getline() read in a newline character
    cin.getline(charBuf, 11);
    cout << charBuf << endl;

    cout << "getline(cin, strBuf)" << endl;
    // <string>
    getline(cin, strBuf);
    cout << strBuf << endl;

    return 0;
}

