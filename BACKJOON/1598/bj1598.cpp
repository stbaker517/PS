#include<iostream>

using namespace std;

int main(){

    int a,b;
    cin>>a>>b;
    a-=1;
    b-=1;
    int A,B;
    A=abs(a%4-b%4);
    B=abs(a/4-b/4);


    cout<<A+B;

    return 0;
}