#include<iostream>
#include<algorithm>
using namespace std;

int n,W;
int tree[1001];
int dp[1000][2][31];

int main(){
    cin>>n>>W;
    for(int i=0;i<n;i++){
        cin>>tree[i];
        tree[i]--;
    }
    if(tree[0]){
        dp[0][1][1]=1;
    }
    else{
        dp[0][0][0]=1;
    }
    for(int i=1;i<n;i++){
        dp[i][0][0]=dp[i-1][0][0]+(tree[i]==0?1:0);
        for(int w=1;w<=W;w++){
            for(int pos=0;pos<2;pos++){
                dp[i][pos][w]=max(dp[i-1][pos][w],dp[i-1][!pos][w-1])+(tree[i]==pos?1:0);

            }
        }
    }
    int mm=0;
    for(int i=0;i<=W;i++){
        for(int p=0;p<2;p++){
            mm=max(dp[n-1][p][i],mm);
        }
    }
    //cout<<"and";
    cout<<mm;
    return 0;
}