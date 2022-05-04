#include<iostream>
#include<map>
#include<algorithm>
#include<stack>
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
    int start=0;
    int dplen=1;
    for(int i=1;i<n;i++)
    {   
        int idx=lower_bound(dp,dp+dplen,arr[i])-dp;
        
        order[i]=idx;
        dp[idx]=arr[i];
        if(idx==dplen)dplen++;


    }
    cout<<dplen<<"\n";
    dplen--;
    stack<int>st;
    for(int i=n-1;i>=0;i--){
        if(order[i]==dplen){
            dplen--;
            st.push(arr[i]);
        }
    }
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }

    return 0;
}