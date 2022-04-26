#include <iostream>

using namespace std;

int n, m;
long long arr[1000][1000];
long long dp[1000][1000][3];
bool visit[1000][1000];

void print()
{
    for (int a = 0; a < 3; a++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                printf("%3d ", dp[i][j][a]);
            }
            printf("\n");
        }
        printf("\n\n");
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
            for (int k = 0; k < 3; k++)
                dp[i][j][k] = -200000000;
        }
    }

    for (int i = 0; i < m; i++)
    {
        dp[0][i][0] = arr[0][i];
        if (i != 0)
            dp[0][i][1] = dp[0][i - 1][1] + arr[0][i];
        else
            dp[0][0][1] = arr[0][0];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i != 1)
                dp[i][j][0] = max(dp[i - 1][j][0], max(dp[i - 1][j][1], dp[i - 1][j][2])) + arr[i][j];
            else
                dp[i][j][0] = max(dp[i - 1][j][1], dp[i - 1][j][2]) + arr[i][j];
        }
        for (int j = 1; j < m; j++) //0->m까지 합 dp
        {

            dp[i][j][1] = max(dp[i][j - 1][0], dp[i][j - 1][1]) + arr[i][j];
        }
        for (int j = m - 2; j >= 0; j--) //m->0까지 합 dp
        {

            dp[i][j][2] = max(dp[i][j + 1][0], dp[i][j + 1][2]) + arr[i][j];
        }
    }
    if (n == 1)
        cout << max(dp[n - 1][m - 1][1], dp[n - 1][m - 1][2]);
    else
        cout << max(dp[n - 1][m - 1][0], max(dp[n - 1][m - 1][1], dp[n - 1][m - 1][2]));
    //printf("\n\n======\n");
    //print();
    return 0;
}