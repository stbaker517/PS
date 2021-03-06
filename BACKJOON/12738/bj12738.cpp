#include<iostream>
#include<map>
#include<algorithm>
using namespace std;
int arr[1000000];
int dp[1000000];
int order[1000000];
int n;

int main(){
    //ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    dp[0]=arr[0];

    int dplen=1;
    for(int i=1;i<n;i++)
    {   
        int idx=lower_bound(dp,dp+dplen,arr[i])-dp;
        cout<<idx<<" ";
        if(dplen>idx){
            dp[idx]=arr[i];
        }
        else if(dplen==idx){
            dp[idx]=arr[i];
            order[i]=idx;
            dplen++;
        }
        for(int l=0;l<dplen;l++){
            printf("%d ",dp[l]);
        }
        printf("\n");

    }


    return 0;
}