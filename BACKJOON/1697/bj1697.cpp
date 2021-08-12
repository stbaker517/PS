#include<iostream>
#include<queue>

using namespace std;

int map[100001]={0,};
queue<int>Q;
int main(){
    int s,t;
    cin>>s>>t;
    Q.push(s);

    while(!Q.empty()){
        int a=Q.front();
        Q.pop();
        if(a==t)break;
        if(a+1<=100000&&!map[a+1])
        {
            map[a+1]=map[a]+1;
            Q.push(a+1);
        }
        if(a-1>=0&&!map[a-1])
        {
            map[a-1]=map[a]+1;
            Q.push(a-1);
        }
        if(a*2<=100000&&!map[a*2])
        {
            map[a*2]=map[a]+1;
            Q.push(a*2);
        }


    }
    cout<<map[t];

    return 0;
}