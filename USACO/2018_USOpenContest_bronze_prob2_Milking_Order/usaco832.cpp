// https://usaco.org/index.php?page=viewproblem2&cpid=832
#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

int n, m, k;

int in_hierarchy[101];
int order[101];
int cow_pos[101];
int pos_cow[101];

vector<pair<int,pair<int,int>>> connections; // (c,hierarchy_idx,pos_idx)
bool cmp(pair<int,int>& a, pair<int,int>&b) {
    return a.second<b.second;
};

void in(vector<int>& hierarchy) {
    int cur_pos = 1;
    for(int hidx = 0; hidx<hierarchy.size();){
        int c = hierarchy[hidx];
        if(cow_pos[c]){
            cur_pos = cow_pos[c] + 1;
            hidx++;
            continue;
        }
        if(pos_cow[cur_pos]) {
            cur_pos++;
            continue;
        }

        cow_pos[c] = cur_pos;
        pos_cow[cur_pos] = c;

        hidx++;
    }
}

void out(vector<int>& hierarchy) {
    int cur_pos = n;
    for(int hidx = hierarchy.size()-1; hidx>=0;){
        int c = hierarchy[hidx];
        if(cow_pos[c]){
            cur_pos = cow_pos[c] - 1;
            hidx--;
            continue;
        }
        if(pos_cow[cur_pos]) {
            cur_pos--;
            continue;
        }

        cow_pos[c] = cur_pos;
        pos_cow[cur_pos] = c;

        hidx--;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("milkorder.in", "r", stdin);
	// freopen("milkorder.out", "w", stdout);
    
    cin>>n>>m>>k;
    bool flag = false;

    vector<int> hierarchy(m);
    for(int i =0;i<m;i++) {
        cin>>hierarchy[i];
        in_hierarchy[hierarchy[i]]= i;
        if(hierarchy[i]==1){
            flag =true;
        }
    }

    vector<pair<int,int>> position(k);
    for(pair<int,int>&p : position) {
        cin>>p.first>>p.second;
        cow_pos[p.first] = p.second;
        pos_cow[p.second] = p.first;
        if(p.first == 1){
            cout<<p.second;
            return 0;
        }
    }

    sort(position.begin(), position.end(), cmp);
    
    if(flag) {
        in(hierarchy);
    } else {
        out(hierarchy);
    }
    int idx = 0;
    for(int i =1;i<=n;i++){
        if(pos_cow[i] == 1){
            idx = i;
            break;
        }

        if(!idx&&!pos_cow[i]){
            idx = i;
        }
    }
    // cout<<"\n";
    cout<<idx;
    return 0;
}