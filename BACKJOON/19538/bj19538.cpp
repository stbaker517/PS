#include<iostream>
#include<vector>
#include<queue>

using namespace std;


class Graph{
    public:
        int time[200001];
        int cnt[200001];
        bool blv[200001];
        vector<int> V[200001];

        void setT(int a){
            for(int i=1;i<=a;i++)
                time[i]=-1;
        }
};

Graph G;
queue<int> Q;
int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    G.setT(n);
    int a;

    for(int i=1;i<=n;i++)
    {
        while(1)
        {
            cin>>a;
            if(a==0)break;
            G.V[i].push_back(a);
        }
    }

    int m;
    cin>>m;
    for(int i=0;i<m;i++)
    {
        cin>>a;
        G.time[a]=0;
        G.blv[a]=1;
        Q.push(a);
    }

    while(!Q.empty())
    {
        int v=Q.front();
        Q.pop();

        for(int d: G.V[v])
        {
            if(G.blv[d])continue;
            G.cnt[d]++;
            if(G.cnt[d]*2<G.V[d].size())continue;
            
            G.blv[d]=1;
            G.time[d]=G.time[v]+1;
           Q.push(d);
        }

    }

    for(int i=1;i<=n;i++)cout<<G.time[i]<<" ";
    return 0;
}