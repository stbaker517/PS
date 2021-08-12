#include<iostream>

using namespace std;
int dp[3000001];
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        if(dp[i+1])
            dp[i+1]=min(dp[i]+1,dp[i+1]);
        else dp[i+1]=dp[i]+1;

        if(dp[3*i])
            dp[3*i]=min(dp[i]+1,dp[3*i]);
        else dp[3*i]=dp[i]+1;

        if(dp[2*i])
            dp[2*i]=min(dp[i]+1,dp[2*i]);
        else dp[2*i]=dp[i]+1;
    }

    cout<<dp[n];


    return 0;
}