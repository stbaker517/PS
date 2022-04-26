#include <bits/stdc++.h>

using namespace std;

int T, N;
double L, R;
double dp[1001][2001];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    for (int aaa = 0; aaa < T; aaa++)
    {
        memset(dp, 0, sizeof(double) * 1001 * 2001);
        cin >> N >> L >> R;
        double remain = 1.0 - L - R;

        dp[0][1000] = 1.0;
        for (int i = 1; i <= N; i++)
        {

            dp[i][1000] = dp[i - 1][1001] * L + dp[i - 1][999] * R + dp[i - 1][1000] * remain;
            for (int idx = 1; idx < i; idx++)
            {
                dp[i][1000 + idx] = dp[i - 1][1001 + idx] * L + dp[i - 1][999 + idx] * R + dp[i - 1][1000 + idx] * remain;
                dp[i][1000 - idx] = dp[i - 1][1001 - idx] * L + dp[i - 1][999 - idx] * R + dp[i - 1][1000 - idx] * remain;
            }
            dp[i][1000 + i] = dp[i - 1][999 + i] * R;
            dp[i][1000 - i] = dp[i - 1][1001 - i] * L;
        }
        double _sum = 0;

        for (int i = 1; i <= N; i++)
        {
            printf("%.4lf ", dp[N][1000 + i]);
            _sum += i * dp[N][1000 + i];
        }
        printf("%.4lf\n", _sum);
    }
    return 0;
}