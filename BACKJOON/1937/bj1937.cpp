#include<iostream>

using namespace std;

int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
int n;
int max_move;
int numb;
int map[500][500];
int dp[500][500];
bool visit[500][500];


void setZero(){
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            visit[i][j]=0;
        }
    }

}



void dfs(int x,int y)
{
    if(dp[x][y])return ;

    for(int i=0;i<4;i++)
    {
        int X=x+dx[i];
        int Y=y+dy[i];

        if(X<0||X>=n||Y>=n||Y<0)continue;
        if(visit[X][Y])continue;
        
        if(map[X][Y]>map[x][y])
        {

                visit[X][Y]=1;
                dfs(X,Y);
                dp[x][y]=max(dp[x][y],dp[X][Y]+1);
                visit[X][Y]=0;
        }
    }


    
    

    return ;

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;


    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>map[i][j];
        }
    }

        for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            
            visit[i][j]=1;
            dfs(i,j);
            visit[i][j]=0;
            
        }
    }

    int M=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            
            M=max(M,dp[i][j]);
            
        }
    }

    cout<<M+1;
    return 0;
}