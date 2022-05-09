#include <iostream>
#include <queue>
#include <string>
using namespace std;
#define pii pair<int, int>
#define pipii pair<int, pair<int, int>>
queue<pii> Qice;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
string mmap[1500];
int ice[1500][1500];
bool vvisit[1500][1500];
int R, C;
int swanX, swanY;
struct cmp
{
    bool operator()(pipii &a, pipii &b)
    {
        if (a.first > b.first)
            return true;
        return false;
    }
};

bool isIceEdge(int x, int y)
{

    if (mmap[x][y] != 'X')
        return false;
    for (int i = 0; i < 4; i++)
    {
        int X = x + dx[i];
        int Y = y + dy[i];
        if (X < 0 || Y < 0 || X >= R || Y >= C)
            continue;
        // printf("[%d,%d %c] %d %c\n", x, y, mmap[x][y], i, mmap[X][Y]);
        if (mmap[X][Y] != 'X')
        {
            // printf("%d %d\n", x, y);
            return true;
        }
    }
    return false;
}

void icef()
{
    while (!Qice.empty())
    {
        pii top = Qice.front();
        int x = top.first;
        int y = top.second;
        Qice.pop();
        for (int i = 0; i < 4; i++)
        {
            int X = x + dx[i];
            int Y = y + dy[i];
            if (X < 0 || Y < 0 || X >= R || Y >= C)
                continue;
            if (mmap[X][Y] != 'X')
                continue;
            if (ice[X][Y])
                continue;
            Qice.push({X, Y});
            ice[X][Y] = ice[x][y] + 1;
        }
    }
}

void bfs(int &day)
{
    priority_queue<pipii, vector<pipii>, cmp> Q;
    // vvisit[swanX][swanY]=1;
    Q.push({0, {swanX, swanY}});
    while (!Q.empty())
    {
        pipii _top = Q.top();
        int x = _top.second.first;
        int y = _top.second.second;
        Q.pop();
        if (vvisit[x][y])
            continue;
        vvisit[x][y] = 1;
        if (mmap[x][y] == 'L')
            day = _top.first;
        for (int i = 0; i < 4; i++)
        {
            int X = x + dx[i];
            int Y = y + dy[i];
            if (X < 0 || Y < 0 || X >= R || Y >= C)
                continue;
            if (vvisit[X][Y])
                continue;
            Q.push({max(_top.first, ice[X][Y]), {X, Y}});
        }
    }
}
void printIce()
{
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cout << ice[i][j];
        }
        cout << "\n";
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> R >> C;
    for (int i = 0; i < R; i++)
    {
        cin >> mmap[i];
    }
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (isIceEdge(i, j))
            {
                ice[i][j] = 1;
                Qice.push({i, j});
            }
            if (mmap[i][j] == 'L')
            {
                swanX = i;
                swanY = j;
            }
        }
    }
    // printIce();
    icef();
    int day = 0;
    bfs(day);
    cout << day;

    return 0;
}
