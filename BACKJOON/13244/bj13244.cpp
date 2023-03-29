#include<iostream>
#include<vector>
#include<cstring>
#include<stack>

using namespace std;

int n;
int v;
int e;
int cnt;
vector<int> V[1001];

int nodes[1001][1001];
bool vvisit[1001];


bool func(){
    stack<pair<int,int>> sstack;

    sstack.push({0,v});
    vvisit[0]=1;
    while(!sstack.empty()){
        int par = sstack.top().first;
        int v=sstack.top().second;
        sstack.pop();
        vvisit[v]=1;
        cnt++;
        for(int nextV: V[v]){
            if(vvisit[nextV]){
                if(nextV==par)continue;
                return true;
            }

            vvisit[nextV]=1;
            sstack.push({v,nextV});
        }
        

    }
    if(cnt==v)return true;
    return false;

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    for(int i=0;i<n;i++){
                memset(vvisit,0,sizeof(bool)*1001);
        memset(nodes,0,sizeof(int)*1001*1001);
        for(int i=0;i<1001;i++){
            V[i].clear();
        }
        cnt=0;
        cin>>v;
        cin>>e;
        int a,b;
        bool flag=0;

        for(int j=0;j<e;j++){
            cin>>a>>b;
            V[a].push_back(b);
            V[b].push_back(a);
            nodes[a][b]++;
            nodes[b][a]++;
            if(nodes[a][b]>1||nodes[b][a]>1){
                flag=1;
            }
        }
        if(e!=v-1){
            cout<<"graph\n";
            continue;
        }
        if(func()&&flag==0){
            cout<<"tree\n";
        } else {
            cout<<"graph\n";
        }



    }

    

}