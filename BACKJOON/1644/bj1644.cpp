#include <bits/stdc++.h>
using namespace std;

vector<int> P;
int nonprime[4000001];
int main()
{
    int n;
    cin >> n;
    if (n == 1)
    {
        cout << 0;
        return 0;
    }
    for (int i = 2; i * i <= n; i++)
    {
        if (nonprime[i])
            continue;
        for (int j = 2; i * j <= n; j++)
        {
            nonprime[i * j] = 1;
        }
    }
    for (int i = 2; i <= n; i++)
    {
        if (nonprime[i] == 0)
            P.push_back(i);
    }
    //cout << P.size();
    int p = 0, q = 0;
    int sum = P[0];
    int cnt = 0;
    while (p < P.size())
    {
        if (sum < n)
        {
            q++;
            if (q == P.size())
                break;
            sum += P[q];
        }
        else if (sum > n)
        {
            sum -= P[p++];
        }
        else
        {
            cnt++;
            q++;

            if (q == P.size())
                break;
            sum += P[q];
        }
    }
    cout << cnt;
    return 0;
}