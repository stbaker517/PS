#include<iostream>
#include<cstring>
using namespace std;

int v,e;
int dist[400][400];

int main(){
    ios::sync_with_stdio(0);
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            dist[i][j]=10;
            if(i==j)dist[i][j]=0;
        }
    }
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            printf("%d ",dist[i][j]);
        }
        printf("\n");
    }
    cin>>v>>e;
    int u,k,w;
    for(int i=0;i<e;i++){
        cin>>u>>k>>w;
        dist[u-1][k-1]=w;
    }
    printf("V:%d\n",v);
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            printf("%d ",dist[i][j]);
        }
        printf("\n");
    }
    for(int t=0;t<v;t++){
        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                if(dist[i][j]>dist[i][t]+dist[t][j]){
                    dist[i][j]=dist[i][t]+dist[t][j];
                }
            }
        }
    }
    printf("V:%d\n",v);
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            printf("%d ",dist[i][j]);
        }
        printf("\n");
    }

    int mindist=0x7fffffff;
    for(int i=0;i<v-1;i++){
        for(int j=i+1;j<v;j++){
            mindist=min(mindist,dist[i][j]+dist[j][i]);
        }
    }
    if(mindist>=100000000)
    cout<<-1;
    else cout<<mindist;



    return 0;
}