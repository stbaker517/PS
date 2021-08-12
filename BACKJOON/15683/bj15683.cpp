#include<iostream>
#include<queue>
#include<vector>

using namespace std;

vector<pair<int,int>>CCTV;

int dx[]={-1,0,1,0};//위 우 하 좌
int dy[]={0,1,0,-1};

int map[8][8];
int cctv_dir[8];
int r,c;
const int on=9;

int Max=0;
void refresh(){
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(map[i][j]==on)map[i][j]=0;
        }
    }
}
void set1(int ,int,int);
void set2(int ,int,int);
void set3(int ,int,int);
void set4(int ,int,int);
void set5(int ,int,int);
void set(int x,int y,int idx)
{
    int type=map[x][y];
    switch(type){
        case 1:
            set1(x,y,idx);
            break;
        case 2:
            set2(x,y,idx);
            break;
        case 3:
            set3(x,y,idx);
            break;
        case 4:
            set4(x,y,idx);
            break;
        case 5:
            set5(x,y,idx);
            break;
        
    }
}


int count(){
    int count=0;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(map[i][j])count++;     
        }
    }
    return count;
}
void print();
void func(int n){
    if(n==CCTV.size())
    {
        refresh();
        for(int i=0;i<CCTV.size();i++){
            set(CCTV[i].first,CCTV[i].second,i);
        }
        int c=count();
        //cout<<"\n";
        //print();
        
        if(Max<c)Max=c;
        return ;
    }
    int last;
    switch(map[CCTV[n].first][CCTV[n].second]){
        
        case 2:
            last=2;
            break;
        
        case 5:
            last=1;
            break;

        default:
            last=4;
            break;
    }
    for(int i=0;i<last;i++)
    {
       
        func(n+1);
        cctv_dir[n]=(cctv_dir[n]+1)%last;
    }

}

int main(){
    cin>>r>>c;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cin>>map[i][j];
            if(map[i][j]>0&&map[i][j]<6)
                CCTV.push_back({i,j});
        }
    }    

    func(0);
    
    cout<<r*c-Max;
    

    return 0;
}

