#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
#define ll long long
#define piii pair<pair<int, int>, int> // id,line,환승횟수.
vector<pair<int, int>> V[100001];      // id , line

int n;
int l;

ll transfer[100001];
struct cmp
{
    bool operator()(piii &a, piii &b)
    {
        if (a.second > b.second)
            return true;
        return false;
    }
};

void D(int s, int e)
{
    priority_queue<piii, vector<piii>, cmp> PQ;
    memset(transfer, -1, sizeof(ll) * 100001);
    transfer[s] = 0;
    if (s == e)
        return;
    // cout << "hello";
    for (pair<int, int> next : V[s])
    {
        int nextV = next.first;
        int nextL = next.second;
        PQ.push({next, 0});
        // cout << nextV;
    }

    while (!PQ.empty())
    {
        piii top = PQ.top();
        PQ.pop();
        int curV = top.first.first;
        int curL = top.first.second;
        int curT = top.second;
        // cout << curV << ", " << curT << "\n";
        if (transfer[curV] > -1)
            continue;
        transfer[curV] = curT;
        for (pair<int, int> next : V[curV])
        {
            int nextV = next.first;
            int nextL = next.second;

            int nextT = curL == nextL ? curT : curT + 1;
            PQ.push({next, nextT});
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> l;

    for (int line = 1; line <= l; line++)
    {
        int input;
        int prev = -1;
        while (1)
        {

            cin >> input;
            if (input == -1)
                break;

            if (prev != -1)
            {
                V[prev].push_back({input, line});
                V[input].push_back({prev, line});
                // printf("%d <-> %d\n", prev, input);
            }
            // printf("{%d,%d}\n", prev, input);
            prev = input;
        }
    }
    int s, e;
    cin >> s >> e;
    D(s, e);
    cout << transfer[e];

    return 0;
}