#include <iostream>
#include <algorithm>
#include <cstring>
#include <bits/stdc++.h>
using namespace std;

int maze[1001];
int dp[1001];
int main()
{
    memset(dp, -1, sizeof(int) * 1001);
    int n;
    cin >> n;
    dp[1] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> maze[i];
    }
    for (int i = 1; i < n; i++)
    {
        if (dp[i] == -1)
            continue;
        for (int jump = 1; jump <= maze[i]; jump++)
        {
            if (i + jump > n)
                break;
            if (dp[i + jump] == -1)
                dp[i + jump] = dp[i] + 1;
            else
            {
                dp[i + jump] = min(dp[i] + 1, dp[i + jump]);
            }
        }
    }
    if (n == 1)
        cout << 0;
    else if (dp[n] <= 0)
        cout << -1;

    else
        cout << dp[n];

    return 0;
}