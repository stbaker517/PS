#include<iostream>
#include<stack>
#include<queue>
#include<tuple>

using namespace std;

int r,c;
int map[10][10];
bool visit[10][10];

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

queue<pair<int,int>>BQ;//바운더리가 저장돼있는 큐.


void getBoundary(int i,int j,int idx){
    queue<pair<int,int>>q;
    q.push({i,j});
    visit[i][j]=true;

    while(!q.empty())
    {
        int x=q.front().first;
        int y=q.front().second;
        map[x][y]=idx;
        q.pop();

        bool isB=false;
        for(int i=0;i<4;i++)
        {
            int X=x+dx[i];
            int Y=y+dy[i];

            if(X<0||Y<0||X>=r||Y>=c)return ;
            if(map[X][Y]&&visit[X][Y]==false)
            {
                visit[X][Y]=true;
                q.push({X,Y});
            }

            if(map[X][Y]==0)isB=true;
        }
        if(isB)BQ.push({x,y});
    }


}

void find(){
    while(!BQ.empty())
    {
        int x=BQ.front().first;
        int y=BQ.front().second;
        BQ.pop();

        for(int i=0;i<4;i++)
        {
            int X=x+dx[i],Y=y+dy[i];
            int len=0;
            while(map[X][Y]==0)
            {
                
            }
            


        }






    }


}

int main(){
    //ios::sync_with_stdio(0);
    //cin.tie(0);

    cin>>r>>c;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cin>>map[i][j];
        }
    }

    int idx=0;

    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(visit[i][j]==false&&map[i][j]!=0)
            {
               getBoundary(i,j,++idx);
            }
        }
    }



    


    return 0;
}