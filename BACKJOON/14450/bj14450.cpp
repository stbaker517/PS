#include <bits/stdc++.h>
using namespace std;

int dp[100001][3][21];
int arr[100001];
int n, K;
//페이퍼> 후프0>가위1>페이퍼2
int isWin(int b, int f)
{
    if (b == 0 && f == 1)
        return 1;
    if (b == 1 && f == 2)
        return 1;
    if (b == 2 && f == 0)
        return 1;
    return 0;
}
void f(int t)
{
    for (int my = 0; my < 3; my++)
    {
        for (int left = 0; left <= K; left++)
        {

            int &ret = dp[t][my][left];
            if (ret == -1)
                break;
            //안 바꾸고.
            dp[t + 1][my][left] = max(dp[t + 1][my][left], ret + isWin(my, arr[t + 1]));
            //바꾸고.
            if (left < K)
            {
                dp[t + 1][(my + 1) % 3][left + 1] = max(dp[t + 1][(my + 1) % 3][left + 1], ret + isWin((my + 1) % 3, arr[t + 1]));
                dp[t + 1][(my + 2) % 3][left + 1] = max(dp[t + 1][(my + 2) % 3][left + 1], ret + isWin((my + 2) % 3, arr[t + 1]));
            }
        }
    }
}
int main()
{
    memset(dp, -1, sizeof(int) * 100001 * 3 * 21);
    cin >> n >> K;
    char ch;
    for (int i = 0; i < n; i++)
    {
        cin >> ch;
        if (ch == 'P')
            arr[i] = 2;
        else if (ch == 'H')
            arr[i] = 0;
        else if (ch == 'S')
            arr[i] = 1;
    }
    for (int i = 0; i < 3; i++)
    {
        dp[0][i][0] = isWin(i, arr[0]);
    }
    for (int i = 0; i < n - 1; i++)
    {
        f(i);
    }
    int M = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j <= K; j++)
        {
            M = max(M, dp[n - 1][i][j]);
        }
    }
    cout << M;
    return 0;
}