#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#include<stack>

using namespace std;

#define pii pair<int,int>
#define pipp pair<int,pair<pii,pii>>
int mmap[51][51];
bool vvisit[51][51];

int dx[]={0,-1,0,1};
int dy[]={-1,0,1,0};
int n;
int x1,y1,x2,y2;
int k;
void setCircuit(int sx,int sy,int ex,int ey,int val){
    if(sx<ex){
        for(int x=sx;x<=ex;x++){
            mmap[x][sy]=val;
        }
    } else if(sx>ex){
        for(int x=ex;x<=sx;x++){
            mmap[x][sy]=val;
        }
    }

    if(sy<ey) {
        for(int y=sy;y<=ey;y++){
            mmap[sx][y]=val;
        }
    } else if( sy>ey){
        for(int y=ey;y<=sy;y++){
            mmap[sx][y]=val;
        }
    }
}
void printMap(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ",mmap[i][j]);
        }
        printf("\n");
    }
}
void printvvisit(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ",vvisit[i][j]);
        }
        printf("\n");
    }
}
struct cmp{
    bool operator()(pipp&a,pipp&b){
        if(a.first>b.first)return true;
        return false;
    }
};

bool outOfMap(int x,int y){
    if(x<0||x>=n)return true;
    if(y<0||y>=n)return true;
    return false;
}

pii parentMap[51][51];
int djikstra(){
    priority_queue<pipp,vector<pipp>,cmp>PQ;
    PQ.push({1,{{x1,y1},{x1,y1}}});
    while(!PQ.empty()){
        pipp top = PQ.top();
        PQ.pop();
        int cost=top.first;
        pii po = top.second.first;
        pii pp = top.second.second;
        int x=po.first;
        int y = po.second;
        if(vvisit[x][y])continue;
        vvisit[x][y]=1;
        parentMap[x][y]={pp.first,pp.second};
        if(x==x2&&y==y2)return cost;

        for(int i=0;i<4;i++){
            int X=x+dx[i];
            int Y=y+dy[i];
            if(outOfMap(X,Y))continue;
            if(vvisit[X][Y])continue;
            PQ.push({cost+(mmap[X][Y]?k:1),{{X,Y},{x,y}}});
        }

    }

}
bool vvvisit[51][51];
// void pathFollow(int x,int y,vector<int,int>&path){
//     if(x==x2&&y==y2)return;

//     for(int i=0;i<)

// }

int mmm[51][51];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    cin>>x1>>y1>>x2>>y2;
    x1--;
    x2--;
    y1--;
    y2--;
    cin>>k;
    int m;
    cin>>m;
    vector<pair<int,int>>vp;
    for(int i=2;i<m+2;i++){
        int r;
        cin>>r;
        vp.clear();
        int tx,ty;
        for(int j=0;j<r;j++){
            cin>>tx>>ty;
            vp.push_back({tx-1,ty-1});
        }
        for(int j=0;j<vp.size()-1;j++){
            setCircuit(vp[j].first,vp[j].second,vp[j+1].first,vp[j+1].second,i);
        }
    }
    cout<<djikstra()<<"\n";
    int xx=x2;
    int yy=y2;
    int dir=-1;
    stack<pii> sst;
    sst.push({x2,y2});
    // printf("---\n");
    while(xx!=x1||yy!=y1){
        int px=parentMap[xx][yy].first;
        int py=parentMap[xx][yy].second;
        // printf("%d %d\n",xx+1,yy+1);
        for(int i=0;i<4;i++){
            int X=xx+dx[i];
            int Y=yy+dy[i];
            if(outOfMap(X,Y))continue;
            if(X==px&&Y==py){
                if(dir!=i){
                    if(dir!=-1)sst.push({xx,yy});
                    dir=i;
                }
            }
        }
        // if(xx==x1&&yy==y1){
        //     printf("break!! %d %d\n",xx,yy);
        // }
        xx=px;
        yy=py;
    }
    // printf("---");
    sst.push({x1,y1});

    cout<<sst.size()<<" ";
    while(!sst.empty()){
        pii top = sst.top();
        sst.pop();
        cout<<top.first+1<<" "<<top.second+1<<" ";
    }
    return 0;
}