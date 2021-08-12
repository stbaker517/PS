#include<iostream>
#include<queue>
using namespace std;

int F= 0x7fffffff;

int map[1000][1000];
bool visit[1000][1000];
queue<pair<int,int>>Q;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int r,c;
int T=0;
void BFS();
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>r>>c;
    char temp;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            visit[i][j]=false;
            cin>>temp;
            if(temp=='#')
                {map[i][j]=-1;}
            else if(temp=='F')
               {map[i][j]=F;}
            else if(temp=='J'){
                map[i][j]=1;
                Q.push({i,j});
                visit[i][j]=true;
            }
            else
                map[i][j]=0;
        }
    }

    /*for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
            cout<<map[i][j]<<" ";
        cout<<'\n';
    }*/


    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(map[i][j]==F){
                visit[i][j]=true;
                Q.push({i,j});
            }
        }
    }

    while(!Q.empty()){
        BFS();
        /*cout<<"\nR\n";
        for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
            cout<<map[i][j]<<" ";
        cout<<'\n';
    }*/
        
        
        }
    
    

    if(T)cout<<T;
    else cout<<"IMPOSSIBLE";



    return 0;
}

void BFS(){
    int x=Q.front().first;
    int y=Q.front().second;
    Q.pop();

    
    for(int i=0;i<4;i++)
    {
        int X=x+dx[i];
        int Y=y+dy[i];

        if(X<0||Y<0||X>=r||Y>=c)
        {
            if(map[x][y]!=F&&!T)T=map[x][y];
            continue;}
        

        if(map[X][Y]>=0)
        {
            if(map[x][y]==F)
            {
                if(map[X][Y]!=F)
                {visit[X][Y]=true;
                map[X][Y]=F;
                Q.push({X,Y});}
            }

            else if(visit[X][Y]==false)
            {
               
                visit[X][Y]=true;
                map[X][Y]=map[x][y]+1;
                Q.push({X,Y});
            }
        }


    }

}