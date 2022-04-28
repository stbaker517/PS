#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
#include<cstring>

using namespace std;
/*
9 2
1 3
4 3
5 4
5 6
6 7
2 3
9 6
6 8
*/
vector<int> V[100001];
bool vvisit[100001];
int dp[100001][21];
int fP[100001][21];
int C[100001][21];//from Parent to Child
//1. 부모노드부터 이어지는 값을 fromP 배열에 저장.
//2. 아래로부터 값을 수집해 위로 리턴.

//-------------

//1. 부모는 dp를 아래로 전달.
//2. dp를 전달받은 child는 맨 처음 전달 받은 frmP값을 제외한 나머지의 dp를 통해 갱신을 시킨다.

int n;
int k;
/*
int* dfs1(int v,int* fromP)
{
    // cout << v;
    for(int i=0;i<k-1;i++){
        fP[v][i+1]=fromP[i];
        dp[v][i+1]+=fromP[i];
    }
    queue<int*>Q;
    for (int next : V[v])
    {
        if(vvisit[next])continue;
        vvisit[1];
        int*ret=dfs1(next, dp[v]);//부모로부터 온 dp+본인의 값만  child 에게전달해줌. -> child간의 값 영향이 없다는 소리.
        Q.push(ret);
        
    }

    //child에서 올라온 dp값을 v의 dp에 추가.
    while(!Q.empty()){
        int* _pop=Q.front();
        Q.pop();

        for(int i=k-2;i>=0;i--){
            dp[v][i+1]=_pop[i]-dp[v][i];
        }
    }
    
    return dp[v];

}
void dfs2(int v,int*fromP){//
    int tmp[21]={0};

}*/

int* dfs_rev(int v){
    //cout<<"dfs_rev["<<v<<"]\n";
    queue<int*>Q;

    for(int nxt:V[v]){
        if(vvisit[nxt])continue;
        vvisit[nxt]=1;
        Q.push(dfs_rev(nxt));
    }

    while(!Q.empty()){
        int*_pop=Q.front();
        Q.pop();
        
        for(int i=0;i<k;i++){
            C[v][i+1]+=_pop[i];
        }

    }
    C[v][0]=1;
    return C[v];
}

void dfs_dwn(int v,int* fromP){
    //cout<<"dfs_dwn["<<v<<"]\n";
    for(int i=0;i<=k;i++){
        dp[v][i]+=C[v][i];
    }

    for(int i=0;i<=k-1;i++){
        dp[v][i+1]+=fromP[i];
    }
    //dp[v][0]=1;

    for(int next:V[v]){
        if(vvisit[next])continue;
        vvisit[next]=1;
        for(int i=0;i<=k-2;i++){
            dp[next][i+2]-=C[next][i];
        }
        dfs_dwn(next,dp[v]);
    }
    return;
}
/*
int* dfs_(int v,int* fromP){


    int to_child[21];
    memset(to_child,0,sizeof(int)*21);
    to_child[0]=1;
    for(int i=0;i<k;i++){
        fP[v][i]=fromP[i];
    }
    for(int i=0;i<k-1;i++){

    }

    for(int nxt:V[v]){
        if(vvisit[nxt])continue;
        vvisit[nxt]=1;
        dfs_(nxt,to_child);
    }
}*/
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    int a, b;
    for (int i = 0; i < n -1; i++)
    {
        cin >> a >> b;
        V[a].push_back(b);
        V[b].push_back(a);
    }

    int tmpzero[21]={0};
    vvisit[1] = 1;
    dfs_rev(1);
    memset(vvisit,0,sizeof(bool)*100001);

/*
    for(int i=1;i<=n;i++){
        printf("[%d] ",i);
        for(int j=0;j<=k;j++){
            printf("%d ",C[i][j]);
        }
        printf("\n");
  */
    vvisit[1] = 1;
    dfs_dwn(1,tmpzero);
    memset(vvisit,0,sizeof(bool)*100001);

    int mm = 0;
    for (int i = 1; i <= n; i++)
    {
        //cout<<i<<"th: ";
        int sum = 0;
        for (int j = 0; j <= k; j++)
        {
            sum += dp[i][j];
        }
        //cout<<sum<<"\n";
        mm = max(mm, sum);
    }

    //cout<<"ANS: ";
    cout << mm;

    return 0;
}