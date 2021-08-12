#include<iostream>
#include<vector>
#include<queue>
#include<tuple>

using namespace std;
int box[100][100][100];
bool visit[100][100][100];
int dx[]={0,0,1,-1,0,0};
int dy[]={1,-1,0,0,0,0};
int dz[]={0,0,0,0,1,-1};
int m,n,h;

int maxD=0;
queue<tuple<int,int,int>>Q;
void BFS();
int main(){
   // ios::sync_with_stdio(0);
   // cin.tie(0);

    cin>>n>>m>>h;
  

//cout<<"0\n";    
    vector<tuple<int,int,int>>vec;
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<m;j++)
        {
            for(int k=0;k<n;k++)
            {
                cin>>box[i][j][k];
                if(box[i][j][k]==1)
                    vec.push_back(make_tuple(i,j,k));
                visit[i][j][k]=false;
            }
        }
    }
    //cout<<"1\n";
    for(tuple<int,int,int>e:vec)
    {
        Q.push(make_tuple(get<0>(e),get<1>(e),get<2>(e)));
        //cout<<get<0>(e)<<get<1>(e)<<get<2>(e)<<'\n';
        visit[get<0>(e)][get<1>(e)][get<2>(e)]=true;
    }




    while(!Q.empty())
        BFS();

 


    for(int k=0;k<h;k++)
    {
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++)
            {
                if(box[k][i][j]==0)
                {
                    cout<<-1;
                    return 0;
                }
                if(box[k][i][j]>maxD)maxD=box[k][i][j];
            }
        }
    }

    cout<<maxD-1;
    return 0;

}

void BFS(){
    int x,y,z;
    z=get<0>(Q.front());
    x=get<1>(Q.front());
    y=get<2>(Q.front());
    Q.pop();
    //cout<<z<<x<<y<<'\n';
    if(x<0||y<0||z<0||x>=m||y>=n||z>=h)return;

    for(int i=0;i<6;i++)
    {
        int X=x+dx[i],Y=y+dy[i],Z=z+dz[i];
        if(X<0||Y<0||Z<0||X>=m||Y>=n||Z>=h)continue;
        if(visit[Z][X][Y]==false&&box[Z][X][Y]==0)
        {
            
            visit[Z][X][Y]=true;
            box[Z][X][Y]=box[z][x][y]+1;
            Q.push(make_tuple(Z,X,Y));
        }
    }
}