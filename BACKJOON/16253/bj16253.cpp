#include<iostream>
#include<vector>

using namespace std;

int MIN=0x7fffffff;
int N;
int time[10001];
int cost[10001];//1만개의 인터벌
int C=0;
int cnt[10001];
vector<pair<int,int>>vec;
int dis(int idx)
{
    if(cnt[idx]==2)return 1;
    else if(3<=cnt[idx]&&cnt[idx]<=6)return 2;
    else return 0;
}


void func(int n,int idx){
    if(n==N)
    {
        MIN=min(C,MIN);
        return ;
    }

    
    if(time[idx]<120)
    {
        if(cnt[idx])func(n,idx+1);


        time[idx]+=vec[n].first;
        cnt[idx]++;
        cost[idx]+=vec[n].second>>dis(idx);
        C+=vec[n].second>>dis(idx);
        func(n+1,idx);
        C-=vec[n].second>>dis(idx);
        cost[idx]-=vec[n].second>>dis(idx);
        cnt[idx]--;
        time[idx]-=vec[n].first;


    }
    else//자리가 없으면?
    {
        func(n,idx+1);
    }




}



int main(){

    cin>>N;
    int x,y;
    for(int i=0;i<N;i++)
    {
        cin>>x>>y;
        vec.push_back({x,y*100});
    }


    func(0,1);
    printf("%d.%02d",MIN/100,MIN%100);

    return 0;
}
