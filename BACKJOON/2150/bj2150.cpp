#include <bits/stdc++.h>
using namespace std;

vector<int> V[10001];
vector<int> SCC[10001];
int par[10001];
int numV, numE;

int dfs(int v)
{
    if (!par[v])
        par[v] = v;
    for (int e : V[v])
    {
        if (par[e])
        {
            par[v] = par[e];
            return par[v];
        }
        int dt = dfs(e);
        if (dt != e)
        {
            par[v] = dt;
            return dt;
        }
    }
    return par[v];
}
int main()
{
    cin >> numV >> numE;
    int a, b;
    for (int i = 0; i < numE; i++)
    {
        cin >> a >> b;
        V[a].push_back(b);
    }
    for (int i = 1; i <= numV; i++)
    {
        if (par[i])
            continue;
        dfs(i);
    }
    for (int i = 1; i <= numV; i++)
    {
        SCC[par[i]].push_back(i);
    }
    int ans = 0;
    for (int i = 1; i <= numV; i++)
    {
        if (SCC[i].size() > 0)
            ans++;
    }
    cout << ans << "\n";
    for (int i = 1; i <= numV; i++)
    {
        if (SCC[i].size() > 0)
        {
            sort(SCC[i].begin(), SCC[i].end());
            for (int e : SCC[i])
            {
                cout << e << " ";
            }
            cout << "-1\n";
        }
    }

    return 0;
}