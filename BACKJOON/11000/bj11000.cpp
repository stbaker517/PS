#include<iostream>
#include<vector>
#include<queue>


using namespace std;

struct compare{
    bool operator()(pair<int,int>&a,pair<int,int>&b)
    {
        if(a.first==b.first)
        {
            return a.second>b.second;
        }
        else
            return a.first>b.first;
    }

};

priority_queue<pair<int,int>,vector<pair<int,int>>,compare>PQ;

priority_queue<int,vector<int>,greater<int>>ClassRoom;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;cin>>n;

    int s,e;
    for(int i=0;i<n;i++)
    {
        cin>>s>>e;
        PQ.push({s,e});
    }

    //int idx=1;
    while(!PQ.empty())
    {
        pair<int,int> TP=PQ.top();
        PQ.pop();

        //cout<<idx++<<": "<<TP.first<<" "<<TP.second<<'\n';//TEST

        if(ClassRoom.empty())
        {
            ClassRoom.push(TP.second);
            continue;
        }

        if(ClassRoom.top()>TP.first)
        {
            ClassRoom.push(TP.second);
            continue;
        }

        ClassRoom.pop();
        ClassRoom.push(TP.second);

    }

    
    cout<<ClassRoom.size();


    /*while(!ClassRoom.empty())
    {
        cout<<"\n"<<ClassRoom.top();
        ClassRoom.pop();
    }*/
    return 0;
}