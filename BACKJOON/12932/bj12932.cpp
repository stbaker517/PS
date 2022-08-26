#include<iostream>

using namespace std;
#define ll long long

ll dp[2001][2001];
ll arr[2001];
int n;

void f(int p){
    //dp[0][p]=min(dp[0][p-1]+abs(arr[p]-arr[p-1]),dp[i][p]);
    //dp[p][0]=min(dp[p-1][0]+abs(arr[p]-arr[p-1]),dp[p][i]);
    for(int i=0;i<p-1;i++){
        //left
        dp[i][p]=min(dp[i][p-1]+abs(arr[p]-arr[p-1]),dp[i][p]);
        if(i==0)
            dp[p][p-1]=min(dp[i][p-1],dp[p][p-1]);
        else
        dp[p][p-1]=min(dp[i][p-1]+abs(arr[p]-arr[i]),dp[p][p-1]);

        //right
        dp[p][i]=min(dp[p-1][i]+abs(arr[p]-arr[p-1]),dp[p][i]);
        if(i==0)
            dp[p-1][p]=min(dp[p-1][i],dp[p-1][p]);
        else
        dp[p-1][p]=min(dp[p-1][i]+abs(arr[p]-arr[i]),dp[p-1][p]);
    }
}
void print(){
    for(int i=0;i<=n;i++){
        for(int j=0;j<n;j++){
            if(dp[i][j]==20000000000000) cout<<"__ ";
            else printf("%02lld ",dp[i][j]);
        }
        printf("\n");
    }
}
int main(){
    cin>>n;
    for(int i=0;i<2001;i++){
        for(int j=0;j<2001;j++){
            dp[i][j]=20000000000000;
        }
    }
    dp[0][0]=0;
    dp[1][0]=0;
    dp[0][1]=0;
    dp[1][2]=0;
    dp[2][1]=0;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    for(int i=2;i<=n;i++){
        f(i);
    }
    ll MM=20000000000000;
    for(int i=1;i<n;i++){
        //if(dp[n][i]!=20000000000000)
            MM=min(dp[n][i],MM);

            MM=min(dp[i][n],MM);
    }
    //print();
    cout<<MM;



}