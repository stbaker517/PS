#include<iostream>
#include<stack>
#include<queue>
#include<vector>

using namespace std;

int n=1,m=1,t=1,p=1;
int map[100][100];
int rs,re,cs,ce;

void mainf();
void refresh();
void fold(int,int);
void print();
int main(){
    while(n||m||t||p)
        mainf();



    return 0;
}

void mainf(){
    
    cin>>n>>m>>t>>p;//m 가로 n 세로 <=32  t 접는 회수 p 펀칭 회수
    if(!n||!m||!t||!p)return;
    int d,a;
    refresh();
    //print();
    for(int i=0;i<t;i++)
    {
        cin>>d>>a;
        fold(d,a);
        //print();
    }
    int cnt=0;
    for(int i=0;i<p;i++)
    {
        cin>>d>>a;
        //cout<<"ANS: ";//TEST
        cout<<map[d][a]<<"\n";
    }
    
    //cout<<cnt<<"\n";
}

void fold(int d ,int c){//n row m col
    int tmp[35][35];
 /*   if(d==2)
    {
        for(int i=rs;i<n;i++ )
        {
            for(int j=cs+c-1;j>=cs;j--)
            {
                map[i][cs+c+(cs+c-1-j)]+=map[i][j];
                //map[i][j]=0;
            }
        }
        cs=cs+c;

    }
    else
    {
        for(int j=cs;j<m;j++)
        {
            for(int i=rs+c-1;i>=rs;i--)
            {
                map[rs+c+(rs+c-1-i)][j]+=map[i][j];
                 //map[i][j]=0;
            }

        }
        rs=rs+c;
    }
*/

//===============================================
    if(d==2)//세로줄 접기.
    {
        
        for(int i=0;i<n;i++ )
        {
            for(int j=c-1;j>=0;j--)
            {
                if(c+c-1-j>=m)
                    map[i][c+c-1-j]=map[i][j];
                else
                    map[i][c+c-1-j]=map[i][j]+map[i][c+(c-1-j)];
                //map[i][j]=0;
            }
        }
        m=(m-c>c)?m-c:c;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                map[i][j]=map[i][j+c];
            }
        }

    }
    else
    {
        for(int j=0;j<m;j++)
        {
            for(int i=c-1;i>=0;i--)
            {
                if(c+(c-1-i)>=n)
                    map[c+c-1-i][j]=map[i][j];
                else    
                    map[c+c-1-i][j]=map[c+(c-1-i)][j]+map[i][j];
                 //map[i][j]=0;
            }

        }
        //cout<<"n: "<<n;
        n=(n-c>c)?n-c:c;
        //cout<<"newN:"<<n<<"\n";
        for(int j=0;j<m;j++)
        {
            for(int i=0;i<n;i++)
            {
                map[i][j]=map[c+i][j];
            }
        }
    }

}
void refresh(){
    for(int i=0;i<100;i++)
    {
        for(int j=0;j<100;j++)
            if(i<n&&j<m)map[i][j]=1;
            else map[i][j]=0;
    }
}
void print(){
    cout<<"map\n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<map[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"done\n";
    
}