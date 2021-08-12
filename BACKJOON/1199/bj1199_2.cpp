#include<iostream>
#include<queue>
#include<stack>
#include<tuple>
#include<vector>
#include<deque>

using namespace std;

int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};//6 3 12 9


int map[100][100];

char smove[10001];


deque<pair<int,int>>snake;


int dir=1;
int n,k;
int t=0;

/*void print(){
    cout<<"printMAP   T: "<<t<<"\n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<map[i][j]<<" ";
        }
        cout<<"\n";
    }
}*/

void ff(){//뱀은 2 사과는 1

    while(1)
    {
        t++;
        int headX=snake.front().first+dx[dir];
        int headY=snake.front().second+dy[dir];

        if(headX>=n||headX<0||headY>=n||headY<0)return;
        if(map[headX][headY]==2)return;

        
        snake.push_front({headX,headY});

        if(!map[headX][headY]){
            map[snake.back().first][snake.back().second]=0;
            snake.pop_back();
        }
        
        map[headX][headY]=2;


        if(smove[t])//포인트
        {
            if(smove[t]=='D')//--
            {
                dir=(dir+3)%4;
            }
            else{//L++
                dir=(dir+1)%4;
            }
        }
        //print();
    }


    
   
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>k;
    int x,y;

    for(int i=0;i<k;i++)
    {
        cin>>x>>y;
        map[x-1][y-1]=1;
    }

    cin>>k;
    char ch;

    for(int i=0;i<k;i++)
    {
        cin>>x>>ch;
        smove[x]=ch;
    }

    snake.push_back({0,0});
    ff();
    cout<<t;

    return 0;
}