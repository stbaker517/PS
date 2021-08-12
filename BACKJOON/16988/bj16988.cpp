#include <iostream>
#include <queue>
#include<vector>
using namespace std;

int map[20][20];
bool visit[20][20];

int r, c;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int Count = 0;

void refresh()
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            visit[i][j] = false;
        }
    }
}
void print()
{
    
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << map[i][j] << " ";
        }
        cout << "\n";
    }
    
}

int fcount(int a, int b)
{
    //refresh();
    if(visit[a][b])return 0;
    visit[a][b] = true;

    queue<pair<int, int>> Q;
    Q.push({a, b});
    int cnt = 0;
    while (!Q.empty())
    {
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();
        cnt++;
        for (int i = 0; i < 4; i++)
        {
            int X = x + dx[i];
            int Y = y + dy[i];

            if (X < 0 || Y < 0 || X >= r || Y >= c)
                continue;
            if (map[X][Y] == 0)
                return 0;
            else if (map[X][Y] == 1)
                continue;
            if (visit[X][Y])
                continue;
            visit[X][Y] = true;
            Q.push({X, Y});
        }
    }
    return cnt;
}
void BFS(int px1,int py1,int px2,int py2)
{

    map[px1][py1] = 1;
    map[px2][py2] = 1;

//print();
//cout<<"\n";

    refresh();
    queue<pair<int, int>> T;
    for (int i = 0; i < 4; i++)
    {
        int Px1 = px1 + dx[i];
        int Py1 = py1 + dy[i];
        int Px2 = px2 + dx[i];
        int Py2 = py2 + dy[i];
        if (Px1 >= 0 && Px1 < r && Py1 >= 0 && Py1 < c && map[px1 + dx[i]][py1 + dy[i]] == 2)
        {
            T.push({px1 + dx[i], py1 + dy[i]});
        }

        if (Px2 >= 0 && Px2 < r && Py2 >= 0 && Py2 < c && map[px2 + dx[i]][py2 + dy[i]] == 2)
        {
            T.push({px2 + dx[i], py2 + dy[i]});
        }
    }
    int tmpC = 0;
    while (!T.empty())
    {
        //cout << "(" << T.front().first << ", " << T.front().second << ")\n";
        //print();
        tmpC += fcount(T.front().first, T.front().second);
        
        
        T.pop();
    }
    //cout<<"Count: "<<tmpC<<"\n";
    if (tmpC > Count)
        Count = tmpC;
    map[px1][py1] = 0;
    map[px2][py2] = 0;
}

int main()
{

    cin >> r >> c;
    vector<pair<int,int>>vec;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> map[i][j];
            if(map[i][j]==0)
                vec.push_back({i,j});
        }
    }

    queue<pair<int, int>> tmp;
 

    for(int i=0;i<vec.size()-1;i++)
    {
        for(int j=i+1;j<vec.size();j++){
            int x1=vec[i].first;
            int y1=vec[i].second;
            int x2=vec[j].first;
            int y2=vec[j].second;
           

                    
            BFS(x1,y1,x2,y2);


        }
    }  

                   
            

    cout << Count;

    return 0;
}