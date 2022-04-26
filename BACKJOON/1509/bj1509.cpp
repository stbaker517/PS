#include <bits/stdc++.h>
using namespace std;

int dp[2501][2501];
string str;
int n;
int dp_[2501];
void makePDtable();
void fDP(int start, int end);
void makeDP();
int main()
{
    cin >> str;
    n = str.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            dp[i][j] = 0;
        }
    }
    makePDtable();
    for (int i = 0; i < n; i++)
        dp_[i] = 0x7fffffff;
    //dp_[0] = 1;
    makeDP();
    cout << dp_[n - 1];
    return 0;
}
void makeDP()
{
    //a->b
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (dp[i][j])
                dp_[j] = min(dp_[i - 1] + 1, dp_[j]);
        }
    }
}
void makePDtable()
{
    for (int i = 0; i < n; i++)
    {

        fDP(i, i);
    }
    for (int i = 0; i < n - 1; i++)
    {
        fDP(i, i + 1);
    }
}
void fDP(int start, int end)
{
    if (start < 0 || end >= n)
        return;
    if (start == end)
    {
        dp[start][end] = 1;
        fDP(start - 1, end + 1);
    }
    else if (end - start == 1 && str[start] == str[end])
    {
        dp[start][end] = 1;
        fDP(start - 1, end + 1);
    }
    else
    {
        if (dp[start + 1][end - 1] && str[start] == str[end])
            dp[start][end] = 1;
        fDP(start - 1, end + 1);
    }
    return;
}