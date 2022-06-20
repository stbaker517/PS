#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int n, k, m;
#define ll long long
#define pii pair<int, int>

vector<int> tube[1001];
vector<int> station[100001];
int vvisit[100001];
int visitTube[1001];
void f(int s, int e);
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k >> m;

    for (int t = 1; t <= m; t++)
    {
        for (int e = 1; e <= k; e++)
        {
            int s;
            cin >> s;
            station[s].push_back(t);
            tube[t].push_back(s);
        }
    }

    int s, e;
    s = 1;
    e = n;
    // cin >> s >> e;
    f(s, e);
    if (vvisit[e] == 0)
        cout << -1;
    else
        cout << vvisit[e];
}
void f(int s, int e)
{

    memset(vvisit, 0, sizeof(int) * 100001);
    memset(visitTube, 0, sizeof(int) * 1001);
    vvisit[s] = 1;
    if (s == e)
        return;

    queue<int> Q;
    Q.push(s);

    while (!Q.empty())
    {
        int frt = Q.front();
        Q.pop();
        for (int nextTube : station[frt])
        {
            if (visitTube[nextTube])
                continue;
            visitTube[nextTube] = 1;
            for (int v : tube[nextTube])
            {
                if (vvisit[v])
                    continue;
                vvisit[v] = vvisit[frt] + 1;
                Q.push(v);
            }
        }
    }
}