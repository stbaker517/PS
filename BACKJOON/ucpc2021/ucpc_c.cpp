#include<iostream>

using namespace std;


int main(){
    float a,b,c;
    cin>>a>>b>>c;
    float tot=0;
    float P=b/100;

    while(P<1)
    {
        tot+=P;
        P+=P*c/100;
    }
    tot+=P;
    //tot/=100;

    cout<<a*tot;



    return 0;
}