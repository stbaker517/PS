#include <bits/stdc++.h>
using namespace std;

int arr[500001];
int n, m;
int findL(int a, int s, int e)
{
    int mid = (s + e) / 2;
    while (s < e)
    {
        int mid = (s + e) / 2;
        if (arr[mid] >= target)
            e = mid;
    }
}
int findR(int a, int s, int e)
{
    int mid = (s + e) / 2;
    if (s == e)
        return s;
    if (s <= e)
    {
        if (arr[mid] <= a)
        {
            return findR(a, mid, e);
        }
        else
            return findR(a, s, mid - 1);
    }
    return 0;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 0; i <= 500000; i++)
        arr[i] = 0x7fffffff;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
    cin >> m;
    int k;
    for (int i = 0; i < m; i++)
    {
        cin >> k;
        cout << findR(k, 0, n) - findL(k, 0, n) << "\n";
    }
}