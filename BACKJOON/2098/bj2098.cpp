#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
// #include <bitset>

#define ll long long

using namespace std;

int n;

vector<pair<ll,int>> g[16];
ll dp[0xffff][0xf];
bool visit[0xffff][0xf];
ll arr[16][16];
ll to_head[16];

queue<pair<unsigned int, int>> q; // visited bit & last node

ll score = 0x7ffffffffff;

bool cmp(pair<ll,int> a, pair<ll,int>b){
    return a.first<b.first;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    ll d;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    for(int i=0;i<0xffff;i++){
        for(int j=0;j<16;j++){
            dp[i][j]=-1;
        }
    }
    for(int i=1;i<n;i++){
        if(!arr[0][i]){
            continue;
        }
        int t = 1<<i;
        dp[t][i]=arr[0][i];
        q.push(make_pair(t,i));
    }

    while(!q.empty()){
        pair<unsigned int, int> front = q.front();
        q.pop();
        if( visit[front.first][front.second]){
            continue;
        }
        visit[front.first][front.second]=1;
        // cout<<bitset<4>(front.first)<<"\n";
        for(int i=1;i<n;i++) {
            if(!arr[front.second][i]){
                continue;
            }
            unsigned int b = 1<<i;
            if(front.first&b){
                continue;
            }
            unsigned int t = front.first|b;
            if(dp[t][i]==-1){
                dp[t][i] = dp[front.first][front.second] + arr[front.second][i];
            } else {
                dp[t][i] = min(dp[front.first][front.second]+ arr[front.second][i], dp[t][i]);
            }
            q.push(make_pair(t,i));
        }
    }

    unsigned int b = 0;
    for(int i=1;i<n;i++){
        b = b | (1<<i);
    }
    // cout<<"B:"<<bitset<4>(b)<<"\n";
    for(int i=1;i<n;i++){
        if(!arr[i][0] || dp[b][i]==-1){
            continue;
        }
        score = min(score,dp[b][i]+arr[i][0]);
    }


    
    cout<<score;
}