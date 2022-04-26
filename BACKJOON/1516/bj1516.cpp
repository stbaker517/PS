#include<iostream>
#include<queue>
using namespace std;
int n;
int info[501][501];
int time[501];
int dp[501];
queue<int>Q;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    int _t;
    

    for(int i=1;i<=n;i++){
        cin>>time[i];
        int cnt=0;
        while(1){
            cin>>_t;
            if(_t==-1){
                break;}
            info[i][_t]=1;
            cnt++;
        }
        info[i][0]=cnt;
        if(cnt==0){Q.push(i);
        dp[i]=time[i];}
    }
    while(!Q.empty()){
        int tobuild=Q.front();
        Q.pop();
        for(int i=1;i<=n;i++){
            if(info[i][tobuild]){
                info[i][0]--;
                info[i][tobuild]=0;
                dp[i]=max(dp[i],dp[tobuild]+time[i]);
                if(info[i][0]==0){
                    
                    Q.push(i);
                }
            }
        }
    }

    for(int i=1;i<=n;i++)
    {
        cout<<dp[i]<<"\n";
    }






    return 0;
}