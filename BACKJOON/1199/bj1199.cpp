#include<iostream>
#include<stack>
#include<string>
using namespace std;

int G[1001][1001];
int vert[1001];

int n;
string str="";
void traverse(int v,int k){
    
    vert[v]=1;
    for(int i=1;i<=n;i++)
    {
        while(G[v][i])
        {
            G[v][i]--;
            G[i][v]--;

            traverse(i,k+1);
        }
    }
    str+=to_string(v);
    str+=" ";

    return;
}
int main(){
    cin>>n;
    int tot=0;
    for(int i=1;i<=n;i++)
    {
        tot=0;
        for(int j=1;j<=n;j++)
        {
            cin>>G[i][j];
            if(G[i][j])
            {
                tot+=G[i][j];
            }
        }
        if(tot%2==1)
        {
            cout<<-1;
            return 0;
        }
    }
    traverse(1,1);
    for(int i=1;i<=n;i++)
    {
        if(vert[i]==0)
        {
            cout<<-1;
            return 0;
        }
    }
    cout<<str;
    return 0;
}