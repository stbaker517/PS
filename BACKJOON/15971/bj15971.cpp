#include<iostream>
#include<tuple>
#include<queue>
#include<vector>

#define edge tuple<int,int,int>
using namespace std;

int Dist[100001];
class Graph{
    public:
        int dist[100001];
        int visit[100001];
        vector<edge> V[100001];

        void setZero(){
            for(int i=0;i<100001;i++)
            {
                dist[i]=0;
                visit[i]=0;
            }
        }
};

Graph G;
int n,r1,r2;
int flag;

void pathFinding(int v,int lv){
    if(v==r2)
    {
        flag=1;
        int M=0;
        long long sum=0;
        for(int i=0;i<lv;i++)
        {
            M=max(Dist[i],M);
            sum+=Dist[i];
        }
        cout<<sum-M;
        return;
    }

    for(edge e: G.V[v])
    {
        if(flag)return;
        if(G.visit[get<1>(e)])continue;
        G.visit[get<1>(e)]=1;
        Dist[lv]=get<2>(e);
        pathFinding(get<1>(e),lv+1);
    }

    return ;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>r1>>r2;

    int a,b,l;
    for(int i=1;i<n;i++)
    {
        cin>>a>>b>>l;
        G.V[a].push_back(make_tuple(a,b,l));
        G.V[b].push_back(make_tuple(b,a,l));
    }
    G.visit[r1]=1;
    pathFinding(r1,0);
    

    return 0;
}