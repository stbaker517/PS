#include <bits/stdc++.h>

using namespace std;

int isPal[2000][2000];
int visited[2000][2000];
string str;
void makePal(int s, int e)
{
    if (s < 0 || e < 0 || s >= str.size() || e >= str.size())
        return;
    if (visited[s][e])
        return;
    visited[s][e] = 1;
    if (s == e)
    {
        isPal[s][e] = 1;
        makePal(s - 1, e + 1);
        return;
    }
    if (e - s == 1 && str[s] == str[e])
    {
        isPal[s][e] = 1;
        makePal(s - 1, e + 1);
        return;
    }
    if (isPal[s + 1][e - 1] && str[s] == str[e])
    {
        isPal[s][e] = 1;
        makePal(s - 1, e + 1);
        return;
    }

    return;
}
void ptr(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", isPal[i][j]);
        }
        printf("\n");
    }
}
int dp[2000];
int main()
{
    cin >> str;
    for (int i = 0; i < str.size(); i++)
        makePal(i, i);
    for (int i = 0; i < str.size() - 1; i++)
    {
        makePal(i, i + 1);
    }
    //ptr(str.size());
    for (int i = 0; i < str.size(); i++)
    {
        if (isPal[0][i])
            dp[i] = 1;
    }
    for (int i = 0; i < str.size() - 1; i++)
    {
        if (dp[i])
        {
            for (int j = str.size(); j > i; j--)
            {
                if (isPal[i + 1][j])
                {
                    if (dp[j] == 0)
                        dp[j] = dp[i] + 1;
                    else
                        dp[j] = min(dp[j], dp[i] + 1);
                }
            }
        }
    }
    cout << dp[str.size() - 1];
    return 0;
}