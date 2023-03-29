#include<iostream>
#include<vector>
using namespace std;

#define ll long long

vector<int>V[1<<20];
ll tree[1<<20];
ll lazy[1<<20];
int ii[1<<20];
int oo[1<<20];
ll depth[1<<20];
int n,c;
int cnt=0;
bool vvisit[1<<20];
void eulerTour(int node,int d){
    vvisit[node]=1;
    ii[node]=++cnt;
    depth[node]=d;
    for(int next: V[node]){
        if(vvisit[next])continue;
        eulerTour(next,d+1);
    }
    oo[node]=cnt;
}



void update(int node, int start, int end, int l, int r){
    
    if(end<l || r<start)return;
    tree[node]++;
    if(l<=start && end<=r){
        
        return;
    }

    int mid = (start+end)>>1;
    update(node*2,start,mid,l,r);
    update(node*2+1,mid+1,end,l,r);
}

ll query(int node, int start, int end, int l, int r) {

    if(end<l || r<start)return 0;
    if(l<=start && end<=r){
        return tree[node];
    }

    int mid = (start+end)>>1;
    return query(node*2,start,mid,l,r) + query(node*2+1,mid+1,end,l,r);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>c;
    int a,b;
    for(int i=1;i<=n-1;i++){
        cin>>a>>b;
        V[a].push_back(b);
        V[b].push_back(a);
    }
    eulerTour(c,1);

    int m;
    ll val;
    cin>>m;
    
    for(int i=0;i<m;i++){
        cin>>a>>b;
        switch (a)
        {
        case 1:
            update(1,1,n,ii[b],ii[b]);
            break;
        
        case 2:
            cout<<depth[b]*query(1,1,n,ii[b],oo[b])<<"\n";
        break;
        }
    }
}