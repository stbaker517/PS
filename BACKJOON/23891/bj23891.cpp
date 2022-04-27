#include<iostream>

using namespace std;

int N;
int M;
int S[101];
int P[101];
int dp[101][100001];
bool visit[101][100001];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    for(int i=1;i<=N;i++){
        cin>>S[i]>>P[i];
    }
    for(int i=0;i<101;i++){
        for(int j=0;j<100001;j++){
            dp[i][j]=-50000000;
        }
    }
    dp[1][0]=-S[1];
    dp[1][P[1]]=0;
    dp[1][P[1]+1]=S[1];

    visit[1][0]=1;
    visit[1][P[1]]=1;
    visit[1][P[1]+1]=1;

    for (int s=1;s<N;s++)
    {
        for (int m=0;m<=M;m++){
            if(!visit[s][m])continue;
            int ns=s+1;
            dp[ns][m]=max(dp[ns][m],dp[s][m]-S[ns]);//한명도 안 씀 -> 패배.
            visit[ns][m]=1;
            if(m+P[ns]>M)continue;
            dp[ns][m+P[ns]]=max(dp[ns][m+P[ns]],dp[s][m]);//똑같이 씀 -> 비김.
            visit[ns][m+P[ns]]=1;
            if(m+P[ns]+1>M)continue;
            dp[ns][m+P[ns]+1]=max(dp[ns][m+P[ns]+1],dp[s][m]+S[ns]);//하나 더 씀 -> 이김.
            visit[ns][m+P[ns]+1]=1;

        }
    }
    int cnt=-50000000;
    for(int i=0;i<=M;i++)
    {
        cnt=max(cnt,dp[N][i]);
    }
    if(cnt>0)cout<<"W";
    else if(cnt==0)cout<<"D";
    else cout<<"L";

    return 0;
}