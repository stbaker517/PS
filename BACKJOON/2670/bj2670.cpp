#include<iostream>
using namespace std;

double arr[10000];
double dp[10000];

int main(){
    int k;
    cin>>k;
    for(int i=0;i<k;i++)
    {
        cin>>arr[i];
    }

    double m=0;
    double tmp;
    int i=0,j=0;
    dp[0]=arr[0];
    for(i=1;i<k;i++){

        dp[i]=max(dp[i-1]*arr[i],arr[i]);
       
    }
    for(int i=0;i<k;i++)
    {
        //cout<<dp[i]<<" ";
        m=max(m,dp[i]);
    }
    printf("%.3lf",m);



}