#include <bits/stdc++.h>
using namespace std;

long long arr[500000];
int n;
int f(int a, int s, int e)
{
    long long mid = (s + e) / 2;
    if (s <= e)
    {
        if (arr[mid] == a)
        {
            return mid;
        }
        else if (arr[mid] < a)
        {
            return f(a, mid + 1, e);
        }
        else
            return f(a, s, mid - 1);
    }

    return -1;
}
int findNum(int a)
{
    int ret = f(a, 0, n - 1);
    cout << ret << ";;\n";
    if (ret == -1)
        return 0;
    int r = a, l = a;
    int cnt = 0;
    while (1)
    {
        if (++r < n && arr[r] != a)
            break;
        cnt++;
    }
    while (1)
    {
        if (--l >= 0 && arr[l] != a)
            break;
        cnt++;
    }
    return cnt + 1;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    int m;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    int k;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> k;
        cout << findNum(k) << "\n";
    }

    return 0;
}