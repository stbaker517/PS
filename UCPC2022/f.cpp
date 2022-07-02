#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
char mv[] = {'U', 'R', 'D', 'L'};
string mmap[50];
int pick[50][50];
string answer;
int n, m, s;
int alphabet[26];
int cnt = 0;

int vvisit[50][50];
int need[26];
int curX, curY;

vector<pii> R;
vector<pii> P;
void findChar(char target, int x, int y, string &route, int &flag);
void f(int C, string &route);
string getRoute()
{
    int x = 0;
    int y = 0;
    string ans = "";
    for (auto p : P)
    {
        int px = p.first;
        int py = p.second;
        if (x != px)
        {
            int mvv = px - x;
            char target;
            if (mvv > 0)
            {
                target = 'D';
            }
            else
                target = 'U';
            for (int i = 0; i < abs(mvv); i++)
                ans += target;
        }
        if (y != py)
        {
            int mvv = py - y;
            char target;
            if (mvv > 0)
            {
                target = 'R';
            }
            else
                target = 'L';
            for (int i = 0; i < abs(mvv); i++)
                ans += target;
        }
        ans += 'P';
        x = px;
        y = py;
    }
    while (x != n - 1)
    {
        x++;
        ans += 'D';
    }
    while (y != m - 1)
    {
        y++;
        ans += 'R';
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin.tie(0);
    cin >> n >> m >> s;
    for (int i = 0; i < n; i++)
    {
        cin >> mmap[i];
        for (int j = 0; j < m; j++)
        {
            alphabet[mmap[i][j] - 'a']++;
        }
    }
    int C = 9999999;

    cin >> answer;
    for (int i = 0; i < s; i++)
    {
        need[answer[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++)
    {
        if (need[i])
        {
            C = min(C, alphabet[i] / need[i]);
        }
    }
    string route = "";
    f(C, route);
    route = getRoute();
    cout << C << " " << route.length() << "\n"
         << route;
    // cout << "\n";
    /*
    for (auto i : R)
    {
        cout << "(" << i.first << "," << i.second << ") ";
    }
    cout << "---\n\n";
    for (auto i : P)
    {
        cout << "(" << i.first << "," << i.second << ") ";
    }

    cout << "\n\n\n"
         << ;*/
}
void f(int C, string &route)
{
    // cout << n << m << s;
    for (int c = 0; c < C; c++)
    {

        for (int i = 0; i < s; i++)
        {
            R.push_back({-(c * s + i), -(c * s + i)});
            int flag = 0;
            memset(vvisit, 0, sizeof(int) * 50 * 50);
            R.push_back({curX, curY});
            vvisit[curX][curY] = 1;
            char target = answer[i];
            findChar(target, curX, curY, route, flag);
        }
    }
    // route += "||";
    while (curX < n - 1)
    {
        route += "D";
        curX++;
    }
    while (curY < m - 1)
    {
        route += "R";
        curY++;
    }
    return;
}
void findChar(char target, int x, int y, string &route, int &flag)
{
    // cout << target;
    if (flag)
        return;

    // route += mmap[x][y];
    if (target == mmap[x][y] && !pick[x][y])
    {
        route += "P";
        P.push_back({x, y});
        R.push_back({7, 7});
        pick[x][y] = 1;
        flag = 1;
        curX = x;
        curY = y;
        /*
        cout << "---\n";
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << pick[i][j];
            }
            cout << "\n";
        }*/
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        if (flag)
            return;
        int X = x + dx[i];
        int Y = y + dy[i];
        if (X < 0 || Y < 0 || X >= n || Y >= m)
            continue;
        if (vvisit[X][Y])
            continue;
        R.push_back({X, Y});
        vvisit[X][Y] = 1;
        route += mv[i];
        findChar(target, X, Y, route, flag);
    }
    R.pop_back();
    route.pop_back();
}