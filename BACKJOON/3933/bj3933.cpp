#include <bits/stdc++.h>
using namespace std;

int dp[(1 << 15) + 1][5];
int arr[1000];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int limit = 1 << 15;
    int i = 0;
    for (i = 1; i * i <= limit; i++)
    {
        // dp[i * i][1] = 1;
        arr[i] = i * i;
    }

    int d1 = 0, d2 = 0, d3 = 0, d4 = 0;
    for (int a = 0; a < i; a++)
    {
        if (a)
            d1 = 1;
        else
            d1 = 0;
        for (int b = a; b < i; b++)
        {
            if (b)
                d2 = 1;
            else
                d2 = 0;

            for (int c = b; c < i; c++)
            {
                if (c)
                    d3 = 1;
                else
                    d3 = 0;
                for (int d = c; d < i; d++)
                {
                    if (d)
                        d4 = 1;
                    else
                        d4 = 0;
                    int ff = d1 + d2 + d3 + d4;
                    if (ff == 0)
                        continue;
                    int sum = arr[a] + arr[b] + arr[c] + arr[d];
                    if (sum >= limit)
                        break;
                    dp[sum][ff]++;
                }
            }
        }
    }
    int input = 1;
    cin >> input;
    while (input)
    {
        int ret = 0;
        for (int tt = 1; tt < 5; tt++)
            ret += dp[input][tt];
        cout << ret << "\n";
        cin >> input;
    }

    return 0;
}