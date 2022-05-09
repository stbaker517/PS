#include <bits/stdc++.h>

using namespace std;
#define div 1'000'000'007
#define pii pair<int, int>
#define tiii tuple<int, int, int>
int dp[500][500]; // [len][p1][p2];
int tmp[500][500];
int du[] = {-1, 0};
int dd[] = {-1, 0};

string mmap[500];
int n;
queue<tiii> Q;
void rstTmp()
{
    memset(tmp, 0, sizeof(int) * 500 * 500);
}
void copyDp(int len)
{
    for (int i = 0; i <= len; i++)
    {
        for (int j = 0; j <= len; j++)
        {
            dp[i][j] = tmp[i][j];
        }
    }
}
void print()
{

    for (int a = 0; a < n; a++)
    {
        for (int b = 0; b < n; b++)
        {
            printf("%d ", dp[a][b]);
        }
        printf("\n");
    }
}

void f()
{
    int L = n - 1;
    while (!Q.empty())
    {
        tiii P = Q.front();
        Q.pop();
        int p1 = get<0>(P);
        int p2 = get<1>(P);
        int len = get<2>(P);
        if (L != len)
        {
            L = len;
            copyDp(len + 1);
            rstTmp();
        }
        if (len == 0)
            continue;

        // cout << "1 ";
        for (int i = 0; i < 2; i++)
        {
            int P1 = p1 + du[i];
            if (P1 < 0 || P1 >= len)
                continue;
            for (int j = 0; j < 2; j++)
            {
                int P2 = p2 + du[j];
                if (P2 < 0 || P2 >= len)
                    continue;
                if (mmap[len - 1 - P1][P1] != mmap[n - 1 - P2][n - 1 - len + 1 + P2])
                    continue;

                if (!tmp[P1][P2])
                {
                    // cout << "2";
                    Q.push(make_tuple(P1, P2, len - 1));
                }
                tmp[P1][P2] = (tmp[P1][P2] + dp[p1][p2]) % div;

                // printf("[%d,%d] -> [%d,%d]  %c == %c %d\n", p1, p2, P1, P2,
                //       mmap[len - 1 - P1][P1], mmap[n - 1 - P2][n - 1 - len + 1 + P2], dp[len - 1][P1][P2]);
                // cout << dp[len - 1][P1][P2];
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> mmap[i];
    }
    for (int i = 0; i < n; i++)
    {
        Q.push(make_tuple(i, i, n - 1));
        // printf("%c %c\n", mmap[n - 1 - i][i], mmap[n - 1 - i][n - 1 - n + 1 + i]);
        dp[i][i] = 1;
    }

    f();
    // print();
    cout << dp[0][0];
    return 0;
}

/*
#include <bits/stdc++.h>

using namespace std;
#define div 1'000'000'007
#define pii pair<int, int>
#define tiii tuple<int, int, int>
int dp[500][500][500]; // [len][p1][p2];
int tmpdp[500][500];
int du[] = {-1, 0};
int dd[] = {-1, 0};

string mmap[500];
int n;
queue<tiii> Q;

void resetTmp()
{
    memset(tmpdp, 0, sizeof(int) * 500 * 500);
}
void f()
{
    while (!Q.empty())
    {
        tiii P = Q.front();
        Q.pop();
        int p1 = get<0>(P);
        int p2 = get<1>(P);
        int len = get<2>(P);
        if (len == 0)
            continue;

        for (int i = 0; i < 2; i++)
        {
            int P1 = p1 + du[i];
            if (P1 < 0 || P1 >= len)
                continue;
            for (int j = 0; j < 2; j++)
            {
                int P2 = p2 + du[i];
                if (P2 < 0 || P2 >= len)
                    continue;
                if (mmap[len - 1 - P1][P1] != mmap[n - 1 - P2][len - 1 - P2])
                    continue;
                if (!dp[len - 1][P1][P2])
                {
                    Q.push(make_tuple(P1, P2, len - 1));
                }
                dp[len - 1][P1][P2] = (dp[len - 1][P1][P2] + dp[len][p1][p2]) % div;
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> mmap[i];
    }
    for (int i = 0; i < n; i++)
    {
        Q.push(make_tuple(n - 1 - i, i, n - 1));
        dp[n - 1][n - 1 - i][i] = 1;
    }
    for (int i = 0; i < n; i++)
    {
        for (int a = 0; a < n; a++)
        {
            for (int b = 0; b < n; b++)
            {
                printf("%d ", dp[i][a][b]);
            }
            printf("\n");
        }
        printf("\n\n");
    }
    f();
    cout << dp[0][0][0];
    return 0;
}

*/