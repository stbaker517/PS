#include<iostream>
#include<queue>
#include<algorithm>

#define pii pair<int,int>

using namespace std;


int n;
int m;

struct cmp {
    bool operator()(pair<int,pii> a, pair<int,pii> b){
        return a.first>b.first;
    }
};
priority_queue<pair<int,pii>, vector<pair<int,pii>>, cmp>pq;

bool visit[1000];

vector<pair<int,int>> vertex[1000];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;

    for(int i=0;i<m;i++){
        int a,b,d;
        cin>>a>>b>>d;
        a--;
        b--;
        vertex[a].push_back(make_pair(b,d));
        vertex[b].push_back(make_pair(a,d));
    }

    int cnt = 0;
    int v = 0;
    int cost =0;
    visit[0] = 1;

    while(1){
        if (++cnt >n){
            break;
        }

        for (pair<int,int> edge: vertex[v]){
            int next = edge.first;
            int val = edge.second;

            if (visit[next]) {
                continue;
            }
            pq.push(make_pair(val,make_pair(v,next)));
        }

        while(!pq.empty()){
            pair<int,pair<int,int>> top = pq.top();
            pq.pop();

            if (visit[top.second.second]){
                continue;
            }

            visit[top.second.second]=1;
            v = top.second.second;
            cost += top.first;
            break;
        }
    }

    cout<<cost;


    return 0;
}