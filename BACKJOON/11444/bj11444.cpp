#include <bits/stdc++.h>
using namespace std;

unsigned long long n;
unsigned long long M[2][2];
int dp[1 << 22 + 1][4];
void calcMat(unsigned long long mat[2][2], unsigned long long t)
{

    unsigned long long mat1[2][2];
    unsigned long long mat2[2][2];
    if (t <= 1 << 22 && dp[t][0])
    {
        mat[0][0] = dp[t][0];
        mat[0][1] = dp[t][1];
        mat[1][0] = dp[t][2];
        mat[1][1] = dp[t][3];
        return;
    }

    if (t % 2 == 0)
    {
        calcMat(mat1, t / 2);
        mat[0][0] = (mat1[0][0] * mat1[0][0] % 1'000'000'007 + mat1[0][1] * mat1[1][0] % 1'000'000'007) % 1'000'000'007;
        mat[0][1] = (mat1[0][0] * mat1[0][1] % 1'000'000'007 + mat1[0][1] * mat1[1][1] % 1'000'000'007) % 1'000'000'007;
        mat[1][0] = (mat1[1][0] * mat1[0][0] % 1'000'000'007 + mat1[1][1] * mat1[1][0] % 1'000'000'007) % 1'000'000'007;
        mat[1][1] = (mat1[1][0] * mat1[0][1] % 1'000'000'007 + mat1[1][1] * mat1[1][1] % 1'000'000'007) % 1'000'000'007;
    }
    else
    {
        calcMat(mat1, t / 2);
        calcMat(mat2, t / 2 + 1);
        mat[0][0] = (mat1[0][0] * mat2[0][0] % 1'000'000'007 + mat1[0][1] * mat2[1][0] % 1'000'000'007) % 1'000'000'007;
        mat[0][1] = (mat1[0][0] * mat2[0][1] % 1'000'000'007 + mat1[0][1] * mat2[1][1] % 1'000'000'007) % 1'000'000'007;
        mat[1][0] = (mat1[1][0] * mat2[0][0] % 1'000'000'007 + mat1[1][1] * mat2[1][0] % 1'000'000'007) % 1'000'000'007;
        mat[1][1] = (mat1[1][0] * mat2[0][1] % 1'000'000'007 + mat1[1][1] * mat2[1][1] % 1'000'000'007) % 1'000'000'007;
    }
    if (t <= 1 << 22)
    {
        dp[t][0] = mat[0][0];
        dp[t][1] = mat[0][1];
        dp[t][2] = mat[1][0];
        dp[t][3] = mat[1][1];
    }
}
int main()
{
    cin >> n;

    dp[1][0] = 1;
    dp[1][1] = 1;
    dp[1][2] = 1;
    dp[1][3] = 0;

    dp[0][0] = 1;
    dp[0][1] = 0;
    dp[0][2] = 0;
    dp[0][3] = 1;
    if (n >= 2)
        calcMat(M, n - 2);
    else if (n == 1)
    {
        M[0][0] = 1;
    }
    unsigned long long ans = 0;
    /*
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("%d ", M[i][j]);
        }
        printf("\n");
    }*/
    ans = (M[0][0] + M[0][1]) % 1'000'000'007;
    cout << ans;
    return 0;
}