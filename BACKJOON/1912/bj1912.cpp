#include<iostream>

using namespace std;

int main(){
    int arr[100001];
    int dp[100001];
    int M;

    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>arr[i];

    M=dp[0]=arr[0];
    
    for(int i=1;i<n;i++)
    {
        int dpParr=dp[i-1]+arr[i];
        if(dpParr>arr[i])dp[i]=dpParr;
        else dp[i]=arr[i];

        if(dp[i]>M)M=dp[i];
    }

    //for(int i=0;i<n;i++)cout<<dp[i]<<" ";
    //cout<<"\n";
    cout<<M;


    return 0;
}