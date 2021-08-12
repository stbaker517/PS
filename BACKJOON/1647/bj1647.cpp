#include<iostream>
#include<queue>
#include<vector>
#include<tuple>
using namespace std;
typedef tuple<int,int,int> TP;

priority_queue<TP,vector<TP>,greater<TP>>PQ;
vector<tuple<int,int,int>>vec;
int n,m;
int set[100001];
int findroot(int v){
    while(v!=set[v])
    {
        v=set[v];
    }
    return v;
}

void setSets(int child,int nroot)
{
    int tmp;
    while(set[child]!=child)
    {
        tmp=set[child];
        set[child]=nroot;
        child=tmp;
    }
    set[child]=nroot;
}
void kruscal(){

    while(!PQ.empty())
    {
        int u,v,w;
        w=get<0>(PQ.top());
        u=get<1>(PQ.top());
        v=get<2>(PQ.top());
        PQ.pop();

        int rootU=findroot(u);
        int rootV=findroot(v);

        if(rootU==rootV)continue;

        if(rootU<rootV)
        {
            setSets(v,rootU);
            //set[set[v]]=rootU;
            vec.push_back(make_tuple(w,u,v));
        }
        else
        {
            setSets(u,rootV);
            //set[set[u]]=rootV;
            vec.push_back(make_tuple(w,u,v));
        }
    }
}

int main(){
    cin>>n>>m;
    int w,u,v;
    for(int i=0;i<=100000;i++)set[i]=i;
    
    for(int i=0;i<m;i++)
    {
        cin>>u>>v>>w;
        PQ.push(make_tuple(w,u,v));
    }
    kruscal();
    long long cnt=0;
    for(int i=0;i<vec.size()-1;i++)
    {
        //cout<<get<1>(vec[i])<<", "<<get<2>(vec[i])<<", "<<get<0>(vec[i])<<"\n";
        cnt+=get<0>(vec[i]);
    
    }
    cout<<cnt;

    return 0;
}