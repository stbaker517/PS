#include<iostream>

using namespace std;
char map[6561][6561];// char 1byte 42mb 200mb 

//========================================================================
//========================================================================

void func(int k,int x,int y)
{
    if(k==3)//BC
    {
        for(int i=0;i<3;i++)   
        {
            for(int j=0;j<3;j++)
                map[x+i][y+j]='*';
        }
        map[x+1][y+1]=' ';
        return ;
    }
    
    int nk=k/3;//새로운 길이
    func(nk,x,y);//1 위 왼쪽
    func(nk,x+nk,y);//2 중간 왼쪽
    func(nk,x+2*nk,y);//3 아래 왼쪽
    func(nk,x,y+nk);//4 위 중간
    func(nk,x+2*nk,y+nk);//5 아래 중간
    func(nk,x,y+2*nk);//6 위 오른쪽
    func(nk,x+nk,y+2*nk);//7 중간 오른쪽
    func(nk,x+2*nk,y+2*nk);//8 아래 오른쪽

    for(int i=x+nk;i<x+2*nk;i++)
    {
        for(int j=y+nk;j<y+2*nk;j++)
            map[i][j]=' ';//공백으로 가운데를 비워줌.
    }
}

//========================================================================
//========================================================================
void print(int k){
    for(int i=0;i<k;i++)
    {
        for(int j=0;j<k;j++)
            cout<<map[i][j];
        cout<<"\n";
    }

}
int main(){
    int k;
    cin>>k;
    func(k,0,0);
    print(k);

    return 0;
}