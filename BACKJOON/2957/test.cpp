#include <bits/stdc++.h>

using namespace std;

int main()
{
    set<int> S;
    S.insert(1);
    S.insert(6);
    S.insert(3);
    S.insert(9);
    S.insert(8);
    S.find(3);
    auto it = --S.find(3);

    cout << *(it);
}