#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

#define ll long long
#define pii pair<int,int>
#define pipii pair<int,pair<int,int>>

struct compare{
    bool operator()(pipii&a, pipii&b){
        return a.first>b.first;
    }
};
struct comp{
    bool operator() (pii&a, pii&b){
        return a.second>b.second;
    }
};
priority_queue<pipii,vector<pipii>,compare> PQ;
priority_queue<pipii,vector<pipii>,compare> mstPQ;
vector<pii> V[1001];
vector<pii> mst[1001];
int n,m;

bool vvisit[1001];
void makeMst(){
    for(pii next: V[1]){
        mstPQ.push({next.first,{1,next.second}});
    }
    vvisit[1]=1;
    while(!mstPQ.empty()){
        pipii top = mstPQ.top();
        mstPQ.pop();
        int u,v,w;
        u = top.second.first;
        v = top.second.second;
        w = top.first;
        if(vvisit[v])continue;
        vvisit[v]=1;
        mst[u].push_back({v,w});
        mst[v].push_back({u,w});
        for(pii next: V[v]){
            if(vvisit[next.first])continue;
            mstPQ.push({next.second,{v,next.first}});
        }

    }
}




int countMst(int a,int b){
    priority_queue<pii,vector<pii>,comp> pq;

    for(pii next: mst[a]){
        pq.push(next);
    }
    for(pii next: mst[b]){
        pq.push(next);
    }
    vvisit[a]=1;
    vvisit[b]=1;
    int cnt=0;
    int val=0;
    while(!pq.empty()){
        pii top = pq.top();
        pq.pop();
        int v = top.first;
        int w = top.second;

        if(vvisit[v])continue;
        vvisit[v]=1;
        val+=w;
        for(pii next: mst[v]){
            pq.push(next);
        }

    }
    return val;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;int a,b,c;
    for(int i=0;i<m;i++){
        cin>>a>>b>>c;
        V[a].push_back({b,c});
        V[b].push_back({a,c});
    }
    makeMst();
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        memset(vvisit,0,sizeof(bool)*1001);
        cout<<countMst(a,b)<<"\n";
    }

    return 0;
}