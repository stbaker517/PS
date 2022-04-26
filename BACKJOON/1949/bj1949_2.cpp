#include <bits/stdc++.h>

using namespace std;

int dp[10000][2];
vector<int> edge[10000];
int visitt[10000];
int popul[10000];
void f(int v)
{
    for (int i = 0; i < edge[v].size(); i++)
    {
        int chd = edge[v][i];
        if (visitt[chd])
            continue;
        visitt[chd] = 1;
        f(chd);
        dp[v][0] += max(dp[chd][0], dp[chd][1]);
        dp[v][1] += dp[chd][0];
    }
}

int n;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> dp[i][1];

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;

        a -= 1;
        b -= 1;

        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    visitt[0] = 1;
    f(0);
    cout << max(dp[0][1], dp[0][0]);

    return 0;
}