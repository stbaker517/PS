#include<iostream>
#include<queue>

using namespace std;

int r,c;
char map[100][100];


void BFS(queue<int,int>>&Q){
    

}

void func(){
    cin>>r>>c;
    queue<pair<int,int>>tq;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cin>>map[i][j];
            if(map[i][j]=='$')
                tq.push({i,j});
                
        }
    }


}
int main(){



    return 0;
}