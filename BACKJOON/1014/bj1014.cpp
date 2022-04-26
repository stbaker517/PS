#include <bits/stdc++.h>
using namespace std;

int dx[] = {-1, 0, 0, -1};
int dy[] = {-1, -1, 1, 1};
int arr[11][11];
int n, m;
int dp[11][11][2];
void f(int x, int y)
{

    if (dp[x][y][1] != -1)
        return;
    dp[x][y][0]=0;
    dp[x][y][1]=0;
    for (int i = 0; i < 4; i++)
    {
        int X=x+dx[i];
        int Y=y+dy[i];

        if(X<0||Y<0||X>=n||Y>=m)continue;

        f(X,Y);
        dp[x][y][0]+=max(dp[x][y][0],dp[x][y][1]);
        if(arr[x][y])
        dp[x][y][1]
    }
}
int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cin >> n >> m;
        char ch;
        for (int r = 0; r < n; r++)
        {
            for (int c = 0; c < m; c++)
            {
                cin >> ch;
                if (ch == '.')
                    arr[r][c] = 1;
                else if (ch == 'x')
                    arr[r][c] = 0;
                for (int k = 0; k < 2; k++)
                {
                    dp[r][c] = -1;
                }
            }
        }
    }

    return 0;
}