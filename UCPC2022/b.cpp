#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll, ll>
ll ccw(pii x, pii y, pii a);
int isCross(pii x, pii y, pii a, pii b);
int Cross[2500][2500];
void printC(int n);
vector<pair<pii, pii>> V;
ll W[2500];
int numCrossed[2500];

int main()
{
    ll sx, sy, ex, ey, w;
    int n;
    cin >> n;
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> sx >> sy >> ex >> ey >> w;
        W[i] = w;
        V.push_back({{sx, sy}, {ex, ey}});
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (W[i] < W[j])
            {
                swap(W[i], W[j]);
                swap(V[i], V[j]);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            Cross[i][j] = isCross(V[i].first, V[i].second, V[j].first, V[j].second);
            // numCrossed[i]+=Cross[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        ans += W[i] * (numCrossed[i] + 1);
        for (int j = 0; j < n; j++)
        {
            if (Cross[i][j])
            {
                numCrossed[j]++;
            }
        }
    }
    // printC(n);
    cout << ans;
    return 0;
}

ll ccw(pii x, pii y, pii a)
{
    ll x1, x2, x3, y1, y2, y3;
    x1 = x.first;
    x2 = y.first;
    x3 = a.first;
    y1 = x.second;
    y2 = y.second;
    y3 = a.second;

    ll tmp = x1 * y2 + x2 * y3 + x3 * y1;
    tmp -= (y1 * x2 + y2 * x3 + y3 * x1);
    if (tmp > 0)
        return 1;
    else if (tmp == 0)
        return 0;
    else
        return -1;
}
int isCross(pii x, pii y, pii a, pii b)
{
    if (ccw(x, y, a) * ccw(x, y, b) < 0 && ccw(a, b, x) * ccw(a, b, y) < 0)
        return 1;
    else
        return 0;
}
void printC(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", Cross[i][j]);
        }
        printf("\n");
    }
}