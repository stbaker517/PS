#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
#include<tuple>
using namespace std;

#define pii pair<int, int>
#define tiii tuple<int, int, int>
#define fmk make_tuple
//vector<pii> V[500];

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
        return a.second > b.second;
    }
};

int dist[500];
bool vvisit[500];
int n;
int numE;
int s, dest;
int delMap[500][500];
bool path[500][500];
void _Dj(vector<pii>*V)
{
    dist[s] = 0;
    priority_queue<tiii, vector<tiii>, compare> PQ;
    PQ.push(fmk(s,s,0));
    int numV=0;
    while (!PQ.empty())
    {
        // cout << "A";

        tiii cur = PQ.top();
        PQ.pop();
        int curU = get<1>(cur);
        int curD =get<2>(cur);
        if(dist[curU]<=curD)
            path[get<0>(cur)][curU]=1;
        else if(numV==n)break;
        else
            continue;
        if(vvisit[curU])continue;
        
        numV++;
        
        vvisit[curU] = 1;
        //cout<<"DJ "<<curV<<" "<<dist[curV]<<"\n"; 

        for (pii next : V[curU])
        {
            int nextV = next.first;
            int distE = next.second;
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

bool dfs(int v, int curD,vector<pii>*V)
{
    if (v == dest)
        return true;
    int cnt = 0;

    for (pii e : V[v])
    {
        if(delMap[v][e.first])return true;
        if(vvisit[e.first])
            continue;
        //if(!path[v][e.first])continue;
        if (curD + e.second > dist[e.first]||curD + e.second>dist[dest])
            continue;
        
        vvisit[e.first] = 1;
        if (dfs(e.first, curD + e.second,V))
        {
            cnt++;
            delMap[v][e.first] = 1;
           // cout<<"del: "<<v<<"->"<<e.first<<"\n";
        }

        vvisit[e.first] = 0;
    }
    if (cnt)
        return true;

    //
    return false;
}

void Dj2(vector<pii>*V)
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
        if(curV==dest)break;
        
        for (pii next : V[curV])
        {
            
            int nextV = next.first;
            int distE = next.second;
            if (delMap[curV][nextV]==1)
                continue;
           // printf("DJ2:from %d  to %d \n",curV,next.first);
            if (dist[nextV] > curD + distE)
            {
                dist[nextV] = curD + distE;
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
        vector<pii>V[500];
        for (int i = 0; i < n; i++)
        {
            dist[i] = 5000000;
        }
        cin >> s >> dest;
       
        memset(path, 0, sizeof(bool)*25'00'00);
        memset(delMap, 0, sizeof(int) * 250'0'00);
        
        
        int u, v, w;
        for (int i = 0; i < numE; i++)
        {
            cin >> u >> v >> w;
            V[u].push_back({v, w});
            
        }
        
        _Dj(V);
        path[s][s]=0;
       //cout << "origin: " << dist[dest] << "\n";
        memset(vvisit, 0, sizeof(bool) * n);
        vvisit[s] = 1;
        dfs(s, 0,V);

        for (int i = 0; i < n; i++)
        {
            dist[i] = 5000000;
        }
        memset(vvisit, 0, sizeof(bool) * n);

        Dj2(V);

        if (dist[dest] == 5000000)
            dist[dest] = -1;
        cout << dist[dest] << "\n";


        memset(vvisit, 0, sizeof(bool) * n);
    }

    return 0;
}