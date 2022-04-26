#include <bits/stdc++.h>
using namespace std;

int dp[101][10][10][10]; //[순서][맨 왼쪽 수][포함하는 수의 시작][포함하는 수의 끝]
int arr[101];
int n;

void f(int t, int ml, int rb)
{ //most left

    for (int s = 0; s < 10; s++)
    {
        for (int e = 0; e < 10; e++)
        {
            if (!dp[t - 1][rb][s][e])
                continue;
            if (s <= ml && ml <= e)
            {
                dp[t][ml][s][e] += dp[t - 1][rb][s][e];
                dp[t][ml][s][e] %= 1000000000;
            }
            if (ml != 9 && ml == s - 1)
            {
                dp[t][ml][ml][e] += dp[t - 1][rb][s][e];
                dp[t][ml][ml][e] %= 1000000000;
            }
            if (ml != 0 && ml == e + 1)
            {
                dp[t][ml][s][ml] += dp[t - 1][rb][s][e];
                dp[t][ml][s][ml] %= 1000000000;
            }
        }
    }
}

void ptr()
{

    for (int t = 0; t < n; t++)
    {
        cout << "T:" << t << "\n";
        for (int a = 0; a < 10; a++)
        {
            for (int b = 0; b < 10; b++)
            {
                cout << dp[t][8][a][b] << " ";
            }
            cout << "\n";
        }
    }
}

int mainF(int a)
{
    n = a;
    memset(dp, 0, sizeof(int) * 101 * 1000);
    for (int i = 0; i < 10; i++)
    {
        dp[0][i][i][i] = 1;
    }
    for (int t = 1; t < n; t++)
    {
        f(t, 0, 1);
        f(t, 9, 8);
        for (int j = 1; j <= 8; j++)
        {
            f(t, j, j - 1);
            f(t, j, j + 1);
        }
    }
    int sum = 0;
    for (int i = 1; i <= 9; i++)
    {
        sum += dp[n - 1][i][0][9];
        sum %= 1000000000;
    }
    //ptr();
    cout << sum;
    return sum;
}
int main()
{
    int a;
    cin >> a;
    mainF(a);
    return 0;
}