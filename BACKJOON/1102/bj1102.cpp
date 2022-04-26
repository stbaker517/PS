#include<bits/stdc++.h>
using namespace std;

int dp[16][1<<15];//dp[이번에 키는 발전소][현재 켜져있는 발전소들의 상태]
int n,p;
int On[16];
int cost[16][16];

void f(int t,int sec){
    if(t==p)return;

    int se=sec;
    for(int i=0;i<n;i++){
        if(On[i])continue;
        On[i]=1;
        se=sec|1<<i;
        if(dp[t+1][se]==0){
            
            f(t+1,se);
        }
        On[i]=0;
    }
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>cost[i][j];
        }
    }

    char ch;
    for(int i=0;i<n;i++){
        cin>>ch;
        if(ch=='Y')On[i]=1;

    }
    cin>>p;
    return 0;
}