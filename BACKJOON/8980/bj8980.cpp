#include <bits/stdc++.h>
using namespace std;

#define tiii tuple<int, int, int>
bool cmp(tiii &a, tiii &b)
{
    if (get<0>(a) < get<0>(b))
    {
        return true;
    }
    else if (get<0>(a) == get<0>(b))
    {
        if (get<1>(a) <= get<1>(b))
            return true;
    }
    return false;
}
int N, C; // N:마을수 C:용량
int M;
int truck[2001];
int town[2001];
int can[2001];
int deliver;
tuple<int, int, int> info[10001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    cin >> C;
    cin >> M;
    // cout << N << C << M << "\n";
    int a, b, c;
    for (int i = 0; i < M; i++)
    {
        // cout << "i:" << i << "\n";
        cin >> a >> b >> c;
        can[b] += c;
        info[i] = make_tuple(a, b, c);
    }
    sort(info, info + M, cmp);
    int idx = 0;
    for (int t = 1; t <= N; t++)
    {
        if (truck[t])
        {
            deliver += truck[t];
            truck[0] -= truck[t];
            truck[t] = 0;
        }
        while (idx < M && get<0>(info[idx]) == t)
        {
            can[get<1>(info[idx])] -= get<2>(info[idx]);
            int canShip = C - truck[0];
            for (int i = t + 1; i < get<1>(info[idx]); i++)
            {
                canShip -= can[i];
            }
            if (canShip > 0)
            {
                if (get<2>(info[idx]) <= canShip)
                {
                    truck[get<1>(info[idx])] += get<2>(info[idx]);
                    truck[0] += get<2>(info[idx]);
                }
                else
                {
                    truck[get<1>(info[idx])] += canShip;
                    truck[0] += canShip;
                }
            }
            idx++;
        }
    }
    cout << deliver;
    return 0;
}