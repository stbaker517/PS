#include<iostream>

using namespace std;
int map[10][10];
int B[20];
int r;
int h;
int Max1=0;
int Max2=0;
int cnt=0;
void set(int ,int,int,int );
void func(int n,int i){
    if(n>=h)
    {
        if(i%2==1){
        if(Max1<cnt)Max1=cnt;}
        else
        {
            if(Max2<cnt)Max2=cnt;
        }
        return;
    }
    if(n<r)
    {
        for(int y=0;y<=n;y++)
        {
            if(map[n-y][y]&&!B[r-1+n-2*y])
            {
                B[r-1+n-2*y]=1;
                cnt++;
                func(n+2,i);
                cnt--;
                B[r-1+n-2*y]=0;
            }
            else func(n+2,i);
        }
        
    }
    else
    {
        for(int y=r-1;y>n-r;y--)
        {
            if(map[n-y][y]&&!B[r-1+n-2*y])
            {
                B[r-1+n-2*y]=1;
                cnt++;
                func(n+2,i);
                cnt--;
                B[r-1+n-2*y]=0;
            }
            else func(n+2,i);
        }
    }
    

}


int main(){
    cin>>r;
    h=r+r-1;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<r;j++)
        {
            cin>>map[i][j];
        }
    }
    func(0,0);
    func(1,1);
    cout<<Max1+Max2;

    return 0;
}
