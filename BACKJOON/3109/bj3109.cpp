#include<iostream>

using namespace std;

int dx[]={-1,0,1};
int dy[]={1,1,1};
int map[10000][501];
int flag;
int r,c;
void ptr()
{
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cout<<map[i][j];
        }
        cout<<"\n";
    }
}
void path(int x,int y){

    if(y==c-1)
    {
        flag=1;
        return;
    }

    
    for(int i=0;i<3;i++)
    {
        int X=x+dx[i];
        int Y=y+dy[i];
        if(X<0||X>=r||Y<0||Y>=c)continue;
        if(map[X][Y])continue;
        if(flag)continue;

        

        map[X][Y]=1;
        path(X,Y);


    }
    
    return ;


}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>r>>c;

    char ch;
   
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cin>>ch;
            if(j==c)continue;

            if(ch=='.')map[i][j]=0;
            else map[i][j]=8;
        }
    }

    for(int i=0;i<r;i++)
    {
        flag=0;
        path(i,0);
        //cout<<"\n";
        //ptr();
    }
    int t=0;
    for(int i=0;i<r;i++)
    {
        if(map[i][c-1]==1)
        t+=1;
    }
    cout<<t;
    return 0;
}