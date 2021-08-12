#include<iostream>

using namespace std;

#define ll long long

int tc;
int n;


ll dp[100][10];
ll Tdp[100];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for(int i=0;i<10;i++)
        dp[1][i]=1;

    for(int i=2;i<=64;i++)
    {
        //맨 앞에 붙는다고 생각해보자.
        ll tot=0;//<--
        for(int j=0;j<10;j++)
            tot+=dp[i-1][j];
        
        for(int j=0;j<10;j++)//dp[n][0~9]
            {
                dp[i][j]=tot;
                tot-=dp[i-1][j];
            }
    }


    cin>>tc;
    for(int i=0;i<tc;i++)
    {
        cin>>n;

        if(!Tdp[n])//
        {
            for(int i=0;i<10;i++)
                Tdp[n]+=dp[n][i];
        }
        
        cout<<Tdp[n]<<"\n";
    }



    return 0;
}