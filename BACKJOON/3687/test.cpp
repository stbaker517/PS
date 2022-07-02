#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str = "hello im lee.";
    auto idx = str.find(' ');
    int cur = 0;
    int prev;
    while (idx != string::npos)
    {
        string strd = str.substr(cur, idx - cur);
        cout << strd << "0\n";

        cur = idx + 1;
        idx = str.find(' ', cur);
    }
    cout << str.substr(cur, idx - cur);
}