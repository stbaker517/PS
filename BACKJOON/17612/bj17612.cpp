#include<iostream>
#include<queue>
#include<vector>
using namespace std;

#define pii pair<int,int>
#define pipii pair<int,pii>//(#info,(outtime,#counter))
#define ll long long
vector<pii>info;
vector<int>endOrder;
int endtime[100'000];
struct cmp_out{
    bool operator()(pipii&a,pipii&b){
        if(a.second.first>b.second.first)return true;//나가는 시간.
        else if(a.second.first==b.second.first){
            if(a.second.second<b.second.second)return true;//카운터 번호
        }
        return false;
    }
};
struct cmp_time{
    bool operator()(pii&a,pii&b){
        if(a.second>b.second)return true;
        else if(a.second==b.second){
            if(a.first>b.first)return true;
        }
        return false;
    }
};
priority_queue<pipii,vector<pipii>,cmp_out>outPQ;//제일 빨리 나가는 회원.
priority_queue<pii,vector<pii>,cmp_time>endPQ;//제일 계산이 빨리 끝나는 카운터.
int n,k;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k;
    for(int i=0;i<k;i++){
        endPQ.push({i,0});
    }
    for(int i=0;i<n;i++){
        int id,w;
        cin>>id>>w;
        int toGo=endPQ.top().first;
        int t=endPQ.top().second;
        endPQ.pop();
        endPQ.push({toGo,t+w});

        outPQ.push({id,{t+w,toGo}});
    }
    ll ans=0;
    for(int i=1;i<=n;i++){
        ll id=outPQ.top().first;
        outPQ.pop();
        ans+=i*id;
    }
    cout<<ans;

    return 0;
}