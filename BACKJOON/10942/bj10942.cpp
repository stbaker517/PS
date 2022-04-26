#include <iostream>

using namespace std;
int n;
int arr[2000];
int pd[2000][2000];

void isPal(int s, int e)
{
    if (s < 0 || e >= n)
        return;
    if (s > e)
        return;
    if (pd[s][e])
        return;
    if (e - s <= 0)
        return;
    if (e - s == 1)
    {
        if (arr[s] == arr[e])
        {
            pd[s][e] = 1;
        }
        else
            pd[s][e] = -1;
        return;
    }
    if (pd[s + 1][e - 1] == 0)
        isPal(s + 1, e - 1);

    if (pd[s + 1][e - 1] == -1 || arr[s] != arr[e])
    {
        pd[s][e] = -1;
        return;
    }

    pd[s][e] = 1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        pd[i][i] = 1;
    }
    int s, e, m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> s >> e;
        isPal(s - 1, e - 1);
        if (pd[s - 1][e - 1] == 1)
            cout << 1 << '\n';
        else
            cout << 0 << '\n';
    }

    return 0;
}