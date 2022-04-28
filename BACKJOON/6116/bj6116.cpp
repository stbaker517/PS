#include <bits/stdc++.h>
using namespace std;

int W[100001];
int N;
int dp[100001];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> W[i];
    int h = 2;
    dp[1] = W[N];
    for (int i = N - 1; i > 0; i--)
    {

        dp[h] += W[i];
        if (dp[h] >= dp[h - 1])
        {
            h++;
        }
    }
    if (dp[h] < dp[h - 1])
        h--;
    cout << h;

    return 0;
}