#include <bits/stdc++.h>
using namespace std;

unsigned long long Dist = 0;

bool visited[100001];
vector<pair<int, int>> V[100001];

int numV;

int dfs(int v, int dist, int &y)
{
    if (dist > Dist)
    {
        Dist = dist;
        y = v;
    }
    int ret = 0;
    for (pair<int, int> e : V[v])
    {
        int next = e.first;
        int d = e.second;
        if (visited[next])
            continue;
        visited[next] = 1;
        ret += dfs(next, dist + d, y);
    }
    if (ret > Dist)
        Dist = ret;
    return ret;
}
int main()
{
    cin >> numV;
    int v;
    for (int i = 0; i < numV; i++)
    {
        int u, v, d;
        cin >> u;
        while (1)
        {
            cin >> v;
            if (v == -1)
                break;
            cin >> d;
            V[u].push_back({v, d});
        }
    }
    int y, z;
    memset(visited, 0, sizeof(bool) * 100001);
    visited[1] = 1;
    dfs(1, 0, y);
    Dist = 0;
    memset(visited, 0, sizeof(bool) * 100001);
    visited[y] = 1;
    dfs(y, 0, z);
    cout << Dist;

    //cout << Dist;
}