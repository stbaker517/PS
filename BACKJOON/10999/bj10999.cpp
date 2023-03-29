#include<iostream>
#include<queue>
using namespace std;
#define ll long long

ll tree[1<<22];
ll lazy[1<<24];
bool isLeaf[1<<22];

ll arr[1<<20];
int idxArr[1<<20];
int parent[1<<22];
void setTree(int idx, int l, int r){
    parent[idx]=idx/2;
    if(l >= r){
        isLeaf[idx]=1;
        tree[idx] = arr[l];
        idxArr[l] = idx;
        return ;
    }

    int mid = (l+r)/2;
    setTree(idx*2, l, mid);
    setTree(idx*2+1, mid+1,r);
    
    tree[idx] = tree[idx*2] + tree[idx*2+1];
    return;
}



void update_lazy(int idx, int start, int end) {
    if(lazy[idx]){
        tree[idx] += ((ll)end-start+1) * lazy[idx];
        if(start!=end){
            lazy[2*idx+1] +=lazy[idx];
            lazy[2*idx] +=lazy[idx];
        }
        lazy[idx]=0;
    }
}

void update(int idx,int l, int r,int start,int end, ll val){
   
    update_lazy(idx, start, end);
   
    if(l<=start && end <=r){
        tree[idx] += ((ll)end-start+1)*val;
        if(start!=end){
            lazy[idx*2]+=val;
            lazy[idx*2+1]+=val;
        }
        return;
    } else if( r<start || end<l) return;

    //반반
    int mid = (start+end)/2;
    update(idx*2,l,r,start,mid,val);
    update(idx*2+1,l,r,mid+1,end,val);
    tree[idx]=tree[idx*2]+tree[idx*2+1];
}

ll query(int idx,int l,int r,int start, int end){
    update_lazy(idx,start,end);
    if(l<=start && end <=r){

        return tree[idx];
    } else if( r<start || end<l) return 0 ;
    //반반
    int mid = (start+end)/2;
    return query(idx*2,l,r,start,mid)+query(idx*2+1,l,r,mid+1,end);
}
int n,m,k;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    setTree(1,1,n);
    parent[1]=1;
    for(int i=0;i<m+k;i++){
        int o,a,b;
        ll c;
        cin>>o;
        switch(o){
            case 1:
            cin>>a>>b;
            cin>>c;
            update(1,a,b,1,n,c);
            break;
            case 2:
            cin>>a>>b;
            cout<<query(1,a,b,1,n)<<"\n";
            break;
        }

    }

}