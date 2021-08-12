#include<iostream>
#include<cmath.h>
#define ll unsigned long long
using namespace std;

int n;
ll cnt=0;
ll dp[100001];
int theExp(int i)
{
    int N=n;
    int ret=0;
    while(N>=i)
    {
        N/=i;
        ret++;
    }

    return ret;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    n=
    for(int i=2;i<=sqrt(n);i++)
    {
        cnt+=(n-1)/i;
    }
    cnt=cnt+n+n-1;
    cout<<cnt;

    return 0;
}