#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int arr[1001];
int dp[1000];
int remv[1000];
int cnt = 0;
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        dp[i] = 1;
    }
    for (int i = 1; i < n; i++)
    {
        if (arr[i - 1] > arr[i])
        {
            dp[i] = dp[i - 1] + 1;
        }
        else if (arr[i - 1] == arr[i])
        {
            remv[i] = 1;
        }
    }

    return 0;
}