#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
int T;
int N;
int div=1000000007;
int H[301];
int dp[301][301];

vector<int>V[301];
void getDiv(int idx){

}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>T;
    for(int i=0;i<T;i++){
        cin>>N;
        for(int i=0;i<301;i++){
            V[i].clear();
        }
        memset(dp,0,sizeof(int)*501*501);

        for(int h=1;h<=N;h++){
            cin>>H[h];
        }
    }

    return 0;
}