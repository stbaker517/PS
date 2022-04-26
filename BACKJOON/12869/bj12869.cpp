#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int dp[61][61][61];
vector<int> _plus = {1, 3, 9};
int A, B, C;
int f(int q, int w, int e)
{
    int a = q, b = w, c = e;
    int cnt = 0;
    if (a < 0)
    {
        a = 0;
        cnt++;
    }
    if (b < 0)
    {
        b = 0;
        cnt++;
    }
    if (c < 0)
    {
        c = 0;
        cnt++;
    }

    if (a == 0 && b == 0 && c == 0)
        return 0;

    if (dp[a][b][c])
        return dp[a][b][c];
    int m = 99999;

    if (cnt == 1)
    {
        if (a == 0)
        {
            m = min(m, min(f(a, b - 9, c - 3), f(a, b - 3, c - 9)));
        }
        else if (b == 0)
        {
            m = min(m, min(f(a - 9, b, c - 3), f(a - 3, b, c - 9)));
        }
        else
        {
            m = min(m, min(f(a - 3, b - 9, c), f(a - 9, b - 3, c)));
        }
        dp[a][b][c] = m + 1;
        return m + 1;
    }
    else if (cnt == 2)
    {
        if (a != 0)
        {
            m = f(a - 9, b, c);
        }
        else if (b != 0)
        {
            m = f(a, b - 9, c);
        }
        else
        {
            m = f(a, b, c - 9);
        }
        dp[a][b][c] = m + 1;
        return m + 1;
    }

    do
    {
        m = min(m, f(a - _plus[0], b - _plus[1], c - _plus[2]));

    } while (next_permutation(_plus.begin(), _plus.end()));
    dp[a][b][c] = m + 1;
    return m + 1;
}
int main()
{
    int n;
    int arr[] = {0, 0, 0};

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << f(arr[0], arr[1], arr[2]);

    return 0;
}