#include<iostream>
#include<queue>
#include<algorithm>
#include<tuple>

using namespace std;
#define pii pair<int,int>
#define tiip tuple<int,int,pii>//lv,jump,pos

int dx[]={0,-1,0,1};
int dy[]={-1,0,1,0};
int mmap[100][100];
int lvmap[100][100];
int vvisit[2][100][100];
int n,m;
int getManD(pii p){
    return n-1-p.first+p.second;
}
struct cmp{
    bool operator()(tiip&a,tiip&b){
        pii pa=get<2>(a),pb=get<2>(b);
        int lva=get<0>(a),lvb=get<0>(b);
        
        if(lva>lvb)return true;
        else if(lva==lvb){
            if(getManD(pa)>getManD(pb))return true;
        }
        return false;
    }
};
void f(){
    priority_queue<tiip,vector<tiip>,cmp>PQ;
    pii inp={0,0};
    PQ.push(make_tuple(lvmap[0][0],0,inp));
    while(!PQ.empty()){
        tiip _frt=PQ.top();
        PQ.pop();
        int lv=get<0>(_frt);
        int jump=get<1>(_frt);
        pii pos=get<2>(_frt);
        printf("%d\n",lv);
        int x=pos.first;
        int y=pos.second;
        //printf("%d %d\n",x,y);
        vvisit[jump][x][y]=lv;
        for(int i=0;i<4;i++){
            int X=x+dx[i];
            int Y=y+dy[i];
            //printf("%d %d 1\n",x,y);
            if(X<0||Y<0||X>=n||Y>=m)continue;
            //printf("%d %d 2\n",x,y);
            int _lv=max(lv,lvmap[X][Y]);

            if(vvisit[0][X][Y]<=_lv)continue;
            //printf("%d %d 3\n",x,y);
            pii input={X,Y};        
            PQ.push(make_tuple(_lv, 0, input));
        }
        if(lv==0){
        for(int i=0;i<4;i++){
            int X=x+2*dx[i];
            int Y=y+2*dy[i];

            if(X<0||Y<0||X>=n||Y>=m)continue;
            int _lv=max(lv,lvmap[X][Y]);

            if(vvisit[1][X][Y]<=_lv)continue;
            if(vvisit[0][X][Y]<_lv)continue;
            pii input={X,Y};        
            PQ.push(make_tuple(_lv, 1, input));
        }}
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>lvmap[i][j];
            vvisit[0][i][j]=1'000'000'000;
            vvisit[1][i][j]=1'000'000'000;
        }
    }
    vvisit[0][0][0]=lvmap[0][0];
    vvisit[1][0][0]=lvmap[0][0];
    f();
    cout<<min(vvisit[0][n-1][m-1],vvisit[1][n-1][m-1]);
}