#include<iostream>

using namespace std;

int score[301];
int jump[301];
int step[301];
int dp[301];

int main(){
    int n;
    cin>>n;
    int input;

    for(int i=0;i<n;i++)
    {
        cin>>input;
        score[i+1]=input;
    }

    for(int i=2;i<=n;i++)
    {
        
        

    }

    cout<<max(jump[n],step[n]);
    return 0;
}