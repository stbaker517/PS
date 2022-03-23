#include<iostream>
#include<cstring>
using namespace std;
// -1 검은 블록 0 무지개 n 일반
int n,m;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};

int map[20][20];//빈 자리는 -1로.
int visit[20][20];
int rainbow=0;
int M=0;
int Mrb=0;
int point;
int score=0;
pair<int,int>Mpos;

void ptrMap( ){
    cout<<"\nmap-------------------\n";
        for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(map[i][j]==-2)cout<<"E ";
            else if(map[i][j]==-1)cout<<"X ";
            else
            cout<<map[i][j]<<" ";
        }
        cout<<"\n";
    }
}
void f(int x,int y,int color,int mode){
    if(mode==1)point++;
    if(map[x][y]==0)rainbow++;
    else map[x][y]=-2;
    for(int i=0;i<4;i++){
        int X=x+dx[i];
        int Y=y+dy[i];
        if(X<0||X>=n||Y<0||Y>=n)continue;
        if(visit[X][Y])continue;
        if(map[X][Y]!=color&&map[X][Y]!=0)continue;
        visit[X][Y]=1;
        f(X,Y,color,mode);
    }
}
//기준 블록 most top or most left
void mainFunc(){
    point=0;
    for(int i=n-1;i>=0;i--){
        for(int j=n-1;j>=0;j--){     
            if(map[i][j]<=0)continue;
            memset(visit,0,sizeof(int)*400);
            point=0;
            visit[i][j]=1;
            rainbow=0;
            f(i,j,map[i][j],1);
            if(M<point){
                printf("test Mx=%d My=%d , point: %d\n",i,j,point);
                M=point;
                Mpos={i,j};
            }
            else if(M==point&&Mrb<rainbow){
                M=point;
                Mpos={i,j};
            }
        }
    }
    memset(visit,0,sizeof(int)*400);
    


}
void getScore(int x,int y,int color){
    if(M<=1)return;
    score+=(M*M);
    memset(visit,0,sizeof(int)*400);
    f(x,y,color,0);
    printf("Mx=%d My=%d , point: %d\n",x,y,M);
    
}
void downMap(){
    for(int j=0;j<n;j++){
        for(int i=n-2;i>=0;i--){
            if(map[i][j]<0)continue;
            int t;
            for(t=i+1;t<n;t++){
                
                if(map[t][j]>=-1){
                    t--;
                    break;
                }
            }
            if(t==n)t--;
            if(t==i)continue;
            //printf("(%d,%d) -> (%d,%d)\n",i,j,t,j);
            map[t][j]=map[i][j];
            map[i][j]=-2;
        }
    }
}
void rotateMap(){
    int tmp[20][20];
    memset(tmp,0,sizeof(int)*400);
    for(int j=0;j<n;j++){
        for(int i=0;i<n;i++){
            tmp[n-1-j][i]=map[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            map[i][j]=tmp[i][j];
        }
    }

}
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>map[i][j];
        }
    }
    M=4;
    while(M>1){
        M=0;
        Mrb=0;
        ptrMap();
        
        mainFunc();
        //if(point<=1)break;
        printf("1111\n");
        int Mx=Mpos.first;
        int My=Mpos.second;
        getScore(Mx,My,map[Mx][My]);
        cout<<"SCORE: "<<score<<"\n";
        cout<<"after";
        ptrMap();
        downMap(); 
        //cout<<"down1\n";
        //ptrMap();
        rotateMap();
        //cout<<"rotate\n";
        //ptrMap();
        downMap();//cout<<"down2\n";
        //ptrMap();
    }

    //rotateMap();
    

    cout<<score;


    return 0;
}