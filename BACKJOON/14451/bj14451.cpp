#include <iostream>
#include <cstring>
#include <tuple>
#include <queue>
using namespace std;
queue<tuple<int, int, int>> Q;
#define mT make_tuple
#define tiii tuple<int, int, int>
int dx[] = {-1, 0, 1, 0}; // U R D L
int dy[] = {0, 1, 0, -1};
int n;
int dp[2][20][20][4];
int map[20][20];

void f(int i)
{
    //전,좌회전,우회전.
    dp[i][n - 1][0][0] = 1;
    dp[i][n - 1][0][1] = 1;
    dp[i][n - 1][0][2] = 1;
    dp[i][n - 1][0][3] = 1;
    dp[i][n - 1][0][i] = 0;

    Q.push(mT(0, 0, 0));
    Q.push(mT(0, 0, 1));

    while (!Q.empty())
    {
        tiii q = Q.front();
        Q.pop();
        int x, y, dir;
        x = get<0>(q);
        y = get<1>(q);
        dir = get<2>(q);
        // cout << x << y << dir;

        //전진.
        int X = x + dx[dir], Y = y + dy[dir];
        if (map[X][Y] == 0 && !(X < 0 || Y < 0 || X >= n || Y >= n))
        {

            /*if (dp[i][X][Y][dir] != -1 && dp[i][X][Y][dir] < dp[i][x][y][dir] + 1)
            {
                dp[i][X][Y][dir] = dp[i][x][y][dir] + 1;
                Q.push(mT(X, Y, dir));
            }
            else*/
            if (dp[i][X][Y][dir] == -1)
            {
                dp[i][X][Y][dir] = dp[i][x][y][dir] + 1;
                Q.push(mT(X, Y, dir));
            }
        }
        //우회전
        X = x;
        Y = y;
        int rD = (dir + 1) % 4;
        int lD = (3 + dir) % 4;
        /*if (dp[i][X][Y][rD] != -1 && dp[i][X][Y][rD] < dp[i][x][y][dir] + 1)
        {
            dp[i][X][Y][rD] = dp[i][x][y][dir] + 1;
            Q.push(mT(X, Y, rD));
        }
        else*/
        if (dp[i][X][Y][rD] == -1)
        {
            dp[i][X][Y][rD] = dp[i][x][y][dir] + 1;
            Q.push(mT(X, Y, rD));
        }

        rD = (dir + 3) % 4;
        /*if (dp[i][X][Y][rD] != -1 && dp[i][X][Y][rD] < dp[i][x][y][dir] + 1)
        {
            dp[i][X][Y][rD] = dp[i][x][y][dir] + 1;
            Q.push(mT(X, Y, rD));
        }
        else */
        if (dp[i][X][Y][rD] == -1)
        {
            dp[i][X][Y][rD] = dp[i][x][y][dir] + 1;
            Q.push(mT(X, Y, rD));
        }
    }
}
int main()
{
    cin >> n;
    char ch;
    memset(dp, -1, sizeof(int) * 20 * 20 * 4);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> ch;
            if (ch == 'H')
                map[i][j] = 1;
            else
                map[i][j] = 0;
        }
    }
    f(0);
    f(1);
    int mm = 0;
    for (int i = 0; i < 2; i++)
    {
        int MM = 122220;
        for (int j = 0; j < 4; j++)
        {
            MM = min(dp[i][0][n - 1][j], MM);
        }
        mm = max(MM, mm);
    }
    cout << mm;
    return 0;
}