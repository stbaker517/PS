#include<iostream>
#include<cstring>
using namespace std;

int dp[5000][5000];
int n;
void resetDP(){
    memset(dp,0,sizeof(dp)*5000*5000);
}
int arr[5000];
void doDP(int target){
    int l=target;
    int r=target;
    

}
void f(int target){
    dp[target][target]=1;
    doDP(target);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++)cin>>arr[i];
    int t;
    cin>>t;
    for(int i=0;i<t;t++){
        int target;
        cin>>target;
        f(target);
    }

    return 0;
}