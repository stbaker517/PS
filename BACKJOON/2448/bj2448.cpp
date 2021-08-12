#include<iostream>

using namespace std;




char arr[3*1024][2*3*1024+1]={0,};
void func(int n,int x,int y)//x:행 y:열
{
    //가로 = 2h+1 높이 n
    if(n==3)
    {
        arr[x][y]=1;
        arr[x+1][y+1]=1;
        arr[x+1][y-1]=1;
        arr[x+2][y-2]=1;
        arr[x+2][y-1]=1;
        arr[x+2][y]=1;
        arr[x+2][y+1]=1;
        arr[x+2][y+2]=1;
        return;
    }

    func(n/2,x,y);//위
    func(n/2,x+n/2,y-n/2);//좌
    func(n/2,x+n/2,y+n/2);//우

}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;
    func(n,0,n);
    for(int i=0;i<n;i++)
    {
        for(int j=1;j<=2*n+1;j++)
        {
            if(arr[i][j])
            cout<<'*';
            else cout<<' ';
        }
        cout<<'\n';
    }





}