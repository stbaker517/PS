#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<set>


using namespace std;

void func(int n,int X,int Y,int x,int y,int &c){
    if(n==-1)return;

    int len=1<<n;//2^(n-1)
    int a=0,b=0;

    if(x>=X+len)//1,3
    { 
        X=X+len;
        a++;
    }


    if(y>=Y+len)//1,2
    {
        Y=Y+len;
        b++;
    }

    c+=len*len*(b+2*a);

    func(n-1,X,Y,x,y,c);


}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    int count=0;
    int x,y;
    cin>>x>>y;
    func(n,0,0,x,y,count);
    cout<<count;

    return 0;
}