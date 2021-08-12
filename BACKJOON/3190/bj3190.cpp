#include <iostream>
#include <queue>
#include <vector>
#include <deque>
using namespace std;

typedef struct HT
{
    queue<pair<int, char>> mov;
    int x;
    int y;
    int cnt;
    int dir;
} HT;

int n, k;
int cnt = 0;
int map[100][100];
int apple[100][100];
HT ht[2];

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void print()
{
    cout << "map\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << map[i][j];
        }
        cout << "\n";
    }
    cout << "\n";
}
void move(int idx)//0 head 1 tail
{
    ht[idx].cnt++;

    if (idx) //꼬리
    {
        map[ht[idx].x][ht[idx].y] = 0;
        ht[idx].x += dx[ht[idx].dir];  //(1,0)->(2,0)
        ht[idx].y += dy[ht[idx].dir];
    }
    else//머리
    {
        ht[idx].x += dx[ht[idx].dir];
        ht[idx].y += dy[ht[idx].dir];
        map[ht[idx].x][ht[idx].y] = 2;//뱀
    }

    if (!ht[idx].mov.empty() && ht[idx].mov.front().first == ht[idx].cnt)
    {
        //cout<<ht[0].cnt<<" here";
        if (ht[idx].mov.front().second == 'D')
        {
            //cout<<"D\n";
            ht[idx].dir = (ht[idx].dir + 1) % 4;
        }
        else
        {
            //cout<<"L\n";
            ht[idx].dir = (ht[idx].dir + 3) % 4;
        }

        ht[idx].mov.pop();
    }
}
void func()
{
    ht[0].cnt = 0;
    ht[0].dir = 0;
    ht[1].cnt = 0;
    ht[1].dir = 0;

    while (1)
    {
        int hx = ht[0].x;
        int hy = ht[0].y;
        int tx = ht[1].x;
        int ty = ht[1].y;

        if (hx + dx[ht[0].dir] < 0 || hy + dy[ht[0].dir] < 0 || hx + dx[ht[0].dir] >= n || hy + dy[ht[0].dir] >= n)
        {
            ht[0].cnt++;
            break;
        }
        /*if (map[hx + dx[ht[0].dir]][hy + dy[ht[0].dir]] == 2)
            {
                //ht[0].cnt++;
                break;}*/
        if (map[hx + dx[ht[0].dir]][hy + dy[ht[0].dir]] == 2)
        {
            ht[0].cnt++;
            break;
        }

        move(0);//HT ht[0] ->head ht[1]->tail
        hx = ht[0].x;
        hy = ht[0].y;
        tx = ht[1].x;
        ty = ht[1].y;

        if (apple[hx][hy] == 0)
        {
            move(1);
        }
        // print();
    }

    cout << ht[0].cnt;
}

int main()
{
    cin >> n >> k;
    int x, y;
    map[0][0] = 2;
    for (int i = 0; i < k; i++)
    {
        cin >> x >> y;
        map[x - 1][y - 1] = 1;
        apple[x - 1][y - 1] = 1;
    }
    cin >> x;
    char c;
    for (int i = 0; i < x; i++)
    {
        cin >> y >> c;
        for (int j = 0; j < 2; j++)
        {
            ht[j].mov.push({y, c});
        }
    }

    func();
    return 0;
}