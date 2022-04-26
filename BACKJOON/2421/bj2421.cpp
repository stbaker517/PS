#include <iostream>
#include <algorithm>

using namespace std;

bool non_prime[1000000];

int dp[1000][1000];
int getDigit(int a)
{
    int cnt = 0;
    while (a)
    {
        cnt++;
        a /= 10;
    }
    return cnt;
}
bool isCombPrime(int a, int b)
{
    int dit = getDigit(b);
    for (int i = 0; i < dit; i++)
        a *= 10;
    int comb = a + b;

    if (non_prime[comb])
        return false;
    return true;
}

int f(int a, int b)
{
    if (a == 0 || b == 0)
        return 0;
    if (a == 1 && b == 1)
        return 0;

    if (dp[a][b])
        return dp[a][b];

    if (isCombPrime(a, b))
        dp[a][b] = 1 + max(f(a - 1, b), f(a, b - 1));
    else
        dp[a][b] = max(f(a - 1, b), f(a, b - 1));
    return dp[a][b];
}
int main()
{
    non_prime[1] = 1;
    for (int i = 2; i < 1000; i++)
    {
        if (i * i >= 1000000)
            break;
        if (non_prime[i])
            continue;

        for (int j = 2; i * j < 1000000; j++)
            non_prime[i * j] = 1;
    }

    int n;
    cin >> n;
    f(n, n);
    cout << dp[n][n];
    return 0;
}