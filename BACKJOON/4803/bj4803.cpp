#include <bits/stdc++.h>

using namespace std;
vector<int> V[500];
int visitt[500];
int par[500];
int idx = 0;
int isTree = 1;
void dfs(int v)
{
    if (visitt[v])
    {
        isTree = 0;
        return;
    }
    visitt[v] = 1;
    for (int i = 0; i < V[v].size(); i++)
    {
        int next = V[v][i];
        if (par[v] == next)
            continue;

        par[next] = v;

        dfs(next);
    }
}
int main()
{
    int n;
    int m;
    for (int t = 1;; t++)
    {
        memset(visitt, 0, sizeof(int) * 500);
        memset(par, -1, sizeof(int) * 500);
        idx = 0;
        for (int i = 0; i < 500; i++)
            V[i].clear();

        cin >> n >> m;

        if (n == 0 && m == 0)
            break;
        int a, b;
        for (int i = 0; i < m; i++)
        {
            cin >> a >> b;
            a -= 1;
            b -= 1;
            V[a].push_back(b);
            V[b].push_back(a);
        }

        for (int i = 0; i < n; i++)
        {
            if (visitt[i])
                continue;
            par[i] = i;
            isTree = 1;

            dfs(i);
            if (isTree)
                idx++;
        }
        /*Case 1: A forest of 3 trees.
Case 2: There is one tree.
Case 3: No trees.*/
        cout << "Case " << t << ": ";
        if (idx > 1)
        {
            cout << "A forest of " << idx << " trees.";
        }
        else if (idx)
        {
            cout << "There is one tree.";
        }
        else
        {
            cout << "No trees.";
        }

        cout << "\n";
    }
    return 0;
}