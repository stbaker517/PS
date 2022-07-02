#include <iostream>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

int main()
{
    map<int, int> M;
    for (int i = 0; i < 5; i++)
    {
        int n;
        cin >> n;
        M[n] = n;
    }
    for (auto d : M)
    {
        cout << d.second << " ";
    }
}