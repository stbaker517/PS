#include<iostream>
#include<cstring>
#include<queue>

using namespace std;
/*
1.

*/
int dy[]={0,-1,0,1};//TODO::어떤게 어떻게 고장날 것 같다.
int dx[]={-1,0,1,0};
int map[20][20];
int visit[20][20];
queue<pair<int,int>>Q;
int sx,sy;
int ex,ey;
//shark size
int _s=0;
int _t=0;
int n;
void resetV(int n){
    memset(visit,0,sizeof(int)*20*20);
}
int isXYval(int x,int y){
    if(x<0||y<0||x>=n||y>=n)return false;
    return true;
}
int getLv(int s){
    int lv=2;
    for(int i=2;;i++){
        if(s>=i){
            lv++;
            s-=i;
        }
        else break;
    }
    return lv;
}

void calcMin(){//뭐를 어떻게 써야겠다.

}
void bfs(int x,int y,int&dist){ 
    //cout<<x<<y;
    if(dist<visit[x][y]-1)
    {
        //cout<<"hello";
        return;
    }
    if(map[x][y]!=9&&map[x][y]&&getLv(_s)>map[x][y]){
        //cout<<"here";
        if(dist>visit[x][y]-1){
            dist=visit[x][y]-1;
            ex=x;
            ey=y;
        }
        else if(dist==visit[x][y]-1){
            if(x<ex){
                ex=x;
                ey=y;
            }
            else if(x==ex&&y<ey){
                ex=x;
                ey=y;
            }
        }

        /*map[x][y]=0;
        cout<<"eat:"<<x<<","<<y<<","<<getLv(_s)<<"\n";
        _s++;
        dist=visit[x][y]-1;
        sx=x;
        sy=y;*/
        
        return;
    }
    //cout<<"123";
    for(int i=0;i<4;i++){
        int X=x+dx[i];
        int Y=y+dy[i];
        if(!isXYval(X,Y))continue;
        if(visit[X][Y])continue;
        if(map[X][Y]>getLv(_s))continue;
        //cout<<"asdf";
        visit[X][Y]=visit[x][y]+1;
        Q.push({X,Y});
    }
}
int f(){
    int dist=999;
    resetV(n);
    visit[sx][sy]=1;
    bfs(sx,sy,dist);
    while(!Q.empty()){
        //cout<<"here2";
        pair<int,int>p=Q.front();
        Q.pop();
        bfs(p.first,p.second,dist);
    }
    while(!Q.empty())Q.pop();
    if(dist==999)return 0;



    map[sx][sy]=0;
    _t+=dist;
    map[ex][ey]=0;
    sx=ex;
    sy=ey;
    _s++;
    //printf("%d, %d  dist: %d\n",sx,sy,dist);

    
    return dist;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>map[i][j];
            if(map[i][j]==9){
                sx=i;
                sy=j;
            }
        }
    }
    while(1){
        int ret=f();
        if(ret==0)break;
        //cout<<ret<<"\n";
    }
    cout<<_t;
    return 0;
}