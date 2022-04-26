#include <bits/stdc++.h>

using namespace std;

int arr[1000000];
int sorted[1000000];
int removed[1000000];
int n, N = 0;
int Bsearch(int target)
{
    int st = 0;
    int en = N - 1;
    int ret = 0;
    while (st <= en)
    {
        int mid = (st + en) / 2;
        if (removed[mid] < target)
        {
            st = mid + 1;
        }
        else if (removed[mid] > target)
        {
            en = mid - 1;
        }
        else
            return mid;
    }
    return 0;
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sorted[i] = arr[i];
    }
    sort(sorted, sorted + n);
    removed[0] = sorted[0];
    N = 1;
    for (int i = 1; i < n; i++)
    {
        if (sorted[i - 1] != sorted[i])
            removed[N++] = sorted[i];
    }

    for (int i = 0; i < n; i++)
    {
        cout << Bsearch(arr[i]) << " ";
    }

    return 0;
}