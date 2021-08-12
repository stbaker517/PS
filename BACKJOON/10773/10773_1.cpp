#include<iostream>
#include<stack>

using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    stack<int> S;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int input;
        cin>>input;
        if(input){
            S.push(input);
        }
        else{
            S.pop();
        }
    }
    int r=0;
    int t=S.size();
    for(int i=0;i<t;i++)
    {
        r+=S.top();
        S.pop();
    }
    cout<<r;
}