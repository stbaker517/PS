#include<iostream>

using namespace std;

int dp[12];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    dp[0]=1;
    dp[1]=1;
    

    int t;
    cin>>t;
    int idx=2;
    while(t--){
        int n;
        cin>>n;
        for(int i=2;i<=n;i++)
        {
            if(dp[i])continue;
            dp[i]=dp[i-1];
            if(i>=2)dp[i]+=dp[i-2];
            if(i>=3)dp[i]+=dp[i-3];
        }
        
        
        cout<<dp[n]<<"\n";
    }
}