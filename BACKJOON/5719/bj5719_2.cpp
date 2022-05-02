#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
#include<tuple>
using namespace std;

#define pii pair<int, int>
#define tiii tuple<int, int, int>
#define fmk make_tuple
vector<pii> V[500];
vector<pii> sV[500];
struct compare
{
    bool operator()(tiii &a, tiii &b)
    {
        return get<2>(a) > get<2>(b);
    }
};
struct compare_pii
{
    bool operator()(pii &a, pii &b)
    {
        return a.first > b.second;
    }
};

int dist[500];
int vvisit[500];
int n;
int numE;
int s, dest;
int delMap[500][500];
bool path[500][500];
void _Dj()
{
    dist[s] = 0;
    priority_queue<tiii, vector<tiii>, compare> PQ;
    PQ.push(fmk(s,s,0));
    while (!PQ.empty())
    {
        // cout << "A";

        tiii cur = PQ.top();
        PQ.pop();
        int beforeU=get<0>(cur);
        int curU = get<1>(cur);
        int curD =get<2>(cur);
        if(dist[curU]==curD)
            path[beforeU][curU]=1;
        else break;
        if(vvisit[curU])continue;
        vvisit[curU] = 1;
        //cout<<"DJ "<<curV<<" "<<dist[curV]<<"\n"; 

        for (pii next : V[curU])
        {
            int nextV = next.first;
            int distE = next.second;
            if (vvisit[nextV])
                continue;
            if (dist[nextV] >= dist[curU] + distE)
            {
                dist[nextV] = dist[curU] + distE;
                PQ.push(fmk(curU,nextV,dist[nextV]));
            }
        }
    }
}
    /*
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
        int curD = cur.second;

        if(vvisit[curV])continue;
        vvisit[curV] = 1;
        //cout<<"DJ "<<curV<<" "<<dist[curV]<<"\n"; 

        for (pii next : V[curV])
        {
            int nextV = next.first;
            int distE = next.second;
            if (vvisit[nextV])
                continue;
            if (dist[nextV] > dist[curV] + distE)
            {
                dist[nextV] = dist[curV] + distE;
                PQ.push({nextV, dist[nextV]});
            }
        }
    }
}*/

bool dfs(int v, int curD)
{
    if (v == dest)
        return true;
    int cnt = 0;

    for (pii e : V[v])
    {
        if (vvisit[e.first])
            continue;
        if(!path[v][e.first])continue;
        if (curD + e.second > dist[e.first]||curD + e.second>dist[dest])
            continue;
        vvisit[e.first] = 1;
        if (dfs(e.first, curD + e.second))
        {
            cnt++;
            delMap[v][e.first] = 1;
           // cout<<"del: "<<v<<"->"<<e.first<<"\n";
        }
        vvisit[e.first] = 0;
    }
    if (cnt)
        return true;
    
    return false;
}

void Dj2()
{
    dist[s] = 0;
    priority_queue<pii, vector<pii>, compare_pii> PQ;
    PQ.push({s, 0});
    while (!PQ.empty())
    {
        // cout << "A";

        pii cur = PQ.top();
        PQ.pop();
        int curV = cur.first;
        int curD = dist[curV];
         if(vvisit[curV])continue;
        vvisit[curV] = 1;
        
        for (pii next : V[curV])
        {

            int nextV = next.first;
            int distE = next.second;
            if (delMap[curV][nextV])
                continue;
            if (vvisit[nextV])
                continue;
            if (dist[nextV] > dist[curV] + distE)
            {
                dist[nextV] = dist[curV] + distE;
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
            
        }

        _Dj();
        path[s][s]=0;
       // cout << "origin: " << dist[dest] << "\n";
        memset(vvisit, 0, sizeof(int) * n);
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