#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
int n;
vector<pii> V[10000];
vector<pii> e[10000];

int main()
{
    ios::sync_with_stdio(0);
    while (1)
    {
        cin >> n;
        if (n == 0)
            break;
        for (int i = 0; i < n; i++)
            V[i].clear();

        int u, v, w;
        for (int i = 1; i < n; i++)
        {
            cin >> u >> v >> w;
            V[u].push_back({v, w});
            V[v].push_back({u, w});
        }
    }
    return 0;
}