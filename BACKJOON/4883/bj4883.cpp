#include<iostream>
#include<cstring>
using namespace std;

int n;
int map[100000][3];
int dp[100000][3];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
for(int aa=1;;aa++){
    
    cin>>n;
    if(n==0)break;
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            cin>>map[i][j];
        }
    }
    dp[0][0]=1000000000;
    dp[0][1]=map[0][1];
    dp[0][2]=map[0][2]+dp[0][1];
    for(int i=1;i<n;i++){
        dp[i][0]=min(dp[i-1][0],dp[i-1][1])+map[i][0];
        dp[i][1]=min(min(dp[i][0],dp[i-1][0]),min(dp[i-1][1],dp[i-1][2]))+map[i][1];
        dp[i][2]=min(min(dp[i][1],dp[i-1][2]),dp[i-1][1])+map[i][2];
    }
    
    cout<<aa<<". "<<dp[n-1][1]<<"\n";memset(dp,0,sizeof(int)*n*3);
    }



    return 0;
}