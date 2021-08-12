#include<iostream>

using namespace std;

int reft;
long long mod(int,int,int);

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a,b,c;

    cin>>a>>b>>c;

    reft=a%c;

    cout<<mod(a,b,c);
    
}

long long mod(int a,int b,int c)
{
    //if(b==0)return 1%c;
    if(b==1)return reft;
    
    long long v=mod(a,b/2,c);//b가 짝수면 정확이 이등분
   

    v=v*v%c;
    if(b%2==0)return v;
    return v*a%c;
        
    //return (mod(a,b/2,c)*mod(a,b-b/2,c))%c;
}