#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

#define pii pair<int,int>

pii arr[101];

int dp[100005][105];

int n,k;

void f(int nowW){
    for(int i=n;i>=1;i--)
    {
        pii item=arr[i];
        if(dp[nowW][i])continue;

        //무게 계산.
        if(nowW+item.first>k)continue;

        //가치 계산.
        if(dp[nowW][0]+item.second<=dp[nowW+item.first][0])continue;
        //cout<<nowW<<"  ";
        //cout<<"\n";
        //for(int i=1;i<=k;i++)cout<<dp[i][0]<<" ";

        
        dp[nowW+item.first][0]=dp[nowW][0]+item.second;

        for(int j=1;j<=n;j++)
            dp[nowW+item.first][j]=dp[nowW][j];
        dp[nowW+item.first][i]=1;
        f(nowW+item.first);
    }

    return ;
}

int main(){
    //ios::sync_with_stdio(0);
    //arr[].f=w .s=v
    cin>>n>>k;
    int x,y;
    for(int i=1;i<=n;i++)
    {
        
        
        cin>>arr[i].first>>arr[i].second;

    
    }
    
    sort(arr+1,arr+n+1);
   
    
    /*for(int i=1;i<=n;i++)
    {
        cout<<arr[i].first<<" "<<arr[i].second<<"--\n";
    }*/

    for(int i=1;i<=n;i++)
    {
        //cout<<i;

        if(dp[arr[i].first][0])dp[arr[i].first][i-1]=0;

        dp[arr[i].first][0]=arr[i].second;
        dp[arr[i].first][i]=1;
        
    }
   // cout<<"ok";
   /*cout<<"\n\n";
    for(int i=1;i<=k;i++)
    {cout<<dp[i][0]<<": ";
        for(int j=1;j<=k;j++)cout<<dp[i][j]<<" ";
        cout<<"\n";
    }
    cout<<"\n\n";*/

    //f(0);
    for(int i=arr[n].first;i>=arr[1].first;i--)
    {
        if(dp[i][0])
            f(i);
    }

    int max=0;
    for(int i=k;i>=0;i--)
    {
        if(dp[i][0]>max)
            max=dp[i][0];
    }
    cout<<max;
    /*cout<<"\n";
    for(int i=1;i<=k;i++)cout<<dp[i][0]<<" ";*/
    return 0;

}