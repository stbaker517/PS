#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;

#define ll long long


ll sum[1<<20];
ll minimun[1<<20];

bool vvisit[1<<20];
ll arr[1<<20];
int n;
ll val;
int lidx,ridx;
void set(int l, int r, ll v){
    if(v>=val){
        val = v;
        lidx = l;
        ridx = r;
    }
}
void func (int start, int end) {
    if(start==end){
        if(arr[start]*arr[start]>=val){
            lidx = start;
            ridx = end;
            val = arr[start]*arr[start];
        }
        return;
    }
    
    int mid = (start+end)>>1;
    func(start,mid);
    func(mid+1,end);
    ll sum = arr[mid];
    ll _min = arr[mid];
    set(mid,mid,sum*_min);
    int l = mid-1;
    int r = mid+1;
    bool Lend = false;
    bool Rend = false;
    
    memset(vvisit+start,0,sizeof(bool)*(end-start+1));
    vvisit[mid]=1;
    
    while(start<=l || r <= end){
        ll vL=-10, vR=-10;
        if(start<=l) vL = arr[l];
        else Lend = true;
        if(r<=end)vR = arr[r];
        else Rend = true;

        if(vL<vR){
            vvisit[r]=1;
            sum+=vR;
            _min = min(vR,_min);
            if(Lend)
            set(start,r,sum*_min);
            else set(l+1,r,sum*_min);
            r++;
        } else {
            vvisit[l]=1;
            sum+=vL;
            _min = min(vL,_min);
            if(Rend)set(l,end,sum*_min);
            else
            set(l,r-1,sum*_min);
            l--;
        }
    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a,b;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    func(1,n);
    printf("%lld\n%d %d",val,lidx,ridx);
    return 0;
}