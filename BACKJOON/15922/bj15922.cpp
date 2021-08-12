#include<iostream>

using namespace std;
#define ll long long

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll tot=0;
    int n;
    cin>>n;
    ll s=0x1111111111111111,e=0x1111111111111111;
    ll ts,te;
    for(int i=0;i<n;i++)
    {
        cin>>ts>>te;
        if(i)
        {
            if(ts<=e)
                {if(te>e)e=te;}
            else{
                //cout<<s<<" "<<e<<" "<<e-s<<"\n";
                tot+=(e-s);
                s=ts;
                e=te;
            }
        }
        else{
            
            s=ts;
            e=te;
        }

    }
    tot+=e-s;
    cout<<tot;

    return 0;
}