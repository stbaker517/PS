#include<iostream>
#include<queue>
#include<tuple>

using namespace std;

#define pii pair<int,int>
#define pipii pair<int,pair<int,int>>

vector<pii>V[10001];
int n,m;
int sV,eV;

//위상정렬하고 bfs
vector<pii>topolV[10001];
int inLV[10001];

void topolSort(int start){
    queue<int>Q;
    Q.push(start);
    while(!Q.empty()){
        int v=Q.front();
        Q.pop();
        for(pii next:V[v]){
            int nextV=next.first;
            int w=next.second;
            if(nextV!=eV&&!inLV[nextV])continue;
            topolV[v].push_back({nextV,w});
            inLV[nextV]--;
            if(inLV[nextV]>0)continue;
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        V[u].push_back({v,w});
        inLV[v]++;
    }

    cin>>sV>>eV;
}