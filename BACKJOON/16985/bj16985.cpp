#include <iostream>
#include <queue>
#include<tuple>
using namespace std;

int map[5][5][5];
int route[5][5][5];
bool visit[5][5][5];
int minDist = 0x7fffffff;

int dx[]={0,0,0,0,1,-1};
int dy[]={0,0,1,-1,0,0};
int dz[]={1,-1,0,0,0,0};

queue<tuple<int,int,int>>Q;
void rotate(int h)
{
    

    int tmp[5][5];
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            tmp[4 - j][i] = map[h][i][j];
        }
    }
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            map[h][i][j] = tmp[i][j];
        }
    }
}

void refresh()
{
    for (int h = 0; h < 5; h++)
    {
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                route[h][i][j] = 0;
                visit[h][i][j] = false;
            }
        }
    }
}

void BFS(){
    for(int sd=0;sd<4;sd++)
    {
        refresh();
        int sx,sy;
        if(sd==0)
        {
            sx=sy=0;
        }
        else if(sd==1)
        {
            sx=4;sy=0;
        }
        else if(sd==2)
        {
            sx=4;sy=4;
        }
        else
        {
            sx=0;sy=4;
        }

        if(map[0][sx][sy]==0)continue;
        if(map[4][4-sx][4-sy]==0)continue;

        Q.push(make_tuple(0,sx,sy));
        visit[0][sx][sy]=true;

        while(!Q.empty())
        {
            int z=get<0>(Q.front());
            int x=get<1>(Q.front());
            int y=get<2>(Q.front());
            Q.pop();
            for(int i=0;i<6;i++)
            {
                int X=x+dx[i];
                int Y=y+dy[i];
                int Z=z+dz[i];
                if(X<0||Y<0||Z<0||X>=5||Y>=5||Z>=5)continue;
                if(visit[Z][X][Y]||map[Z][X][Y]==0)continue;

                //방문 안한 노드.
                visit[Z][X][Y]=true;

                route[Z][X][Y]=route[z][x][y]+1;
                Q.push(make_tuple(Z,X,Y));



            }




        }

        if(route[4][4-sx][4-sy]&&route[4][4-sx][4-sy]<minDist)minDist=route[4][4-sx][4-sy];
    }
}

void swap(int a,int b)
{
    int tmp[5][5];
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            tmp[i][j]=map[a][i][j];
        }
    }
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            map[a][i][j]=map[b][i][j];
        }
    }
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            map[b][i][j]=tmp[i][j];
        }
    }
}
void Permutation(int start,int end){
    if(start==end)
    {
        BFS();
    }
    else
    {
        for(int i=start;i<=end;i++)
        {
            swap(start,i);
            Permutation(start+1,end);
            swap(start,i);
        }
    }
}
int main()
{
    for (int h = 0; h < 5; h++)
    {
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                cin >> map[h][i][j];
            }
        }
    }

    //cout<<"input OK\n";
    for (int f0 = 0; f0 < 4; f0++)
    {
        for (int f1 = 0; f1 < 4; f1++)
        {
            for (int f2 = 0; f2 < 4; f2++)
            {
                for (int f3 = 0; f3 < 4; f3++)
                {
                    for (int f4 = 0; f4 < 4; f4++)
                    {
                        
                        Permutation(0,4);
                        if(minDist==12)
                        {
                            cout<<12;
                            return 0;
                        }
                        rotate(4);
                    }
                    
                    rotate(3);
                }
                rotate(2);
            }
            rotate(1);
        }
        rotate(0);
    }
    
    cout<<(minDist==0x7fffffff?-1:minDist);
    return 0;
}