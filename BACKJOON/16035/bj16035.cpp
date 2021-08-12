#include<iostream>

using namespace std;

int map[10][10];
bool visit[10][10];
int win[10];
int lose[10];
int N=1;
int cnt=0;
void mainf();
void refresh();
void func();
int main(){
    while(1)
    {
        cin>>N;
        if(N==0)
            return 0;
        mainf();
    }
        return 0;
}
void func(int x,int y){

    if(x==N)
    {
        for(int i=1;i<=N;i++)
        {
            if(win[i]!=N/2||lose[i]!=N/2)return;
        }
        cnt++;
        return;
    }
    if(visit[x][y])
    {
        if(y==N)
            func(x+1,x+2);
        else func(x,y+1);
    }

    if(win[x]<N/2&&lose[y]<N/2)
    {
        win[x]++;
        lose[y]++;
        if(y==N)
            func(x+1,x+2);
        else func(x,y+1);
        win[x]--;
        lose[y]--;

    }
    if(win[y]<N/2&&lose[x]<N/2)
    {
        win[y]++;
        lose[x]++;
        if(y==N)
            func(x+1,x+2);
        else func(x,y+1);
        win[y]--;
        lose[x]--;
    }


}
void mainf(){
    int p;
    cin>>p;
    int x,y;

    cnt=0;
    refresh();

    for(int i=0;i<p;i++)
    {
        cin>>x>>y;
        map[x][y]=1;
        win[x]++;
        lose[y]++;
        visit[x][y]=true;
        visit[y][x]=true;
    }
    func(1,2);
    //cout<<"ANS: ";
    cout<<cnt<<"\n";
    return;

}

void refresh(){
    for(int i=1;i<=N;i++)
    {
        win[i]=0;
        lose[i]=0;
        for(int j=i+1;j<=9;j++)
        {
            map[i][j]=0;
            visit[i][j]=false;
        }
    }
}