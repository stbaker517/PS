#include <bits/stdc++.h>

using namespace std;

int n;
int v[10000];
int dp[10000][3];
bool visit[10000];
vector<int> edge[10000];
void f(int p, int c)
{

    for (int i = 0; i < edge[c].size(); i++)
    {
        if (edge[c][i] == p)
            continue;

        f(c, edge[c][i]);
    }
    cout << "node:" << c << "\n";
    dp[p][0] += max(dp[c][1], dp[c][2]);
    dp[p][1] += dp[c][0];
    if (edge[c].size() != 1)
        dp[p][2] += dp[c][1];
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> v[i];

    for (int i = 0; i < n; i++)
        dp[i][0] = v[i];

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;

        a -= 1;
        b -= 1;

        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    for (int i = 0; i < edge[0].size(); i++)
    {
        f(0, edge[0][i]);
    }

    //cout << max(dp[0][0], dp[0][1]);

    for (int i = 0; i < n; i++)
    {
        cout << i << ": ";
        for (int j = 0; j < 3; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}