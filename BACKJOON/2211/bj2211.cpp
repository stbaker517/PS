#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;

#define pii pair<int, int>
#define tiii tuple<int, int, int> // v,dist,numofedge
#define MAXINT 9999999;
int n, k;
vector<pii> V[1001];
int dist[1001];
int pprev[1001];
int vvisit[1001];
int prt[1001];
int E = 0;
typedef struct cmp
{
    bool operator()(tiii a, tiii b)
    {
        if (get<1>(a) > get<1>(b))
            return true;
        else if (get<1>(a) == get<1>(b))
        {
            if (get<2>(a) > get<2>(b))
                return true;
        }
        return false;
    }
} cmp;
void D()
{
    for (int i = 1; i <= n; i++)
    {
        dist[i] = MAXINT;
        pprev[i] = 0;
    }
    priority_queue<tiii, vector<tiii>, cmp> PQ;
    PQ.push(make_tuple(1, 0, 0));

    dist[1] = 0;
    pprev[1] = 1;
    while (!PQ.empty())
    {
        tiii top = PQ.top();
        PQ.pop();
        int curV = get<0>(top);
        int curD = get<1>(top);
        int numE = get<2>(top);
        if (vvisit[curV])
            continue;
        vvisit[curV] = 1;
        E = max(E, numE);
        for (auto next : V[curV])
        {
            int nextV = next.first;
            int nextW = next.second;
            if (vvisit[nextV])
                continue;
            if (dist[nextV] > dist[curV] + nextW)
            {
                dist[nextV] = dist[curV] + nextW;
                PQ.push(make_tuple(nextV, dist[curV] + nextW, numE + 1));
                pprev[nextV] = curV;
            }
        }
    }
}

int main()
{
    cin >> n >> k;
    for (int i = 0; i < k; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        V[u].push_back({v, w});
        V[v].push_back({u, w});
    }
    D();

    queue<pii> Q;
    for (int i = 2; i <= n; i++)
    {
        if (prt[i])
            continue;
        prt[i] = 1;

        Q.push({i, pprev[i]});
    }
    cout << Q.size() << "\n";
    while (!Q.empty())
    {
        pii top = Q.front();
        Q.pop();
        cout << top.first << " " << top.second << "\n";
    }

    return 0;
}