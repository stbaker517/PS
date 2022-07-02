#include <iostream>

using namespace std;

int digit[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6, 6};
int small[] = {0, 1, 7, 4, 2, 7, 8};
int Test = 0;

long long dp[101];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> Test;
    int n;
    dp[2] = 1;
    dp[3] = 7;
    dp[4] = 4;
    dp[5] = 2;
    dp[6] = 6;
    dp[7] = 8;
    for (int i = 2; i <= 100; i++)
    {
        //작은 거.
        for (int j = 0; j < 7; j++)
        {
            if (i + digit[small[j]] > 100)
                continue;
            // if(dp[dp[i+small[j]]])continue;
            if (dp[i + digit[small[j]]] != 0)
                dp[i + digit[small[j]]] = min(dp[i] * 10 + small[j], dp[i + digit[small[j]]]);
            else
            {
                dp[i + digit[small[j]]] = dp[i] * 10 + small[j];
            }
        }
    }

    for (int aa = 0; aa < Test; aa++)
    {
        cin >> n;
        cout << dp[n] << " ";
        // print Big
        if (n % 2 == 0)
        {
            for (int i = 0; i < n / 2; i++)
            {
                cout << 1;
            }
        }
        else
        {
            cout << 7;
            for (int i = 0; i < (n - 3) / 2; i++)
            {
                cout << 1;
            }
        }
        cout << "\n";
    }

    return 0;
}