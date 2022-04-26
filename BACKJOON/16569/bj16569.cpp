#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<tuple>

using namespace std;

#define tiii tuple<int,int,int>

int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
int map[100][100];
int visit[100][100];
int vol[100][100];

priority_queue<tiii,vector<tiii>,greater<tiii>> V;
queue<tiii> ER;

int m,n,v,x,y;

int FR=0;
int FRt=0;

void ptr(int idx)
{
    cout<<"\n";
    if(idx)
    {
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<vol[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    else
        {
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<visit[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
}
void pathF(){
    ER.push(make_tuple(0,x,y));

    visit[x][y]=1;

    int t=0;
    while(!ER.empty())
    {
        t=get<0>(ER.front());
        
        while(!V.empty()&&t==get<0>(V.top()))
        {
            tiii vqf=V.top();
            V.pop();

            int vt=get<0>(vqf);
            int vx=get<1>(vqf);
            int vy=get<2>(vqf);

            vol[vx][vy]=vt;

            int vT=vt+1;
            
            for(int i=0;i<4;i++)
            {
                
                int vX=vx+dx[i];
                int vY=vy+dy[i];

                if(vX<0||vY<0||vX>=m||vY>=n)continue;
                if(vol[vX][vY]>0)continue;

                vol[vX][vY]=vT;
                V.push(make_tuple(vT,vX,vY));
            }
        }

        tiii er=ER.front();
        ER.pop();

        int tx=get<1>(er);
        int ty=get<2>(er);
        int T=t+1;

        for(int i=0;i<4;i++)
        {
            
            int X=tx+dx[i];
            int Y=ty+dy[i];

            if(X<0||Y<0||X>=m||Y>=n)continue;
            if(visit[X][Y]||vol[X][Y])continue;

            visit[X][Y]=T;

            if(FR<map[X][Y])
            {
                FR=map[X][Y];
                FRt=T;
            };

            ER.push(make_tuple(T,X,Y));
        }
        //ptr(1);

    }




}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>m>>n>>v;
    cin>>x>>y;
    x-=1;
    y-=1;

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>map[i][j];
        }
    }

    int tx,ty,t;   
    FR=map[x][y];

    for(int i=0;i<v;i++)
    {
        cin>>tx>>ty>>t;
        //vol[tx][ty]=t;
        V.push(make_tuple(t,tx-1,ty-1));
        vol[tx-1][ty-1]=-1;
    }
  
    pathF();

    cout<<FR<<" "<<FRt;

    //ptr(1);
    //ptr(0);
    return 0;
}