#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>
#define tiii tuple<int, int, int>
vector<pii> V[500];
vector<pii> sV[500];
struct compare
{
    bool operator()(pii &a, pii &b)
    {
        return a.second > b.second;
    }
};

int dist[500];
int vvisit[500];
int n;
int numE;
int s, dest;
int delMap[500][500];
void Dj()
{
    dist[s] = 0;
    priority_queue<pii, vector<pii>, compare> PQ;
    PQ.push({s, 0});
    while (!PQ.empty())
    {
        // cout << "A";

        pii cur = PQ.top();
        PQ.pop();
        int curV = cur.first;
        int curD = dist[curV];
        vvisit[curV] = 1;
        for (pii next : V[curV])
        {
            int nextV = next.first;
            int distE = next.second;
            if (vvisit[nextV])
                continue;
            if (dist[nextV] > dist[curD] + distE)
            {
                dist[nextV] = dist[curD] + distE;
                PQ.push({nextV, dist[nextV]});
            }
        }
    }
}

bool dfs(int v, int curD)
{
    if (v == dest)
        return true;
    int cnt = 0;

    for (pii e : V[v])
    {
        if (vvisit[e.first])
            continue;

        if (curD + e.second > dist[e.first])
            continue;

        vvisit[e.first] = 1;
        if (dfs(e.first, curD + e.second))
        {
            cnt++;
            delMap[v][e.first] = 0;
        }
        vvisit[e.first] = 0;
    }
    if (cnt)
        return true;
    else
        return false;
}

void Dj2()
{
    dist[s] = 0;
    priority_queue<pii, vector<pii>, compare> PQ;
    PQ.push({s, 0});
    while (!PQ.empty())
    {
        // cout << "A";

        pii cur = PQ.top();
        PQ.pop();
        int curV = cur.first;
        int curD = dist[curV];
        vvisit[curV] = 1;
        for (pii next : V[curV])
        {

            int nextV = next.first;
            int distE = next.second;
            if (!delMap[curV][nextV])
                continue;
            if (vvisit[nextV])
                continue;
            if (dist[nextV] > dist[curD] + distE)
            {
                dist[nextV] = dist[curD] + distE;
                PQ.push({nextV, dist[nextV]});
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while (1)
    {
        cin >> n >> numE;
        if (n == 0)
            break;
        for (int i = 0; i < n; i++)
        {
            dist[i] = 500000;
        }

        cin >> s >> dest;
        memset(delMap, 0, sizeof(int) * 500 * 500);
        int u, v, w;
        for (int i = 0; i < numE; i++)
        {
            cin >> u >> v >> w;
            V[u].push_back({v, w});
            delMap[u][v] = 1;
        }

        Dj();
        cout << "origin: " << dist[dest] << "\n";
        memset(vvisit, 0, sizeof(int) * 500);
        vvisit[s] = 1;
        dfs(s, 0);

        for (int i = 0; i < n; i++)
        {
            dist[i] = 500000;
        }
        memset(vvisit, 0, sizeof(int) * 500);
        Dj2();

        if (dist[dest] == 500000)
            dist[dest] = -1;
        cout << dist[dest] << "\n";

        for (int i = 0; i < n; i++)
        {
            V[i].clear();
            sV[i].clear();
        }
        memset(vvisit, 0, sizeof(int) * 500);
    }

    return 0;
}