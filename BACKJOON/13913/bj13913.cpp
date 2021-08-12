#include<iostream>
#include<queue>
#include<stack>
using namespace std;





queue<int>Q;
int main(){
    int prev[100001]={0,};
    int map[100001]={0,};
    bool visit[100001];
    int s,t;
    cin>>s>>t;
    visit[s]=true;
    Q.push(s);
    prev[s]=-1;
    while(!Q.empty()){
        int a=Q.front();
        Q.pop();
        
        if(a+1<=100000)
        {
            if(visit[a+1]==false)
            {
                visit[a+1]=true;
                prev[a+1]=a;
                map[a+1]=map[a]+1;
            Q.push(a+1);
            
            }
            
        }
        if(a-1>=0)
        {
            if(visit[a-1]==false)
            {
                visit[a-1]=true;
                prev[a-1]=a;
            map[a-1]=map[a]+1;
            Q.push(a-1);}
           
        }
        if(a*2<=100000)
        {
            if(visit[a*2]==false)
            {
                visit[a*2]=true;
                prev[a*2]=a;
            map[a*2]=map[a]+1;
            Q.push(a*2);}
          
        }


    }
    cout<<map[t]<<'\n';
    stack<int>ptr;
    int a=t;

    while(prev[a]!=-1)
    {
        a=prev[a];
        ptr.push(a);
        //cout<<a<<"";
        
    }

    while(!ptr.empty())
    {
        cout<<ptr.top()<<" ";
        ptr.pop();
    }
    cout<<t;
    return 0;
}