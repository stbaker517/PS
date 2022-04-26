#include <bits/stdc++.h>
using namespace std;

vector<int> arr;
int S[1000000];
int n, ns = 0;

int Bsearch(int target)
{
    int st = 0;
    int en = ns - 1;
    while (st <= en)
    {
        int mid = (st + en + 1) / 2;
        if (S[mid] > target)
        {
            en = mid - 1;
        }
        else if (S[mid] < target)
        {
            st = mid + 1;
        }
        else
            return mid;
    }
    return -1;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    // 1e8
    cin >> n;
    int tmp;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        arr.push_back(tmp);
    }
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            S[ns++] = arr[i] + arr[j];
        }
    }
    sort(S, S + ns);

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            int left = arr[i] - arr[j];
            if (Bsearch(left) != -1)
            {
                cout << arr[i];
                return 0;
            }
        }
    }

    return 0;
}