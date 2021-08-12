#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
int map[100][100];
int visit[100][100];

int m,n,k;//m 행 n 열 k 직사각형 개수
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int dfs(int x,int y){
   int cnt=0;
    queue<pair<int,int>>Q;
    visit[x][y]=true;
    Q.push({x,y});

    while(!Q.empty())
    {   
        cnt++;
        //cout<<cnt<<"\n";
        int a=Q.front().first;
        int b=Q.front().second;
        map[a][b]=1;
        
        Q.pop();
        
        for(int i=0;i<4;i++)
        {
            int A=a+dx[i];
            int B=b+dy[i];

            if(A<0||B<0||A>=m||B>=n)continue;
            if(map[A][B])continue;
            if(visit[A][B])continue;

            map[A][B]=1;
            visit[A][B]=true;

            Q.push({A,B});



        }

    }

    //cout<<cnt<<"ll\n";
    return cnt;


}
void print(int m,int n){
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<map[i][j];
        }
        cout<<"\n";
    }
}
int main(){
    

    cin>>m>>n>>k;

    int x1,x2,y1,y2;
    for(int i=0;i<k;i++)
    {
        cin>>y1>>x1>>y2>>x2;
        for(int x=x1;x<x2;x++)
        {
            for(int y=y1;y<y2;y++){
                map[x][y]=1;
            }
        }
    }

    //print(m,n);

    vector<int>Vec;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++)
        {
            if(!map[i][j])
            {
                Vec.push_back(dfs(i,j));
                //print(m,n);
            }
        }
    }
    sort(Vec.begin(),Vec.end());

    cout<<Vec.size()<<"\n";
    for(int e:Vec)
    {
        cout<<e<<" ";
    }





    return 0;
}