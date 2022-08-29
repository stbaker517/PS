#include <iostream>
#include <cstring>
#include <queue>
#include <tuple>
using namespace std;

long long dp[101][101][101];
bool visit[101][101][101];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        memset(dp, 0, sizeof(long long) * 101 * 101 * 101);
        memset(visit, 0, sizeof(bool) * 101 * 101 * 101);
        int r, y, b;
        cin >> r >> y >> b;
        // cout << r << y << b;
        dp[r][y][b] = 1;

        queue<tuple<int, int, int>> Q;

        Q.push(make_tuple(r, y, b));
        while (!Q.empty())
        {
            tuple<int, int, int> top = Q.front();
            Q.pop();
            int rr = get<0>(top);
            int yy = get<1>(top);
            int bb = get<2>(top);
            if (visit[rr][yy][bb])
                continue;
            visit[rr][yy][bb] = 1;
            printf("[%d]: %d %d %d => %d\n", rr + yy + bb, rr, yy, bb, dp[rr][yy][bb]);
            // 1 r가 y를 잡아먹음.
            if (rr > 0 && yy > 0)
            {
                dp[rr][yy - 1][bb] += dp[rr][yy][bb];
                Q.push(make_tuple(rr, yy - 1, bb));
            }
            // y 가 b를 잡아먹음.
            if (yy > 0 && bb > 0)
            {
                dp[rr][yy][bb - 1] += dp[rr][yy][bb];
                Q.push(make_tuple(rr, yy, bb - 1));
            }
            if (bb > 0 && rr > 0)
            {
                dp[rr - 1][yy][bb] += dp[rr][yy][bb];
                Q.push(make_tuple(rr - 1, yy, bb));
            }
        }

        long long R = 0;
        long long Y = 0;
        long long B = 0;
        for (int i = 0; i < 101; i++)
        {
            R += dp[i][0][0];
        }
        for (int i = 0; i < 101; i++)
        {
            Y += dp[0][i][0];
        }
        for (int i = 0; i < 101; i++)
        {
            B += dp[0][0][i];
        }
        double dr = double(r);
        double dy = double(y);
        double db = double(b);
        int sum = r + y + b;
        dr /= double(sum);
        dy /= double(sum);
        db /= double(sum);

        printf("%ld %ld %ld\n", R, Y, B);
    }

    return 0;
}