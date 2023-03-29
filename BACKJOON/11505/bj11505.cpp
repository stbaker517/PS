#include<iostream>

using namespace std;
#define ll long long

const ll divv = 1000000007;

int idxArr[5000000];
int arr[1000001];
ll tree[5000000];
bool isLeaf[5000000];

ll setTree(int idx, int start, int end){
    
    if(start>=end){
        tree[idx]=arr[start];
        idxArr[start]=idx;
        isLeaf[idx]=1;
        return tree[idx];
    }

    ll left=0,right=0;
    left = setTree(2*idx, start, (start + end)/2 );
    right = setTree(2*idx+1, (start+end)/2+1, end);

    tree[idx] = left * right % divv;
    return tree[idx];
}
void update(int idx, ll val){
    if(isLeaf[idx])tree[idx] = val;
    else{
        tree[idx] = tree[2*idx] *tree[2*idx+1]%divv;
    }
    if(idx!=1)
    update(idx/2,val);
}

ll query(int idx, int l, int r, int start, int end){
    //[l,r]query 구간 [start,end] 현재 노드의 범위
    if(l <= start && end <= r) {
        return tree[idx];
    } 
    
    ll left=1, right =1;
    int mid = (start+end)/2;
    if(l<=mid){
        left = query(2*idx, l, r , start, mid);
        
    }
    if(mid<r){
        right = query(2*idx+1, l, r, mid+1,end);
    }
    return left*right%divv;
}

int n,m,k;
int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    setTree(1,1,n);
    for(int i=0;i<(m+k);i++){
        
        int o,a,b;
        cin>>o>>a>>b;
        switch(o){
            case 1:
                arr[a]=b;
                update(idxArr[a],b);
                
                break;
            case 2:
                cout<<query(1,a,b,1,n)<<"\n";
                break;
        }
    }

    return 0;
}