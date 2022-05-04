#include<iostream>
#include<cstring>
using namespace std;

int n;
int k;
int used[100];
int add[100][100];
int pluged[100];
int numP=0;
bool isPluged(int item){
    for(int i=0;i<n;i++){
        if(pluged[i]==item)return true;
    }
    return false;
}
bool isThereSpace(int item){
    for(int i=0;i<n;i++){
        if(pluged[i]==-1){
            pluged[i]=item;
            numP++;
            return true;
        }
    }
    return false;
}
int getLastJob(int item,int time){
    
    for(int t=time+1;t<k;t++){
        if(used[t]==item){
            return t;
        }
    }
    return 0;
}
int getReplIdx(int time){
    int retIdx=0;
    int idxTime=0;
    for(int i=0;i<n;i++){
        int item=pluged[i];
        int nextT=getLastJob(item,time);
        if(!nextT)return i;
        if(idxTime<nextT){
            retIdx=i;
            idxTime=nextT;
        }
    }
    return retIdx;
}
void printPlug(){
    for(int i=0;i<n;i++){
        printf("%d ",pluged[i]);
    }
    printf("\n");
}
int main(){
    cin>>n>>k;
    for(int i=0;i<k;i++){
        cin>>used[i];
    }
    memset(pluged,-1,sizeof(int)*100);
    int replaced=0;
    for(int t=0;t<k-1;t++){
        //printPlug();
        int job=used[t];
        if(isPluged(job))continue;//꽂혀있으면 그냥 넘어감.
        if(numP<n&&isThereSpace(job))continue;//빈자리가 있으면 꼽고 넘어감.
        int lj=getReplIdx(t);
        if(numP>=n)replaced++;
        pluged[lj]=job;
        
    }
    isThereSpace(used[k-1]);
    if(!isPluged(used[k-1]))replaced++;
    //printPlug();
    cout<<replaced;
    return 0;
}