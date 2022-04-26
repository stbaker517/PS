#include <bits/stdc++.h>
using namespace std;

int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int dp[21][20][20][20][20]; //dp[길이][시작점][끝점]
int arr[20][20];
int n, l;

void f(int sx, int sy, int ex, int ey, int len)
{
    for (int i = 0; i < 8; i++)
    {
        int hx, hy, tx, ty; //head x,y tail x,y
        hx = sx + dx[i];
        hy = sy + dy[i];
        if (hx < 0 || hy < 0 || hx >= n || hy >= n)
            continue;
        for (int j = 0; j < 8; j++)
        {
            tx = ex + dx[j];
            ty = ey + dy[j];
            if (tx < 0 || ty < 0 || tx >= n || ty >= n)
                continue;
            if (arr[tx][ty] != arr[hx][hy])
                continue;
            if (len + 2 > l)
                continue;
            dp[len + 2][hx][hy][tx][ty] += dp[len][sx][sy][ex][ey];
        }
    }
}

int main()
{
    cin >> n >> l;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    //1자리 처리
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            dp[1][i][j][i][j] = 1;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < 8; k++)
            {
                int X = i + dx[k];
                int Y = j + dy[k];
                if (X < 0 || Y < 0 || X >= n || Y >= n)
                    continue;
                if (arr[i][j] != arr[X][Y])
                    continue;
                dp[2][i][j][X][Y] = 1;
            }
        }
    }
    for (int o = 1; o <= l - 2; o++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for (int a = 0; a < n; a++)
                {
                    for (int b = 0; b < n; b++)
                    {
                        f(i, j, a, b, o);
                    }
                }
            }
        }
    }

    int M = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int a = 0; a < n; a++)
            {
                for (int b = 0; b < n; b++)
                {
                    M += dp[l][i][j][a][b];
                }
            }
        }
    }
    cout << M;
    return 0;
}