#include<iostream>
#include<vector>

using namespace std;

int n,m;
vector<pair<int,int>> V[101];
int need[101];
int howmanyneed[101];
int basepart[101];
void f(int target){
    if(need[target])return;

    
    for(pair<int,int> e: V[target]){
        int _part=e.first;
        int _num=e.second;

        need[_part]--;
        howmanyneed[_part]+=_num*howmanyneed[target];
        if(need[_part]==0)f(_part);
    }

}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    cin>>m;
    int _part;
    int _outcome;
    int _num;
    for(int i=0;i<m;i++){
        cin>>_outcome>>_part>>_num;
        V[_outcome].push_back({_part,_num});
        need[_part]++;
        basepart[_outcome]=1;
        //howmanyneed[_part]+=_num;
    }   
    int product;
    for(int i=1;i<=n;i++){
        if(need[i]==0)product=i;
    }
    howmanyneed[product]=1;
    f(product);

    for(int i=1;i<=n;i++){
        if(!basepart[i]){
            cout<<i<<" "<<howmanyneed[i]<<"\n";
        }
    }



    return 0;
}