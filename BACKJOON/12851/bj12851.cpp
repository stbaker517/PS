#include<iostream>
#include<queue>

using namespace std;

int map[200000]={0,};
bool visit[200000];
int count[200000]={0,};
queue<int>Q;
int main(){
    int s,t;
    cin>>s>>t;
    visit[s]=true;
    Q.push(s);
    count[s]++;
    while(!Q.empty()){
        int a=Q.front();
        Q.pop();
        
        if(a+1<=100000)
        {
            if(visit[a+1]==false)
            {
                visit[a+1]=true;
                count[a+1]+=count[a];
                map[a+1]=map[a]+1;
            Q.push(a+1);
            
            }
            else if(map[a+1]==map[a]+1)
                count[a+1]+=count[a];
        }
        if(a-1>=0)
        {
            if(visit[a-1]==false)
            {
                visit[a-1]=true;
                count[a-1]+=count[a];
            map[a-1]=map[a]+1;
            Q.push(a-1);}
            else if(map[a-1]==map[a]+1)
                count[a-1]+=count[a];
        }
        if(a*2<=100000)
        {
            if(visit[a*2]==false)
            {
                visit[a*2]=true;
                count[a*2]+=count[a];
            map[a*2]=map[a]+1;
            Q.push(a*2);}
            else if(map[a*2]==map[a]+1)
                count[a*2]+=count[a];
        }


    }
    cout<<map[t]<<"\n"<<count[t];

    return 0;
}