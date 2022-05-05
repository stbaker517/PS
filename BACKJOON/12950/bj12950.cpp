#include<iostream>
#include<queue>
#include<tuple>
using namespace std;
#define tiii tuple<int,int,int>
#define pic pair<int,char>
bool vvisit[20][20];
queue<tuple<int,int,int>>Q;
vector<pair<int,char>>V[20];
int len=0;
int n,m;
void f(){
    while(!Q.empty()){
        
        tiii top=Q.front();
        int L=get<0>(top);
        int R=get<1>(top);
        int l=get<2>(top);
        
        Q.pop(); if(len!=0&&l>=len)continue;
        for(pic nextL:V[L]){
            for(pic nextR:V[R]){
                int lv=nextL.first;
                char lch=nextL.second;
                int rv=nextR.first;
                char rch=nextR.second;
                if(lch!=rch)continue;
                if(vvisit[lv][rv])continue;

                vvisit[lv][rv  ]=1;
                
                if(lv==R&&rv==L){
                    if(len==0)
                        len=l+1;
                    else if(len>l+1){
                        len=l+1;
                    }
                    
                }
                if(lv==rv){
                    if(len==0)
                        len=l+2;
                    else if(len>l+2){
                        len=l+2;
                    }
                   
                }
                Q.push(make_tuple(lv,rv,l+2));
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    int u,v;
    char a;
    for(int i=0;i<m;i++){
        cin>>u>>v>>a;
        V[u].push_back({v,a});
        V[v].push_back({u,a});
        //cout<<a<<"\n";
    }
    Q.push(make_tuple(0,1,0));
    vvisit[0][1]=1;
    f();
    if(len==0)cout<<-1;
    else cout<<len;

    return 0;
}