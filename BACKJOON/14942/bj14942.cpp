#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define ll long long
vector<pair<int, ll>> V[100001];
/*vector<ll> D;
vector<int> num;*/
int n;
int vidx = 0;
ll D[100000];
int num[100000];
ll dist[100001];
ll energy[100001];
bool vvisit[100001];
int room[100001];

void dfs(int v, ll len)
{
    /*D.push_back(len);
    num.push_back(v);
    ll leftE = len - energy[v];
    int idx = lower_bound(D.begin(), D.end(), leftE) - D.begin();*/
    /*if (D[idx] > len && idx != 0)
    {
        room[v] = num[idx - 1];
    }
    else*/
    D[vidx] = len;
    num[vidx++] = v;
    ll left = len - energy[v];
    int idx = lower_bound(D, D + vidx, left) - D;
    room[v] = num[idx];
    for (pii next : V[v])
    {
        int nextV = next.first;
        ll d = next.second;
        if (vvisit[nextV])
            continue;
        vvisit[nextV] = 1;
        dfs(nextV, len + d);
    }
    /*D.pop_back();
    num.pop_back();*/
    vidx--;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> energy[i];
    }
    int a, b, c;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> a >> b >> c;
        V[a].push_back({b, c});
    }
    vvisit[1] = 1;
    dfs(1, 0);
    for (int i = 1; i <= n; i++)
    {
        cout << room[i] << "\n";
    }
    return 0;
}