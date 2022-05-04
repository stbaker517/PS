#include<iostream>
#include<queue>
#include<tuple>
#include<vector>
#include<algorithm>
using namespace std;

//https://www.geeksforgeeks.org/binary-search-sorted-vector-pairs/
#define tiii tuple<int,int,int>
#define pii pair<int,int>
int getDist(int v1,int v2);
struct cmp{
    bool operator()(tiii&a,tiii& b){
        if(get<2>(a)>get<2>(b))return true;
        return false;
    }
};
bool compare(pii&a,pii&b){
    return a.first<=b.second;
}
struct cmp1{
bool operator()(pii&a,pii&b){
    return getDist(a.first,a.second)>getDist(b.first,b.second);
}};
//#define MAX_NODE 100001;
vector<tiii>V;
priority_queue<tiii,vector<tiii>,cmp>PQ;
priority_queue<pii,vector<pii>,cmp1>PQv;
bool inSet[100001];
vector<pii>X;
vector<pii>Y;
vector<pii>Z;
vector<pii>_X;
vector<pii>_Y;
vector<pii>_Z;
int n;



void d(){
    inSet[0]=1;
    //두개씩 pq에 저장.
    tiii cur=V[0];
    int curx=get<0>(V[0]);
    int cury=get<1>(V[0]);
    int curz=get<2>(V[0]);

    for(int i=0;i<n-1;i++){
        int cx1=lower_bound()
    }
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        int x,y,z;
        cin>>x>>y>>z;
        V.push_back(make_tuple(x,y,z));
        X.push_back({x,i});
        _X.push_back({-x,i});
        Y.push_back({y,i});
        _Y.push_back({-y,i});
        Z.push_back({z,i});
        _Z.push_back({-z,i});
    }
    sort(X.begin(),X.end());
    sort(_X.begin(),_X.end());
    sort(Y.begin(),Y.end());
    sort(_Y.begin(),_Y.end());
    sort(Z.begin(),Z.end());
    sort(_Z.begin(),_Z.end());

    return 0;
}
int getDist(int v1,int v2){
    return min({abs(get<0>(V[v1])-get<0>(V[v2])),abs(get<1>(V[v1])-get<1>(V[v2])),abs(get<2>(V[v1])-get<2>(V[v2]))});
}