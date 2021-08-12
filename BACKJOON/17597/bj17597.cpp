#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<tuple>
#include<map>
#include<set>

using namespace std;


#define ll long long

set<ll>m;
set<ll>newW;
ll w[10];
int c[100];
int N;

void func(int n,ll l,ll r){
    if(n==N)
    {
        m.insert(abs(l-r));
        //cout<<"func: "<<abs(l-r)<<"\n";
        return;
    }

    func(n+1,l+w[n],r);
    func(n+1,l,r+w[n]);
    func(n+1,l,r);

}


void check(int i)
{
    if(i==0)
    {
        for(ll e:m)
        {
            newW.insert(e-c[i]);
        }

        return;
    }

    
}
void mainf(int n){
    
    m.clear();
    newW.clear();
    for(int i=0;i<n;i++)
    {
        cin>>c[i];
    }
    for(int j=0;j<N;j++)
    {
        cin>>w[j];
    }
    //cout<<"00";
    func(0,0,0);
    //cout<<"11123";
    check(0);
    
    for(int i=1;i<n;i++)
    {
        
    }
    cout<<"2";
    if(newW.empty())
    {
        cout<<"-1";
        return;
    }

    ll min=0x7fffffffffffffff;

    for(ll e:newW)
    {
        if(min>e)min=e;
    }

    cout<<min<<"\n";
*/
    return ;

}
int main(){
    int n;
    while(1)
    {
        cin>>n>>N;
        if(n==0&&N==0)return 0;

        mainf(n);
    }
    



    return 0;
}