#include<iostream>
#include<vector>
#include<tuple>
#include<queue>
#include<algorithm>

using namespace std;

#define tiii tuple<int,int,int>
#define pii pair<int,int>
int a[3];
int n,m;

class Graph{
    public:
        vector<pair<int,int>>* V;
        int *dist[3];
        bool *visit[3];

    void init(){
        V=new vector<pair<int,int>>[n+1];
        for(int i=0;i<3;i++)
        {    
            dist[i]=new int[n+1];
            visit[i]=new bool[n+1];

            for(int j=0;j<n+1;j++)
            {
                dist[i][j]=0x7fffffff;
                visit[i][j]=0;
            }
        }
        
    }



};

Graph G;

void DIJI(){
    priority_queue<pii,vector<pii>,greater<pii>> PQ;
    
    for(int qq=0;qq<3;qq++)
    {
        //cout<<qq;
        int V=a[qq];
        //G.visit[qq][V]=1;
        G.dist[qq][V]=0;
        PQ.push({0,V});

        while(!PQ.empty())
        {
            int curV=PQ.top().second;
            int curD=PQ.top().first;
            //cout<<"curV: "<<curV<<" curD "<<curD<<"\n";
            PQ.pop();

            if(G.visit[qq][curV])continue;
            

            G.visit[qq][curV]=1;
            G.dist[qq][curV]=curD;

            for(pii e:G.V[curV])
            {
                if(curD+e.first<G.dist[qq][e.second])
                {
                    G.dist[qq][e.second]=curD+e.first;
                    PQ.push({curD+e.first,e.second});
                }
            }
        }
    }
}
int main(){
    //ios::sync_with_stdio(0);
    //cin.tie(0);

    cin>>n>>a[0]>>a[1]>>a[2]>>m;

    G.init();

    int u,v,w;

    for(int i=0;i<m;i++)
    {
        cin>>u>>v>>w;
        G.V[u].push_back({w,v});
        G.V[v].push_back({w,u});
    }
    //cout<<"dd";
    DIJI();

    int* ARR=new int[n+1];
    for(int i=1;i<=n;i++)
    {
        ARR[i]=min(G.dist[0][i],min(G.dist[1][i],G.dist[2][i]));
        //cout<<ARR[i]<<" ";
    }

    int idx=1;

    for(int i=1;i<=n;i++)
    {
        if(ARR[idx]<ARR[i])idx=i;
    }

    cout<<idx;

    return 0;
}