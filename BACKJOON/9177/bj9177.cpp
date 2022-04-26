#include <iostream>
#include <string>
#include <cstring>
using namespace std;
/*1
abcdef
qwert
abqwcdertef
Data set 1: no*/
int dp[205][205];
string a;
string b;
string c;
bool f(int i, int j)
{
    if (i < 0 || j < 0)
        return false;
    if (dp[i][j] == 1)
        return true;
    else if (dp[i][j] == -1)
        return false;

    //0일 때
    if (f(i - 1, j))
    {
        if (c[i + j - 1] == a[i - 1])
        {
            dp[i][j] = 1;
            return true;
        }
    }
    if (f(i, j - 1))
    {
        if (c[i + j - 1] == b[j - 1])
        {
            dp[i][j] = 1;
            return true;
        }
    }
    dp[i][j] = -1;
    return false;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        memset(dp, 0, sizeof(int) * 205 * 205);

        cin >> a >> b >> c;

        if (a[0] == c[0])
            dp[1][0] = 1;
        else
            dp[1][0] = -1;

        if (b[0] == c[0])
            dp[0][1] = 1;
        else
            dp[0][1] = -1;

        //cout << a.length() << b.length();
        f(a.length(), b.length());
        if (dp[a.length()][b.length()] == 1)
            cout << "Data set " << i + 1 << ": yes\n";
        else
            cout << "Data set " << i + 1 << ": no\n";
    }

    return 0;
}