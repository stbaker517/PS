#include <iostream>
#include <queue>

using namespace std;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int board[500][500];
int dp[500][500];
bool visit[500][500];
int n, m;

queue<pair<int, int>> Q;
bool isNeighborVisit(int x, int y)
{
    for (int i = 0; i < 4; i++)
    {
        int X = x + dx[i];
        int Y = y + dy[i];
        if (X < 0 || Y < 0 || X >= n || Y >= m)
            continue;

        if (board[X][Y] > board[x][y] && visit[X][Y] != true)
            return false;
    }
    return true;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
        }
    }
    visit[0][0] = 1;
    dp[0][0] = board[0][0];

    while (visit[n - 1][m - 1] && !Q.empty())
    {
        pair<int, int> tmp = Q.front();

        if (!isNeighborVisit(tmp.first, tmp.second))
            continue;

        int x = tmp.first;
        int y = tmp.second;

        for (int i = 0; i < 4; i++)
        {
            int X = x + dx[i];
            int Y = y + dy[i];
            if (X < 0 || Y < 0 || X >= n || Y >= m)
                continue;
            if (visit[X][Y])
                continue;

            dp[X][Y] += dp[x][y];
        }
    }
    cout << dp[n - 1][m - 1];
    return 0;
}