void print(){
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cout<<map[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
}
void set1(int ox,int oy,int idx){
    int i=cctv_dir[idx];
    queue<pair<int,int>>Q;
    //map[ox][oy]=on;
    Q.push({ox+dx[i],oy+dy[i]});
    while(!Q.empty())
    {
        int x=Q.front().first;
        int y=Q.front().second;
        Q.pop();  
        if(x<0||y<0||x>=r||y>=c)continue;
        if(map[x][y]==6)continue;
        if(map[x][y]==0)
            map[x][y]=on; 
        Q.push({x+dx[i],y+dy[i]});
    }
}
void set2(int ox,int oy,int idx){
    int i=cctv_dir[idx];
    queue<pair<int,int>>Q;
    //map[ox][oy]=on;
    Q.push({ox+dx[i],oy+dy[i]});
    while(!Q.empty())
    {
        int x=Q.front().first;
        int y=Q.front().second;
        Q.pop();   
        if(x<0||y<0||x>=r||y>=c)continue;
        if(map[x][y]==6)continue;
        if(map[x][y]==0)
            map[x][y]=on;
        Q.push({x+dx[i],y+dy[i]});
    }

    i=(cctv_dir[idx]+2)%4;
    Q.push({ox+dx[i],oy+dy[i]});
    while(!Q.empty())
    {
        int x=Q.front().first;
        int y=Q.front().second;
        Q.pop();  
        if(x<0||y<0||x>=r||y>=c)continue;
        if(map[x][y]==6)continue;
        if(map[x][y]==0)
            map[x][y]=on;
        Q.push({x+dx[i],y+dy[i]});
    }
}
void set3(int ox,int oy,int idx)
{
    int i=cctv_dir[idx];
    queue<pair<int,int>>Q;
    //map[ox][oy]=on;
    Q.push({ox+dx[i],oy+dy[i]});
    while(!Q.empty())
    {
        int x=Q.front().first;
        int y=Q.front().second;
        Q.pop();   
        if(x<0||y<0||x>=r||y>=c)continue;
        if(map[x][y]==6)continue;
        if(map[x][y]==0)
            map[x][y]=on;
        Q.push({x+dx[i],y+dy[i]});
    }

    i=(cctv_dir[idx]+1)%4;
    Q.push({ox+dx[i],oy+dy[i]});
    while(!Q.empty())
    {
        int x=Q.front().first;
        int y=Q.front().second;
        Q.pop();   
        if(x<0||y<0||x>=r||y>=c)continue;
        if(map[x][y]==6)continue;
        if(map[x][y]==0)
            map[x][y]=on;
        Q.push({x+dx[i],y+dy[i]});
    }
}
void set4(int ox,int oy,int idx){
    int i=cctv_dir[idx];
    queue<pair<int,int>>Q;
    //map[ox][oy]=on;
    Q.push({ox+dx[i],oy+dy[i]});
    while(!Q.empty())
    {
        int x=Q.front().first;
        int y=Q.front().second;
        Q.pop();   
        if(x<0||y<0||x>=r||y>=c)continue;
        if(map[x][y]==6)continue;
        if(map[x][y]==0)
            map[x][y]=on;
            Q.push({x+dx[i],y+dy[i]});
    }

    i=(cctv_dir[idx]+1)%4;
    Q.push({ox+dx[i],oy+dy[i]});
    while(!Q.empty())
    {
        int x=Q.front().first;
        int y=Q.front().second;
        Q.pop();   
        if(x<0||y<0||x>=r||y>=c)continue;
        if(map[x][y]==6)continue;
       if(map[x][y]==0)
         map[x][y]=on;
         Q.push({x+dx[i],y+dy[i]});
    }
    i=(cctv_dir[idx]+3)%4;
    Q.push({ox+dx[i],oy+dy[i]});
    while(!Q.empty())
    {
        int x=Q.front().first;
        int y=Q.front().second;
        Q.pop();   
        if(x<0||y<0||x>=r||y>=c)continue;
        if(map[x][y]==6)continue;
        if(map[x][y]==0)
            map[x][y]=on;
        Q.push({x+dx[i],y+dy[i]});
    }
}
void set5(int ox,int oy,int idx)
{
    int i=0;
    queue<pair<int,int>>Q;
    //map[ox][oy]=on;
   Q.push({ox+dx[i],oy+dy[i]});
    while(!Q.empty())
    {
        int x=Q.front().first;
        int y=Q.front().second;
        Q.pop();   
        if(x<0||y<0||x>=r||y>=c)continue;
        if(map[x][y]==6)continue;
        if(map[x][y]==0)
            map[x][y]=on;
            Q.push({x+dx[i],y+dy[i]});
    }

    i=1;
   Q.push({ox+dx[i],oy+dy[i]});
    while(!Q.empty())
    {
        int x=Q.front().first;
        int y=Q.front().second;
        Q.pop();  
        if(x<0||y<0||x>=r||y>=c)continue;
        if(map[x][y]==6)continue;
        if(map[x][y]==0)
            map[x][y]=on;
            Q.push({x+dx[i],y+dy[i]});
    }
    i=2;
    Q.push({ox+dx[i],oy+dy[i]});
    while(!Q.empty())
    {
        int x=Q.front().first;
        int y=Q.front().second;
        Q.pop();  
        if(x<0||y<0||x>=r||y>=c)continue;
        if(map[x][y]==6)continue;
        if(map[x][y]==0)
            map[x][y]=on;
             Q.push({x+dx[i],y+dy[i]});
    }
    i=3;
    Q.push({ox+dx[i],oy+dy[i]});
    while(!Q.empty())
    {
        int x=Q.front().first;
        int y=Q.front().second;
        Q.pop();   
        if(x<0||y<0||x>=r||y>=c)continue;
        if(map[x][y]==6)continue;
        if(map[x][y]==0)
            map[x][y]=on;
        Q.push({x+dx[i],y+dy[i]});
    }
}