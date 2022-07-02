#include <iostream>

using namespace std;

int n;
int mmap[2][51];
int dp[2][50][2]; // 1흑 0 백
int main()
{
    cin >> n;
    string str;
    for (int i = 0; i < 2; i++)
    {
        cin >> str;
        for (int j = 0; j < n; j++)
        {
            if (str[i] == '.')
                mmap[i][j] = 0;
            else
                mmap[i][j] = 1;
        }
    }

    return 0;
}