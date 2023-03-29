#include<iostream>
#include<vector>
#include<stack>
using namespace std;
#define ll long long
vector<int> td[100001];
int par[100001];
ll lazy[1<<20];
ll tree[1<<20];
int ii[100001];
int oo[100001];

int n,m;
int boss;

int cnt=0;
void dfs(int node){
    cnt++;
    ii[node]=cnt;
    for(int d: td[node]){
        dfs(d);
    }
    oo[node]=cnt;
}

void update_lazy(int node,int start,int end){
    if(lazy[node]){
        
        if(start!=end){
            lazy[node*2]+=lazy[node];
            lazy[node*2+1]+=lazy[node];
        }else tree[node]+=lazy[node];
        lazy[node]=0;
    }
}
void update(int node, int start, int end, int l, int r, ll val){
    update_lazy(node,start,end);
    if(end<l || r<start)return;
    if(l<=start && end <=r){
        lazy[node]+=val;
        update_lazy(node,start,end);
        return;
    }
    int mid = (start+end)>>1;
    update(node*2,start,mid,l,r,val);
    update(node*2+1,mid+1,end,l,r,val);
}
ll query(int node, int start, int end, int l, int r) {
    update_lazy(node,start,end);
    if(end<l || r<start)return 0;
    if(l <= start && end <= r) {
        return tree[node];
    }

    int mid = (start+end)>>1;
    return query(node*2,start,mid,l,r) + query(node*2+1,mid+1,end,l,r);
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int u;
        cin>>u;
        par[i]=u;
        if(u==-1)continue;
        td[u].push_back(i);
    }
    
    dfs(1);
    for(int i=0;i<m;i++){
        int a,b;
        ll c;
        cin>>a>>b;
        switch(a){
            case 1:
            cin>>c;
            update(1,1,n,ii[b],oo[b],c);
            break;
            case 2:
            cout<<query(1,1,n,ii[b],ii[b])<<"\n";
            break;
        }
    }


    return 0;
}