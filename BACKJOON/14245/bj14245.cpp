#include<iostream>

using namespace std;
#define ll long long

ll tree[1<<22];
ll lazy[1<<22];
ll arr[1<<20];
int idxArr[1<<20];
bool isLazy[1<<22];

ll createSegTree(int node, int start, int end) {
    if(start==end){
        tree[node] = arr[start];
        idxArr[start]=node;
        return tree[node];
    }

    int mid=(start+end)/2;
    tree[node] = createSegTree(node*2,start,mid) ^ createSegTree(node*2+1,mid+1,end);
    return tree[node];
}

void update_lazy(int node,int start,int end) {
    if(lazy[node]){
        if((end-start)%2==0){
            tree[node] ^= lazy[node];}
        if(start!=end){
            lazy[node*2]^=lazy[node];
            lazy[node*2+1]^=lazy[node];
        }
        lazy[node]=0;
    }
}

void update(int node, int l, int r, int start, int end, ll val) {
    update_lazy(node,start,end);
    if(l<=start && end<=r) {
        if((end-start)%2==0){
            tree[node] ^= val;}
        if(start!=end){
            lazy[node*2]^=val;
            lazy[node*2+1]^=val;
        }
        return;
    }
    if( r<start || l>end) return;

    int mid = (start+end)/2;
    update(node*2,l,r,start,mid,val);
    update(node*2+1,l,r,mid+1,end,val);
    tree[node] = tree[node*2]^tree[node*2+1];
}

ll query(int node,int l,int r,int start, int end) {
    update_lazy(node,start,end);
    if(l<=start && end<=r) {
       return tree[node];
    }
    if( r<start || l>end) return 0;

    int mid = (start+end)/2;
    
    ll left = query(node*2,l,r,start,mid);
    ll right = query(node*2+1,l,r,mid+1,end);
   
   return left^right;
   
}
int n,m,k;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    createSegTree(1,1,n);
    cin>>m;
    int a,b;
    ll c;
    for(int i=0;i<m;i++){
        int o;
        cin>>o;
        switch(o){
            case 2:
            cin>>a;
            cout<<query(1,a+1,a+1,1,n)<<"\n";
            break;
            
            case 1:
            cin>>a>>b>>c;
            update(1,a+1,b+1,1,n,c);
            break;
        }
    }


    return 0;
}