#include<iostream>

using namespace std;

void ff(int k){
    if(k&0b1)
    {
        cout<<" ON\n";
        return;
    }
    else cout<<" OFF\n";


}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;

 
    int ch,input;
    for(int i=1;i<=n;i++)
    {
        int test=1;
       
        cin>>ch>>input; 
        test=test<<ch;
        test-=1;

        cout<<"#"<<i;
        
        if((input&test)^test)cout<<" OFF\n";
        else cout<<" ON\n";
    }

    return 0;
}