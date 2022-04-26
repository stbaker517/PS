#include <iostream>

using namespace std;

int cost[1000][3];
int dp[1000][3];
int n;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> cost[i][j];
        }
    }
    for (int i = 0; i < 3; i++)
    {
        dp[0][i] = cost[0][i];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            dp[i][j] = min(dp[i - 1][(j + 1) % 3], dp[i - 1][(j + 2) % 3]) + cost[i][j];
        }
    }

    cout << min(dp[n - 1][0], min(dp[n - 1][1], dp[n - 1][2]));

    return 0;
}