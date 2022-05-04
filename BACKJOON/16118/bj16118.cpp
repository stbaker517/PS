#include<iostream>
#include<tuple>
#include<vector>
#include<queue>
using namespace std;
#define pii pair<int,long long>
#define tiii tuple<int,int,long long>
#define fmt make_tuple
struct cmp{

    bool operator()(tiii&a , tiii&b){
        if(get<2>(a)>get<2>(b))return true;
        return false;
    }
};
struct cmp_pii{
    bool operator()(pii&a,pii&b){
        if(a.second<=b.second)return true;
        return false;
    }
};

int n,m;

vector<pii> V[4000];
long long dist_fox[4000];
long long dist_wolf[4000][2];

bool fvisit[4000];
bool wvisit[4000][2]; 
void DJ_fox(){
    priority_queue<pair<int,long long>,vector<pair<int,long long>>,cmp_pii>PQ;
    dist_fox[0]=0;
    PQ.push({0,0});
    while(!PQ.empty()){
        pii cur=PQ.top();
        PQ.pop();
        int curV=cur.first;
        long long curD=cur.second;
        if(curV>dist_fox[curV])continue;
        for(pii next:V[curV]){
            int nextV=next.first;
            long long nextD=next.second;
            if(dist_fox[nextV]>curD+nextD){
                dist_fox[nextV]=curD+nextD;
                PQ.push({nextV,dist_fox[nextV]});
            }
        }
    }
}

void DJ_wolf(){
    priority_queue<tuple<int,int,long long>,vector<tuple<int,int,long long>>,cmp>PQ;
    //wvisit[0][1]=1;
    //wvisit[0][1]=1;
    PQ.push(fmt(0,1,0));
    dist_wolf[0][1]=0;
    while(!PQ.empty()){
        tiii cur=PQ.top();
        PQ.pop();
        int curV=get<0>(cur);  
        int prespeed=get<1>(cur);
        long long curD=get<2>(cur);
        //cout<<curD<<"\n";

        if(dist_wolf[curV][prespeed]<curD)continue;
        int speed=!prespeed;
        //printf(">%d speed: %d dist:%d\n",curV,prespeed,curD);
        //dist_wolf[curV][prespeed]=curD;
        for(pii next:V[curV]){
            int nextV=next.first;
            long long nextD=next.second;
            
            if(!speed){
                nextD/=2;
            }
            else{
                nextD*=2;
            }
            if(dist_wolf[nextV][speed]>dist_wolf[curV][prespeed]+nextD){
                dist_wolf[nextV][speed]=dist_wolf[curV][prespeed]+nextD;
                PQ.push(fmt(nextV,speed,dist_wolf[nextV][speed]));
            }
        }
    }

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    int u,v;
    long long w;
    for(int i=0;i<m;i++){
        cin>>u>>v>>w;
        w*=2;
        V[u-1].push_back({v-1,w});
        V[v-1].push_back({u-1,w});
    }
    for(int i=0;i<n;i++){
        dist_fox[i]=(long long)2e10;
        dist_wolf[i][0]=(long long)2e10;
        dist_wolf[i][1]=(long long)2e10;
    }
    dist_wolf[0][1]=0;
    DJ_fox();
    DJ_wolf();
    int cnt=0;
    
    for(int i=0;i<n;i++){
        
       printf("[%d] %lld %lld %lld\n",i,dist_fox[i],dist_wolf[i][0],dist_wolf[i][1]);
        if(dist_fox[i]<dist_wolf[i][0]&&dist_fox[i]<dist_wolf[i][1]){
            cnt++;
        }
    }
    cout<<cnt;


    return 0;
}