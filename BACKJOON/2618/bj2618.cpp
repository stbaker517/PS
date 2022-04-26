#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>

int ccase[1001][2];
int n, m;
int dp[1001][1001];
pii mvv[1001][1001];
int nxtarr[1001][1001];
int ans = 0x7fffffff;
void ptr()
{
    stack<int> trace;
    int moved = 1;
    int x = 0, y = 0;
    while (moved)
    {
        moved = nxtarr[x][y];
        if (!moved)
            break;
        cout << moved << "\n";
        pii tmp = mvv[x][y];
        x = tmp.first;
        y = tmp.second;
    }
}
int dist(int mv, int t1, int t2)
{
    int ret = 0;
    int x = ccase[t1][0], y = ccase[t1][1];
    if (t1 == 0)
    {
        if (mv)
        {
            //b
            x = y = n - 1;
        }
        else
        {
            x = y = 0;
        }
    }
    return abs(x - ccase[t2][0]) + abs(y - ccase[t2][1]);
}
int dfs(int a, int b)
{
    if (dp[a][b] != -1)
        return dp[a][b];

    int time = max(a, b);
    //cout << time << " ";
    if (time == m)
        return 0;

    int p1 = dfs(time + 1, b) + dist(0, a, time + 1);
    int p2 = dfs(a, time + 1) + dist(1, b, time + 1);

    int ret;

    if (p1 < p2)
    {
        mvv[a][b] = {time + 1, b};
        nxtarr[a][b] = 1;
        ret = p1;
    }
    else
    {
        mvv[a][b] = {a, time + 1};
        nxtarr[a][b] = 2;
        ret = p2;
    }
    dp[a][b] = ret;
    return ret;
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < 1001; i++)
    {
        for (int j = 0; j < 1001; j++)
        {
            dp[i][j] = -1;
        }
    }

    int q, w;
    for (int i = 1; i <= m; i++)
    {
        cin >> q >> w;
        ccase[i][0] = q - 1;
        ccase[i][1] = w - 1;
    }

    ans = dfs(0, 0);
    cout << ans << "\n";
    ptr();

    return 0;
}