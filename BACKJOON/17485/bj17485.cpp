#include <bits/stdc++.h>
using namespace std;
int dx[] = {1, 1, 1};
int dy[] = {-1, 0, 1};

int dp[1000][1000][3];
int arr[1000][1000];

int n, m;
void f(int x, int y)
{
    //x,y의 자식에 세팅될 값

    for (int i = 0; i < 3; i++)
    {
        int X = x + dx[i];
        int Y = y + dy[i];

        if (X < 0 || Y < 0 || X >= n || Y >= m)
            continue;
        if (dp[X][Y][i] > arr[X][Y] + min(dp[x][y][(i + 1) % 3], dp[x][y][(i + 2) % 3]))
            dp[X][Y][i] = arr[X][Y] + min(dp[x][y][(i + 1) % 3], dp[x][y][(i + 2) % 3]);
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
        }
    }
    for (int i = 0; i < 1000; i++)
    {
        for (int j = 0; j < 1000; j++)
        {
            for (int k = 0; k < 3; k++)
                dp[i][j][k] = 0x7fffffff;
        }
    }
    for (int i = 0; i < m; i++)
    {

        for (int k = 0; k < 3; k++)
            dp[0][i][k] = arr[0][i];
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < m; j++)
        {
            f(i, j);
        }
    }

    int M = 0x7fffffff;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < 3; j++)
            M = min(dp[n - 1][i][j], M);
    }
    cout << M;

    return 0;
}