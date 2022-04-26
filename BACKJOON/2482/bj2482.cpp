#include <bits/stdc++.h>

using namespace std;

int dp[1001][1001];
int divv = 1000000003;

int n, k;
int main()
{
    cin >> n >> k;
    dp[1][1] = 1;
    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;
    for (int i = 2; i < n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            int chosen = dp[i - 2][j - 1];
            int not_chosen = dp[i - 1][j];

            dp[i][j] = (chosen + not_chosen) % divv;
        }
    }
    cout << (dp[n - 3][k - 1] + dp[n - 1][k]) % divv;
    return 0;
}