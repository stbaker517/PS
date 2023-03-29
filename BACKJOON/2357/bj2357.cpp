#include<iostream>
#include<queue>

using namespace std;

typedef struct dtype {
    bool isLeaf;
    int start;
    int end;
    int mmax;
    int mmin;
}dtype;

dtype tree[1000000];
int arr[100001];

int n,m;

int setSegTree(int idx, int start, int end){
    int left,right;
    //cout<<idx<<": "<<start<<" - "<<end<<"\n";
    if (start >= end){
        tree[idx].isLeaf = 1;
        tree[idx].mmax = arr[start];
        tree[idx].mmin = arr[start];
        tree[idx].start = start;
        tree[idx].end=end;
        return idx;
    }

    left = setSegTree(2*idx, start, (start+end)/2);
    right = setSegTree(2*idx+1, (start+end)/2+1, end);

    tree[idx].mmax = max(tree[left].mmax, tree[right].mmax);
    tree[idx].mmin = min(tree[left].mmin, tree[right].mmin);
    tree[idx].start = start;
    tree[idx].end = end;

    return idx;
}

void query (int idx, int start, int end,int&_min,int&_max){
    //cout<<"["<<idx<<"]:"<<start<<"-"<<end<<"\n";
    if (start<=tree[idx].start && tree[idx].end<=end){
        _min = min(_min, tree[idx].mmin);
        _max = max(_max, tree[idx].mmax);
        return ;
    } 

    int mid = (tree[idx].start + tree[idx].end)/2;



    if (start<=mid) {
        if(end<mid)
        query(2*idx,start,end,_min,_max);
        else
        query(2*idx, start, mid, _min, _max);
    }

    if (mid < end) {
        if (start>mid){
            query(2*idx+1,start,end,_min,_max);
        }
        else 
        query(2*idx+1, mid+1, end, _min, _max);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int d;
        cin>>arr[i];
    }
    setSegTree(1,1,n);
    for(int i=0;i<m;i++){
        int mmax=0, mmin=2000000000;
        int a,b;
        cin>>a>>b;
        query(1, a, b, mmin, mmax);
        //cout<<"ans: ";
        cout<<mmin<<" "<<mmax<<"\n";
    }
    return 0;
}