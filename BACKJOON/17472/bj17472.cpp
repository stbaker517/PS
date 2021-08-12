#include<iostream>
#include<queue>
#include<vector>
#include<tuple>

using namespace std;


//처음에 각 섬마다 길이를 측정해서 엣지로 박아주고. ->100*100최대 1만
//크루스칼 때립세. 크루스칼이 보기 편하잖아~ ->O(E) 얼마 안하누;
//다리 길이 1짜리 제외 잘하고.
//다리 방향 조절 잘하시거.


typedef tuple<int,int,int> P;


priority_queue<P,vector<P>,greater<P> > PQ;

queue<pair<int,int>>Q;
queue<pair<int,int>>BQ;

int**graph;
int map[10][10];
int copy[10][10];
bool visit[10][10];
int root[100];

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

int r,c;
int tot=0;

void find(int isleNum,int x,int y,int dx,int dy,int len){
    if(x<0||y<0||x>=r||y>=c||map[x][y])return;

    while(!map[x][y])//육지에 닿을 때까지
    {
        //cout<<"x:"<<x<<"y:"<<y<<' ';
        x+=dx;
        y+=dy;
        len++;

        if(x<0||y<0||x>=r||y>=c)return;
    }
    //cout<<"\n";
    if(len>2&&isleNum!=map[x][y])
    {
        //cout<<"done\n";
        PQ.push(make_tuple(len-1,isleNum,map[x][y]));
    }

}

void edging()
{
    int x=Q.front().first;
    int y=Q.front().second;
    //cout<<"Edging "<<x<<" "<<y<<'\n';
    int ret=100;
    for(int i=0;i<4;i++)
    {
        find(map[x][y],x+dx[i],y+dy[i],dx[i],dy[i],1);
    }
    
}

void funcBoundary(int num,int x,int y){
     queue<pair<int,int>>tq;
     tq.push({x,y});
    
     while(!tq.empty())
     {
         int tx=tq.front().first;
         int ty=tq.front().second;
        tq.pop();
        map[tx][ty]=num;

        
        
        int cnt=0;
        for(int i=0;i<4;i++)
        {
            int X=tx+dx[i];
            int Y=ty+dy[i];

            if(X<0||Y<0||X>=r||Y>=c)continue;
            if(map[X][Y]&&visit[X][Y]==false)
            {
                visit[X][Y]=true;
                tq.push({X,Y});
            }
            else if(map[X][Y]==0)
                cnt++;//테두리만 저장.

        }
        if(cnt)Q.push({tx,ty});
     }
}
void print(){
    cout<<"\nmap\n";
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cout<<map[i][j]<<" ";
        }
        cout<<"\n";
    }
}
void kruscal();
int fset(int );
int main(){
    //ios::sync_with_stdio(0);
    //cin.tie(0);

    for(int i=0;i<100;i++)
        root[i]=i;
    cin>>r>>c;

    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cin>>map[i][j];
        }
    }
    //cout<<"step0\n";
    int idx=1;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(map[i][j]&&visit[i][j]==false){
                //cout<<i<<", "<<j<<'\n';
                visit[i][j]=true;
                funcBoundary(idx++,i,j);

            }
        }
    }

    //print();
    //cout<<"step1\n";
    

    while(!Q.empty())
    {   
        
        edging();
        Q.pop();
    }
    //cout<<"step2\n";
    //크루스칼.
    //if(PQ.empty())cout<<"none\n";
    


    kruscal();
    
    //cout<<"step3\n";

    for(int i=1;i<idx;i++)
    {
        //cout<<fset(i)<<" ";//TEST
        if(fset(i)!=1)
        {
            cout<<-1;
            return 0;
        }
    }
    if(tot) cout<<tot;
    else cout<<-1;
}

int fset(int x)
{
    while(root[x]!=x)
    {
        x=root[x];
    }
    return x;
}
void kruscal(){
    while(!PQ.empty())
    {
        int len=get<0>(PQ.top());
        int v1=get<1>(PQ.top());
        int v2=get<2>(PQ.top());
        PQ.pop();
        //cout<<v1<<" "<<v2<<" W:"<<len;//TEST
        //서로 disjoint면 가능
        if(fset(v1)!=fset(v2))
        {
            //cout<<"IN";//TEST
            tot+=len;
            if(fset(v1)<fset(v2))
                root[fset(v2)]=fset(v1);
            else    root[fset(v1)]=fset(v2);
        }
        //cout<<"\n";//TEST
    }
}