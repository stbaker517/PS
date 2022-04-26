#include<iostream>
#include<queue>

using namespace std;

#define pii pair<int,int>
int arr[100][100];
char dp[100][100][101];
int n;
void sum(int x1,int y1,int x2,int y2,int tx,int ty){
    for(int i=0;i<100;i++)
    {
        dp[tx][ty][i]=(dp[x1][y1][i]+dp[x2][y2][i])%10;
        dp[tx][ty][i+1]=(dp[x1][y1][i]+dp[x2][y2][i])/10;
    }
}
void print(int x,int y){
    int flag=0;
    for(int i=99;i>=0;i--){
        if(dp[x][y][i])flag=1;
        if(flag){
            printf("%d",dp[x][y][i]);
        }
    }
    if(!flag)printf("0");

}
void set(int x,int y){
    int X,Y;
    //1
    X=x+arr[x][y];
    Y=y;
    if(X<n){
        sum(x,y,X,Y,X,Y);
    }
    X=x;
    Y=y+arr[x][y];
    if(Y<n){
        sum(x,y,X,Y,X,Y);
    }
}

void printdp(){
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            print(i,j);
            printf(" ");


        }
        printf("\n");
    }
}
int main(){
    
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>arr[i][j];
        }
    }

    dp[0][0][0]=1;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==n-1&&j==n-1)break;
            set(i,j);
            //printf("[%d %d]\n",i,j);
            //printdp();
        }
    }
    

    print(n-1,n-1);
}